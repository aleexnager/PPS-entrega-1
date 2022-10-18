#include <stdio.h>

int main(int argc, char *argv[])
{
    /*Comprobacion de la llamada*/
    if (argc != 2)
    {
        printf("ERROR\nFormato esperado: invertir <fichero.txt>\n");
        return 1;
    }

    /*Declaracion de variables y comprobacion de que el fichero se abre correctamente*/
    FILE *f;
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("No se pudo abrir el fichero %s", argv[1]);
        return 1;
    }

    int i, j, k;
    int m = 0; /* int positivo representa filas 1 matriz */
    int n = 0; /* int positivo representa columnas 1 matriz (coincide con num filas 2 matriz)*/
    int p = 0; /* int positivo representa columnas 2 matriz */

    fscanf(f, "%d", &m);
    fscanf(f, "%d", &n);
    fscanf(f, "%d", &p);

    int m1[m][n], m2[n][p], mRes[m][p]; /*matriz 1, matriz 2 y matriz resultado*/

    /*guardamos la matriz 1*/
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            fscanf(f, "%d", &m1[i][j]);
        }
    }

    /*guardamos la matriz 2*/
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < p; ++j)
        {
            fscanf(f, "%d", &m2[i][j]);
        }
    }

    /*multiplicamos las matrices*/
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < p; ++j)
        {
            mRes[i][j] = 0;
            for (k = 0; k < n; ++k)
            {
                mRes[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    /*imprimimos la matriz resultado*/
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < p; ++j)
        {
            printf("%d ", mRes[i][j]);
        }
        printf("\n");
    }

    fclose(f);
    return 0;
}
