#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int num_celdas = 0;
    char *archivo_entrada = NULL;
    char *archivo_salida = NULL;
    int mostrar_celdas = 0;

    int opt;
    while ((opt = getopt(argc, argv, "N:i:o:D")) != -1) {
        switch (opt) {
            case 'N':
                num_celdas = atoi(optarg);
                break;
            case 'i':
                archivo_entrada = optarg;
                break;
            case 'o':
                archivo_salida = optarg;
                break;
            case 'D':
                mostrar_celdas = 1;
                break;
            default:
                fprintf(stderr, "Uso: %s -N num_celdas -i archivo_entrada -o archivo_salida -D\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // Verificar que los argumentos requeridos se proporcionaron
    if (num_celdas == 0 || archivo_entrada == NULL || archivo_salida == NULL) {
        fprintf(stderr, "Faltan argumentos requeridos.\n");
        fprintf(stderr, "Uso: %s -N num_celdas -i archivo_entrada -o archivo_salida -D\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Procesar los argumentos y realizar la lógica del programa aquí

    printf("Número de celdas: %d\n", num_celdas);
    printf("Archivo de entrada: %s\n", archivo_entrada);
    printf("Archivo de salida: %s\n", archivo_salida);

    if (mostrar_celdas) {
        printf("Mostrar celdas de material\n");
    }

    // Resto del programa...

    return 0;
}