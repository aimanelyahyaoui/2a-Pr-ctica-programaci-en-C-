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
// Multiplicació escalar: multiplicar un vector per un escalar
void MultEscalar(float vect[N], float vectres[N], float alfa) {
    for (int i = 0; i < N; i++) {
        vectres[i] = alfa * vect[i];
    }
}
//Funció per calcular la infi-norma d'una matriu
float Infininorm( float M[N][N] ) {
    float suma_max  = 0.0;
    for (int i = 0; i<N;i++){
        float suma = 0.0;
        for (int j = 0; j<N; j++){
            suma += fabs (M[i][j]);
            if(suma>=suma_max) {
            suma_max = suma;
            }
        }
    }
    return suma_max;
}
//FUnció per calclar la Norma ú d'una matriu
float Onenorm( float M[N][N] ) {
    float suma_max  = 0.0;
    for (int i = 0; i<N;i++){
        float suma = 0.0;
        for (int j = 0; j<N; j++){
            suma += fabs (M[j][i]);
            if(suma>=suma_max) {
            suma_max = suma;
            }
        }
    }
    return suma_max;
}
float NormFrobenius( float M[N][N] ){
    float suma = 0.0;
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            suma += M[i][j]*M[i][j];
            }
        }
    return sqrt(suma);
}

int DiagonalDom( float M[N][N] ) {
    for (int i = 0; i < N; i++) {
        float element_diagonal = fabs(M[i][i]);
        float sum = 0.0;
        for (int j = 0; j < N; j++) {
            if (i != j) {
                sum += fabs(M[i][j]);
            }
        }
        if(element_diagonal<=sum){
            return 0;
            }
    return 1;
    }
}
float Scalar( float vect1[N], float vect2[N] ) {
    float producte_escalar = 0.0;
    for ( int i = 0; i<N ; i++) {
        producte_escalar += vect1[i] * vect2[i];
        }
    return producte_escalar;
}
float Magnitude( float vect[N] ) {
    float  magnitud = 0.0;
    for (int i=0; i<N; i++) {
        magnitud += vect [i]*vect[i];
    }
    return sqrt(magnitud);
}
int Ortogonal( float vect1[N], float vect2[N] ) {
    float suma = 0.0;
    for (int i=0; i<N; i++) {
        suma += vect1[i] * vect2[i];
    }

    if (suma == 0.0) {
        return 1;
    }else {
        return 0;
    }
}
// Projecció: calcular la projecció d’un vector sobre un altre
void Projection(float vect1[N], float vect2[N], float vectres[N]) {
    float prod_escalarj = Scalar(vect1, vect2) / Scalar(vect2, vect2);
    MultEscalar(vect2, vectres, prod_escalarj);
}

// Multiplicació matriu per vector
void Matriu_x_Vector(float M[N][N], float vect[N], float vectres[N]) {
    for (int i = 0; i < N; i++) {
        vectres[i] = 0.0;
        for (int j = 0; j < N; j++) {
            vectres[i] += M[i][j] * vect[j];
        }
    }
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
    // Infininorma, norma ú, norma de Frobenious i si és o no diagonalment dominant de Mat
    printf("Infininorma de Mat = %.3f\n", Infininorm(Mat));
    printf("Norma ú de Mat = %.3f\n", Onenorm(Mat));
    printf("Norma de Frobenius de Mat = %.3f \n", NormFrobenius(Mat));
    if(DiagonalDom (Mat)) {
        printf("La matriu Mat és diagonal dominant \n");
    } else {
        printf("La matriu Mat no és diagonal dominant \n");
    }
    // Infininorma, norma ú, norma de Frobenious i si és o no diagonalment dominant de MatDD
    printf("Infininorma de MatDD = %.3f\n", Infininorm(MatDD));
    printf("Norma ú de MatDD = %.3f\n", Onenorm(MatDD));
    printf("Norma de Frobenius de MatDD = %.3f \n", NormFrobenius(MatDD));
    if(DiagonalDom (MatDD)) {
        printf("La matriu MatDD és diagonal dominant \n"); //HHAURIA DE DONAR QUE SI QUE HO ÉS I DONA QUE NO
    } else {
        printf("La matriu MatDD no és diagonal dominant \n"); 
    }
    //Càlcul de productes escalars
    printf("Escalar <V1, V2>= %.3f \n ", Scalar( V1, V2 ));
    printf("Escalar <V1, V3>= %.3f \n ", Scalar( V1, V3 ));
    printf("Escalar <V2, V3>= %.3f \n ", Scalar( V2, V3 ));
    //Càlcul de magnituds
    printf("Magnitud V1, V2, V3 = %.2f %.2f %.2f\n", Magnitude(V1), Magnitude(V2), Magnitude(V3));
    //Ortogonals o no
    if(Ortogonal (V1, V2)){
        printf("V1 i V2 són ortogonals \n");
    }
    else if(Ortogonal (V1, V3)){
        printf("V1 i V3 són ortogonals \n");
    }
    else if (Ortogonal (V3, V2)){
        printf("V2 i V3 són ortogonals \n");
    }
    else {
        printf ("Cap dels vaectors són ortogonals entre ells \n");
    }
    // Multiplicaci´po pvectpr amb escalar
    float vectres[N];
    MultEscalar(V3, vectres, 2.0);  // Multiplicació de V3 per 2.0
    PrintVect(vectres, 0, 10); 
    //Projecció de vectors
    Projection(V2, V3, vectres);
    printf("Projecció de V2 sobre V3: ");
    PrintVect(vectres, 0, 10);
    Projection(V1, V2, vectres);
    printf("Projecció de V1 sobre V2: ");
    PrintVect(vectres, 0, 10);
    //Multiplicació de matriu per un vector
    Matriu_x_Vector(Mat, V2, vectres);
    printf("Resultat de Mat x V1: ");
    PrintVect(vectres, 0, 10);
    return 0;
}


