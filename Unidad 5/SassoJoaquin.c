#include <stdio.h>
const int N = 4;
struct materias
{
    int matematica;
    int algoritmos;
    int estructura;
};
void cargar(struct materias x[])
{
    int i;
    for(i = 0; i < N; i++)
    {   
        printf("Ingrese la nota de matematica del estudiante %d\n", (i+1));
        scanf("%d", &x[i].matematica);
        printf("Ingrese la nota de algoritmos del estudiante %d\n", (i+1));
        scanf("%d", &x[i].algoritmos);
        printf("Ingrese la nota de estructura del estudiante %d\n", (i+1));
        scanf("%d", &x[i].estructura);
    }
    return;
}
int contar(struct materias xa[])
{
    int i, c;
    float Prom;
    c = 0;
    for (i = 0; i < N; i++)
    {
        Prom = (xa[i].matematica + xa[i].algoritmos + xa[i].estructura) / 3.0;
        if (Prom >= 7)
        {
            printf("Semestre Aprobado con nota: %.2f\n", Prom);
            c = c + 1;
        }
    }
    return(c);
}
void mostrar(struct materias xb[])
{

    int i;
    for (i = 0; i < N; i++)
    {
        if ((xb[i].matematica >= 7) && (xb[i].algoritmos >= 7) && (xb[i].estructura >= 7))
        {
            printf("Estudiante %d aprobo las 3 materias\n", (i + 1));
        }
    }
    return;
}
int main()
{
    struct materias a[N];
    int cant;
    cargar(a);
    cant = contar(a);
    printf("Cantidad de aprobados es: %d\n", cant);
    mostrar(a);
    printf("Sasso Joaquin  DNI:44991289  Registro: E010-272");
    return(0);
}
/*Lote de prueba
7
9
6
8
7
7
5
8
7
5
8
7
*/