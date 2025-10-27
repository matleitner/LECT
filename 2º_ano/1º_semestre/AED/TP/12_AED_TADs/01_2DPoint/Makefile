# make          - to compile all programs
# make clean    - to clean programs and object files.

CFLAGS = -Wall -Wextra -g

PROGS = testing_Point2D_XY testing_Point2D_Polar

all: $(PROGS)

testing_Point2D_XY: testing_Point2D.o Point2D_XY.o
	$(CC) -o $@ $^ -lm

testing_Point2D_Polar: testing_Point2D.o Point2D_Polar.o
	$(CC) -o $@ $^ -lm

clean:
	rm *.o
	rm $(PROGS)
