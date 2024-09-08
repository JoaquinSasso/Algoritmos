#include<stdio.h>
const int N = 5;
void mostrar(float importes[]) {
    for (int i = 0; i < N; i++) {
        printf("El vendedor %d vendió por un importe de %.2f\n", (i+1), importes[i]);
    }
    return;
}
void mostrarEspecial(float importes[]) {
    float impMin;
    printf("Ingresé el importe mínimo a mostrar\n");
    scanf("%f", &impMin);
    for (int i = 0; i < N; i++) {
        if(importes[i] > impMin) {
            printf("El vendedor %d vendió por un importe de %.2f\n", (i+1), importes[i]);
        }
    }
    return;
}
void cereador(float importes[]) {
    for (int i = 0; i < N; i++) {
        importes[i] = 0;
    }
    return;
}
void carga(float importes[]) {
    int num;
    float imp;
    for (int i = 0; i < N; i++) // Itera por todos los elementos del arreglo
    {
        printf("Ingrese el numero del vendedor\n");
        scanf("%d", &num);
        while(num != 0) {
            printf("Ingrese el importe de venta\n");
            scanf("%f", &imp);
            importes[i] = importes[i] + imp;
            printf("Ingrese el numero del vendedor\n");
            scanf("%d", &num);
        }
        printf("Fin de vendedor %d\n", (i+1));
    }
    return;
}
int main()
{
    float importes[N];
    carga(importes);
    mostrar(importes);
    mostrarEspecial(importes);
    return 0;
}