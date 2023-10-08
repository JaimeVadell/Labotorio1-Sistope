#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "funciones.h"

int main(int argc, char *argv[]) {
    int N = 0;
    char *archivo_entrada = NULL;
    char *archivo_salida = NULL;
    int mostrar_celdas = 0;

    int opt;
    while ((opt = getopt(argc, argv, "N:i:o:D")) != -1) {
        switch (opt) {
            case 'N':
                N = atoi(optarg);
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
                fprintf(stderr, "Uso: %s -N N -i archivo_entrada -o archivo_salida -D\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // Verificar que los argumentos requeridos se proporcionaron
    if (N == 0 || archivo_entrada == NULL || archivo_salida == NULL) {
        fprintf(stderr, "Faltan argumentos requeridos.\n");
        fprintf(stderr, "Uso: %s -N N -i archivo_entrada -o archivo_salida -D\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    //Leer archivo, calcular e imprimir archivo
    leerArchivo(archivo_entrada, N, mostrar_celdas, archivo_salida);

    printf("Archivo Creado Exitosamente\n");
    printf("Parámetros:\n");
    printf("Número de celdas: %d\n", N);
    printf("Archivo de entrada: %s\n", archivo_entrada);
    printf("Archivo de salida: %s\n", archivo_salida);

    if (mostrar_celdas) {
        printf("Impresion normalizada: SI\n");
    }
    else{
        printf("Impresion normalizada: NO\n");
    }

    return 0;
}