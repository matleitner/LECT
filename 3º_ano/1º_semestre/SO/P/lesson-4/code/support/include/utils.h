/**
 * \defgroup utils utils 
 * \ingroup C-Cpp-library
 * \brief Useful macros.
 * \author Miguel Oliveira e Silva
 * \date 2017, 2026
 * \version 1.0
 *  @{ 
 **/

/*!
 * \file
 *
 * \brief Useful common functions and macros.
 **/

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "dbc.h"
#include "hdp.h"

/** @name String concatenation in stack memory (useful to compose contract error messages)
 *  @anchor concat @{
 */
/**
 *  \hideinitializer
 *  \brief Concatenates two strings in the stack memory (thus it cannot be implemented in a function).
 *
 *  \details A `NULL` reference is treated as an empty string.
 *
 *  \param [in] str1 [<code>char*</code>] string 1
 *  \param [in] str2 [<code>char*</code>] string 2
 *
 *  \return the concatenated string
 */
#define concat_2str(str1,str2) \
        ({ \
           char* s1 = (str1) == NULL ? (char*)"" : (char*)(str1); \
           char* s2 = (str2) == NULL ? (char*)"" : (char*)(str2); \
           char* __res__ = (char*)alloca(strlen(s1)+strlen(s2)+1); \
           strcpy(__res__, s1); \
           strcat(__res__, s2); \
           __res__; \
        })

/**
 *  \hideinitializer
 *  \brief Concatenates three strings in the stack memory (thus it cannot be implemented in a function).
 *
 *  \details A `NULL` reference is treated as an empty string.
 *
 *  \param [in] str1 [<code>char*</code>] string 1
 *  \param [in] str2 [<code>char*</code>] string 2
 *  \param [in] str3 [<code>char*</code>] string 3
 *
 *  \return the concatenated string
 */
#define concat_3str(str1,str2,str3) \
        ({ \
           char* s1 = (str1) == NULL ? (char*)"" : (char*)(str1); \
           char* s2 = (str2) == NULL ? (char*)"" : (char*)(str2); \
           char* s3 = (str3) == NULL ? (char*)"" : (char*)(str3); \
           char* __res__ = (char*)alloca(strlen(s1)+strlen(s2)+strlen(s3)+1); \
           strcpy(__res__, s1); \
           strcat(__res__, s2); \
           strcat(__res__, s3); \
           __res__; \
        })

/**
 *  \hideinitializer
 *  \brief Concatenates four strings in the stack memory (thus it cannot be implemented in a function).
 *
 *  \details A `NULL` reference is treated as an empty string.
 *
 *  \param [in] str1 [<code>char*</code>] string 1
 *  \param [in] str2 [<code>char*</code>] string 2
 *  \param [in] str3 [<code>char*</code>] string 3
 *  \param [in] str4 [<code>char*</code>] string 4
 *
 *  \return the concatenated string
 */
#define concat_4str(str1,str2,str3,str4) \
        ({ \
           char* s1 = (str1) == NULL ? (char*)"" : (char*)(str1); \
           char* s2 = (str2) == NULL ? (char*)"" : (char*)(str2); \
           char* s3 = (str3) == NULL ? (char*)"" : (char*)(str3); \
           char* s4 = (str4) == NULL ? (char*)"" : (char*)(str4); \
           char* __res__ = (char*)alloca(strlen(s1)+strlen(s2)+strlen(s3)+strlen(s4)+1); \
           strcpy(__res__, s1); \
           strcat(__res__, s2); \
           strcat(__res__, s3); \
           strcat(__res__, s4); \
           __res__; \
        })

/**
 *  \hideinitializer
 *  \brief Concatenates five strings in the stack memory (thus it cannot be implemented in a function).
 *
 *  \details A `NULL` reference is treated as an empty string.
 *
 *  \param [in] str1 [<code>char*</code>] string 1
 *  \param [in] str2 [<code>char*</code>] string 2
 *  \param [in] str3 [<code>char*</code>] string 3
 *  \param [in] str4 [<code>char*</code>] string 4
 *  \param [in] str5 [<code>char*</code>] string 5
 *
 *  \return the concatenated string
 */
#define concat_5str(str1,str2,str3,str4,str5) \
        ({ \
           char* s1 = (str1) == NULL ? (char*)"" : (char*)(str1); \
           char* s2 = (str2) == NULL ? (char*)"" : (char*)(str2); \
           char* s3 = (str3) == NULL ? (char*)"" : (char*)(str3); \
           char* s4 = (str4) == NULL ? (char*)"" : (char*)(str4); \
           char* s5 = (str5) == NULL ? (char*)"" : (char*)(str5); \
           char* __res__ = (char*)alloca(strlen(s1)+strlen(s2)+strlen(s3)+strlen(s4)+strlen(s5)+1); \
           strcpy(__res__, s1); \
           strcat(__res__, s2); \
           strcat(__res__, s3); \
           strcat(__res__, s4); \
           strcat(__res__, s5); \
           __res__; \
        })

