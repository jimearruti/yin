CXX = -c -g -std=c99 -pedantic-errors -Wall -Wextra -Werror

main : main.o funciones.o 
	gcc main.o funciones.o -lm -o main

main.o: main.c
	gcc $(CXX) main.c

funciones.o: funciones.c
	gcc $(CXX) funciones.c

clean: 
	rm -f *.o
