#include <stdio.h>
#include <stdlib.h>
#include "calculadoraBombardeo.h"
#include "impresionNormalizado.h"

/* Entrada: Recibe el nombre del archivo a buscar y el largo de impacto(largo arreglo)
Salida: N/A
Descripcion: Lee el archivo y llama a las funciones necesarias para calcular la energia de todas las celdas y la maxima 
 posteriormente normaliza el arreglo y lo imprime */
void leerArchivo(const char *nombreArchivo, int N) {
    FILE *archivo = fopen(nombreArchivo, "r");
    
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }
    

    int numLineas;
    fscanf(archivo, "%d", &numLineas); // Lee la primera línea con el número de líneas
    
    //Crear arreglo de largo N
    double* arregloEnergiaParticulas = CrearArregloEnergiaParticulas(N);
    int posicionEnergiaMaximaActual = 0;
    
    // Lee el archivo línea por línea y ejecuta los calculos
    for (int i = 0; i < numLineas; i++) {
        int posicion, energia;
        fscanf(archivo, "%d %d", &posicion, &energia);
        
        sumarEnergiaParticulas(arregloEnergiaParticulas, N, posicion, energia, &posicionEnergiaMaximaActual);
    }
    
    fclose(archivo);
    printf("Energia Maxima %f \n", arregloEnergiaParticulas[posicionEnergiaMaximaActual]);
    imprimirNormalizado(arregloEnergiaParticulas,posicionEnergiaMaximaActual, N);

    //Libera el arreglo de la memoria
    free(arregloEnergiaParticulas);
}

int main(){
    leerArchivo("test1_35.txt", 35);
    return 0;
}