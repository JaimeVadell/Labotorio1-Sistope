FLAGS = -Wall
OUTPUT_DIR = output

lab1: lab1.c funciones.o
	gcc $(FLAGS) -o $(OUTPUT_DIR)/lab1 lab1.c funciones.o -lm

funciones.o: funciones.c
	gcc -c $(FLAGS) funciones.c

clean:
	rm -f $(OUTPUT_DIR)/lab1 *.o