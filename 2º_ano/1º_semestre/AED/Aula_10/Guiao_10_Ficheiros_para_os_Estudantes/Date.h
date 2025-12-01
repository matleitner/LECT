//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// JMR, 2021
//

#ifndef _DATE_
#define _DATE_

#include <inttypes.h>

// The _date struct.
// ATTENTION: It is not usually defined in the .h file.
// Since it is defined here, the clients have direct access
// to the struct fields.
// And no getter/setter functions have to be defined.
// BUT, if this internal representation is changed,
// the clients code will have to be changed too.
struct _date {
  uint16_t year;
  uint8_t month;
  uint8_t day;
};

// The Date type. (To be used in clients.)
typedef struct _date Date;

// Constants
extern const Date DateMIN;
extern const Date DateMAX;

// Macros to select date format
#define YMD 0
#define DMY 1
#define MDY 2

Date* DateCreate(int yy, int mm, int dd);

void DateDestroy(Date** pd);

int DateIsValid(int yy, int mm, int dd);

int DateDaysInMonth(int yy, int mm);

int DateIsLeapYear(int yy);

char* DateFormat(const Date* d, int FMT);

int DateParse(Date* d, const char* str, int FMT);

int DateCompare(const Date* a, const Date* b);

void DateIncr(Date* d);

void DateDecr(Date* d);

#endif  // _DATE_
