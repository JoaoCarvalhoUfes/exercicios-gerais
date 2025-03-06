#include "matrizgenerica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct matrizgenerica
{
    void ***matriz;
    int linhas;
    int colunas;
    int numBytesElem;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar uma Matriz de qualquer tipo de dados,
 * desde que esse tipo ocupe determinado número de bytes.
 *
 * @param linhas - Numero de linhas da matriz
 * @param colunas - Numero de colunas da matriz
 * @param numByteElem - Número de Bytes que cada elemento da matriz ocupará
 *
 * @return Um ponteiro para a estrutura que armazena uma matriz genérica
 */
tMatrizGenerica *CriaMatrizGenerica(int linhas, int colunas, int numByteElem)
{
    tMatrizGenerica *matrizgen = (tMatrizGenerica *)malloc(sizeof(tMatrizGenerica));

    if (matrizgen == NULL)
    {
        printf("erro ao alocar memoria matrizgen");
        exit(1);
    }

    matrizgen->colunas = colunas;
    matrizgen->linhas = linhas;
    matrizgen->numBytesElem = numByteElem;

    matrizgen->matriz = (void ***)malloc(matrizgen->linhas * sizeof(void **));

    if (matrizgen->matriz == NULL)
    {
        printf("erro ao alocar memoria matrizgen->matriz");
        exit(1);
    }

    for (int i = 0; i < matrizgen->linhas; i++)
    {
        matrizgen->matriz[i] = (void **)malloc(matrizgen->colunas * sizeof(void *));
        if (matrizgen->matriz[i] == NULL)
        {
            printf("erro ao alocar memoria matrizgen->matriz[%d]", i);
            exit(1);
        }
    }
    for (int i = 0; i < matrizgen->linhas; i++)
        for (int j = 0; j < matrizgen->colunas; j++)
            matrizgen->matriz[i][j] = NULL;

    return matrizgen;
}

/**
 * @brief Libera a memória alocada dinamicamente para uma matriz
 *
 * @param mat - Ponteiro para a matriz a ser liberada
 *
 */
void DestroiMatrizGenerica(tMatrizGenerica *mat)
{
    if (mat != NULL)
    {
        if (mat->matriz != NULL)
        {
            for (int i = 0; i < mat->linhas; i++)
                if (mat->matriz[i] != NULL)
                {

                    for (int j = 0; j < mat->colunas; j++)
                    {
                        if (mat->matriz[i][j] != NULL)
                            free(mat->matriz[i][j]);
                    }
                    free(mat->matriz[i]);
                    mat->matriz[i] = NULL;
                }
            free(mat->matriz);
            mat->matriz = NULL;
        }
        free(mat);
        mat = NULL;
    }

    return;
}

/**
 * @brief Obtém o número de linhas da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos saber o número de linhas
 *
 * @return O número de linhas da matriz
 */
int ObtemNumeroLinhasMatrizGenerica(tMatrizGenerica *mat)
{
    return mat->linhas;
}

/**
 * @brief Obtém o número de colunas da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos saber o número de colunas
 *
 * @return O número de colunas da matriz
 */
int ObtemNumeroColunasMatrizGenerica(tMatrizGenerica *mat)
{
    return mat->colunas;
}

/**
 * @brief Obtém ponteiro para um elemento qualquer da matriz genérica.
 *
 * @param mat - Ponteiro para a matriz que queremos encontrar o elemento na linha e coluna desejada
 * @param linha - Linha que o elemento está
 * @param coluna - Coluna que o elemento está
 *
 * @return Ponteiro para o elemento da matriz que está na linha e coluna passadas como parâmetro
 */
void *ObtemElementoMatrizGenerica(tMatrizGenerica *mat, int linha, int coluna)
{
    return mat->matriz[coluna][linha];
}

/**
 * @brief Atribui um elemento a uma posição de uma matriz.
 *
 * @param mat - Ponteiro para a matriz que queremos atribuir o elemento na linha e coluna desejada
 * @param linha - Linha que o elemento ficará
 * @param coluna - Coluna que o elemento ficará
 * @param *elem - Ponteiro para o elemento que será colocado na matriz (será feita uma cópia)
 *
 * @return Ponteiro para o elemento da matriz que está na linha e coluna passadas como parâmetro
 */
void AtribuiElementoMatrizGenerica(tMatrizGenerica *mat, int linha, int coluna, void *elem)
{

    if (mat->matriz[linha][coluna] != NULL)
        free(mat->matriz[linha][coluna]);

    mat->matriz[linha][coluna] = (void *)malloc(mat->numBytesElem);
    memcpy(mat->matriz[linha][coluna], elem, mat->numBytesElem);

    // mat->matriz[coluna][linha] = elem;

    return;
}

/**
 * @brief Imprime os elementos usando um callback para imprimir o tipo de dados da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos atribuir o elemento na linha e coluna desejada
 * @param imprime_elemento - Ponteiro para a função (callback) que tem a capacidade de imprimir os dados de um elemento desta matriz
 */

void ImprimirMatrizGenerica(tMatrizGenerica *mat, void(imprime_elemento(void *)))
{
    for (int i = 0; i < mat->linhas; i++)
    {
        for (int j = 0; j < mat->colunas; j++)
        {
            imprime_elemento(mat->matriz[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    return;
}

/**
 * @brief Encontra a transposta de uma matriz passada como parâmetro
 *
 * @param mat - A matriz que queremos encontrar a transposta
 *
 * @return Ponteiro para uma nova matriz, igual à transposta da matriz mat
 */
tMatrizGenerica *MatrizTransposta(tMatrizGenerica *mat)
{
    tMatrizGenerica *matTransp = CriaMatrizGenerica(mat->colunas, mat->linhas, mat->numBytesElem);

    for (int i = 0; i < mat->linhas; i++)
    {
        for (int j = 0; j < mat->colunas; j++)
        {
            AtribuiElementoMatrizGenerica(matTransp, j, i, mat->matriz[i][j]);
        }
    }

    return matTransp;
}

/**
 * @brief Calcula e retorna a multiplicação entre duas matrizes
 *
 * @param mat1 - A primeira matriz da multiplicação
 * @param mat2 - A segunda matriz da multiplicação
 * @param numByteTarget - Número de bytes do elemento resultante
 * @param multi_elem - Ponteiro para função (callback) que realiza a multiplicação entre dois elementos do tipo de dados contido na matriz
 * @param soma_elem - Ponteiro para função (callback) que realiza a soma entre dois elementos do tipo de dados contido na matriz
 *
 * @return Ponteiro para uma nova matriz, igual a multiplicação entre mat1 e mat2.
 */
tMatrizGenerica *MultiplicaMatrizes(tMatrizGenerica *mat1, tMatrizGenerica *mat2, int numByteTarget, void *(*multi_elem)(void *, void *), void *(*soma_elem)(void *, void *))
{

    tMatrizGenerica *matMult = CriaMatrizGenerica(mat1->linhas, mat2->colunas, numByteTarget);
    void *prod, *soma;

    for (int i = 0; i < mat1->linhas; i++)
        for (int j = 0; j < mat2->colunas; j++)
            for (int k = 0; k < mat1->colunas; k++)
            {

                prod = multi_elem(mat1->matriz[i][k], mat2->matriz[k][j]);

                if (!k)
                    AtribuiElementoMatrizGenerica(matMult, i, j, prod);
                else
                {
                    soma = soma_elem(matMult->matriz[i][j], prod);
                    AtribuiElementoMatrizGenerica(matMult, i, j, soma);
                    free(soma);
                }
                free(prod);
            }

    return matMult;
}

/**
 * @brief Converte o tipo da matriz
 *
 * @param mat - A matriz que queremos converter para o novo tipo
 * @param novoNumByteElem - Número de bytes do novo tipo da matriz
 * @param converte_elem - Ponteiro para função que tem a capacidade de converter o elemento do tipo original para o novo tipo
 *
 * @return Ponteiro para uma nova matriz, no novo formato
 */
tMatrizGenerica *ConverteTipoMatriz(tMatrizGenerica *mat2, int novoNumByteElem, void *(*converte_elem)(void *))
{
    void *novo;
    tMatrizGenerica *matConvet = CriaMatrizGenerica(mat2->linhas, mat2->colunas, novoNumByteElem);

    for (int i = 0; i < matConvet->linhas; i++)
    {
        for (int j = 0; j < matConvet->colunas; j++)
        {
            novo = converte_elem(mat2->matriz[i][j]);
            AtribuiElementoMatrizGenerica(matConvet, i, j, novo);
            free(novo);
        }
    }

    return matConvet;
}
