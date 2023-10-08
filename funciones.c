#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MIN_ENERGY 0.001

/* Entrada: Recibe el nombre del archivo a buscar y el largo de impacto(largo arreglo)
Salida: N/A
Descripcion: Lee el archivo y llama a las funciones necesarias para calcular la energia de todas las celdas y la maxima 
 posteriormente normaliza el arreglo y lo imprime */
void leerArchivo(const char *nombreArchivo, int N, int flagD, const char *nombreArchivoSalida) {
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

    // Imprimir arreglo en Orden o Normalizado
    if(!flagD){imprimirEnOrden(arregloEnergiaParticulas,posicionEnergiaMaximaActual, N, nombreArchivoSalida);}
    
    else{imprimirNormalizado(arregloEnergiaParticulas,posicionEnergiaMaximaActual, N, nombreArchivoSalida);}

    //Libera el arreglo de la memoria
    free(arregloEnergiaParticulas);
}



/*
Entrada: Arreglo de energía de las partículas, posición de la energía máxima actual, número de partículas totales,
nombre de archivo de salida
Salida: N/A
Descripcion: Imprime el gráfico de barras normalizado a partir de los argumentos de la funcion
 */
void imprimirNormalizado(double * arregloEnergiaParticulas, int posicionEnergiaMaximaActual, int N, const char *nombreArchivoSalida){
    
    FILE *archivoSalida = fopen(nombreArchivoSalida, "w");

    // Imprime el gráfico de barras normalizado
    for (int i = 0; i < N; i++) {
        int longitudBarra = (int)((arregloEnergiaParticulas[i] / arregloEnergiaParticulas[posicionEnergiaMaximaActual]) * 50); // Normaliza a 50 caracteres de ancho
        fprintf(archivoSalida, "%2d %10.4lf |", i, arregloEnergiaParticulas[i]);
        for (int j = 0; j < longitudBarra; j++) {
            fprintf(archivoSalida, "o");
        }
        fprintf(archivoSalida, "\n");
    }
}

/* 
Entrada: Arreglo de energía de las partículas, posición de la energía máxima actual, número de partículas totales,
nombre de archivo de salida
Salida: N/A
Descripcion: Imprime el arreglo de energía de las partículas en orden mostrando primero cual es la casilla con mayor energia
 */
void imprimirEnOrden(double * arregloEnergiaParticulas, int posicionEnergiaMaximaActual, int N, const char *nombreArchivoSalida){
    
    FILE *archivoSalida = fopen(nombreArchivoSalida, "w");
    
    fprintf(archivoSalida, "Energia Maxima (casilla %d): ", posicionEnergiaMaximaActual);
    fprintf(archivoSalida, "%f \n", arregloEnergiaParticulas[posicionEnergiaMaximaActual]);
    //Imprimir Arreglo
    for(int i = 0; i < N; i++){
        fprintf(archivoSalida, "%d ", i);
        fprintf(archivoSalida, "%f ", arregloEnergiaParticulas[i]);
        fprintf(archivoSalida, "\n");
    }
}



// Entrada: Recibe eel largo de impacto(largo arreglo)
// Salida: Retorna un arreglo de doubles con el largo de impacto
// Descripcion: Crea un arreglo de doubles con el largo de impacto y lo inicializa en 0
double* CrearArregloEnergiaParticulas(int N){
    double* arregloEnergiaParticulas = (double*)malloc(N*sizeof(double));
    for(int i=0; i<N; i++){
        arregloEnergiaParticulas[i] = 0;
    }
    return arregloEnergiaParticulas;
}

// Entrada: Recibe el arreglo de las energias de las particulas, la posicion con la energia maxima actual y la posicion de la particula a comparar
// Salida: N/A
// Descripcion: Compara la energia de la particula a comparar con la energia maxima actual y si es mayor actualiza la posicion de la energia maxima actual
void obtenerPosicionEnergiaMaxima(double * arregloEnergiaParticulas, int* posicionEnergiaMaximaActual, int posicionEnergiaComparacion){
    if(arregloEnergiaParticulas[posicionEnergiaComparacion] > arregloEnergiaParticulas[*posicionEnergiaMaximaActual]){
        *posicionEnergiaMaximaActual = posicionEnergiaComparacion;
    }
}

/* Entrada: Recibi el arreglo de las energia de las particulas, 
el numero de particulas totales, la posicion de la particula impactada
y la energia de la particula impactada

Salida: N/A

Descripcion: Suma la energia de la particula impactada a la posicion
correspondiente(junto con sus vecinos) en el arreglo de las energias de las particulas 
*/
void sumarEnergiaParticulas(double *arregloEnergiaParticulas, int N, int posicionImpactoParticula, int energiaParticula, int * posicionEnergiaMaximaActual){
    double largoArreglo = (double) N;
    double numerador = 1000 * energiaParticula; 
    for(int i = 0; i<N; i++){
        double denominador = largoArreglo * (sqrt( abs(posicionImpactoParticula - i) + 1));
        double energiaCorrespondiente_i = numerador/denominador;
        if(energiaCorrespondiente_i >= (MIN_ENERGY/largoArreglo)){
            arregloEnergiaParticulas[i] += energiaCorrespondiente_i;
            obtenerPosicionEnergiaMaxima(arregloEnergiaParticulas, posicionEnergiaMaximaActual, i);
        }
    }

}

