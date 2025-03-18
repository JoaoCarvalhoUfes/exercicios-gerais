#include "base_alunos.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BaseAlunos
{
    tAluno **alunos;
    int qtdAlunos;
};

/**
 * @brief Função para criar uma nova base de alunos.
 * 
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos* CriarBaseAlunos()
{

    tBaseAlunos *novaBase = (tBaseAlunos *) malloc(sizeof(tBaseAlunos));

    if(novaBase == NULL)
    {
        printf("erro");
        exit(1);
    }

    novaBase->alunos = NULL;
    novaBase->qtdAlunos = 0;

    return novaBase;
}


/**
 * @brief Função para destruir uma base de alunos.
 * 
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos* baseAlunos)
{

    if(baseAlunos != NULL)
    {
        if(baseAlunos->alunos != NULL)
        {
            for(int i = 0; i < baseAlunos->qtdAlunos; i++)
                if(baseAlunos->alunos[i] != NULL)
                {
                    DestruirAluno(baseAlunos->alunos[i]);
                    baseAlunos->alunos[i] = NULL;
                }

        free(baseAlunos->alunos);
        baseAlunos->alunos = NULL;
        }
        free(baseAlunos);
        baseAlunos = NULL;
    }

    return;
}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 * 
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo)
{
    int qtdAlunos;

    FILE *file = fopen(nomeArquivo, "rb");

    fread(&qtdAlunos, sizeof(int), 1, file);

    baseAlunos->qtdAlunos = qtdAlunos;
    baseAlunos->alunos = (tAluno **) malloc (sizeof(tAluno *)*baseAlunos->qtdAlunos);

    for(int i = 0; i < baseAlunos->qtdAlunos; i++)
    {
        baseAlunos->alunos[i] = LeAluno(file);
    }

    fclose(file);

    return;
}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 * 
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos)
{
    float soma = 0;

    for(int i = 0; i < baseAlunos->qtdAlunos ; i++)
    {
        soma += GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);
    }

    return soma/(float)baseAlunos->qtdAlunos;
}
