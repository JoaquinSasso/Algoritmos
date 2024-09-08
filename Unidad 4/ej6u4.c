/*Ejercicio 6
Hacer un algoritmo que resuelva el siguiente enunciado: Se cuenta con las estaturas de N deportistas.
1. Cargue un arreglo.
2. Informe el valor de la menor estatura.
3. Muestre los números de aquellos deportistas que registran la menor estatura.
4. Informe el valor de la mayor estatura.
5. Muestre los números de aquellos deportistas que registran la mayor estatura.
6. Ingrese por teclado una estatura e indique la cantidad de deportistas que la registran.*/
#include <stdio.h>
const int N = 5;

int main()
{
    int alturas[N], maxAlt = 0, minAlt = 1000, alt;
    for (int i = 0; i < N; i++)
    {
        printf("Ingrese la altura del deportista %d en cm\n", (i + 1));
        scanf("%d", &alturas[i]);
        if (maxAlt < alturas[i])
        {
            maxAlt = alturas[i];
        }
        if (minAlt > alturas[i])
        {
            minAlt = alturas[i];
        }
    }
    printf("Ingrese la altura que se desea buscar\n");
    scanf("%d", &alt);
    for (int i = 0; i < N; i++)
    {
        if (maxAlt == alturas[i])
        {
            printf("El deportista %d tiene la maxima estatura\n", (i + 1));
        }
        if (minAlt == alturas[i])
        {
            printf("El deportista %d tiene la minima estatura\n", (i + 1));
        }
        if (alt == alturas[i])
        {
            printf("El deportista %d tiene la estatura deseada\n", (i + 1));
        }
    }
    return (1);
}