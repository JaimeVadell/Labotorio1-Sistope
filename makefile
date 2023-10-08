FLAGS = -Wall
OUTPUT_DIR = output

main: main.c funciones.o
	gcc $(FLAGS) -o $(OUTPUT_DIR)/main main.c funciones.o -lm

funciones.o: funciones.c
	gcc -c $(FLAGS) funciones.c

clean:
	rm -f $(OUTPUT_DIR)/main *.o