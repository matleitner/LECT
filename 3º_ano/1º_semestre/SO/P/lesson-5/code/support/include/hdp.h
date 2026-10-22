/**
 * \defgroup hdp hdp
 * \ingroup C-Cpp-library
 * \brief Handle Defensive Programming of C/C++ library functions module.
 *
 * \details This file handles defensive programming approach of native C/C++ libraries functions, removing the
 *          responsibility of handling errors from the function's clients.
 *          Error identification uses <a href="https://man7.org/linux/man-pages/man3/errno.3.html">errno values</a>, although not necessarily using <tt>errno</tt> global variable
 *          (like in <tt>\ref NZ</tt> macro, used for pthread library functions).
 *
 * Errors are handled by two possible error handling policies (through the definition of a macro -- EXIT_POLICY/EXCEPTION_POLICY --
 * as a compiler option):
 *      -# <tt>EXIT_POLICY</tt> (default): describes the failed call in `stderr` (with the identification
 *         of the errno error, and the precise location the call), generates a segmentation fault
 *         (enabling a stack trace within a debugger like `gdb`), and exits program execution (applicable
 *          for C and C++);
 *      -# <tt>EXCEPTION_POLICY</tt>: throws a `int` exception with the (errno) status error returned by
 *         the original function (applicable only to C++).
 *
 * To change the default (<tt>EXIT_POLICY</tt>) policy just add \c -DEXCEPTION_POLICY in the compiler options.
 *
 * Available macros (name directly related with error test):
 *      -# <tt>\ref MO</tt>/<tt>\ref errMO</tt> [Minus One]: test error comparing to -1 (== -1)                          --  error in errno
 *      -# <tt>\ref Ne</tt>/<tt>\ref errNe</tt> [Negative]: test error comparing to negative integer result (< 0)        --  error in errno
 *      -# <tt>\ref Nu</tt>/<tt>\ref errNu</tt> [Null]: test error comparing to NULL (== NULL)                           --  error in errno
 *      -# <tt>\ref NZ</tt>/<tt>\ref errNZ</tt> [Not Zero]: test error comparing to non-zero value (!= 0)                --  error in function result
 *      -# <tt>\ref EF</tt>/<tt>\ref errEF</tt> [End of File]: test error comparing to EOF (== EOF)                      --  error in errno
 *      -# <tt>\ref MOP</tt>/<tt>\ref errMOP</tt> [Minus One Pointer]: test error comparing to (void*)-1 (== (void*)-1)  --  error in errno
 *
 * Examples:
 *
 * \code{.c}
 *    pid_t ret = MO(fork());
 *
 *    MO(wait(NULL));
 *
 *    Ne(printf("Hello\n"));
 *
 *    int *p = (int*)Nu(malloc(10));
 *
 *    int shmid = MO(shmget(IPC_PRIVATE, sizeof(int), 0600 | IPC_CREAT | IPC_EXCL));
 *    int* shm = (int*)MOP(shmat(shmid, NULL, 0));
 *
 *    NZ(pthread_create(...));
 * \endcode
 *
 * To discover the proper macro check for section RETURN VALUE in the function man page.<BR>
 * Consider the definition of the following bash function to make it easier to fetch this information.
 *
 * \code{.bash}
 *   function manrv() {
 *      man -P 'less -p ^"RETURN VALUE"' $*
 *   }
 * \endcode
 *
 * \brief \ref hdp "Handle Defensive Programming of C/C++ library functions" include file.
 * \remarks Handles defensive programming of native libraries
 * <p><b>group of hdp</b>
 *
 * \author Miguel Oliveira e Silva
 * \date 2026
 * \version 1.0
 *  @{ 
 **/

/*!
 * \file
 * \brief Handle Defensive Programming module.
 */

#ifndef HDP_H
#define HDP_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//#define EXCEPTION_POLICY // only for C++
//#define EXIT_POLICY // DEFAULT

#if defined __cplusplus && defined EXCEPTION_POLICY
#define MO(func_call) ({\
      int result; \
      if ((result = (func_call)) == -1) \
         throw errno; \
      result; \
   })

#define Ne(func_call) ({\
      int result; \
      if ((result = (func_call)) < 0) \
         throw errno; \
      result; \
   })

#define Nu(func_call) ({\
      void* result; \
      if ((result = (func_call)) == NULL) \
         throw errno; \
      result; \
   })

#define NZ(func_call) ({\
      int result; \
      if ((result = (func_call)) != 0) \
         throw result; \
      result; \
   })

#define EF(func_call) ({\
      int result; \
      if ((result = (func_call)) == EOF) \
         throw errno; \
      result; \
   })

