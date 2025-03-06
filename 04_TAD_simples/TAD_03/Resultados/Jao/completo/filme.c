#include "filme.h"
#include <stdio.h>
#include <string.h>

tFilme criarFilme (char* nome, int codigo, int valor, int quantidade)
{
    tFilme f;

    strcpy(f.nome, nome);
    f.codigo = codigo;
    f.valor = valor;
    f.qtdEstoque = quantidade;
    f.qtdAlugada = 0;

    return f;
}

tFilme leFilme(int codigo)
{

    tFilme f;

    scanf(" %[^,],%d,%d", f.nome, &f.valor, &f.qtdEstoque);
    f.codigo = codigo;
    f.qtdAlugada = 0;

    return f;
}

int obterCodigoFilme (tFilme filme)
{
    return filme.codigo;
}

void imprimirNomeFilme (tFilme filme)
{
    printf("%s", filme.nome);
}

int obterValorFilme (tFilme filme)
{
    return filme.valor;
}

int obterQtdEstoqueFilme (tFilme filme)
{
    return filme.qtdEstoque;
}

int obterQtdAlugadaFilme (tFilme filme)
{
    return filme.qtdAlugada;
}

int ehMesmoCodigoFilme (tFilme filme, int codigo)
{
  
    if(filme.codigo == codigo)
        return 1;
    else
        return 0;
}

tFilme alugarFilme (tFilme filme)
{
    filme.qtdAlugada++;
    filme.qtdEstoque--;
    return filme;
}

tFilme devolverFilme (tFilme filme)
{
    filme.qtdAlugada--;
    filme.qtdEstoque++;
    return filme;
}

int compararNomesFilmes (tFilme filme1, tFilme filme2)
{
    // ordem Alfabetica

    if(strcmp(filme1.nome, filme2.nome) > 0)
        return 1;
    else if(strcmp(filme1.nome, filme2.nome) < 0)
        return -1;
    else
        return 0;
}