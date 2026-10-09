/**
 * \defgroup DbC DbC 
 * \ingroup C-Cpp-library
 * \brief Design-by-Contract module for C/C++.
 *
 * \details This module gives a better support for DbC in C++.
 *
 * When compared with `assert.h` this module offers the following functionalities:
 *   - separates different assertion types (preconditions, postconditions, invariants, and others);
 *   - augments assert with error message strings;
 *   - implements two error handling policies (through the definition of a macro -- EXIT_POLICY/EXCEPTION_POLICY --
 *     as a compiler option):
 *      -# <tt>EXIT_POLICY</tt> (default): describes the failed assertion in `stderr` (with the identification
 *         and the precise location of the assertion), generates a segmentation fault
 *         (enabling a stack trace within a debugger like `gdb`), and exits program execution;
 *      -# <tt>EXCEPTION_POLICY</tt>: throws a `char*` exception with the description of the failed assertion.
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
 * \version 1.0
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
   if (!(condition)) \
      throw (char*)Nu(strdup(concat_12str((char*)"Assertion fail", message[0] ? (char*)": " : (char*)"", message, (char*)", assertion: \"", #condition, (char*)"\", function: \"", __FUNCTION__, (char*)"\":", int2str(__LINE__), (char*)", file: \"", __FILE__, (char*)"\"\n")))
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
                  message[0] ? ": " : "", message, #condition, __FUNCTION__, __LINE__ , __FILE__); \
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
   if (!(condition)) \
      throw (char*)Nu(strdup(concat_12str((char*)"Precondition fail", message[0] ? (char*)": " : (char*)"", message, (char*)", assertion: \"", #condition, (char*)"\", function: \"", __FUNCTION__, (char*)"\":", int2str(__LINE__), (char*)", file: \"", __FILE__, (char*)"\"\n")))
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
                  message[0] ? ": " : "", message, #condition, __FUNCTION__, __LINE__ , __FILE__); \
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
   if (!(condition)) \
      throw (char*)Nu(strdup(concat_12str((char*)"Postcondition fail", message[0] ? (char*)": " : (char*)"", message, (char*)", assertion: \"", #condition, (char*)"\", function: \"", __FUNCTION__, (char*)"\":", int2str(__LINE__), (char*)", file: \"", __FILE__, (char*)"\"\n")))
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
                  message[0] ? ": " : "", message, #condition, __FUNCTION__, __LINE__ , __FILE__); \
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
   if (!(condition)) \
      throw (char*)Nu(strdup(concat_12str((char*)"Invariant fail", message[0] ? (char*)": " : (char*)"", message, (char*)", assertion: \"", #condition, (char*)"\", function: \"", __FUNCTION__, (char*)"\":", int2str(__LINE__), (char*)", file: \"", __FILE__, (char*)"\"\n")))
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
                  message[0] ? ": " : "", message, #condition, __FUNCTION__, __LINE__ , __FILE__); \
         *((int*)0) = 0; \
         abort (); \
      } while (0)
#endif
#endif

#endif

/* ************************************************** */
/**
 * @} close group DbC
 **/
/* ************************************************** */

