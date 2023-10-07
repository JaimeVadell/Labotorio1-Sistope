#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MIN_ENERGY 0.001

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






