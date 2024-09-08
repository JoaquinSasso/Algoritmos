#include<stdio.h>
#include<string.h>
int porcentaje(int n1, int n2){
    return((n1*100)/n2);
}
int promedio(int n1, int n2){
    return(n1/n2);
}
void ipv(){
    int dni, cuotas, cont= 0, cont2= 0, cont3= 0;
    float ing, imp, sum= 0, sumc= 0, minIng= 999999999;
    char tipo, nombre[80], minNombre[80], minTipo;
    printf("Ingrese el DNI, ingrese 0 para detener\n");
    scanf("%d", &dni);
    while(dni != 0) {
        printf("Ingrese el nombre del adjudicatario\n");
        fflush(stdin);
        scanf("%[^\n]", nombre);
        printf("Ingrese la cantidad de cuotas adeudadas\n");
        scanf("%d", &cuotas);
        printf("Ingrese el importe de la cuota\n");
        scanf("%f", &imp);
        printf("Ingrese el tipo de operatoria: P para procrear, S para sorteo y A para ampliacion\n");
        scanf(" %c", &tipo);
        printf("Ingrese el Ingreso mensual\n");
        scanf("%f", &ing);
        if (cuotas > 0){
        cont++;
        }
        sum= sum + (cuotas*imp);
        sumc= sumc + cuotas;
         if ((tipo == 'P') && (ing > 10000) && (cuotas == 0)){
            cont2++;
        }
        if ((ing >= 90000) && (ing <= 120000) && (cuotas > 2)){
            cont3++;
        }
        if (minIng > ing){
            minIng = ing;
            strcpy(minNombre, nombre);
            minTipo = tipo;
        }
        printf("Ingrese el DNI, ingrese 0 para detener\n");
        scanf("%d", &dni);
    }
    printf("1) La cantidad de adjudicatarios que adeudan cuotas es de: %d \n", cont);
    printf("2) La cantidad de adjudicatarios por la operatoria de Procrear, con un ingreso mensual superior a los $10000 que no adeudan cuotas es de: %d \n", cont2);
    printf("3) El porcentaje respecto del total que adeudan cuotas, de adjudicatarios por la operatoria de prestamo para ampliacion, con un ingreso mensual comprendido entre $90000 y $120000 que adeudan mas de 2 cuotas es de: %d \n", porcentaje(cont3, cont));
    printf("4) El importe total de dinero adeudado al IPV por los adjudicatarios es de: %2f \n", sum);
    printf("5) La cantidad promedio de cuotas que adeudan los mencionados adjudicatarios es de: %d \n", promedio(sumc, cont));
    printf("6) El adjudicatario de menor ingreso mensual es: %s y su tipo de operatoria es: %c \n", minNombre, minTipo);
    return;
}

int main(){
    ipv();
    return 1;
} 