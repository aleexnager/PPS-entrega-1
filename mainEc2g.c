#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ec2g.h"

int main(int argc, char *argv[])
{
    /*Comprobacion de la llamada*/
    if (argc != 2)
    {
        printf("ERROR\nFormato esperado: invertir <fichero.txt>\n");
        return 1;
    }

    /*Declaracion de variables y comprobacion de que el fichero se abre correctamente*/
    int cont = 1;
    double a, b, c, px1, px2;

    FILE *f;
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("No se pudo abrir el fichero %s", argv[1]);
        return 1;
    }

    while (!feof(f))
    {
        while (cont != 0)
        {
            fscanf(f, "%lf", &a);
            fscanf(f, "%lf", &b);
            fscanf(f, "%lf", &c);
            cont--;
        }
        cont = 1;
        resolver (a, b, c, &px1, &px2);
        printf("%lf, %lf\n", px1, px2);

    }
    fclose(f);
    return 0;
}