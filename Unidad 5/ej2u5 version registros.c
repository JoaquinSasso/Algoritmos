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
struct dpto{
    int horas;
    int cantidad;
};
void cerear(struct dpto departamentos[])
{
    for (int i = 0; i < N; i++)
    {
        departamentos[i].horas = 0;
        departamentos[i].cantidad = 0;
    }
    return;
}
void cargar(struct dpto departamentos[])
{
    int dep, hora;
    printf("Ingrese el departamento del alumno, 0 para detener\n");
    scanf("%d", &dep);
    while (dep != 0)
    {
        printf("Ingrese la cantidad de horas estudiadas\n");
        scanf("%d", &hora);
        departamentos[dep - 1].horas =departamentos[dep - 1].horas + hora;
        departamentos[dep - 1].cantidad++;
        printf("Ingrese el departamento del alumno, 0 para detener\n");
        scanf("%d", &dep);
    }
    return;
}
void promedio(struct dpto departamentos[])
{
    for (int i = 0; i < N; i++)
    {
        switch (i)
        {
        case 0:
            printf("El promedio en Capital es de: %d\n", (departamentos[i].horas / departamentos[i].cantidad));
            break;
        case 1:
            printf("El promedio en Caucete es de: %d\n", (departamentos[i].horas / departamentos[i].cantidad));
            break;
        case 2:
            printf("El promedio en Rawson es de: %d\n", (departamentos[i].horas / departamentos[i].cantidad));
            break;
        case 3:
            printf("El promedio en Rivadavia es de: %d\n", (departamentos[i].horas / departamentos[i].cantidad));
            break;
        case 4:
            printf("El promedio en Santa Lucia es de: %d\n", (departamentos[i].horas / departamentos[i].cantidad));
            break;
        case 5:
            printf("El promedio en Chimbas es de: %d\n", (departamentos[i].horas / departamentos[i].cantidad));
            break;
        case 6:
            printf("El promedio en Pocito es de: %d\n", (departamentos[i].horas / departamentos[i].cantidad));
            break;
        case 7:
            printf("El promedio en Iglesia es de: %d\n", (departamentos[i].horas / departamentos[i].cantidad));
            break;
        case (8):
            printf("El promedio en 9 de Julio es de: %d\n", (departamentos[i].horas / departamentos[i].cantidad));
            break;
        case 9:
            printf("El promedio en Albardon es de: %d\n", (departamentos[i].horas / departamentos[i].cantidad));
            break;
        case 10:
            printf("El promedio en 25 de Mayo es de: %d\n", (departamentos[i].horas / departamentos[i].cantidad));
            break;
        case 11:
            printf("El promedio en Calingasta es de: %d\n", (departamentos[i].horas / departamentos[i].cantidad));
            break;
        case 12:
            printf("El promedio en Valle Fertil es de: %d\n", (departamentos[i].horas / departamentos[i].cantidad));
            break;
        case 13:
            printf("El promedio en Ullum es de: %d\n", (departamentos[i].horas / departamentos[i].cantidad));
            break;
        case 14:
            printf("El promedio en Jachal es de: %d\n", (departamentos[i].horas / departamentos[i].cantidad));
            break;
        case 15:
            printf("El promedio en Angaco es de: %d\n", (departamentos[i].horas / departamentos[i].cantidad));
            break;
        case 16:
            printf("El promedio en Sarmiento es de: %d\n", (departamentos[i].horas / departamentos[i].cantidad));
            break;
        case 17:
            printf("El promedio en San Martin es de: %d\n", (departamentos[i].horas / departamentos[i].cantidad));
            break;
        case 18:
            printf("El promedio en Zonda es de: %d\n", (departamentos[i].horas / departamentos[i].cantidad));
            break;
        }
    }
    return;
}
int main()
{   
    struct dpto departamentos[N];
    cerear(departamentos);
    cargar(departamentos);
    promedio(departamentos);
    return (1);
}