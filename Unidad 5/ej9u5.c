/*En una concesionaria de autos trabajan N vendedores; de cada uno de ellos se poseen los siguientes datos: DNI y
Apellido y Nombre. Además, se cuenta con los siguientes datos de las ventas registradas en un periodo de tiempo: DNI
del vendedor e importe del vehículo.
Construir un algoritmo que usando subprogramas que permita:
1. Registrar en una estructura de datos adecuada los datos de cada uno de los N vendedores.
2. Informar por cada vendedor: Importe total vendido y cantidad de ventas realizadas.*/
#include <stdio.h>
#include <string.h>
const int N = 5;
struct vendedor
{
    int dni;
    char nombre[100];
    int cantidad;
    float importe;
};
void cerear(struct vendedor vendedores[]){
    for (int i = 0; i < N; i++){
        vendedores[i].cantidad = 0;
        vendedores[i].importe = 0;
    }
}
void cargarVendedores(struct vendedor vendedores[N])
{
    for (int i = 0; i < N; i++)
    {
        printf("Ingrese el DNI del vendedor\n");
        scanf("%d", &vendedores[i].dni);
        printf("Ingrese el nombre del vendedor\n");
        fflush(stdin);
        gets(vendedores[i].nombre);
    }
}
void cargarVentas(struct vendedor vendedores[N])
{
    float importe;
    int dni;
    printf("Ingrese el importe de la venta, 0 para detener\n");
    scanf("%f", &importe);
    while (importe != 0)
    {
        printf("Ingrese el DNI del vendedor\n");
        scanf("%d", &dni);
        for (int i = 0; i < N; i++)
        {
            if (dni == vendedores[i].dni)
            {
                vendedores[i].cantidad++;
                vendedores[i].importe += importe;
            }
        }
        printf("Ingrese el importe de la venta, 0 para detener\n");
        scanf("%f", &importe);
    }
}
void mostrar(struct vendedor vendedores[]){
    for (int i = 0; i < N; i++){
        printf("El venderdor con DNI %d vendio %d autos y consiguio un total de %.2f\n", vendedores[i].dni, vendedores[i].cantidad, vendedores[i].importe);
    }
}
int main()
{
    struct vendedor vendedores[N];
    cerear(vendedores);
    cargarVendedores(vendedores);
    cargarVentas(vendedores);
    mostrar(vendedores);
    return 0;
}
/*Lote de prueba
1023453
Paz Julio
1231234
Figeroa Roberto
2132133
Sasso Joaquin
23124234
Reynoso Nicolas
49359349
Flores Mauro
123.56
23124234
256.87
23124234
0
*/