#define MOP(func_call) ({\
      void* result; \
      if ((result = (func_call)) == (void*)-1) \
         throw errno; \
      result; \
   })
#else
/**
 * \hideinitializer
 * Macro <i>Minus One</i>: applicable to functions returning \c -1 for error indication (cause stored in \c errno).
 *
 * \param [in] func_call [<code>int</code>] function call (or expression with the result of a library function call)
 *
 * Same as \ref errMO.
 */
#define MO(func_call) ({\
      int result; \
      if ((result = (func_call)) == -1) \
         do { \
            fprintf (stderr, "%s at \"%s\":%d: %s\n", \
                     __FUNCTION__ , __FILE__, __LINE__, strerror (errno)); \
            *((int*)0) = 0; \
            abort (); \
         } while (0); \
      result; \
   })

/**
 * \hideinitializer
 * Macro <i>Negative</i>: applicable to functions returning a negative integer value for error indication (cause stored in \c errno).
 *
 * \param [in] func_call [<code>int</code>] function call (or expression with the result of a library function call)
 *
 * Same as \ref errNe.
 */
#define Ne(func_call) ({\
      int result; \
      if ((result = (func_call)) < 0) \
         do { \
            fprintf (stderr, "%s at \"%s\":%d: %s\n", \
                     __FUNCTION__ , __FILE__, __LINE__, strerror (errno)); \
            *((int*)0) = 0; \
            abort (); \
         } while (0); \
      result; \
   })

/**
 * \hideinitializer
 * Macro <i>Null</i>: applicable to functions returning \c NULL for error indication (cause stored in \c errno).
 *
 * \param [in] func_call [<code>void*</code>] function call (or expression with the result of a library function call)
 *
 * Same as \ref errNu.
 */
#define Nu(func_call) ({\
      void* result; \
      if ((result = (func_call)) == NULL) \
         do { \
            fprintf (stderr, "%s at \"%s\":%d: %s\n", \
                     __FUNCTION__ , __FILE__, __LINE__, strerror (errno)); \
            *((int*)0) = 0; \
            abort (); \
         } while (0); \
      result; \
   })

/**
 * \hideinitializer
 * Macro <i>Not Zero</i>: applicable to functions returning a value different to 0 for error indication (error in function result using errno code values).
 *
 * \param [in] func_call [<code>int</code>] function call (or expression with the result of a library function call)
 *
 * Same as \ref errNZ.
 */
#define NZ(func_call) ({\
      int result; \
      if ((result = (func_call)) != 0) \
         do { \
            fprintf (stderr, "%s at \"%s\":%d: %s\n", \
                     __FUNCTION__ , __FILE__, __LINE__, strerror (result)); \
            *((int*)0) = 0; \
            abort (); \
         } while (0); \
      result; \
   })

/**
 * \hideinitializer
 * Macro <i>End of File</i>: applicable to functions returning \c EOF for error indication (cause stored in \c errno).
 *
 * \param [in] func_call [<code>int</code>] function call (or expression with the result of a library function call)
 *
 * Same as \ref errEF.
 */
#define EF(func_call) ({\
      int result; \
      if ((result = (func_call)) == EOF) \
         do { \
            fprintf (stderr, "%s at \"%s\":%d: %s\n", \
                     __FUNCTION__ , __FILE__, __LINE__, strerror (errno)); \
            *((int*)0) = 0; \
            abort (); \
         } while (0); \
      result; \
   })

/**
 * \hideinitializer
 * Macro <i>Minus One Pointer</i>: applicable to functions returning \c (void*)-1 for error indication (cause stored in \c errno).
 *
 * \param [in] func_call [<code>void*</code>] function call (or expression with the result of a library function call)
 *
 * Same as \ref errMOP.
 */
#define MOP(func_call) ({\
      void* result; \
      if ((result = (func_call)) == (void*)-1) \
         do { \
            fprintf (stderr, "%s at \"%s\":%d: %s\n", \
                     __FUNCTION__ , __FILE__, __LINE__, strerror (errno)); \
            *((int*)0) = 0; \
            abort (); \
         } while (0); \
      result; \
   })
#endif

/**
 * Same as \ref MO
 */
#define errMO MO
/**
 * Same as \ref Ne
 */
#define errNe Ne
/**
 * Same as \ref Nu
 */
#define errNu Nu
/**
 * Same as \ref NZ
 */
#define errNZ NZ
/**
 * Same as \ref EF
 */
#define errEF EF
/**
 * Same as \ref MOP
 */
#define errMOP MOP

#endif

/* ************************************************** */
/**
 * @} close group hdp
 **/
/* ************************************************** */

