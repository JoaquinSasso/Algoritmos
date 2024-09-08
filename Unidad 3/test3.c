#include<stdio.h>
void escribir(float sumSector2, int minSector){
    printf("El importe total de sueldos a pagar en el esector 2 es de : %.2f\n", sumSector2);
    printf("El sueldo mas bajo esta en el sector %d\n", minSector);
    return;
}
void salarios(){
    float sueldo, sumSector2 = 0, sumSector1 = 0, minSueldo = 999999999999;
    int sector, minSector;
    printf("Ingrese el sueldo del trabajador, 0 para detener\n");
    scanf("%f", &sueldo);
    while (sueldo != 0){
        printf("Ingrese el sector del trabajador: 1 o 2\n");
        scanf("%d", &sector);
        if (sector == 2){
            sumSector2 = sumSector2 + sueldo;
        }
        else if (sector == 1){
            sumSector1 = sumSector1 + sueldo;
        }  
        if (minSueldo > sueldo){
            minSueldo = sueldo;
            minSector = sector;
        }
        printf("Ingrese el sueldo del trabajador, 0 para detener\n");
        scanf("%f", &sueldo);
    }
    escribir(sumSector2, minSector);
    return;
}
int main(){
    salarios();
    return 5;
}
/*Bloque de prueba
650
1
400
1
302
2
320
2
750
2
120
1
540
1
920
2
290
1
583
2
0

*/