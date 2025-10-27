//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// JMR, 2021
//

#ifndef _PERSON_
#define _PERSON_

#include "Date.h"

// The Person struct.
// ATTENTION: It is not usually defined in the .h file.
// Since it is defined here, the clients have direct access
// to the struct fields.
// And no getter/setter functions have to be defined.
// BUT, if this internal representation is changed,
// the clients code will have to be changed too.
typedef struct {
  int id;
  Date birthDate;  // this is the actual struct, not a pointer!
  char *firstName;
  char *lastName;
} Person;

Person *PersonCreate(const char *fname, const char *lname, int yy, int mm,
                     int dd);

void PersonDestroy(Person **pd);

void PersonPrintf(Person *p, const char *suffix);

int PersonCompareByBirth(const Person *p1, const Person *p2);

int PersonCompareByLastFirstName(const Person *p1, const Person *p2);

#endif  // _PERSON_
