#include <stdio.h>

int factorial(int n) {
    int i = 1;
    while (n > 1) {
        i = i * n;
        n = n - 1;
    }
    return i;
}

int main(int argc, char *argv[]) {//modificacion para el ingreso de datos
    int numero;
    
    printf("Escriba su numero a calcular el factorial: ");
    scanf("%d", &numero);
    
    int resultado = factorial(numero);
    printf("%d! = %d\n", numero, resultado);
    
    return 0;
}