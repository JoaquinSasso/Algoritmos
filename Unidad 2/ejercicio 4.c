#include<stdio.h>

float calculovolumen(float xradio, float xaltura);
float latas(float xvol, float xlt);

int main(){
float altura, radio, volumen, litros, cantidad;
printf("Ingrese la altura de la lata en cm: ");
scanf("%f", &altura);
printf("Ingrese el radio de la lata en cm: ");
scanf("%f", &radio);
printf("Ingrese la cantidad de litros a llenar en la lata: ");
scanf("%f", &litros);
volumen = calculovolumen(radio,altura);
printf("El volumen de la lata es %f cm3\n", volumen);
cantidad = latas(volumen,litros);
printf("Con %f litros se pueden llenar %f latas de %f cm3\n", litros, cantidad, volumen);
return 0;
}

float calculovolumen(float xradio, float xaltura){
float vol = 3.14*(xradio*xradio)*xaltura;
return(vol);
}

float latas(float xvol, float xlt){
float canti = (xlt*1000)/xvol;
return(canti);
}