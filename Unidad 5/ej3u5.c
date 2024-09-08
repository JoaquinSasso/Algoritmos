/*Ejercicio 3
Una consultora procesa los datos de 600 empresas. De cada empresa conoce: código de localidad (número entre 1 y 19),
cantidad de empleados.
Construya un algoritmo que usando subprogramas permita:
1. Decir para cada localidad la cantidad de empresas.
2. Informar para cada localidad la cantidad promedio de empleados.*/
#include <stdio.h>
#include <string.h>
const int N = 599;
const int dep = 18;
struct departamento
{
    int cantEmpresas;
    int cantEmpleados;
};
void cerearDeptos(struct departamento deptos[])
{
    for (int i = 0; i < dep; i++)
    {
        deptos[i].cantEmpresas = 0;
        deptos[i].cantEmpleados = 0;
    }
    return;
}
void contar(struct departamento deptos[])
{
    int cant, local;
    for (int i = 0; i < N; i++)
    {
        printf("Ingrese el codigo de localidad de la empresa %d\n", i);
        scanf("%d", &local);
        printf("Ingrese la cantidad de empleados de dicha empresa\n");
        scanf("%d", &cant);
        switch (local)
        {
        case 0: // Capital
            deptos[0].cantEmpleados = deptos[0].cantEmpleados + cant;
            deptos[0].cantEmpresas++;
            break;
        case 1: // Caucete
            deptos[1].cantEmpleados = deptos[1].cantEmpleados + cant;
            deptos[1].cantEmpresas++;
            break;
        case 2: // Rawson
            deptos[2].cantEmpleados = deptos[2].cantEmpleados + cant;
            deptos[2].cantEmpresas++;
            break;
        case 3: // Rivadavia
            deptos[3].cantEmpleados = deptos[3].cantEmpleados + cant;
            deptos[3].cantEmpresas++;
            break;
        case 4:
            deptos[4].cantEmpleados = deptos[4].cantEmpleados + cant;
            deptos[4].cantEmpresas++;
            break;
        case 5: // Chimbas
            deptos[5].cantEmpleados = deptos[5].cantEmpleados + cant;
            deptos[5].cantEmpresas++;
            break;
        case 6: // Pocito
            deptos[6].cantEmpleados = deptos[6].cantEmpleados + cant;
            deptos[6].cantEmpresas++;
            break;
        case 7: // Iglesia
            deptos[7].cantEmpleados = deptos[7].cantEmpleados + cant;
            deptos[7].cantEmpresas++;
            break;
        case (8): // 9 de Julio
            deptos[8].cantEmpleados = deptos[8].cantEmpleados + cant;
            deptos[8].cantEmpresas++;
            break;
        case 9: // Albardon
            deptos[9].cantEmpleados = deptos[9].cantEmpleados + cant;
            deptos[9].cantEmpresas++;
            break;
        case 10: // 25 de Mayo
            deptos[10].cantEmpleados = deptos[10].cantEmpleados + cant;
            deptos[10].cantEmpresas++;
            break;
        case 11: // Calingasta
            deptos[11].cantEmpleados = deptos[11].cantEmpleados + cant;
            deptos[11].cantEmpresas++;
            break;
        case 12: // Valle fertil
            deptos[12].cantEmpleados = deptos[12].cantEmpleados + cant;
            deptos[12].cantEmpresas++;
            break;
        case 13: // Ullum
            deptos[13].cantEmpleados = deptos[13].cantEmpleados + cant;
            deptos[13].cantEmpresas++;
            break;
        case 14: // Jachal
            deptos[14].cantEmpleados = deptos[14].cantEmpleados + cant;
            deptos[14].cantEmpresas++;
            break;
        case 15: // Angaco
            deptos[15].cantEmpleados = deptos[15].cantEmpleados + cant;
            deptos[15].cantEmpresas++;
            break;
        case 16: // Sarmiento
            deptos[16].cantEmpleados = deptos[16].cantEmpleados + cant;
            deptos[16].cantEmpresas++;
            break;
        case 17: // San Martin
            deptos[17].cantEmpleados = deptos[17].cantEmpleados + cant;
            deptos[17].cantEmpresas++;
            break;
        case 18: // Zonda
            deptos[18].cantEmpleados = deptos[18].cantEmpleados + cant;
            deptos[18].cantEmpresas++;
            break;
        }
    }
    return;
}
void mostrar(struct departamento deptos[])
{
    for (int i = 0; i < dep; i++)
    {
        printf("El departamento %d tiene %d empresas y %d empleados\n", i, deptos[i].cantEmpresas, deptos[i].cantEmpleados);
    }
    return;
}
int main()
{
    struct departamento deptos[dep];
    cerearDeptos(deptos);
    contar(deptos);
    mostrar(deptos);
    return (1);
}