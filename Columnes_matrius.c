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

// Funció per imprimir elements d'una fila específica de la matriu
void PrintRowElements(float mat[N][N], int row, int from, int to) {
    printf("Elements de la fila %d, columnes %d a %d:\n", row, from, to);
    for (int i = from; i <= to; i++) {
        printf("%f ", mat[row][i]);
    }
    printf("\n");
}

// Funció per multiplicar un vector per un escalar
void MultEscalar(float vect[N], float vec2[N], float alfa) {
    for (int i = 0; i < N; i++) {
        vec2[i] = alfa * vect[i];  // Multiplica cada element del vector pel valor escalar
    }
}

// Funció per imprimir una part del vector
void PrintVect(float vect[N], int from, int numel) {
    for (int i = from; i < from + numel; i++) {
        printf("%f ", vect[i]);  // Imprimeix cada element del vector a partir de la posició 'from'
    }
    printf("\n");  // Salta a la següent línia després d'imprimir
}

int main() {
    float vec2[N];
    float alfa = 2.0;  // Multiplicarem el vector per l'escalar 2.0

    // Inicialitzem les dades en matrius i vectors
    InitData();

    // Comprovar i mostrar els elements de la fila 0, columnes 0 a 9
    PrintRowElements(Mat, 0, 0, 9);

    // Comprovar i mostrar els elements de la fila N-1, columnes 0 a 9
    PrintRowElements(Mat, N - 1, 0, 9);

    // Multipliquem el vector V1 pel valor escalar
    MultEscalar(V1, vec2, alfa);

    // Imprimim els primers 10 elements del vector V1 i del vector resultant
    printf("Vector V1 (primers 10 elements):\n");
    PrintVect(V1, 0, 10);

    printf("Vector resultant (primers 10 elements després de multiplicar per l'escalar):\n");
    PrintVect(vec2, 0, 10);

    return 0;
}
