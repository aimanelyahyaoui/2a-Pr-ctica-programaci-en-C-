#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

// 1. Mostrar un cert nombre d’elements (numel) d’un vector a partir d’una posició donada (from).
void PrintVect(float vect[N], int from, int numel) {
    printf("Elements de Vect del %d al %d:\n", from, from + numel - 1);
    for (int i = from; i < from + numel; i++) {
        printf("%f ", vect[i]);
    }
    printf("\n");
}

// 2. Mostrar un cert nombre d’elements (numel) d’una fila (row) d’una matriu a partir d’una posició donada (from).
void PrintRow(float mat[N][N], int row, int from, int numel) {
    printf("Elements de la fila %d del %d al %d:\n", row, from, from + numel - 1);
    for (int i = from; i < from + numel; i++) {
        printf("%f ", mat[row][i]);
    }
    printf("\n");
}

// 3. Multiplicació escalar: multiplicar un vector per un escalar
void MultEscalar(float vect[N], float vectres[N], float alfa) {
    for (int i = 0; i < N; i++) {
        vectres[i] = alfa * vect[i];
    }
}

// 4. Producte escalar: producte punt entre dos vectors
float Scalar(float vect1[N], float vect2[N]) {
    float producte_escalar = 0.0;
    for (int i = 0; i < N; i++) {
        producte_escalar += vect1[i] * vect2[i];
    }
    return producte_escalar;
}

// 5. Magnitud: calcular la magnitud d’un vector
float Magnitude(float vect[N]) {
    float magnitud = 0.0;
    for (int i = 0; i < N; i++) {
        magnitud += vect[i] * vect[i];
    }
    return sqrt(magnitud);
}

// 6. Ortogonals: determinar si dos vectors són ortogonals
int Ortogonal( float vect1[N], float vect2[N] ) {
    float suma = 0.0;
    for (int i=0; i<N; i++) {
        suma += vect1[i] * vect2[i];
    }
}

// 7. Projecció: calcular la projecció d’un vector sobre un altre
void Projection(float vect1[N], float vect2[N], float vectres[N]) {
    float prod_escalarj = Scalar(vect1, vect2) / Scalar(vect2, vect2);
    MultEscalar(vect2, vectres, prod_escalarj);
}

// 8. Infini-norma: calcular la infini-norma d’una matriu
float Infininorm(float M[N][N]) {
    float suma_max = 0.0;
    for (int i = 0; i < N; i++) {
        float suma = 0.0;
        for (int j = 0; j < N; j++) {
            suma += fabs(M[i][j]);
        }
        if (suma > suma_max) {
            suma_max = suma;
        }
    }
    return suma_max;
}

// 9. Norma-u: calcular la norma ú d’una matriu
float Onenorm(float M[N][N]) {
    float suma_max = 0.0;
    for (int i = 0; i < N; i++) {
        float suma = 0.0;
        for (int j = 0; j < N; j++) {
            suma += fabs(M[j][i]);
        }
        if (suma > suma_max) {
            suma_max = suma;
        }
    }
    return suma_max;
}

// 10. Norma de Frobenius: calcular la norma de Frobenius d’una matriu
float NormFrobenius(float M[N][N]) {
    float suma = 0.0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            suma += M[i][j] * M[i][j];
        }
    }
    return sqrt(suma);
}

// 11. Diagonal dominant: determinar si una matriu és o no diagonal dominant (no funciona)
int DiagonalDom(float M[N][N]) {
    for (int i = 0; i < N; i++) {
        float element_diagonal = fabs(M[i][i]);
        float sum = 0.0;
        for (int j = 0; j < N; j++) {
            if (i != j) {
                sum += fabs(M[i][j]);
            }
        }
        if (element_diagonal < sum) {
            return 0;  // No és diagonal dominant
        }
    }
    return 1;  // És diagonal dominant
}

// 12. Multiplicació matriu per vector
void Matriu_x_Vector(float M[N][N], float vect[N], float vectres[N]) {
    for (int i = 0; i < N; i++) {
        vectres[i] = 0.0;
        for (int j = 0; j < N; j++) {
            vectres[i] += M[i][j] * vect[j];
        }
    }
}


int main() {
    // Inicialitzem les dades en les matrius i vectors
    InitData();




}
