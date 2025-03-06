#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>

struct Tabuleiro
{
    char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    char peca_1;
    char peca_2;
    char peca_vazia;
};

/**
 * Aloca e retorna uma estrutura do tipo tTabuleiro.
 * Se a alocação falhar, o programa é encerrado.
 *
 * @return a estrutura do tipo tTabuleiro alocada.
 */
tTabuleiro *CriaTabuleiro()
{
    tTabuleiro *t = (tTabuleiro *)malloc(sizeof(tTabuleiro));
    if (!t)
    {
        printf("erro ao alocar memoria");
        exit(1);
    }

    t->peca_1 = 'X';
    t->peca_2 = '0';
    t->peca_vazia = '-';

    for (int i = 0; i < TAM_TABULEIRO; i++)
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            t->tabuleiro[i][j] = t->peca_vazia;
        }

    return t;
}

/**
 * Libera a memória de uma estrutura do tipo tTabuleiro.
 *
 * @param tabuleiro a estrutura do tipo tTabuleiro a ser liberada.
 */
void DestroiTabuleiro(tTabuleiro *tabuleiro)
{
    if (tabuleiro)
    {
        free(tabuleiro);
        tabuleiro = NULL;
    }

    return;
}

/**
 * Marca uma posição do tabuleiro com a peça do jogador.
 *
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 */
void MarcaPosicaoTabuleiro(tTabuleiro *tabuleiro, int peca, int x, int y)
{
    switch (peca)
    {
    case 1:
        tabuleiro->tabuleiro[x][y] = tabuleiro->peca_1;
        break;
    case 2:
        tabuleiro->tabuleiro[x][y] = tabuleiro->peca_2;
        break;

    default:
        printf("%d - peca invalida\n", peca);
        break;
    }

    return;
}

/**
 * Verifica se há alguma posição livre no tabuleiro.
 *
 * @param tabuleiro o tabuleiro atual.
 *
 * @return 1 se há alguma posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro *tabuleiro)
{
    for (int i = 0; i < TAM_TABULEIRO; i++)
        for (int j = 0; j < TAM_TABULEIRO; j++)
            if (tabuleiro->tabuleiro[i][j] == tabuleiro->peca_vazia)
                return 1;

    return 0;
}

/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 *
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * @param peca a peça do jogador (1 ou 2).
 *
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro *tabuleiro, int x, int y, int peca)
{
    switch (peca)
    {
    case 1:
        if (tabuleiro->tabuleiro[x][y] == tabuleiro->peca_1)
            return 1;
        else
            return 0;
        break;
    case 2:
        if (tabuleiro->tabuleiro[x][y] == tabuleiro->peca_2)
            return 1;
        else
            return 0;
        break;

    default:
        printf("%d - peca invalida\n", peca);
        break;
    }

    printf("Nao entrou em nenhum dos returns");
}

/**
 * Verifica se a posição do tabuleiro está livre.
 *
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 *
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro *tabuleiro, int x, int y)
{
    if (tabuleiro->tabuleiro[x][y] == tabuleiro->peca_vazia)
        return 1;
    else
        return 0;
}

/**
 * Verifica se a posição do tabuleiro é válida.
 *
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 *
 * @return 1 se a posição é válida, 0 caso contrário.
 */
int EhPosicaoValidaTabuleiro(int x, int y)
{
    if (x < 3 && x >= 0 && y < 3 && y >= 0)
        return 1;
    else
        return 0;
}

/**
 * Imprime o tabuleiro.
 *
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro *tabuleiro)
{
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        printf("\t");
        for (int j = 0; j < TAM_TABULEIRO; j++)
            printf("%c", tabuleiro->tabuleiro[j][i]);
        printf("\n");
    }

    return;
}
