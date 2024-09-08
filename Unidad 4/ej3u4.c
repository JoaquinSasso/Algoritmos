/*Ejercicio 3
Se desea almacenar las notas de 50 alumnos. Construir un algoritmo que permita:
1. Cargar un arreglo sabiendo que por cada alumno se ingresa: nota y número de alumno ( valor comprendido entre 1
y 50)
2. Mostrar las notas de los alumnos con número par.
3. Informar cuántos alumnos registran una nota superior a la nota promedio*/
#include <stdio.h>
const int N = 50;
void promedio(int notas[], int acumNotas)
{
    int prom = acumNotas / N;
    int cont = 0;
    for (int i = 0; i < N; i++)
    {
        if (notas[i] > prom)
        {
            cont++;
        }
    }
    printf("La cantidad de alumnos que superan la nota promedio es de: %d\n", cont);
    return;
}
int main()
{
    int notas[N], num[N], acumNotas;
    for (int i = 0; i < N; i++)
    {
        printf("Ingrese el numero del alumno\n");
        scanf("%d", &num[i]);
        printf("Ingrese la nota\n");
        scanf("%d", &notas[i]);
        acumNotas = acumNotas + notas[i];
    }
    for (int i = 0; i < N; i++)
    {
        if ((num[i] % 2) == 0)
        {
            printf("La nota del alumno %d es: %d\n", num[i], notas[i]);
        }
    }
    promedio(notas, acumNotas);
    return 1;
}