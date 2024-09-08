#include<stdio.h>
void escribir(float pago, int num){
switch (num)
{
case 1:
    printf("La sucursal Zona Centro  debe pagar %.2f\n",pago);
    break;
case 2:
    printf("La sucursal Zona Sur  debe pagar %.2f\n",pago);
    break;
case 3:
    printf("La sucursal Zona Este  debe pagar %.2f\n",pago);
    break;
case 4:
    printf("La sucursal Zona Zona Oeste  debe pagar %.2f\n",pago);
    break;
case 5:
    printf("La sucursal Zona Norte  debe pagar %.2f\n",pago);
    break;

default:  printf("El numero de sucursal no corresponde o la sucursal no existe");
    break;
}
    return;
}
void sucursales(int num, float imp, int fecha, int dia){
    float pago;
    if ((num == 2) || (num == 5)){
        if (dia > fecha){
            pago = imp*1.015;
        }
        else pago = imp;
    }
    else if (dia <= fecha){
        pago = imp-(imp*0.025);
    }
    else pago = imp;
    escribir(pago, num);
    return;
}

int main(){
    int num, dia, fecha;
    float imp;
    for (int i= 1; i <= 5; i++){
        printf("Ingrese el numero de sucursal\n");
        scanf("%d", &num);
        printf("Ingrese el importe\n");
        scanf("%f", &imp);
        printf("Ingrese la fecha de vencimiento\n");
        scanf("%d", &fecha);
        printf("Ingrese el dia de pago\n");
        scanf("%d", &dia);
        sucursales(num, imp, fecha, dia);
    }
        return(5);
}