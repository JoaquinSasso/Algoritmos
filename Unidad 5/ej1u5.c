/*Ejercicio 1
Un local de comidas para llevar, premia a los primeros 15 clientes del día con 15% de descuento. Los datos que se
registran de cada cliente son Nombre y apellido, DNI, Edad, Domicilio, Importe pagado.
Realizar un algoritmo que usando subprogramas permita:
1. Cargar la información en un arreglo de registros.
2. Mostrar los datos de los clientes que pagaron más y de los clientes que pagaron menos.
3. Escribir la edad promedio de los clientes.*/
#include <stdio.h>
#include <string.h>

const int N = 15;

struct persona
{
    char nombre[100];
    int dni;
    int edad;
    char domicilio[100];
    float importe;
};
void promedio(int edadAcu)
{
    int prom;
    prom = edadAcu / N;
    printf("La edad promedio de los compradores es de: %d\n", prom);
}
void mostrarM(float min, float max, struct persona clientes[])
{
    for (int i = 0; i < N; i++)
    {
        if (clientes[i].importe == min)
        {
            printf("Los datos de la siguiente persona coinciden con el importe minimo son:\n");
            printf("El nombre es: %s\n", clientes[i].nombre);
            printf("El DNI es: %d\n", clientes[i].dni);
            printf("La edad es: %d\n", clientes[i].edad);
            printf("El domicilio es: %s\n", clientes[i].domicilio);
            printf("El importe es: %.2f\n", (clientes[i].importe - (clientes[i].importe * 0.15)));
        }
        if (clientes[i].importe == max)
        {
            printf("\nLos datos de la persona con el importe maximo son:\n");
            printf("El nombre es: %s\n", clientes[i].nombre);
            printf("El DNI es: %d\n", clientes[i].dni);
            printf("La edad es: %d\n", clientes[i].edad);
            printf("El domicilio es: %s\n", clientes[i].domicilio);
            printf("El importe es: %.2f\n", (clientes[i].importe - (clientes[i].importe * 0.15)));
        }
    }
}

void carga(struct persona clientes[])
{
    int edadAcu = 0;
    float impMax = -1, impMin = 1000000;

    for (int i = 0; i < N; i++)
    {
        printf("Ingrese el nombre del cliente: ");
        fflush(stdin);
        fgets(clientes[i].nombre, sizeof(clientes[i].nombre), stdin);
        printf("Ingrese el DNI del cliente: ");
        scanf("%d", &clientes[i].dni);
        printf("Ingrese la edad del cliente: ");
        scanf("%d", &clientes[i].edad);
        edadAcu = edadAcu + clientes[i].edad;
        printf("Ingrese el domicilio del cliente: ");
        fflush(stdin);
        fgets(clientes[i].domicilio, sizeof(clientes[i].domicilio), stdin);
        printf("Ingrese el importe pagado: ");
        scanf("%f", &clientes[i].importe);

        if (clientes[i].importe > impMax)
        {
            impMax = clientes[i].importe;
        }

        if (clientes[i].importe < impMin)
        {
            impMin = clientes[i].importe;
        }
    }

    mostrarM(impMin, impMax, clientes);
    promedio(edadAcu);
}

int main()
{
    struct persona clientes[N];
    carga(clientes);

    return 0;
}