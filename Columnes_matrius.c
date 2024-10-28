#include <stdio.h>
#include <stdlib.h>

#define N 512

float Mat[N][N];  // Matriu de mida N x N

void InitData() {
    int i, j;
    srand(334411);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            Mat[i][j] = (((i * j) % 3) ? -1 : 1) * (100.0 * (rand() / (1.0 * RAND_MAX)));
        }
    }
}

void PrintRowElements(float mat[N][N], int row, int from, int to) {
    printf("Elements de la fila %d, columnes %d a %d:\n", row, from, to);
    for (int i = from; i <= to; i++) {
        printf("%f ", mat[row][i]);
    }
    printf("\n");
}

int main() {
    InitData();

    // Comprovar i mostrar els elements de la fila 0, columnes 0 a 9
    PrintRowElements(Mat, 0, 0, 9);

    // Comprovar i mostrar els elements de la fila 99, columnes 0 a 9 (fila N-1)
    PrintRowElements(Mat, N - 1, 0, 9);

    return 0;
}
