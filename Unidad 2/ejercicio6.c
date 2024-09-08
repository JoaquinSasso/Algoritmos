#include <stdio.h>
float cant_Caract (float xalmac, float xbytes, float xkilobyte)
{
   float Cant_Caracteres;
   Cant_Caracteres = (xalmac * xbytes) / xkilobyte;
   return Cant_Caracteres;
}
int main()
{
   float almac, bytes, kilobyte = 1;
   printf("Ingrese la cantidad\n");
   scanf("%f", &almac);
   printf("Ingrese el multiplo\n");
   scanf("%f", &bytes);
   printf("La cantidad de caracteres que puede almacenar es %.0f\n", cant_Caract(almac, bytes, kilobyte));
   return 0;
}