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
void swap(struct reg* a, struct reg* b) {
    struct reg temp = *a;
    *a = *b;
    *b = temp;
}

int partition(struct reg registro[], int low, int high) {
    int pivot = registro[high].cantidad;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (registro[j].cantidad < pivot) {
            i++;
            swap(&registro[i], &registro[j]);
        }
    }
    swap(&registro[i + 1], &registro[high]);
    return (i + 1);
}

void quicksort(struct reg registro[], int low, int high) {
    if (low < high) {
        int pi = partition(registro, low, high);
        quicksort(registro, low, pi - 1);
        quicksort(registro, pi + 1, high);
    }
}
int main()
{
    struct reg registro[N];
    cerearCantidad(registro);
    nombrador(registro);
    cargar(registro);
    mostrar(registro);
    int n = sizeof(registro) / sizeof(registro[0]);
    quicksort(registro, 0, n - 1);
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