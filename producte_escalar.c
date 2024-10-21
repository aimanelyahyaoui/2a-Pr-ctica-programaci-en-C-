#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 512  // Definim N com 512

float Mat[N][N], MatDD[N][N], V1[N], V2[N], V3[N]; // Declaració de les matrius i vectors

// Inicialitza les dades per a matrius i vectors
void InitData() {
    int i, j;
    srand(334411);  // Inicialització de la llavor per a números aleatoris

    // Inicialització de Mat i MatDD
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            Mat[i][j] = (((i * j) % 3) ? -1 : 1) * (100.0 * (rand() / (1.0 * RAND_MAX)));
            if ((abs(i - j) <= 3) && (i != j)) {
                MatDD[i][j] = (((i * j) % 3) ? -1 : 1) * (rand() / (1.0 * RAND_MAX));
            } else if (i == j) {
                MatDD[i][j] = (((i * j) % 3) ? -1 : 1) * (10000.0 * (rand() / (1.0 * RAND_MAX)));
            } else {
                MatDD[i][j] = 0.0;
            }
        }
    }

    // Inicialitzar V1, V2 i V3
    for (i = 0; i < N; i++) {
        V1[i] = (i < N / 2) ? (((i % 3) ? -1 : 1) * (100.0 * (rand() / (1.0 * RAND_MAX)))) : 0.0;
        V2[i] = (i >= N / 2) ? (((i % 3) ? -1 : 1) * (100.0 * (rand() / (1.0 * RAND_MAX)))) : 0.0;
        V3[i] = (((i % 5) ? -1 : 1) * (100.0 * (rand() / (1.0 * RAND_MAX)))); // Genera valors aleatoris
    }
}

// Funció per imprimir una part del vector
void PrintVect(float vect[N], int from, int numel) {
    for (int i = from; i < from + numel; i++) {
        printf("%f ", vect[i]);  // Imprimeix cada element del vector a partir de la posició 'from'
    }
    printf("\n");  // Salta a la següent línia després d'imprimir
}

// Funció per calcular el producte vectorial de dos vectors de 3 components
void ProducteVectorial(float v1[3], float v2[3], float result[3]) {
    result[0] = v1[1] * v2[2] - v1[2] * v2[1]; // Component x
    result[1] = v1[2] * v2[0] - v1[0] * v2[2]; // Component y
    result[2] = v1[0] * v2[1] - v1[1] * v2[0]; // Component z
}

int main() {
    // Inicialitzem les matrius i vectors
    InitData();

    // Imprimim els elements 0 al 9 i 256 al 265 dels vectors V1, V2 i V3
    printf("V1 del 0 al 9 i del 256 al 265:\n");
    PrintVect(V1, 0, 10);
    PrintVect(V1, 256, 10);

    printf("V2 del 0 al 9 i del 256 al 265:\n");
    PrintVect(V2, 0, 10);
    PrintVect(V2, 256, 10);

    printf("V3 del 0 al 9 i del 256 al 265:\n");
    PrintVect(V3, 0, 10);
    PrintVect(V3, 256, 10);

    // Calcular i imprimir el producte vectorial dels primers tres elements de V1 i V2
    float result[3];
    ProducteVectorial((float[]){V1[0], V1[1], V1[2]}, (float[]){V2[0], V2[1], V2[2]}, result);
    
    printf("Producte vectorial de V1 i V2 (primeres 3 components):\n");
    printf("(%f, %f, %f)\n", result[0], result[1], result[2]);

    return 0;  // Tancar el programa correctament
}
