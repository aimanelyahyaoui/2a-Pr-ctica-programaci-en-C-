Fort#include <stdio.h>
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

// 6. Ortogonals: determinar si dos vectors són ortogonals (no funciona)
int Ortogonal( float vect1[N], float vect2[N] ) {
    float suma = 0.0;
    for (int i=0; i<N; i++) {
        suma += vect1[i] * vect2[i];
    }

// 7. Projecció: calcular la projecció d’un vector sobre un altre
void Projection(float vect1[N], float vect2[N], float vectres[N]) {
    float scalar_proj = Scalar(vect1, vect2) / Scalar(vect2, vect2);
    MultEscalar(vect2, vectres, scalar_proj);
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

// 13. Resoldre sistemes d’equacions lineals: mètode de Jacobi
int Jacobi(float M[N][N], float vect[N], float vectres[N], unsigned iter) {
    if (!DiagonalDom(M)) {
        return 0;  // Retorna 0 si la matriu no és diagonal dominant
    }

    for (unsigned k = 0; k < iter; k++) {
        float x_old[N];
        for (int i = 0; i < N; i++) {
            x_old[i] = vect[i];
        }

        for (int i = 0; i < N; i++) {
            float sum = vect[i];
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    sum -= M[i][j] * x_old[j];
                }
            }
            vect[i] = sum / M[i][i];
        }

        // Comprovar la convergència
        float error = 0.0;
        for (int i = 0; i < N; i++) {
            error += fabs(vect[i] - x_old[i]);
        }
        if (error < 1e-5) {
            break;  // Convergència
        }
    }
    for (int i = 0; i < N; i++) {
        vectres[i] = vect[i];
    }
    return 1;  // Retorna 1 si el mètode de Jacobi es pot aplicar
}

int main() {
    // Inicialitzem les dades en les matrius i vectors
    InitData();

    // Proves de la funció PrintVect
    PrintVect(V1, 0, 10);  // Mostra els primers 10 elements de V1
    PrintVect(V2, 0, 10);  // Mostra els primers 10 elements de V2

    // Proves de la funció PrintRow
    PrintRow(Mat, 0, 0, 10);  // Mostra els primers 10 elements de la fila 0 de Mat
    PrintRow(MatDD, 0, 0, 10); // Mostra els primers 10 elements de la fila 0 de MatDD

    // Proves de la multiplicació escalar
    float vectres[N];
    MultEscalar(V1, vectres, 2.0);  // Multiplicació de V1 per 2.0
    PrintVect(vectres, 0, 10);      // Mostra el resultat

    // Proves del producte escalar
    float scalar_product = Scalar(V1, V2);
    printf("Producte escalar de V1 i V2: %f\n", scalar_product);

    // Proves de la magnitud
    float magnitude_V1 = Magnitude(V1);
    printf("Magnitud de V1: %f\n", magnitude_V1);

    // Proves de la ortogonalitat
    int ortogonal = Ortogonal(V1, V2);
    printf("V1 i V2 són ortogonals: %d\n", ortogonal);

    // Proves de la projecció
    Projection(V1, V2, vectres);
    printf("Projecció de V1 sobre V2: ");
    PrintVect(vectres, 0, 10);

    // Proves de la infini-norma
    float infini_norm = Infininorm(Mat);
    printf("Infini-norma de Mat: %f\n", infini_norm);

    // Proves de la norma-ú
    float one_norm = Onenorm(Mat);
    printf("Norma-ú de Mat: %f\n", one_norm);

    // Proves de la norma de Frobenius
    float frobenius_norm = NormFrobenius(Mat);
    printf("Norma de Frobenius de Mat: %f\n", frobenius_norm);

    // Proves de la diagonal dominant
    int diagonal_dominant = DiagonalDom(MatDD);
    printf("MatDD és diagonal dominant: %d\n", diagonal_dominant);

    // Proves de la multiplicació matriu per vector
    Matriu_x_Vector(Mat, V1, vectres);
    printf("Resultat de Mat x V1: ");
    PrintVect(vectres, 0, 10);

    // Proves del mètode de Jacobi
    float vect_res[N];
    if (Jacobi(MatDD, V1, vect_res, 1000)) {
        printf("Solució del sistema d'equacions (Jacobi): ");
        PrintVect(vect_res, 0, 10);
    } else {
        printf("El mètode de Jacobi no es pot aplicar.\n");
    }

    return 0;
}
