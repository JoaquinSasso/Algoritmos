#include<stdio.h>
float importeParcial(float imp, int cuotas){
    return (imp*cuotas);
}
float importeTotal(float impP, int cuotas){
float total = impP;
    if ((cuotas == 2) || (cuotas == 3)){
        total = (impP * 0.1) + impP;
    }
    else if ((cuotas == 4) || (cuotas == 5)){
        total = (impP * 0.15) + impP;
    }
    else if (cuotas > 5){
        total = (impP * 0.2) + impP;
    }
    return(total);
}
void clientes(){
    int cuotas;
    float imp;
    for (int i = 1; i <= 35; i++){
        printf("Ingrese la cantidad de cuotas que se adeudan\n");
        scanf("%d", &cuotas);
        printf("Ingrese el importe de cuota\n");
        scanf("%f", &imp);
        printf("La deuda del cliente es de: %.2f\n", importeTotal(importeParcial(imp, cuotas), cuotas));
    }
}

int main(){
clientes();
return 5;
}
/* Bloque de prueba
2
850
5
1000
3
432
1
324
6
233
7
91
6
14
3
45
2
50
2
42
3
67
2
98
7
65
4
63
4
77
3
54
1
23
3
54
4
45
5
67
7
80
12
15
2
45
2
34
5
23
2
34
2
37
2
98
1
32
8
44
7
44
4
32
4
23
2
54
3
28
1
54

*/