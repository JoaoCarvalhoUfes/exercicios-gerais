#include "locadora.h"
#include <stdio.h>

tLocadora criarLocadora ()
{
    tLocadora l;
    l.lucro = 0;
    l.numFilmes = 0;
    return l;
}

int verificarFilmeCadastrado (tLocadora locadora, int codigo)
{
    int i;

    for(i = 0; i < locadora.numFilmes; i++)
    {
        if (ehMesmoCodigoFilme(locadora.filme[i], codigo))
            return 1;
    }
    return 0;   
}

tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme)
{
    if (verificarFilmeCadastrado(locadora, obterCodigoFilme(filme)))
    {
        printf("Filme ja cadastrado no estoque\n");
        return locadora;
    }
    
    locadora.filme[locadora.numFilmes] = filme;
    locadora.numFilmes++;
    printf("Filme cadastrado %d - %s\n", obterCodigoFilme(filme), filme.nome);
    return locadora;
}

tLocadora lerCadastroLocadora (tLocadora locadora)
{
    int codigo;

    while(scanf(" %d", &codigo))
    {  
        scanf("%*c");
        locadora = cadastrarFilmeLocadora(locadora, leFilme(codigo));
    }
    
    return locadora;
}

tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos)
{
    int i, j;
    int qtdAlugados = 0,custo = 0;

    for(i = 0; i < quantidadeCodigos; i++)
    {
        int Cadastrado = 0;
        for(j = 0; j < locadora.numFilmes; j++)
            if(ehMesmoCodigoFilme(locadora.filme[j],codigos[i]))
            {
                Cadastrado = 1;
                if(!obterQtdEstoqueFilme(locadora.filme[j]))
                {
                    printf("Filme %d - ", obterCodigoFilme(locadora.filme[j]));
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(" nao disponivel no estoque. Volte mais tarde.");
                    printf("\n");
                    break;
                }
                locadora.filme[j] = alugarFilme(locadora.filme[j]);
                custo += obterValorFilme( locadora.filme[j]);
                qtdAlugados++;
                break;
            }
        if (!Cadastrado)
        {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
        
        
    }
    if(qtdAlugados)
        printf("Total de filmes alugados: %d com custo de R$%d\n", qtdAlugados, custo);

    return locadora;
}

tLocadora lerAluguelLocadora (tLocadora locadora)
{
    int codigos[locadora.numFilmes];
    int numCodigos = 0;
    int custo = 0;

    int codigo;

    while(scanf(" %d", &codigo))
    {  
        scanf("%*c");

        codigos[numCodigos] = codigo;
        numCodigos++;
    }

  
    return alugarFilmesLocadora(locadora, codigos, numCodigos);
}

tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos)
{
    int i, j;

    for(i = 0; i < quantidadeCodigos; i++)
    {
        int Cadastrado = 0;
        for(j = 0; j < locadora.numFilmes; j++)
            if(ehMesmoCodigoFilme(locadora.filme[j],codigos[i]))
            {
                Cadastrado = 1;
                if(!obterQtdAlugadaFilme(locadora.filme[j]))
                {
                    printf("Nao e possivel devolver o ");
                    printf("filme %d - ", obterCodigoFilme(locadora.filme[j]));
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(".\n");
                    break;
                }
                locadora.filme[j] = devolverFilme(locadora.filme[j]);
                locadora.lucro += obterValorFilme(locadora.filme[j]);
                printf("Filme %d - ", obterCodigoFilme(locadora.filme[j]));
                imprimirNomeFilme(locadora.filme[j]);
                printf(" Devolvido!\n");
            }
            if (!Cadastrado)
        {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }

    return locadora;
}

tLocadora lerDevolucaoLocadora (tLocadora locadora)
{
    int codigos[locadora.numFilmes];
    int numCodigos = 0;

    int codigo;

    while(scanf(" %d", &codigo))
    {  
        scanf("%*c");
        codigos[numCodigos] = codigo;
        numCodigos++;
    }
    
    return devolverFilmesLocadora(locadora, codigos, numCodigos);
}

tLocadora ordenarFilmesLocadora (tLocadora locadora)
{
    int i, j;

    for(i = 0; i < locadora.numFilmes ; i++)
        for (j = i+1; j  < locadora.numFilmes; j++)
        {
            if(compararNomesFilmes(locadora.filme[i], locadora.filme[j]) > 0)
            {
                tFilme aux = locadora.filme[i];
                locadora.filme[i] = locadora.filme[j];
                locadora.filme[j] = aux;
            }

        }


    return locadora;
        
}

void consultarEstoqueLocadora (tLocadora locadora)
{
    int i;
    printf("~ESTOQUE~\n");
    for(i = 0; i < locadora.numFilmes; i++)
        printf("%d - %s Fitas em estoque: %d\n", obterCodigoFilme(locadora.filme[i])
        , locadora.filme[i].nome, obterQtdEstoqueFilme(locadora.filme[i]));
    
        
}

void consultarLucroLocadora (tLocadora locadora)
{
    if (locadora.lucro > 0)
        printf("\nLucro total R$%d\n", locadora.lucro);
}