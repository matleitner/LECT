#include <stdio.h>


struct Point{
	int x;
	int y;
};

void ModifyPoint(struct Point *p){
	p -> x = 10;

	p -> y = p-> y+10;
}	


int main(void){


	struct Point p1 = {5,10};

	printf("Before ModifyPoint: x = %d, y = %d\n", p1.x, p1.y);
	ModifyPoint(&p1);
	printf("After ModifyPoint: x = %d, y = %d\n", p1.x, p1.y);

	return 0;
}
