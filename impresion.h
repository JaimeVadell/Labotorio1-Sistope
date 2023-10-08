#include <stdio.h>

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