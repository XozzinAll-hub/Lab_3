#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 3

int findLargestLine(int matrix[][SIZE]) {
    // se ocupa verfificar si la matirz es magico, por lo que ocupo una variable temporal para cada suma y una para comparar
    int Suma = 0, temp = 0;
    //una complicacion, para definir suma hacer una secuencia de una sola repeticion, como una diagonal
    for (int i = 0; i < SIZE; i++) {
        Suma += matrix[i][i]; // Suma de la diagonal principal
    }   //ya con esto podemos comparar con el temporal

    //Suma filas y columnas
    for (int i = 0; i < SIZE; i++) {
        //fila i
        temp = 0;
        for (int j = 0; j < SIZE; j++) {
            temp += matrix[i][j]; 
        }
        if (temp != Suma) return 0; // Si no coincide, no es magico
        //columna i
        temp = 0;
        for (int j = 0; j < SIZE; j++) {
            temp += matrix[j][i]; // Suma de la columna i
        }
        if (temp != Suma) return 0; // Si no coincide, no es magico
    }

    // diagonal secundaria
    temp = 0;
    for (int i = 0; i < SIZE; i++) {
        temp += matrix[i][SIZE - i - 1]; // Suma de la diagonal secundaria
    }
    if (temp != Suma) return 0;  

    return 1; // Es una matriz magica
}

int main() {
    srand(time(NULL));
    // ejemplo de matriz magica 3x3 conocido 
    int matrix[SIZE][SIZE] = {
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8}
    };
    printf("La matriz utilizada corresponde a:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("La matriz es "), findLargestLine(matrix) ? printf("magica\n") : printf("no magica\n");

    //usando matrices aleatorias
    for(int k = 0; k < SIZE; k++) {//genero 3 matrices aleatorias 
        int randomMatrix[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                randomMatrix[i][j] = rand() % 10; // Numeros aleatorios entre 0 y 9
            }
        }
        printf("Matriz aleatoria %d:\n", k + 1);
        for (int i = 0; i < SIZE; i++) {    
            for (int j = 0; j < SIZE; j++) {
                printf("%d ", randomMatrix[i][j]);
            }
            printf("\n");
        }
        printf("La matriz es "), findLargestLine(randomMatrix) ? printf("magica\n") : printf("no magica\n");
    }
    return 0;
}