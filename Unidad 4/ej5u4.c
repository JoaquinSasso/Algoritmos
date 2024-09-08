/*Ejercicio 5
Hacer un algoritmo que resuelva el siguiente enunciado:
Se cuenta con las edades de 200 personas.
1. Cargue un arreglo.
2. Escriba la edad promedio.
3. Indique cuantas edades no superan a la edad promedio.
4. Informe si alguna de las edades coincide con la edad promedio.*/
#include <stdio.h>
const int N = 5;
int promedio(int acumEdades)
{
    return (acumEdades / N);
}
void cantidad(int edades[], int p)
{
    int cont = 0;
    for (int i = 0; i < N; i++)
    {
        if (edades[i] < p)
        {
            cont++;
        }
    }
    printf("La cantidad de edades que no superan el promedio es de: %d \n", cont);
    return;
}
void informe(int edades[], int p)
{
    int bandera = 0, i = 0;
    while ((bandera == 0) && (i < N))
    {
        if (edades[i] == p)
        {
            bandera = 1;
            printf("Hay alguna edad que coincide con el promedio\n");
        }
        i++;
    }
    return;
}
int main()
{
    int edades[N], acumEdades = 0, p;
    for (int i = 0; i < N; i++)
    {
        printf("Ingrese la edad de la persona %d\n", (i + 1));
        scanf("%d", &edades[i]);
        acumEdades = acumEdades + edades[i];
    }
    p = promedio(acumEdades);
    printf("La edad promedio es de: %d\n", p);
    cantidad(edades, p);
    informe(edades, p);
    return 1;
}