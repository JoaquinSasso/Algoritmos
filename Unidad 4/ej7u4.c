/*Ejercicio 7
Construir un algoritmo que resuelva el siguiente enunciado:
Se cuenta con el número de día y la temperatura registrada a las 16 hs, de cada uno de los 30 días del mes de abril.
1. Almacene esas temperaturas en un arreglo, teniendo en cuenta que el número de día es aleatorio.
2. Imprima las temperaturas registradas en los días impares.
3. Muestre los números de los días donde se registró la menor temperatura.
4. Muestre los números de los días donde se registró la mayor temperatura.
5. Ingrese por teclado dos números de días e intercambie las temperaturas registradas en los mismos.*/
#include <stdio.h>
const int N = 30; //Los dias del mes Abril
void muestraMaxMin(float temp[], int dia[], float maxTemp, float minTemp) //Funcion para calcular los dias con temperaturas maximas y minimas, y mostrarlos en pantalla. Consignas 3 y 4
{
    for (int i = 0; i < N; i++) // Itera por todos los elementos de los arreglos dia y temp
    {
        if (maxTemp == temp[i]) //Comprueba si la temperatura actual es la misma que la maxima
        {
            printf("El dia %d alcanzo la temperatura maxima \n", dia[i]);
        }
        if (minTemp == temp[i]) //Comprueba si la temperatura actual es la misma que la minima
        {
            printf("El dia %d alcanzo la temperatura minima \n", dia[i]);
        }
    }
    return;
}
void carga(float temp[], int dia[]) //Funcion para cargar los datos en el arreglo y calcular los maximos y minimos, Consigna 1
{
    float maxTemp = -50, minTemp = 300;
    for (int i = 0; i < N; i++) // Itera por todos los elementos de los arreglos dia y temp
    {
        printf("Ingrese el dia\n");
        scanf("%d", &dia[i]);
        printf("Ingrese la temperatura del dia a las 16hrs\n");
        scanf("%f", &temp[i]);
        if (maxTemp < temp[i]) // Verifica si la temperatura del dia actual es mayor que la temperatura maxima
        {
            maxTemp = temp[i]; // Actualiza el valor de la temperatura maxima
        }
        if (minTemp > temp[i]) // Verifica si la temperatura del dia actual es menor que la temperatura minima
        {
            minTemp = temp[i]; // Actualiza el valor de la temperatura minima
        }
    }
    muestraMaxMin(temp, dia, maxTemp, minTemp);
    return;
}
void intercambiador(float temp[]) //Intercambia el valor de dos componentes del arreglo a eleccion del usuario. Consigna 5
{
    float tempAux1, tempAux2;
    int dia1, dia2;
    printf("Ingrese el dia que quiere intercambiar\n");
    scanf("%d", &dia1);
    printf("Ingrese el dia por el que quiere intercambiarlo\n");
    scanf("%d", &dia2);
    tempAux1 = temp[dia1]; //Se guarda el valor actual de temp[dia1] en la variable auxiliar tempAux1
    tempAux2 = temp[dia2]; //Se guarda el valor actual de temp[dia2] en la variable auxiliar tempAux2
    temp[dia1] = tempAux2; //Se guarda el valor actual de tempAux2 en la variable temp[dia1], para intercambiar los valores con temp[dia2]
    temp[dia2] = tempAux1; //Se guarda el valor actual de tempAux1 en la variable temp[dia2], para intercambiar los valores con temp[dia1]
    return;
}
void muestraImpar(float temp[], int dia[]) // Muestra el valor de temperatura de los dias impares. Consigna 2
{
    for (int i = 0; i < N; i++) // Itera por todos los elementos de los arreglos dia y temp
    {
        if ((dia[i] % 2) != 0) // Calcula los dias impares, todos los numeros que tienen resto distino de 0 diviendolos en 2
        {
            printf("La temperatura del dia %d fue de: %f \n", dia[i], temp[i]);
        }
    }
    return;
}
int main() //Solo se declaran los arreglos y se invocan los subprogramas
{
    float temp[N]; // Arreglo de temperaturas
    int dia[N]; // Arreglo de dias
    carga(temp, dia);
    muestraImpar(temp, dia);
    intercambiador(temp);
    return 1;
}