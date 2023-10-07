#include <stdio.h>

/*
Entrada: Arreglo de energía de las partículas, posición de la energía máxima actual, número de partículas totales
Salida: N/A
Descripcion: Imprime el gráfico de barras normalizado a partir de los argumentos de la funcion
 */
void imprimirNormalizado(double * arregloEnergiaParticulas, int posicionEnergiaMaximaActual, int N){
    // Imprime el gráfico de barras normalizado
    for (int i = 0; i < N; i++) {
        int longitudBarra = (int)((arregloEnergiaParticulas[i] / arregloEnergiaParticulas[posicionEnergiaMaximaActual]) * 50); // Normaliza a 50 caracteres de ancho
        printf("%2d %10.4lf |", i, arregloEnergiaParticulas[i]);
        for (int j = 0; j < longitudBarra; j++) {
            printf("o");
        }
        printf("\n");
    }
}
