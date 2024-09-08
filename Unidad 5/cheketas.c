/*Se cuenta con un arreglo de 4 cheketas, cada cheketa tiene nombre, edad y puntuacion y votos.
Se carga cada cheketa por teclado.
1)Se recolectan los votos del 1 al 10 de todos los integrantes del grupo (cantidad de integrantes desconocida)
2)Se debe calcular el promedio de puntuacion de cada cheketa y ordenar el arreglo de mayor a menor
3)Se debe poder buscar una cheketa por su nombre y que se muestre la promedio de puntuacion
4)Indicar si la cheketa de menor edad coincide con la que tiene mayor puntuacion
5)Registrar si alguna cheketa no tiene votos
*/
#include<stdio.h>
#include<string.h>
const int N = 4;
struct cheketa
{
    char nombre[100];
    int votos;
    int puntuacion;
    int edad;
    int promedio;
};
void cerear(struct cheketa cheketas[]){
    for(int i = 0; i < N; i++){
        cheketas[i].puntuacion = 0;
        cheketas[i].votos = 0;
    }
}
void cargar(struct cheketa cheketas[]){
    for(int i = 0; i < N; i++){
        printf("Ingrese el nombre de la cheketa\n");
        fflush(stdin);
        gets(cheketas[i].nombre);
        printf("Ingrese la edad de la cheketa\n");
        scanf("%d", &cheketas[i].edad);
    }
    return;
}
void votar(struct cheketa cheketas[]){
for(int i = 0; i < N; i++){
    int voto;
    printf("Ingrese los votos de %s, -1 para detener\n", cheketas[i].nombre);
    scanf("%d", &voto);
    while(voto != -1)
    {
        cheketas[i].votos++;
        cheketas[i].puntuacion += voto;
        printf("Ingrese los votos de %s, -1 para detener\n", cheketas[i].nombre);
        scanf("%d", &voto);
    }
    
}
    return;
}
void promediar(struct cheketa cheketas[]){
    for(int i = 0; i < N; i++){
        cheketas[i].promedio = cheketas[i].puntuacion / cheketas[i].votos;
    }
    return;
}
void ordenar(struct cheketa a[]){
    int j;
    char valor[100];
    struct cheketa aux;
    for(int i = 0; i < N; i++){
        j = i - 1;
        aux = a[i];
        strcpy(valor, a[i].nombre);
        while((j >= 0) && (a[j].promedio > valor)){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = aux;
    }
    printf("El siguiente arreglo deberia estar ordenado\n\n");
    for(int i = 0; i < N; i++){
        printf("%s\n", a[i].nombre);
    }
    printf("\n\nFin de la lista\n");
    return;
}
void buscar(struct cheketa cheketas[]){
    int sup = N-1, inf = 0, medio;
    medio = (sup+inf)/2;
    char nombre[100];
    printf("Ingrese el nombre de la cheketa que desea buscar:\n");
    fflush(stdin);
    gets(nombre);
    while ((inf <= sup) && (strcmp(nombre, cheketas[medio].nombre) != 0))
    {
        if(strcmp(nombre, cheketas[medio].nombre) == -1){
            sup = medio-1;
        }
        else{
            inf= medio+1;
        }
        medio = (sup+inf) / 2;
    }
    if(inf <= sup){
        printf("La cheketa esta en la lista\n");
    }
    else{
        printf("La cheketa no esta en la lista\n");
    }
    return;
}
void minMax(struct cheketa cheketas[]){
    int iMax, iMin;
    int minEdad = 999, maxPuntuacion = -1;
    for(int i = 0; i < N; i++){
        if(minEdad > cheketas[i].edad){
            minEdad = cheketas[i].edad;
            iMin = i;
        }
        if(maxPuntuacion > cheketas[i].puntuacion){
            maxPuntuacion = cheketas[i].puntuacion;
            iMax = i;
        }
    }
    if(iMax == iMin){
        printf("La cheketa de menor edad tiene la maxima puntuacion\n");
    }
    else{
        printf("La cheketa de menor edad no tiene la maxima puntuacion\n");
    }
    return;
}
void bandera(struct cheketa cheketas[]){
    int ban = 0;
    for(int i = 0; i < N; i++){
        if(cheketas[i].votos == 0)
        ban = 1;
}
    if(ban == 1){
        printf("Hay alguna cheketa sin votos, incheckeable\n");
    }
    else{
        printf("Todas las cheketas tienen votos, como deberia de ser\n");
    }
}
int main(){
    struct cheketa cheketas[N];
    cerear(cheketas);
    cargar(cheketas);
    votar(cheketas);
    promediar(cheketas);
    ordenar(cheketas);
    buscar(cheketas);
    minMax(cheketas);
    bandera(cheketas);
    return 0;
}
/*Lote de prueba
Candela
17
Martina Rinaldi
19
Yanina Santander
39
Yanina Flores
43
8
7
9
-1
10
10
10
-1
10
5
4
10
9
-1
4
10
10
8
-1
Candela
*/