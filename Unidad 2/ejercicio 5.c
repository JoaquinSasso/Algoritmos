#include <stdio.h>

float calcularPrecio(float cantidad, float precio_por_litro);
float galonesALitros(float galones);

int main() {
    float galones_vendidos, precio_litro, monto_a_cobrar, litros;
    printf("Ingrese la cantidad de galones vendidos: ");
    scanf("%f", &galones_vendidos);
    printf("Ingrese el precio por litro en pesos: ");
    scanf("%f", &precio_litro);
    litros = galonesALitros(galones_vendidos);
    monto_a_cobrar = calcularPrecio(litros, precio_litro);
    printf("El monto a cobrar es: $%.2f\n", monto_a_cobrar);
    return 0;
}
float galonesALitros(float galones){
    return galones * 0.2642;
}
float calcularPrecio(float cantidad, float precio_por_litro) {
    return cantidad * precio_por_litro;
}