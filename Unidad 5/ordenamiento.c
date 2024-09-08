#include <stdio.h>
#include <string.h>
const int N = 4;
struct reg
{
    int cantidad;
    char nombre[30];
};
void cerearCantidad(struct reg registro[])
{
    for (int i = 0; i < N; i++)
    {
        registro[i].cantidad = 0;
    }
    return;
}
void nombrador(struct reg registro[])
{
    for (int i = 0; i < N; i++)
    {
        switch (i)
        {
        case 0:
            strcpy(registro[i].nombre, "Papa/s");
            break;
        case 1:
            strcpy(registro[i].nombre, "Cebolla/s");
            break;
        case 2:
            strcpy(registro[i].nombre, "Lechuga/s");
            break;
        case 3:
            strcpy(registro[i].nombre, "Remolacha/s");
            break;
        }
    }
    return;
}
void cargar(struct reg registro[])
{
    int cant, tipo;
    printf("Ingrese la cantidad de verduras, 0 para detener\n");
    scanf("%d", &cant);
    while (cant != 0)
    {
        printf("Ingrese el tipo de verdura 0-3\n");
        scanf("%d", &tipo);
        registro[tipo].cantidad = registro[tipo].cantidad + cant;
        printf("Ingrese la cantidad de verduras, 0 para detener\n");
        scanf("%d", &cant);
    }
    return;
}
void mostrar(struct reg registro[])
{
    printf("La siguiente lista esta desordenada\n");
    for (int i = 0; i < N; i++)
    {
        printf("(%d)Hay %d %s\n", (i + 1), registro[i].cantidad, registro[i].nombre);
    }
    return;
}
void mostrarOrden(struct reg registro[])
{
    printf("La siguiente lista esta ordenada de manera ascendente\n");
    for (int i = 0; i < N; i++)
    {
        printf("(%d)Hay %d %s\n", (i + 1), registro[i].cantidad, registro[i].nombre);
    }
    return;
}
void ordenar(struct reg registro[])
{
    int k = 1, cota;
    struct reg aux;
    cota = N - 1;
    while (k != -1)
    {
        k = -1;
        for (int i = 0; i < cota; i++)
        {
            if (registro[i].cantidad > registro[i + 1].cantidad)
            {
                aux = registro[i];
                registro[i] = registro[i + 1];
                registro[i + 1] = aux;
                k = i;
            }
        }
        cota = k;
    }
    return;
}
int main()
{
    struct reg registro[N];
    cerearCantidad(registro);
    nombrador(registro);
    cargar(registro);
    mostrar(registro);
    ordenar(registro);
    mostrarOrden(registro);
    return 0;
}
/*Lote de prueba
10
0
2
1
5
2
8
3
0

*/