#include <stdio.h>
#include "aluno.h"

int main(){

    int qtdAlunos = 0;
    scanf("%d", &qtdAlunos);

    tAluno alunos[qtdAlunos];
    int aprovados[qtdAlunos];


    for(int i = 0; i < qtdAlunos; i++)
    {
        alunos[i] = LeAluno();

        if(VerificaAprovacao(alunos[i]))
            aprovados[i] = 1;
        else
            aprovados[i] = 0;
    }

    for(int i = 0; i < qtdAlunos; i++)
        for(int j = i+1; j < qtdAlunos;j++)
            if(ComparaMatricula(alunos[i], alunos[j]) > 0)
            {
               //trocando os alunos//
                tAluno aux = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = aux;

                //trocando a posicao do array de aprovados

                int aux2 = aprovados[i];
                aprovados[i] = aprovados[j];
                aprovados[j] = aux2;
            }

    for(int i = 0; i < qtdAlunos; i++)
    {
        if(aprovados[i])
            ImprimeAluno(alunos[i]);
    }

    return;

}