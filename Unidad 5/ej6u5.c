/*Una Empresa Constructora almacena la siguiente información de cada uno de los 110 aspirantes a un nuevo barrio a
construirse: número aspirante, apellido y nombre, cantidad de Integrantes del grupo familiar, cantidad de cuotas e
importe de cuota. El ingreso de la información no posee ningún orden.
Realizar un algoritmo que utilizando subprogramas permita:
1. Emitir un listado con los aspirantes que han pagado más de $ 77.500, indicando apellido y nombre, cantidad de
cuotas e importe total abonado a la empresa.
2. Calcular el importe total recaudado por la empresa.
3. Realizar un listado ordenado alfabéticamente por nombre y apellido, donde se muestren todos los datos del
aspirante.
4. Ingresar un apellido y nombre por teclado y decir si es aspirante o no.*/
#include<stdio.h>
#include<string.h>
const int N = 3;
struct aspirante{
    int num;
    char nombre[100];
    int integrantes;
    int cuotas;
    float importe;
};
void prueba(struct aspirante aspirantes[], int num){
    printf("El numero es %d\n", aspirantes[num].num);
    printf("El nombre es %s\n", aspirantes[num].nombre);
    printf("La cantidad de integrante es %d\n", aspirantes[num].integrantes);
    printf("La cantidad de cuotas es %d\n", aspirantes[num].cuotas);
    printf("El importe de las cuotas es %.2f\n", aspirantes[num].importe);

}
void cargar(struct aspirante aspirantes[]){
    int num;
    printf("Ingrese el numero de aspirante, 0 para detener\n");
    scanf("%d", &num);
    while(num != 0){
        aspirantes[num-1].num = num;
        printf("Ingrese el nombre del aspirante\n");
        fflush(stdin);
        gets(aspirantes[num-1].nombre);
        printf("Ingrese la cantidad de integrantes del grupo familiar\n");
        scanf("%d", &aspirantes[num-1].integrantes);
        printf("Ingrese la cantidad de cuotas\n");
        scanf("%d", &aspirantes[num-1].cuotas);
        printf("Ingrese el importe de las cuotas\n");
        scanf("%f", &aspirantes[num-1].importe);
        printf("Fin de aspirante\n");
        printf("Ingrese el numero de aspirante, 0 para detener\n");
        scanf("%d", &num);
    }
}
void listado(struct aspirante aspirantes[]){
    float total;
    printf("Listado de aspirantes que han pagado un importe total superior a 77500\n");
    for(int i = 0; i < N; i++){
        total = aspirantes[i].importe * aspirantes[i].cuotas;
        if(total> 77500){
            printf("\nNombre: %s, ", aspirantes[i].nombre);
            printf("cantidad de cuotas: %d\n", aspirantes[i].cuotas);
            printf("El importe total abonado es: %f\n\n", total);
        }
    }
    printf("Fin del listado\n\n");
}
float calcular(struct aspirante aspirantes[]){
    float total;
    for(int i = 0; i < N; i++){
        total += (aspirantes[i].cuotas * aspirantes[i].importe);
    }
    return total;
}
void mostrarOrden(struct aspirante aspirantes[]){
    printf("La siguiente lista deberia estar ordenada\n");
    for(int i = 0; i < N; i++){
        printf("%s\n", aspirantes[i].nombre);
    }
}
void ordenar(struct aspirante aspirantes[])
{
    int k = 1, cota;
    struct aspirante aux;
    cota = N - 1;
    while (k != -1)
    {
        k = -1;
        for (int i = 0; i < cota; i++)
        {
            if(strcmp(aspirantes[i].nombre, aspirantes[i+1].nombre) == 1)
            {
                aux = aspirantes[i];
                aspirantes[i] = aspirantes[i + 1];
                aspirantes[i + 1] = aux;
                k = i;
            }
        }
        cota = k;
    }
    //mostrarOrden(aspirantes);
}
void buscar(struct aspirante aspirantes[]){
    int sup, inf, medio;
    sup = N-1;
    inf = 0;
    medio = (inf+sup) / 2;
    char nombre[100];
    printf("Ingrese el nombre del aspirante que desea buscar\n");
    fflush(stdin);
    gets(nombre);
    while((inf <= sup) && (strcmp(nombre, aspirantes[medio].nombre) != 0)){
        if(strcmp(nombre, aspirantes[medio].nombre) == -1){
            sup = medio-1;
        }
        else{
            inf= medio+1;
        }
        medio = (sup+inf) / 2;
    }
    if(inf <= sup){
        printf("El aspirante esta en la lista\n");
    }
    else{
        printf("No se encontro al aspirante");
    }
}
int main(){
    struct aspirante aspirantes[N];
    float importeTotal;
    cargar(aspirantes);
    listado(aspirantes);
    importeTotal = calcular(aspirantes);
    printf("El importe total recaudado por la empresa es %f\n", importeTotal);
    ordenar(aspirantes);
    buscar(aspirantes);
    return 0;
}
/*Lote de prueba
1
Sasso Joaquin
5
10
225.56
2
Castro Elias
3
8
35000.67
3
Reynoso Nicolas
4
6
1568.75

*/