/**
 *  \hideinitializer
 *  \brief Concatenates six strings in the stack memory (thus it cannot be implemented in a function).
 *
 *  \details A `NULL` reference is treated as an empty string.
 *
 *  \param [in] str1 [<code>char*</code>] string 1
 *  \param [in] str2 [<code>char*</code>] string 2
 *  \param [in] str3 [<code>char*</code>] string 3
 *  \param [in] str4 [<code>char*</code>] string 4
 *  \param [in] str5 [<code>char*</code>] string 5
 *  \param [in] str6 [<code>char*</code>] string 6
 *
 *  \return the concatenated string
 */
#define concat_6str(str1,str2,str3,str4,str5,str6) \
        ({ \
           char* s1 = (str1) == NULL ? (char*)"" : (char*)(str1); \
           char* s2 = (str2) == NULL ? (char*)"" : (char*)(str2); \
           char* s3 = (str3) == NULL ? (char*)"" : (char*)(str3); \
           char* s4 = (str4) == NULL ? (char*)"" : (char*)(str4); \
           char* s5 = (str5) == NULL ? (char*)"" : (char*)(str5); \
           char* s6 = (str6) == NULL ? (char*)"" : (char*)(str6); \
           char* __res__ = (char*)alloca(strlen(s1)+strlen(s2)+strlen(s3)+strlen(s4)+strlen(s5)+strlen(s6)+1); \
           strcpy(__res__, s1); \
           strcat(__res__, s2); \
           strcat(__res__, s3); \
           strcat(__res__, s4); \
           strcat(__res__, s5); \
           strcat(__res__, s6); \
           __res__; \
        })

/**
 *  \hideinitializer
 *  \brief Concatenates seven strings in the stack memory (thus it cannot be implemented in a function).
 *
 *  \details A `NULL` reference is treated as an empty string.
 *
 *  \param [in] str1 [<code>char*</code>] string 1
 *  \param [in] str2 [<code>char*</code>] string 2
 *  \param [in] str3 [<code>char*</code>] string 3
 *  \param [in] str4 [<code>char*</code>] string 4
 *  \param [in] str5 [<code>char*</code>] string 5
 *  \param [in] str6 [<code>char*</code>] string 6
 *  \param [in] str7 [<code>char*</code>] string 7
 *
 *  \return the concatenated string
 */
#define concat_7str(str1,str2,str3,str4,str5,str6,str7) \
        ({ \
           char* s1 = (str1) == NULL ? (char*)"" : (char*)(str1); \
           char* s2 = (str2) == NULL ? (char*)"" : (char*)(str2); \
           char* s3 = (str3) == NULL ? (char*)"" : (char*)(str3); \
           char* s4 = (str4) == NULL ? (char*)"" : (char*)(str4); \
           char* s5 = (str5) == NULL ? (char*)"" : (char*)(str5); \
           char* s6 = (str6) == NULL ? (char*)"" : (char*)(str6); \
           char* s7 = (str7) == NULL ? (char*)"" : (char*)(str7); \
           char* __res__ = (char*)alloca(strlen(s1)+strlen(s2)+strlen(s3)+strlen(s4)+strlen(s5)+strlen(s6)+strlen(s7)+1); \
           strcpy(__res__, s1); \
           strcat(__res__, s2); \
           strcat(__res__, s3); \
           strcat(__res__, s4); \
           strcat(__res__, s5); \
           strcat(__res__, s6); \
           strcat(__res__, s7); \
           __res__; \
        })

/**
 *  \hideinitializer
 *  \brief Concatenates twelve strings in the stack memory (thus it cannot be implemented in a function).
 *
 *  \details A `NULL` reference is treated as an empty string.
 *
 *  \param [in] str1 [<code>char*</code>] string 1
 *  \param [in] str2 [<code>char*</code>] string 2
 *  \param [in] str3 [<code>char*</code>] string 3
 *  \param [in] str4 [<code>char*</code>] string 4
 *  \param [in] str5 [<code>char*</code>] string 5
 *  \param [in] str6 [<code>char*</code>] string 6
 *  \param [in] str7 [<code>char*</code>] string 7
 *  \param [in] str8 [<code>char*</code>] string 8
 *  \param [in] str9 [<code>char*</code>] string 9
 *  \param [in] str10 [<code>char*</code>] string 10
 *  \param [in] str11 [<code>char*</code>] string 11
 *  \param [in] str12 [<code>char*</code>] string 12
 *
 *  \return the concatenated string
 */
