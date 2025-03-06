#include "matrizgenerica.h"
#include "numcomplexo.h"
#include <stdio.h>

void (*imprimeFptr)(void *);

int main()
{
    int exit;

    while (!exit)
    {
        int linhas, colunas, tipo;

        printf("Digite o número de linhas, colunas e o tipo da matriz (0 – inteiro, 1 – float, 2 – double, 3 – char, 4 – número complexo): \n");

        scanf("%d %d %d\n", &linhas, &colunas, &tipo);

        int NumBytes;

        switch (tipo)
        {
        case 0:
            NumBytes = sizeof(int);
            break;
        case 1:
            NumBytes = sizeof(float);
            break;
        case 2:
            NumBytes = sizeof(double);
            break;
        case 3:
            NumBytes = sizeof(char);
            break;
        case 4:
            imprimeFptr = ImprimeNumeroComplexo;
            NumBytes = RetornaNumBytesComplexo();
            break;

        default:
            printf("tipo indefinido\n");
            break;
        }
        tMatrizGenerica *mat = CriaMatrizGenerica(linhas, colunas, NumBytes);

        for (int i = 0; i < linhas; i++)
            for (int j = 0; j < colunas; j++)
            {
                switch (tipo)
                {
                case 0:
                    int inteiro;
                    scanf("%d", &inteiro);
                    AtribuiElementoMatrizGenerica(mat, i, j, &inteiro);
                case 1:
                    float flutuante;
                    scanf("%d", &flutuante);
                    AtribuiElementoMatrizGenerica(mat, i, j, &flutuante);
                    break;
                case 2:
                    double duplo;
                    scanf("%d", &duplo);
                    AtribuiElementoMatrizGenerica(mat, i, j, &duplo);
                    break;
                case 3:
                    char caracter;
                    scanf("%d", &caracter);
                    AtribuiElementoMatrizGenerica(mat, i, j, &caracter);
                    break;
                case 4:
                    float real, imag;
                    scanf("(%f,%f)", &real, &imag);
                    AtribuiElementoMatrizGenerica(mat, i, j, CriaNumComplexo(real, imag));
                    break;

                default:
                    printf("tipo indefinido\n");
                    break;
                }
            }

        while (!exit)
        {
            int command;
            printf("Digite a operação desejada\n");

            printf("1 - Apenas imprimir a matriz\n");
            printf("2 - Converter para o tipo complexo e imprimir\n");
            printf("3 - Calcular e imprimir a multiplicacao da matriz pela sua transposta.\n");

            scanf("%d\n", &command);

            switch (command)
            {
            case 1:
                ImprimirMatrizGenerica(mat, imprimeFptr);
                break;
            case 2:
                ImprimirMatrizGenerica(mat, imprimeFptr);
                break;
            case 3:
                ImprimirMatrizGenerica(mat, imprimeFptr);
                break;

            default:
                break;
            }
        }
    }
}