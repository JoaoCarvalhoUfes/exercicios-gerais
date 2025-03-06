#include "jogo.h"
#include <stdio.h>
#include <stdlib.h>

struct Jogo
{
    tTabuleiro *Tabuleiro;
    tJogador *jogador_1;
    tJogador *jogador_2;
};

/**
 * Aloca e retorna uma estrutura do tipo tJogo.
 * Se a alocação falhar, o programa é encerrado.
 *
 * @return a estrutura do tipo tJogo alocada.
 */
tJogo *CriaJogo()
{

    printf("entrei na criajogo\n");
    tJogo *j = (tJogo *)malloc(sizeof(tJogo));

    if (!j)
    {
        printf("erro ao alocar memoria");
        exit(1);
    }

    return j;
}

/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 *
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo *jogo)
{
    printf("entrei na comecajogo\n");

    jogo->jogador_1 = CriaJogador(ID_JOGADOR_1);
    jogo->jogador_2 = CriaJogador(ID_JOGADOR_2);
    jogo->Tabuleiro = CriaTabuleiro();

    return;
}

/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 *
 * @param jogo o jogo atual.
 *
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo *jogo)
{
    printf("entrei na acaboujogo\n");
    if (TemPosicaoLivreTabuleiro(jogo->Tabuleiro))
        return 0;
    else
        return 1;
}

/**
 * Verifica se o usuário deseja jogar novamente.
 *
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo()
{
    printf("entrei na Continuajogo\n");
    char escolha;
    scanf(" %c", &escolha);
    printf("%c\n", escolha);

    switch (escolha)
    {
    case 's':
        return 1;
        break;
    case 'n':
        return 0;
        break;

    default:
        return 1;
        break;
    }
}

/**
 * Libera a memória de uma estrutura do tipo tJogo.
 *
 * @param jogo a estrutura do tipo tJogo a ser liberada.
 */
void DestroiJogo(tJogo *jogo)
{
    printf("entrei na destroijogo\n");
    if (jogo)
    {
        DestroiTabuleiro(jogo->Tabuleiro);
        DestroiJogador(jogo->jogador_1);
        DestroiJogador(jogo->jogador_2);

        free(jogo);
        jogo = NULL;
    }

    return;
}
