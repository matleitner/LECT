/**
 * \defgroup dbc dbc 
 * \ingroup C-Cpp-library
 * \brief Design-by-Contract module for C/C++.
 *
 * \details This module gives an alternative support for DbC in C++.
 *
 * When compared with <a href="https://en.wikipedia.org/wiki/Assert.h">`assert.h`</a> this module offers the following functionalities:
 *   - separates different assertion types (preconditions, postconditions, invariants, and others);
 *   - augments assert with error message strings;
 *   - contains a disciplined exception mechanism (@ref DbC-DEM);
 *   - implements two error handling policies (through the definition of a macro -- EXIT_POLICY/EXCEPTION_POLICY --
 *     as a compiler option):
 *      -# <tt>EXIT_POLICY</tt> (default): describes the failed assertion in `stderr` (with the identification
 *         and the precise location of the assertion), generates a segmentation fault
 *         (enabling a stack trace within a debugger like `gdb`), and exits program execution;
 *      -# <tt>EXCEPTION_POLICY</tt>: throws a <code>DbC_Error*</code> exception with the description of the failed assertion.
 *
 * Compared to recent <a href="https://cppreference.com/cpp/26">C++26</a> contracts standard:
 *   - in EXCEPTION_POLICY mode, a contract failure always throws an exception;
 *   - augments contracts with error message strings;
 *   - contains a disciplined exception mechanism (@ref DbC-DEM);
 *   - applies also to virtual functions;
 *   - however, unlike this module, in C++26 preconditions and postconditions are part of the function prototype (as they should).
 *
 * Debug settings:
 * - As happens with `assert.h`, this module accepts <b>`NDEBUG`</b> macro definition to disable all
 * assertion run-time verification.
 * - Also, each assertion type verification can be disabled with macros: <b>`NDEBUG_CHECKS`</b>,
 *   <b>`NDEBUG_PRECONDITIONS`</b>, <b>`NDEBUG_POSTCONDITIONS`</b>, and <b>`NDEBUG_INVARIANTS`</b>.
 * - A special (high priority) macro named <b>`DEBUG_ONLY_PRECONDITIONS`</b> ensures that only precondition
 *   debugging remains active (regardless of other debug definitions).
 *  
 * \author Miguel Oliveira e Silva
 * \date 2018, 2026
 * \version 1.1
 *  @{ 
 **/

/*!
 * \file
 * \brief Design-by-Contract module.
 */

#ifndef DBC_H
#define DBC_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hdp.h"
#include "utils.h"

/**
 *  \hideinitializer
 *  \brief Integer value for a precondition error code (ensured not to be an <a href="https://man7.org/linux/man-pages/man3/errno.3.html">errno value</a>).
 */
#define PRECONDITION_ERROR   0x1000000

/**
 *  \hideinitializer
 *  \brief Integer value for a postcondition error code (ensured not to be an <a href="https://man7.org/linux/man-pages/man3/errno.3.html">errno value</a>).
 */
#define POSTCONDITION_ERROR  0x2000000

/**
 *  \hideinitializer
 *  \brief Integer value for an invariant error code (ensured not to be an <a href="https://man7.org/linux/man-pages/man3/errno.3.html">errno value</a>).
 */

#define INVARIANT_ERROR      0x3000000
/**
 *  \hideinitializer
 *  \brief Integer value for a check error code (ensured not to be an <a href="https://man7.org/linux/man-pages/man3/errno.3.html">errno value</a>).
 */
#define CHECK_ERROR          0x4000000

#define MAX_DBC_ERROR_MESSAGE 255

/**
 *  \hideinitializer
 *  \brief DbC exceptions throw a pointer to an instance of this structure.
 */
typedef struct {
   //! contract error code
   int err;
   //! message describing the error
   char msg[MAX_DBC_ERROR_MESSAGE+1];
} DbC_Error;

#ifdef NDEBUG
#define NDEBUG_CHECKS
#define NDEBUG_PRECONDITIONS
#define NDEBUG_POSTCONDITIONS
#define NDEBUG_INVARIANTS
#endif

