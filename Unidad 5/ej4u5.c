/*Ejercicio 4
La policía ha lanzado un operativo para controlar el tránsito durante el verano. Se ha dividido a la provincia en 12 zonas.
Se han clasificado las infracciones en 10 tipos (1: exceso de velocidad, 2: falta de iluminación, … , 10: alcoholemia).
Por cada infracción realizada se tienen los siguientes datos: patente del vehículo, zona y tipo de infracción.
Para evaluar los resultados del Operativo realizar un algoritmo que con subprogramas permita:
1. Realizar un listado ordenado ascendentemente por cantidad, de los 10 tipos de infracciones.
2. Mostrar el o los tipos de infracción/es que más se cometen.
3. Decir si algún tipo de infracción no se cometió.
4. Indicar para cada zona la cantidad de infracciones realizadas.
5. Mostrar todas las zonas que tuvieron una cantidad de infracciones inferior al promedio de las infracciones realizadas
en las 12 zonas de la provincia.*/
#include <stdio.h>
#include <string.h>
const int N = 11;
const int M = 9;
struct infraccion
{
    int cantidad;
    char nombre[100];
};

void cerearTipo(int zonas[])
{
    for (int i = 0; i < N; i++)
    {
        zonas[i] = 0;
    }
    return;
}

void cerearCantidad(struct infraccion infracciones[])
{
    for (int i = 0; i < M; i++)
    {
        infracciones[i].cantidad = 0;
    }
    return;
}

void nombrador(struct infraccion infracciones[])
{
    for (int i = 0; i < M; i++)
    {
        switch (i)
        {
        case 0:
            strcpy(infracciones[i].nombre, "Exceso de velocidad(cod = 1)");
            break;
        case 1:
            strcpy(infracciones[i].nombre, "Falta de iluminacion(cod = 2)");
            break;
        case 2:
            strcpy(infracciones[i].nombre, "RTO vencida(cod = 3)");
            break;
        case 3:
            strcpy(infracciones[i].nombre, "Seguro vencido(cod = 4)");
            break;
        case 4:
            strcpy(infracciones[i].nombre, "No posee carnet de conducir(cod = 5)");
            break;
        case 5:
            strcpy(infracciones[i].nombre, "No posee cedula verde/azul(cod = 6)");
            break;
        case 6:
            strcpy(infracciones[i].nombre, "Cinturon de seguridad(cod = 7)");
            break;
        case 7:
            strcpy(infracciones[i].nombre, "Exceso de pasajeros(cod = 8)");
            break;
        case 8:
            strcpy(infracciones[i].nombre, "Bajo efecto de estufacientes(cod = 9)");
            break;
        case 9:
            strcpy(infracciones[i].nombre, "Alcoholemia(cod = 10)");
            break;
        }
    }
    return;
}

void cargar(int zonas[], struct infraccion infracciones[])
{
    int zone, type;
    char string[10];
    printf("Ingrese la zona donde se cometio la infraccion, 0 para detener\n");
    scanf("%d", &zone);
    while (zone != 0)
    {
        printf("Ingrese el tipo de infraccion\n");
        scanf("%d", &type);
        infracciones[type - 1].cantidad++;
        zonas[zone - 1]++;
        printf("Ingrese la patente del vehiculo infractor\n");
        fflush(stdin);
        gets(string);
        printf("Ingrese la zona donde se cometio la infraccion, 0 para detener\n");
        scanf("%d", &zone);
    }
    return;
}
void mostrarOrden(struct infraccion infracciones[])
{ // Muestra el orden actual del arreglo, se uso para probar ordenar(), Consigna 1
    printf("La siguiente lista esta ordenada de manera ascendente\n");
    for (int i = 0; i < M; i++)
    {
        printf("La %d infraccion es %s y tiene una cantidad de %d\n", (i + 1), infracciones[i].nombre, infracciones[i].cantidad);
    }
}
void ordenar(struct infraccion infracciones[]) // Consigna 1
{
    int k = 1, cota;
    struct infraccion aux;
    cota = M - 1;
    while (k != -1)
    {
        k = -1;
        for (int i = 0; i < cota; i++)
        {
            if (infracciones[i].cantidad > infracciones[i + 1].cantidad)
            {
                aux = infracciones[i];
                infracciones[i] = infracciones[i + 1];
                infracciones[i + 1] = aux;
                k = i;
            }
        }
        cota = k;
    }
    // mostrarOrden(infracciones); //Se utiliza para comprobar el correcto funcionamiento del algoritmo, no es necesaria
    return;
}
void mostrarM(struct infraccion infracciones[], int max, int min) // Consigna 2
{
    for (int i = 0; i < M; i++)
    {
        if (infracciones[i].cantidad == max)
        {
            printf("La infraccion %s tiene la cantidad maxima de infracciones\n", infracciones[i].nombre);
        }
        if (infracciones[i].cantidad == min)
        {
            printf("La infraccion %s tiene la cantidad minima de infracciones\n", infracciones[i].nombre);
        }
    }
    return;
}
void comparador(struct infraccion infracciones[]) // Consigna 2
{
    int max = -1, min = 99999;
    for (int i = 0; i < M; i++)
    {
        if (max < infracciones[i].cantidad)
        {
            max = infracciones[i].cantidad;
        }
        if (min > infracciones[i].cantidad)
        {
            min = infracciones[i].cantidad;
        }
    }
    mostrarM(infracciones, max, min);
    return;
}
int busqueda(struct infraccion infracciones[]) // Consigna 3
{
    int i = 0;
    while ((infracciones[i].cantidad != 0) && (i < M))
    {
        i++;
    }
    return i;
}
void mostrarString(char string[]) // Consigna 3
{
    printf("La infraccion: '%s' no se cometio ni una vez\n", string);
}
void mostrarZonas(int zonas[]) // Consigna 4
{
    for(int i = 0; i < N; i++){
        printf("La zona %d tiene %d infracciones\n", (i+1), zonas[i]);
    }
}
void promedio(int zonas[])
{
    int sum = 0;
    for(int i = 0; i < N; i++){
        sum = sum + zonas[i];
    }
   int prom = sum / N;
    for(int i = 0; i < N; i++){
        if(zonas[i] < prom){
            printf("La zona %d tuvo una cantidad de infracciones menor al promedio\n", (i+1));
        }
    }
}
int main()
{
    int zonas[N], ind;
    struct infraccion infracciones[M]; // Crear el arreglo
    cerearTipo(zonas);                 // Preparar el arreglo
    cerearCantidad(infracciones);      // Preparar el arreglo
    cargar(zonas, infracciones);       // Cargar el arreglo
    nombrador(infracciones);           // Para facilitar la comprension, no es necesario
    ordenar(infracciones);             // Consigna 1
    comparador(infracciones);          // Consigna 2
    ind = busqueda(infracciones);      // Consigna 3
    if (ind < N)
    {
        mostrarString(infracciones[ind].nombre);
    }
    mostrarZonas(zonas); // Consigna 4
    promedio(zonas); // Consigna 5
    return (0);
}
/*Lote de prueba
1
2
AE987BJ
2
5
AE987BJ
3
1
AE987BJ
4
4
AE987BJ
6
7
AE987BJ
7
3
AE987BJ
8
8
AE987BJ
8
8
AE987BJ
9
9
AE987BJ
10
10
AE987BJ
1
1
AE987BJ
1
1
AE987BJ
0

*/