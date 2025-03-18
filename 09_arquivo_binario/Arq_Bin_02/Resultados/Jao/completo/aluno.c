#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM_NOME 100
#define MAX_TAM_DATA 11
#define MAX_TAM_CURSO 50


struct Aluno
{
    char nome[MAX_TAM_NOME];
    char dataNascimento[MAX_TAM_DATA];
    char curso[MAX_TAM_CURSO];
    float cr;
    int periodo;
};

/**
 * @brief Função para criar um novo aluno.
 * 
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso em que o aluno está matriculado.
 * @param periodo Período do curso em que o aluno está.
 * @param coeficienteRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para o aluno recém-criado. Se houver erro na alocação de memória, o programa é encerrado.
 */
tAluno* CriarAluno(char* nome, char* dataNascimento, char* curso, int periodo, float coeficienteRendimento)
{
    tAluno *novoAluno = (tAluno *) malloc(sizeof(tAluno));

    if( novoAluno == NULL)
    {
        printf("erro");
        exit(1);
    }

    strcpy(novoAluno->nome, nome);
    strcpy(novoAluno->curso, curso);
    strcpy(novoAluno->dataNascimento, dataNascimento);
    novoAluno->cr = coeficienteRendimento;
    novoAluno->periodo = periodo;

    return novoAluno;
}

/**
 * @brief Função para destruir um aluno.
 * 
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno* aluno)
{

    if(aluno != NULL)
    {
        free(aluno);
        aluno = NULL;
    }

    return;
}


/**
 * @brief Função para ler um aluno de um arquivo binário.
 * 
 * @param arquivo_binario O arquivo binário para ler o aluno.
 * @return Um ponteiro para o aluno lido.
 */
tAluno *LeAluno(FILE *arquivo_binario)
{
    char nome[MAX_TAM_NOME];
    char curso[MAX_TAM_CURSO];
    char data[MAX_TAM_DATA];
    float cr;
    int periodo = 0;

    fread(nome, sizeof(char), MAX_TAM_NOME, arquivo_binario);
    fread(data, sizeof(char), MAX_TAM_DATA, arquivo_binario);
    fread(curso, sizeof(char), MAX_TAM_CURSO, arquivo_binario);
    fread(&periodo, sizeof(int), 1, arquivo_binario);
    fread(&cr, sizeof(float), 1, arquivo_binario);


    return CriarAluno(nome, data, curso, periodo, cr);
}

/**
 * @brief Função para obter o coeficiente de rendimento de um aluno.
 * 
 * @param aluno O aluno para obter o coeficiente de rendimento.
 * @return O coeficiente de rendimento do aluno.
 */
float GetCoeficienteRendimentoAluno(tAluno* aluno)
{
    return aluno->cr;
}

