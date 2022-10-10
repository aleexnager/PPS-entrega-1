#include <stdio.h>
#define M 1000

int main(int argc, char *argv[])
{

    /*Comprobacion de la llamada*/
    if (argc != 2)
    {
        printf("ERROR\nFormato esperado: invertir <fichero.txt>\n");
        return 1;
    }

    /*Declaracion de variables y comprobacion de que el fichero se abre correctamente*/
    int i, length, a[M];
    char c;

    FILE *f;
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("No se pudo abrir el fichero %s", argv[1]);
        return 1;
    }

    /*Obtención de los numeros, formato e inversion de las cadenas*/
    length = 1;
    while ((c = fgetc(f)) != EOF)
    {   
        /*Comprobamos que inicia en numero*/
        if (c >= '0' && c <= '9')
        {
            a[0] = c - '0';
        }
        else
        {
            length = 0;
        }
        /*Obtenemos numeros (siendo como max M)*/
        for (i = 0; i < M; i++)
        {
            if (fscanf(f, "%d", &a[length]) == 1)
            {
                length++;
            }
        }
        /*Inversion*/
        for (i = length - 1; i >= 0; i--)
        {
            printf("%d ", a[i]);
            if (i == 0)
                printf("\n");
        }
        length = 0;
    }
    fclose(f);
    return 0;
}