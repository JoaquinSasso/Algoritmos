#include<stdio.h>
#include<string.h>
float promedio(int n1, int n2){
    return(n1/n2);
}
int main (){
    int dni, dias, contSinObra= 0, contPacientes= 0;
    float gasto, impTotalObraSocial = 0, gastoTotal = 0, gastoMax = -1, imp;
    char nombre[80], obraSocial;
    printf("Ingrese el DNI, ingrese 0 para detener\n");
    scanf("%d", &dni);
    while(dni != 0) {
        printf("Ingrese el nombre del paciente\n");
        fflush(stdin);
        scanf("%[^\n]", nombre);
        printf("Ingrese la obra social: s si posee, n si no posee\n");
        scanf(" %c", &obraSocial);
        printf("Ingrese la cantidad de dias de internacion\n");
        scanf("%d", &dias);
        printf("Ingrese el gasto diario de internacion\n");
        scanf("%f", &gasto);
        contPacientes++;
        imp = gasto * dias;
        gastoTotal= gastoTotal + imp;
        if (obraSocial == 'n'){
            contSinObra++;
        }
        else if (obraSocial == 's'){
            impTotalObraSocial = impTotalObraSocial + imp;
        }
        if (gastoMax < imp){
            gastoMax= imp;  
        }
        printf("El paciente %s, con DNI: %d debe abonar un importe de gastos por internacion de: $%.2f \n", nombre, dni, imp);
        printf("Ingrese el DNI, ingrese 0 para detener\n");
        scanf("%d", &dni);
    }
    printf("El sanatorio atendio %d pacientes sin obra social\n", contSinObra);
    printf("El importe total que el sanatorio recauda de pacientes con obra social es de: %.2f\n", impTotalObraSocial);
    printf("El monto promedio por afiliado es de: %.2f\n", promedio(gastoTotal, contPacientes));
    printf("El monto maximo pagado por un afiliado es de: %.2f\n", gastoMax);
    return(5);
}
/* Lote de prueba:
35627890
Julio Vallejos
s
13
7800
43239876
Agustina Reyna
n
21
2800
23472832
Martha De La Vega
s
67
8500
36016244
Lionel Messi
s
3
24000
35012834
Angel Di Maria
n
42
7500
0

*/
