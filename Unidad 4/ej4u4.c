/*Ejercicio 4
Complete el Algoritmo considerando el siguiente enunciado: Se cuenta con las temperaturas máximas registradas
durante cada día del mes de enero de 2019 en la ciudad de SanJuan.
1. Mostrar la temperatura promedio mensual.
2. Indicar la cantidad de días en el mes cuyas temperaturas no fueron inferiores a la temperatura promedio mensual.
3. Mostrar el/los números de día cuya temperatura máxima varió entre dos valores ingresados por teclado.*/
#include <stdio.h>
const int N = 31;
void carga(float temp[])
{
    for (int i = 0; i < N; i++)
    {
        printf("Ingrese la temperatura del dia %d\n", (i + 1));
        scanf("%f", &temp[i]);
    }
    return;
}
float promedio(float temp[])
{

    float s, prom;
    s = 0;
    for (int i = 0; i < N; i++)
    {
        s = s + temp[i];
    }
    prom = s / N;
    return (prom);
}
void cantidad(float t[N], float xp)
{

    int i, ct;
    ct = 0;
    for (int i = 0; i < N; i++)
    {
        if (!(t[i] < xp))
        {
            ct++;
        }
    }
    printf("La cantidad de dias cuya temperatura no es menor al promedio es: %d\n", ct);
    return;
}
void muestra(float a[], float temp1, float temp2)
{

    for (int i = 0; i < N; i++)
    {
        if ((a[i] > temp1) && (a[2] < temp2))
        {
            printf("El dia %d, vario su temperatura entre %f C y %f C\n", (i + 1), temp1, temp2);
        }
    }
    return;
}

/*---Algoritmo principal--*/
int main()
{
    float temp[N], p, temp1, temp2;
    carga(temp);
    p = promedio(temp);
    printf("El promedio mensual de temperaturas de enero de 2019 es: %f", p);
    cantidad(temp, p);
    printf("Ingrese la temperatura 1\n");
    scanf("%f", &temp1);
    printf("Ingrese la temperatura 2\n");
    scanf("%f", &temp2);
    muestra(temp, temp1, temp2);
    return 1;
}