#include "tabuleiro.h"
#include <stdio.h>

/**
 * Cria um tabuleiro e retorna o tabuleiro criado.
 * 
 * @return o tabuleiro criado.
 */
tTabuleiro CriaTabuleiro()
{
    tTabuleiro NovoTabuleiro;
    NovoTabuleiro.peca1 = PECA_1;
    NovoTabuleiro.peca2 = PECA_2;
    NovoTabuleiro.pecaVazio = '-';
    
    for(int i = 0; i < TAM_TABULEIRO; i++)
        for(int j = 0; j < TAM_TABULEIRO; j++)
        {
            NovoTabuleiro.posicoes[i][j] = NovoTabuleiro.pecaVazio;
        }

        return NovoTabuleiro;
}


/**
 * Marca uma posição do tabuleiro com a peça do jogador e retorna o tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada x da posição a ser marcada.
 * @param y a coordenada y da posição a ser marcada.
 * 
 * @return o tabuleiro atualizado.
 */
tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y)
{
    char pecaJog;
    switch (peca)
    {
    case 1:
        pecaJog = 'X';
        break;
    case 2:
        pecaJog = '0';
        break;
    default:
        printf("valor da peca invalido");
        break;
    }

    tabuleiro.posicoes[x][y] = pecaJog;

    return tabuleiro;
    
}


/**
 * Verifica se há alguma posição livre no tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se há posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro)
{
    for(int i = 0; i < TAM_TABULEIRO; i++)
        for(int j = 0; j < TAM_TABULEIRO; j++)
        {
            if(tabuleiro.posicoes[i][j] == '-')
                return 1;
        }

    return 0;
}


/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 * 
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * @param peca a peça do jogador (1 ou 2).
 * 
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca)
{
     char pecaJog;
    switch (peca)
    {
    case 1:
        pecaJog = 'X';
        break;
    case 2:
        pecaJog = '0';
        break;
    default:
        printf("valor da peca invalido");
        break;
    }

    if(tabuleiro.posicoes[x][y] == pecaJog)
    {
        return 1;
    }
    return 0;
}


/**
 * Verifica se a posição do tabuleiro está livre.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * 
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y)
{
    if(tabuleiro.posicoes[x][y] == '-')
        return 1;
    else 
        return 0;
}

/**
 * Verifica se a posição do tabuleiro é válida.
 * 
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * @return 1 se a posição é válida, 0 caso contrário.
*/
int EhPosicaoValidaTabuleiro(int x, int y)
{
    if(x < 3 && y < 3 && x >= 0 && y >= 0)
        return 1;
    else   
        return 0;
}


/**
 * Verifica se o tabuleiro está cheio.
 * 
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro tabuleiro)
{
    for(int i = 0; i < TAM_TABULEIRO; i++)
    {
        printf("\t");
        for(int j = 0; j < TAM_TABULEIRO; j++)
        {
            printf("%c", tabuleiro.posicoes[j][i]);
        }
        printf("\n");
    }

}

