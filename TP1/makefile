exe_1: exe_1.c  exe_1.h Number.c Number.h
	gcc -Wall exe_1.c Number.c -o exe_1

exe_1_a: exe_1_a.c  exe_1.h Number.c Number.h
	gcc -Wall exe_1_a.c Number.c -o exe_1_a

exe_2: exe_2.c exe_2.h FileValue.c FileValue.h Range.c Range.h Number.c Number.h Param.c Param.h Functions.c Functions.h
	gcc -Wall  FileValue.c Number.c Range.c Param.c Functions.c exe_2.c -o exe_2 -lm



clean:
	rm -f *.o
	rm -f exe_1 exe_2 exe_3
