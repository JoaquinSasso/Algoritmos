/*Ejercicio 2
Dado el siguiente enunciado y el algoritmo que lo resuelve:
Para estudiar el problema de la deserción en los primeros años de la Universidad, se realiza una encuesta a los alumnos
que no aprobaron el parcial de una asignatura. De cada encuestado se tienen los siguientes datos: código del
departamento donde vive (1: Capital, 2: Caucete, …. 19: Zonda) y cantidad de horas dedicada al estudio.
Se pide mostrar por cada departamento la cantidad de horas de estudio promedio.
Realizar el seguimiento del algoritmo. Generar el lote de prueba suponiendo que hay 4 departamentos y se encuestaron
8 alumnos.*/

#include <stdio.h>
#include <string.h>
const int N = 18;
void cerear(int arreglo[])
{
    for (int i = 0; i < N; i++)
    {
        arreglo[i] = 0;
    }
    return;
}
void cargar(int horas[], int cantidad[])
{
    int dep, hora;
    printf("Ingrese el departamento, -1 para detener\n");
    scanf("%d", &dep);
    while (dep != -1)
    {
        printf("Ingrese la cantidad de horas estudiadas\n");
        scanf("%d", &hora);
        horas[dep - 1] = horas[dep - 1] + hora;
        cantidad[dep - 1]++;
        printf("Ingrese el departamento, -1 para detener\n");
        scanf("%d", &dep);
    }
    return;
}
void promedio(int horas[], int cantidad[])
{   
    int i = 0;
    printf("El promedio en Capital es de: %d", (horas[i] / cantidad[i]));
    i++;
    printf("El promedio en Caucete es de: %d", (horas[i] / cantidad[i]));
    i++;
    printf("El promedio en Rawson es de: %d", (horas[i] / cantidad[i]));
    i++;
    printf("El promedio en Rivadavia es de: %d", (horas[i] / cantidad[i]));
    i++;
    printf("El promedio en Santa Lucia es de: %d", (horas[i] / cantidad[i]));
    i++;
    printf("El promedio en Chimbas es de: %d", (horas[i] / cantidad[i]));
    i++;
    printf("El promedio en Pocito es de: %d", (horas[i] / cantidad[i]));
    i++;
    printf("El promedio en Iglesia es de: %d", (horas[i] / cantidad[i]));
    i++;
    printf("El promedio en 9 de Julio es de: %d", (horas[i] / cantidad[i]));
    i++;
    printf("El promedio en Albardon es de: %d", (horas[i] / cantidad[i]));
    i++;
    printf("El promedio en 25 de Mayo es de: %d", (horas[i] / cantidad[i]));
    i++;
    printf("El promedio en Calingasta es de: %d", (horas[i] / cantidad[i]));
    i++;
    printf("El promedio en Valle Fertil es de: %d", (horas[i] / cantidad[i]));
    i++;
    printf("El promedio en Ullum es de: %d", (horas[i] / cantidad[i]));
    i++;
    printf("El promedio en Jachal es de: %d", (horas[i] / cantidad[i]));
    i++;
    printf("El promedio en Angaco es de: %d", (horas[i] / cantidad[i]));
    i++;
    printf("El promedio en Sarmiento es de: %d", (horas[i] / cantidad[i]));
    i++;
    printf("El promedio en San Martin es de: %d", (horas[i] / cantidad[i]));
    i++;
    printf("El promedio en Zonda es de: %d", (horas[i] / cantidad[i]));
    return;
}
int main()
{

    int horas[N];
    int cantidad[N];
    cerear(horas);
    cerear(cantidad);
    cargar(horas, cantidad);
    promedio(horas, cantidad);
    return (1);
}