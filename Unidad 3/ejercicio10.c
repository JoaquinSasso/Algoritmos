    #include <stdio.h>
#include <string.h>

int esCultivable(int mes, const char *semilla) {
    int cultivable = 0;
    switch (mes) {
        case 1 ... 3:
            cultivable = (strcmp(semilla, "rosa") == 0);
            break;
        case 4:
            cultivable = (strcmp(semilla, "camelia") == 0);
            break;
        case 5:
            cultivable = (strcmp(semilla, "clavel") == 0);
            break;
        case 6 ... 7:
            cultivable = (strcmp(semilla, "lirio") == 0);
            break;
        case 8:
            cultivable = (strcmp(semilla, "azucena") == 0);
            break;
        case 9 ... 12:
            cultivable = (strcmp(semilla, "dalia") == 0);
            break;
        default:
            printf("Mes no válido\n");
            cultivable = -1;
            break;
    }
    return cultivable;
}

int main() {
    int mes;
    char semilla[10];
    printf("Ingrese el numero del mes: ");
    scanf("%d", &mes);
    printf("Ingrese el nombre de la semilla: ");
    scanf("%s", semilla);
    int cultivable = esCultivable(mes, semilla);
    if (cultivable == 1) {
        printf("La semilla %s se puede cultivar en el mes %d\n", semilla, mes);
    } else if (cultivable == 0) {
        printf("La semilla %s no se puede cultivar en el mes %d\n", semilla, mes);
        printf("Se puede cultivar ");
        switch (mes) {
            case 1 ... 3:
                printf("rosa\n");
                break;
            case 4:
                printf("camelia\n");
                break;
            case 5:
                printf("clavel\n");
                break;
            case 6 ... 7:
                printf("lirio\n");
                break;
            case 8:
                printf("azucena\n");
                break;
            case 9 ... 12:
                printf("dalia\n");
                break;
            default:
                break;
        }
    }
    return 0;
}
