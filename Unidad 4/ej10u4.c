/*Ejercicio 10
Escribir un algoritmo que mediante subprogramas permita:
1. Generar y mostrar un arreglo de N componentes enteras. Utilizar la función de Lenguaje C que genera números
aleatorios.
2. Ingresar por teclado dos números de índices e intercambiar las componentes situadas en esos índices. Mostrar el
arreglo resultante.
3. Mostrar el resultado de multiplicar las componentes impares del arreglo por un valor ingresado por teclado.
4. Generar un subarreglo con las componentes menores a un valor ingresado por teclado*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int N = 10;
int subN = 0;
void carga(int arreglo[])
{                               // Se cargan numeros aleatorios en el arreglo. Consigna 1
    for (int i = 0; i < N; i++) // Itera por todos los elementos del arreglo
    {
        arreglo[i] = rand() % 11; // Se carga un numero de maximo 10 a la posicion actual del arreglo
    }
}
void muestra(int arreglo[]) // Muestra el valor de todas las componentes del arreglo. Consigna 2
{
    for (int i = 0; i < N; i++) // Itera por todos los elementos del arreglo
    {
        printf("La componente %d, tiene un valor de: %d\n", (i + 1), arreglo[i]);
    }
    return;
}
void intercambiador(int arreglo[]) // Intercambia el valor de dos componentes del arreglo a eleccion del usuario. Consigna 2
{
    int Aux1, n1, n2;
    printf("Ingrese la componente que quiere intercambiar\n");
    scanf("%d", &n1);
    printf("Ingrese la componente por la que quiere intercambiarla\n");
    scanf("%d", &n2);
    Aux1 = arreglo[n2 - 1]; // Se guarda el valor actual de arreglo[n1] en la variable auxiliar Aux1
    arreglo[n2 - 1] = arreglo[n1 -1]; // Se guarda el valor actual de arreglo[n2] en la variable auxiliar Aux2
    arreglo[n1 - 1] = Aux1; // Se intercamia el valor
    return;
}
void muestraImpar(int arreglo[]) // Muestra el valor de temperatura de los dias impares. Consigna 3
{
    int num;
    printf("Ingrese el valor por el que quiere multiplicar las componentes con indices impares\n");
    scanf("%d", &num);
    for (int i = 0; i < N; i++) // Itera por todos los elementos del arreglo
    {
        if ((i % 2) != 0) // Calcula los indices impares, todos los numeros que tienen resto distino de 0 diviendolos en 2
        {
            printf("El resultado con la componente con indice %d (%d) es: %d \n", (i), arreglo[i], (arreglo[i] * num)); // Muestra en pantalla el resultado de la operacion entre la componente actual del arreglo multiplicada por el numero ingresado
        }
    }
    return;
}
void subarreglo(int arreglo[]) // Se calcula el tamaño del subarreglo con un contador, y despues se le asignan las componentes al subarreglo. Consigna 4
{
    int num;
    subN = 0;
    printf("Ingrese el maximo de las componentes del subarreglo\n");
    scanf("%d", &num);
    for (int i = 0; i < N; i++) // Itera por todos los elementos del arreglo
    {
        if (arreglo[i] < num) // Calcula los componentes menores al numero seleccionado
        {
            subN++; // Cuenta la cantidad de componentes que cumplen con la condicion, se usara para asignar el tamaño del subarreglo
        }
    }
    int subarreglo[subN], i2 = 0; // Se declara el subarreglo con subN elementos y se declara i2 para acomodar las componentes en los indices correspondientes
    for (int i = 0; i < N; i++)   // Itera por todos los elementos del arreglo
    {
        if (arreglo[i] < num) // Calcula los componentes menores al numero seleccionado
        {
            subarreglo[i2] = arreglo[i]; // Asigna las componentes del arreglo que cumplen la condicion al subarreglo
            i2++;
        }
    }
    // La siguiente iteracion no es necesaria, es para comprobar el correcto funcionamiento del algoritmo
    for (int i = 0; i < subN; i++) // Itera por todos los elementos del arreglo
    {
        printf("La componente %d, tiene un valor de: %d\n", (i + 1), subarreglo[i]);
    }
}
int main()
{
    srand(time(NULL));
    int arreglo[N];
    carga(arreglo);          // Se asigna una cantidad aleatoria de componentes con maximo 11 y minimo 1. Consigna 1
    muestra(arreglo);        // Para testear consigna 2
    intercambiador(arreglo); // Consigna 2
    muestra(arreglo);        // Consigna 2
    muestraImpar(arreglo);   // Consigna 3
    subarreglo(arreglo);     // Consigna 4
    return 0;
}