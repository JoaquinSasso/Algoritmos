#include<stdio.h>
void escribir(float carga, char telefono[]){
    printf("El numero de telefono es %s y el importe total acreditado a la recarga es de %.2f\n",telefono, carga);
    return;
}
float recarga(float importe){
    if ((importe >= 200) && (importe <= 700)){
        importe= importe *1.2;
    }
    else if ((importe >= 700) && (importe <= 900)){
        importe= importe *0.5;       
    }
    else if (importe > 700){
        importe = importe * 2;
    }
    return(importe);
}

int main(){
    char telefono[20];
    float importe, carga;
    printf("Ingrese el numero de telefono\n");
    scanf("%s", &telefono);
    printf("Ingrese el importe de la recarga\n");
    scanf("%f", &importe);
    carga= recarga(importe);
    escribir(carga, telefono);
    return 5;
}