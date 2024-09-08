/*Ejercicio 1
Se desea guardar en un arreglo las 50 notas de la materia algoritmos y resolución de problemas. Construir un
algoritmo que permita el ingreso de las 50 notas y luego las muestre.*/
#include <stdio.h>
const int N = 50;
int main()
{
    int notas[N];
    printf("Ingrese las 50 notas\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &notas[i]);
    }
    for (int i = 0; i < N; i++)
    {
        printf("La nota %d es: %d\n", (i + 1), notas[i]);
    }
    return 1;
}