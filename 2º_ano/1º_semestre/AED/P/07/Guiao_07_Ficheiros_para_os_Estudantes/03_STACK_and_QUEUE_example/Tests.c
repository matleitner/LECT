#include "Person.h"
#include "Date.h" 
#include "PointersStack.h"
#include "PointersQueue.h"



int main(void){
	Stack* s = StackCreate(2);
	Queue* q = QueueCreate(20);
	Person* martim = PersonCreate("Martim", "Leitner", 2006, 10, 3);
	Person* p1 = PersonCreate("Joaquim", "Ambrosio", 202, 1, 1);
	StackPush(s, p1);
	StackPush(s, martim);
	while(!StackIsEmpty(s)){
		PersonPrintf(StackPop(s), "Ajuda");
	}
	
	StackDestroy(&s);
	QueueDestroy(&q);
	PersonDestroy(&martim);
	PersonDestroy(&p1);

	return 0;

}
