/*Se conoce la información de 6 cursos de capacitación. Se procesa información ordenada por cursos, de cada uno se
ingresa por alumno su edad y sexo (M: mujeres, V: varones).
Construya un algoritmo que usando subprogramas permita:
1. Mostrar la edad promedio de las mujeres y la de varones.
2. Decir el número de curso y edad promedio en donde la cantidad de mujeres es igual a la cantidad de varones.
3. Informar cantidad de cursos en los que la edad promedio de varones y la edad promedio de mujeres coinciden.*/
#include<stdio.h>
const int N = 2;
struct curso{
    int hombres;
    int edadH;
    int mujeres;
    int edadM;
};
void cerear(struct curso curso[]){
    for(int i = 0; i < N; i++){
        curso[i].hombres = 0;
        curso[i].mujeres = 0;
        curso[i].edadH = 0;
        curso[i].edadM = 0;
    }
}
void cargar(struct curso curso[]){
    int edad;
    char genero;
    for(int i = 0; i < N; i++){
        int j = 1;
        printf("Ingrese la edad del estudiante %d del curso %d\n", j, (i+1));
        scanf("%d", &edad);
        while(edad != 0){
            printf("Ingrese el genero del alumno %d del curso %d\n", j, (i+1));
            fflush(stdin);
            scanf("%c", &genero);
            j++;
            if(genero == 'V'){
                curso[i].hombres++;
                curso[i].edadH += edad;
            }
            if(genero == 'M'){
                curso[i].mujeres++;
                curso[i].edadM += edad;
            }
            printf("Ingrese la edad del %d estudiante del curso %d\n", j, (i+1));
            scanf("%d", &edad);
        }
    }
}
void promediar(struct curso curso[]){
    int sumH = 0, cantH = 0;
    int sumM = 0, cantM = 0;
    int promH, promM;
    for(int i = 0; i < N; i++){
        sumH += curso[i].edadH;
        sumM += curso[i].edadM;
        cantH += curso[i].hombres;
        cantM += curso[i].mujeres;
    }
    promH = sumH / cantH;
    promM = sumM / cantM;
    printf("La edad promedio de los hombres es de: %d\n", promH);
    printf("La edad promedio de las mujeres es de: %d\n", promM);
}
void compararCantidad(struct curso curso[]){
    for(int i = 0; i < N; i++){
        if(curso[i].hombres == curso[i].mujeres){
           int promedio = (curso[i].edadH + curso[i].edadM)/(curso[i].hombres + curso[i].mujeres);
            printf("El curso %d tiene la misma cantidad de hombres que de mujeres y su edad promedio es de: %d\n", (i+1), promedio);
        }
    }
}
void compararEdad(struct curso curso[]){
    int cant = 0;
    for(int i = 0; i < N; i++){
        int promH = curso[i].edadH / curso[i].hombres;
        int promM = curso[i].edadM / curso[i].mujeres;
        if(promH == promM){
            cant++;
        }
    }
    printf("En %d cursos los promedios de edad de hombres y mujeres coinciden\n", cant);
}
int main(){
    struct curso curso[N];
    cerear(curso);
    cargar(curso);
    promediar(curso);
    compararCantidad(curso);
    compararEdad(curso);
    return 0;
}