#define concat_12str(str1,str2,str3,str4,str5,str6,str7,str8,str9,str10,str11,str12) \
        ({ \
           char* s1 = (str1) == NULL ? (char*)"" : (char*)(str1); \
           char* s2 = (str2) == NULL ? (char*)"" : (char*)(str2); \
           char* s3 = (str3) == NULL ? (char*)"" : (char*)(str3); \
           char* s4 = (str4) == NULL ? (char*)"" : (char*)(str4); \
           char* s5 = (str5) == NULL ? (char*)"" : (char*)(str5); \
           char* s6 = (str6) == NULL ? (char*)"" : (char*)(str6); \
           char* s7 = (str7) == NULL ? (char*)"" : (char*)(str7); \
           char* s8 = (str8) == NULL ? (char*)"" : (char*)(str8); \
           char* s9 = (str9) == NULL ? (char*)"" : (char*)(str9); \
           char* s10 = (str10) == NULL ? (char*)"" : (char*)(str10); \
           char* s11 = (str11) == NULL ? (char*)"" : (char*)(str11); \
           char* s12 = (str12) == NULL ? (char*)"" : (char*)(str12); \
           char* __res__ = (char*)alloca(strlen(s1)+strlen(s2)+strlen(s3)+strlen(s4)+strlen(s5)+strlen(s6)+strlen(s7)+strlen(s8)+strlen(s9)+strlen(s10)+strlen(s11)+strlen(s12)+1); \
           strcpy(__res__, s1); \
           strcat(__res__, s2); \
           strcat(__res__, s3); \
           strcat(__res__, s4); \
           strcat(__res__, s5); \
           strcat(__res__, s6); \
           strcat(__res__, s7); \
           strcat(__res__, s8); \
           strcat(__res__, s9); \
           strcat(__res__, s10); \
           strcat(__res__, s11); \
           strcat(__res__, s12); \
           __res__; \
        })
/** @} */

/**
 *  \hideinitializer
 *  \brief Number of digits of an integer number (ignores signal!).
 *
 *  \param [in] num [<code>int</code>] integer number
 *
 *  \return the number of digits
 */
#define numDigits(num) \
        ({ \
           int res = 1; \
           int n = abs(num)/10; \
           while(n != 0) \
           { \
              res++; \
              n /= 10; \
           } \
           res; \
        })

/**
 *  \hideinitializer
 *  \brief Converts an `int` value to a stack allocated string (signal is considered).
 *
 *  \param [in] num [<code>int</code>] integer number
 *
 *  \return the converted string
 */
#define int2str(num) \
        ({ \
           char* __res__ = (char*)alloca(numDigits((int)num)+((int)num < 0 ? 1 : 0)+1); \
           sprintf(__res__, "%d", (int)num); \
           __res__; \
        })

/**
 *  \hideinitializer
 *  \brief Converts an `int` value to a stack allocated string (signal is considered).
 *
 *  \details If necessary, fills the result string with left zeros.
 *
 *  \param [in] num [<code>int</code>] integer number
 *  \param [in] len [<code>int</code>] minimum length of result string
 *  
 *  <DL><DT><B>Precondition:</B></DT>
 *     <DD><code>len > 0</code></DD>
 *  </DL>
 *
 *  \return the converted string
 */
#define int2nstr(num, len) \
        ({ \
           require (len > 0, concat_3str("invalid length value (", int2str(len), ")")); \
           int d = numDigits((int)num)+((int)num < 0 ? 1 : 0); \
           if (len > d) \
              d = len; \
           char* __res__ = (char*)alloca(d+1); \
           sprintf(__res__, "%0*d", d, (int)num); \
           __res__; \
        })

/**
 *  \hideinitializer
 *  \brief Converts an `long` value to a stack allocated string (signal is considered).
 *
 *  \param [in] num [<code>long</code>] integer number
 *
 *  \return the converted string
 */
#define long2str(num) \
        ({ \
           char* __res__ = (char*)alloca(numDigits((long)num)+((long)num < 0 ? 1 : 0)+1); \
           sprintf(__res__, "%ld", (long)num); \
           __res__; \
        })

