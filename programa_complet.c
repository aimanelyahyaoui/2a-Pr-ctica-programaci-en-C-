#include <stdio.h>
#include <stdlib.h>
#include <math.h>  // Inclou abs

#define N 512  // Definim N com 512

// Declaració de les matrius i vectors globals
float Mat[N][N], MatDD[N][N];
float V1[N], V2[N], V3[N];

// Funció per inicialitzar les dades en matrius i vectors
void InitData() {
    int i, j;
    srand(334411);  // Inicialitza el generador de números aleatoris amb una llavor constant

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            Mat[i][j] = (((i * j) % 3) ? -1 : 1) * (100.0 * (rand() / (1.0 * RAND_MAX)));

            // Assignació de valors a MatDD segons les condicions
            if ((abs(i - j) <= 3) && (i != j))
                MatDD[i][j] = (((i * j) % 3) ? -1 : 1) * (rand() / (1.0 * RAND_MAX));
            else if (i == j)
                MatDD[i][j] = (((i * j) % 3) ? -1 : 1) * (10000.0 * (rand() / (1.0 * RAND_MAX)));
            else
                MatDD[i][j] = 0.0;
        }
    }

    for (i = 0; i < N; i++) {
        V1[i] = (i < N / 2) ? (((i * j) % 3) ? -1 : 1) * (100.0 * (rand() / (1.0 * RAND_MAX))) : 0.0;
        V2[i] = (i >= N / 2) ? (((i * j) % 3) ? -1 : 1) * (100.0 * (rand() / (1.0 * RAND_MAX))) : 0.0;
        V3[i] = (((i * j) % 5) ? -1 : 1) * (100.0 * (rand() / (1.0 * RAND_MAX)));
    }
}

// Funció per imprimir elements d'un rang específic d'un vector
void PrintVectorElements(float vect[N], int start, int end, const char* name) {
    printf("%s del %d al %d:\n", name, start, end);
    for (int i = start; i <= end; i++) {
        printf("%f ", vect[i]);
    }
    printf("\n");
}

// Funció per imprimir elements d'una fila específica de la matriu
void PrintRowElements(float mat[N][N], int row, int from, int to) {
    printf("Elements de la fila %d, columnes %d a %d:\n", row, from, to);
    for (int i = from; i <= to; i++) {
        printf("%f ", mat[row][i]);
    }
    printf("\n");
}
int main() {
    // Inicialitzem les dades en matrius i vectors
    InitData();

    // Imprimir els elements 0 al 9 i 256 al 265 dels vectors V1, V2 i V3
    printf("V1 del 0 al 9 i del 256 al 265:\n");
    PrintVectorElements(V1, 0, 9, "V1");
    PrintVectorElements(V1, 256, 265, "V1");

    printf("V2 del 0 al 9 i del 256 al 265:\n");
    PrintVectorElements(V2, 0, 9, "V2");
    PrintVectorElements(V2, 256, 265, "V2");

    printf("V3 del 0 al 9 i del 256 al 265:\n");
    PrintVectorElements(V3, 0, 9, "V3");
    PrintVectorElements(V3, 256, 265, "V3");

    // Imprimir els elements 0 al 9 de les files 0 i 100 de la matriu Mat
    printf("MatDD fila 0 del 0 al 9 i fila 100 del 95 al 104:\n");
    PrintRowElements(MatDD, 0, 0, 9);
    PrintRowElements(MatDD, 100, 90, 99);
    // Imprimir els elements 0 al 9 de la fila 0 i 90 a 99 de la fila 100 de la matriu MatDD
    PrintRowElements(MatDD, 0, 0, 9);
    PrintRowElements(MatDD, 100, 90, 99);

}
return 0;

