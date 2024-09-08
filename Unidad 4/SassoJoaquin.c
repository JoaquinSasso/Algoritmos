// Sasso Rodriguez Joaquin Nicolas Registro: E010-272 DNI: 44991289
#include<stdio.h>
float Proceso(int a, int b){
    float prom;
    prom = ((a+b)/2.0);
    return(prom);
}
void mostrar(float m){
    printf("El resultado es: %f\n", m);
    return;
}
int main(){
    int cant, num1, num2;
    float t = 0;
    cant = 0;
    while (cant <= 1){
        scanf("%d", &num1);
        scanf("%d", &num2);
        if((num1 < 100) && (num2 > 0)){
            t = t + Proceso(num1, num2);
        }
        cant++;
    }
    mostrar(t);
    printf("Sasso Rodriguez Joaquin Nicolas Registro: E010-272 DNI: 44991289");
    return(1);
}