#ifdef DEBUG_ONLY_PRECONDITIONS
#ifdef NDEBUG_PRECONDITIONS
#undef NDEBUG_PRECONDITIONS
#endif
#ifndef NDEBUG_CHECKS
#define NDEBUG_CHECKS
#endif
#ifndef NDEBUG_POSTCONDITIONS
#define NDEBUG_POSTCONDITIONS
#endif
#ifndef NDEBUG_INVARIANTS
#define NDEBUG_INVARIANTS
#endif
#endif

// check:
#ifdef NDEBUG_CHECKS
#define check(condition, message)
#else
#if defined __cplusplus && defined EXCEPTION_POLICY
#define check(condition, message) \
   ({ \
      if (!(condition)) { \
         DbC_Error *e = (DbC_Error*)Nu(malloc(sizeof(DbC_Error))); \
         e->err = CHECK_ERROR; \
         strcpy(e->msg, concat_12str((char*)"Assertion fail", message[0] ? (char*)": " : (char*)"", message, (char*)", assertion: \"", #condition, (char*)"\", function: \"", __func__, (char*)"\":", int2str(__LINE__), (char*)", file: \"", __FILE__, (char*)"\"")); \
         throw e; \
      } \
   })
#else // EXIT_POLICY (default)
/**
 *  \hideinitializer
 *  \brief Checks the verification of an general algorithm assertion.
 *
 *  \details This assertion verification can be disabled at compile time by defining the macro <b>`NDEBUG_CHECKS`</b>.
 *
 *  \param [in] condition [<code>int</code>] expression to assert its truthness
 *  \param [in] message [<code>char*</code>] text to be presented with error information when the assertion fails
 */
#define check(condition, message) \
   if (!(condition)) \
      do { \
         fprintf (stderr, "Assertion fail%s%s, assertion: \"%s\", function: \"%s\":%d, file: \"%s\"\n", \
                  message[0] ? ": " : "", message, #condition, __func__, __LINE__ , __FILE__); \
         *((int*)0) = 0; \
         abort (); \
      } while (0)
#endif
#endif


// precondition:
#ifdef NDEBUG_PRECONDITIONS
#define require(condition, message)
#else
#if defined __cplusplus && defined EXCEPTION_POLICY
#define require(condition, message) \
   ({ \
      if (!(condition)) { \
         DbC_Error *e = (DbC_Error*)Nu(malloc(sizeof(DbC_Error))); \
         e->err = PRECONDITION_ERROR; \
         strcpy(e->msg, concat_12str((char*)"Precondition fail", message[0] ? (char*)": " : (char*)"", message, (char*)", assertion: \"", #condition, (char*)"\", function: \"", __func__, (char*)"\":", int2str(__LINE__), (char*)", file: \"", __FILE__, (char*)"\"")); \
         throw e; \
      } \
   })
#else // EXIT_POLICY (default)
/**
 *  \hideinitializer
 *  \brief Checks the verification of a precondition.
 *
 *  \details This assertion verification can be disabled at compile time by defining the macro <b>`NDEBUG_PRECONDITIONS`</b>.
 *
 *  \param [in] condition [<code>int</code>] expression to assert its truthness
 *  \param [in] message [<code>char*</code>] text to be presented with error information when the assertion fails
 */
#define require(condition, message) \
   if (!(condition)) \
      do { \
         fprintf (stderr, "Precondition fail%s%s, assertion: \"%s\", function: \"%s\":%d, file: \"%s\"\n", \
                  message[0] ? ": " : "", message, #condition, __func__, __LINE__ , __FILE__); \
         *((int*)0) = 0; \
         abort (); \
      } while (0)
#endif
#endif


// postcondition:
#ifdef NDEBUG_POSTCONDITIONS
#define ensure(condition, message)
#else
#if defined __cplusplus && defined EXCEPTION_POLICY
#define ensure(condition, message) \
   ({ \
      if (!(condition)) { \
         DbC_Error *e = (DbC_Error*)Nu(malloc(sizeof(DbC_Error))); \
         e->err = POSTCONDITION_ERROR; \
         strcpy(e->msg, concat_12str((char*)"Postcondition fail", message[0] ? (char*)": " : (char*)"", message, (char*)", assertion: \"", #condition, (char*)"\", function: \"", __func__, (char*)"\":", int2str(__LINE__), (char*)", file: \"", __FILE__, (char*)"\"")); \
         throw e; \
      } \
   })
#else // EXIT_POLICY (default)
/**
 *  \hideinitializer
 *  \brief Checks the verification of a postcondition.
 *
 *  \details This assertion verification can be disabled at compile time by defining the macro <b>`NDEBUG_POSTCONDITIONS`</b>.
 *
 *  \param [in] condition [<code>int</code>] expression to assert its truthness
 *  \param [in] message [<code>char*</code>] text to be presented with error information when the assertion fails
 */
#define ensure(condition, message) \
   if (!(condition)) \
      do { \
         fprintf (stderr, "Postcondition fail%s%s, assertion: \"%s\", function: \"%s\":%d, file: \"%s\"\n", \
                  message[0] ? ": " : "", message, #condition, __func__, __LINE__ , __FILE__); \
         *((int*)0) = 0; \
         abort (); \
      } while (0)
#endif
#endif

//
// invariant:
#ifdef NDEBUG_INVARIANTS
#define invariant(condition, message)
#else
#if defined __cplusplus && defined EXCEPTION_POLICY
#define invariant(condition, message) \
   ({ \
      if (!(condition)) { \
         DbC_Error *e = (DbC_Error*)Nu(malloc(sizeof(DbC_Error))); \
         e->err = INVARIANT_ERROR; \
         strcpy(e->msg, concat_12str((char*)"Invariant fail", message[0] ? (char*)": " : (char*)"", message, (char*)", assertion: \"", #condition, (char*)"\", function: \"", __func__, (char*)"\":", int2str(__LINE__), (char*)", file: \"", __FILE__, (char*)"\"")); \
         throw e; \
      } \
   })
#else // EXIT_POLICY (default)
/**
 *  \hideinitializer
 *  \brief Checks the verification of an invariant.
 *
 *  \details This assertion verification can be disabled at compile time by defining the macro <b>`NDEBUG_INVARIANTS`</b>.
 *
 *  \param [in] condition [<code>int</code>] expression to assert its truthness
 *  \param [in] message [<code>char*</code>] text to be presented with error information when the assertion fails
 */
#define invariant(condition, message) \
   if (!(condition)) \
      do { \
         fprintf (stderr, "Invariant fail%s%s, assertion: \"%s\", function: \"%s\":%d, file: \"%s\"\n", \
                  message[0] ? ": " : "", message, #condition, __func__, __LINE__ , __FILE__); \
         *((int*)0) = 0; \
         abort (); \
      } while (0)
#endif
#endif

/**
 *  \hideinitializer
 *  \brief  checks if it is a DbC error code
 *
 *  \param [in] e [<code>int</code>] integer error value
 *
 *  \return true if value is a DbC error
 */
#define IS_DbC_ERROR(e) ((e) >= PRECONDITION_ERROR && (e) <= CHECK_ERROR)

/**
 *  \hideinitializer
 *  \brief  Converts DbC error code to a string
 *
 *  \param [in] e [<code>int</code>] integer error value
 *
 *  \return the result string
 */
#define DbC_ERROR_2_STR(e) \
   ({ \
      char*res = (char*)""; \
      switch(e) { \
         case PRECONDITION_ERROR: \
            res = (char*)"PRECONDITION_ERROR"; \
            break; \
         case POSTCONDITION_ERROR: \
            res = (char*)"POSTCONDITION_ERROR"; \
            break; \
         case INVARIANT_ERROR: \
            res = (char*)"INVARIANT_ERROR"; \
            break; \
         case CHECK_ERROR: \
            res = (char*)"CHECK_ERROR"; \
            break; \
      } \
      res; \
   })

#endif

/**
 * \defgroup DbC-DEM 
 *
 * \brief The following macros are an approximation to implement a <a href="https://se.inf.ethz.ch/~meyer/publications/methodology/exceptions.pdf">Disciplined Exception Mechanism</a>
 * using only the language preprocessor.
 *
 * \details
 *
 * Unlike standard try/catch error handling, a Disciplined Exception Mechanism (DbC-DEP) adopts a simpler approach.
 * Under Design by Contract (DbC) principles, a function or method must either succeed by fully meeting its contract
 * or fail completely—no other outcome is acceptable. Therefore, a function only returns if it succeeds. If it fails,
 * it throws an exception. Recovery is only permitted if the function can successfully fulfill its contract on a new
 * attempt, whether by employing a different algorithm or through another suitable method.
 *
 * This perspective simplifies tremendously error handling solving two very serious problems with common try-catch exception mechanisms:
 * - First, there is the possibility of ignoring an error, either by simply omitting the defensive error-handling
 *   code or by writing it in a way that ignores the failure (such as catching an exception and doing nothing with it).
 * - Second, relying on exception types to differentiate errors overlooks how quickly the meaning of an exception type fades within
 *   the function call stack, given that it is typically only meaningful to the direct client.
 * (For a deeper analysis of these issues using Java as an example, see section 4 of
 * <a href="https://doi.org/10.4230/OASIcs.SLATE.2014.111">Contract-java: Design by contract in Java with safe error handling</a>).
 *
 * However, in the DbC-DEP a failed function causes the failure of the client function, and so on, until, if required, a rescue
 * is attempted.
 * A rescue never compromises the function/module contract, as it allows only a retry to fulfill the contract (probably by
 * using a different approach, or in a function which prescribes a weaker contract for an alternative acceptable behavior).
 *
 * Example:
 *
 * \code{.cpp}
 * #include <dbc.h>
 * ...
 * void redundant_function_with_two_alternative_implementations(...)
 * {
 *    require (..., "..."); // precondition
 *
 *    int algorithm = 1;
 *    rescue_retry;
 *    switch(algorithm)
 *    {
 *       case 1:
 *          ...
 *          break;
 *       case 2:
 *          ...
 *          break;
 *    }
 *
 *    ensure (..., "..."); // postcondition
 *
 *    rescue_begin
 *       algorithm++;
 *       if (algorithm <= 2)
 *          retry
 *    rescue_end
 * }
 * \endcode
 *
 * Since exceptions are necessary here, these macros are only applicable in C++ (with <b>`EXCEPTION_POLICY`</b> macro defined),
 * not in C (for a C approach see <a href="https://sweet.ua.pt/mos/c-dbc">c-dbc library</a>).
 *
 * By default, rescue clause only catches DbC errors (<code>DbC_Error*</code>). This behavior can be modified to catch all
 * types of exceptions be defining the compiling macro <b>`CATCH_ALL`</b>.
 *
 *  @{ 
 */

//#define CATCH_DBC
//#define CATCH_ALL

#if defined __cplusplus && defined EXCEPTION_POLICY
#define rescue_retry \
   __body_start_label__: \
   try {

#ifdef CATCH_ALL
#define rescue_begin \
   } \
   catch(...) {
#else
#define rescue_begin \
   } \
   catch(DbC_Error* e) {
#endif

#define rescue_end \
      throw; \
   }

#define retry \
   goto __body_start_label__;
#else
//#warning "Only avaliable in C++ with EXCEPTION_POLICY"
/**
 *  \hideinitializer
 *  \brief  To place at the beginning of the code to be retried.
 */
#define rescue_retry \
   _Pragma("GCC warning \"Only avaliable in C++ with EXCEPTION_POLICY\"")

/**
 *  \hideinitializer
 *  \brief  To place at the beginning of the rescue code.
 */
#define rescue_begin \
   _Pragma("GCC warning \"Only avaliable in C++ with EXCEPTION_POLICY\"")

/**
 *  \hideinitializer
 *  \brief  To place at the end of the rescue code.
 */
#define rescue_end

/**
 *  \hideinitializer
 *  \brief  Jump to the beginning of the code to be retried (must be inside the rescue code!).
 */
#define retry \
   _Pragma("GCC warning \"Only avaliable in C++ with EXCEPTION_POLICY\"")
#endif

/* ************************************************** */
/**
 * @} close group DbC-DEM
 **/
/* ************************************************** */

/* ************************************************** */
/**
 * @} close group dbc
 **/
/* ************************************************** */