/**
 *  \hideinitializer
 *  \brief Converts an `long` value to a stack allocated string (signal is considered).
 *
 *  \details If necessary, fills the result string with left zeros.
 *
 *  \param [in] num [<code>long</code>] integer number
 *  \param [in] len [<code>int</code>] minimum length of result string
 *  
 *  <DL><DT><B>Precondition:</B></DT>
 *     <DD><code>len > 0</code></DD>
 *  </DL>
 *
 *  \return the converted string
 */
#define long2nstr(num, len) \
        ({ \
           require (len > 0, concat_3str("invalid length value (", int2str(len), ")")); \
           int d = numDigits((int)num)+((long)num < 0 ? 1 : 0); \
           if (len > d) \
              d = len; \
           char* __res__ = (char*)alloca(d+1); \
           sprintf(__res__, "%0*ld", d, (long)num); \
           __res__; \
        })

/**
 *  \hideinitializer
 *  \brief Converts an `int` percentage to a stack allocated string.
 *
 *  \param [in] percentage [<code>int</code>] an integer number with a percentage value
 *  
 *  <DL><DT><B>Precondition:</B></DT>
 *     <DD><code>percentage >= 0 && percentage <= 100</code></DD>
 *  </DL>
 *
 *  \return the converted string
 */
#define perc2str(percentage) \
        ({ \
           require (percentage >= 0 && percentage <= 100, concat_3str("invalid percentage value (", int2str(percentage), ")")); \
           char* __res__ = (char*)alloca(4+1); \
           sprintf(__res__, "%3d%%", (int)percentage); \
           __res__; \
        })

/**
 *  \hideinitializer
 *  \brief Generates a random boolean value.
 *
 *  \details
 *  This function generates boolean values with defined probabilities
 *  for true (`!=0`) and false (`0`) values.
 *
 *  \param [in] trueProb [<code>int</code>] probability (in interval `[0;100]`).
 *  
 *  <DL><DT><B>Precondition:</B></DT>
 *     <DD><code>trueProb >= 0 && trueProb <= 100</code></DD>
 *  </DL>
 *
 *  \return the random boolean value
 */
#define random_boolean(trueProb) \
        ({ \
            require (trueProb >= 0 && trueProb <= 100, concat_3str("invalid percentage (", int2str(trueProb), ")")); \
            int res = (double)rand()/(double)RAND_MAX < (double)trueProb/100.0; \
            res; \
        })

/**
 *  \hideinitializer
 *  \brief Generates a random integer value within a given interval.
 *
 *  \details
 *  This function generates integer values in the interval `[min;max]`with an uniform distribution for all values.
 *
 *  \param [in] min [<code>int</code>] lower value of interval
 *  \param [in] max [<code>int</code>] higher value of interval
 *  
 *  <DL><DT><B>Precondition:</B></DT>
 *     <DD><code>max >= min</code></DD>
 *  </DL>
 *
 *  \return the random integer value
 */
#define random_int(min, max) \
        ({ \
            require (max >= min, concat_5str("invalid interval [", int2str(min), ",", int2str(max), "]")); \
            int res = min + (int)(((double)rand()/(double)RAND_MAX)*(max-min)+0.5); \
            res; \
        })

/**
 *  \hideinitializer
 *  \brief Clears the terminal.
 *
 *  \details
 *  This function clears the terminal.
 */
#define clear_console() \
   ({ \
      printf("\u001B[2J"); \
      fflush(stdout); \
   })

/**
 *  \hideinitializer
 *  \brief Moves the cursor to a position in terminal.
 *
 *  \param [in] line [<code>int</code>] position in the terminal
 *  \param [in] column [<code>int</code>] position in the terminal
 *  
 *  <DL><DT><B>Precondition:</B></DT>
 *     <DD><code>line >= 0 && column >= 0</code></DD>
 *  </DL>
 */
#define move_cursor(line,column) \
   ({ \
      require ((line) >= 0 && (column) >= 0, concat_4str("invalid cursor position, line:", int2str(line), ", column:", int2str(column))); \
      printf("\u001B[%d;%df", 1+(line), 1+(column)); \
      fflush(stdout); \
   })

/**
 *  \hideinitializer
 *  \brief Hides the terminal cursor.
 *
 *  \details
 *  This function hides the cursor in the terminal.
 */
#define hide_cursor() \
   ({ \
      printf("\e[?25l"); \
      fflush(stdout); \
   })

/**
 *  \hideinitializer
 *  \brief Shows the terminal cursor.
 *
 *  \details
 *  This function shows the cursor in the terminal.
 */
#define show_cursor() \
   ({ \
      printf("\e[?25h"); \
      fflush(stdout); \
   })

#endif

/* ************************************************** */
/**
 * @} close group utils
 **/
/* ************************************************** */

