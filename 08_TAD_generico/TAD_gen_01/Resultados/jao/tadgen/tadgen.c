#include "tadgen.h"
#include <stdlib.h>
#include <stdio.h>

struct generic
{
    Type tipo;
    float *elementosF;
    int *elementosI;
    int numElementos;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric *CriaGenerico(Type type, int numElem)
{
    tGeneric *novoGen = (tGeneric *)malloc(sizeof(tGeneric));

    novoGen->tipo = type;
    novoGen->numElementos = numElem;

    if (novoGen->tipo == INT)
    {
        novoGen->elementosI = (int *)malloc(numElem * sizeof(int));
        novoGen->elementosF = NULL;
    }
    else
    {
        novoGen->elementosF = (float *)malloc(numElem * sizeof(float));
        novoGen->elementosI = NULL;
    }

    return novoGen;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric *gen)
{

    if (gen != NULL)
    {
        if (gen->elementosF != NULL)
            free(gen->elementosF);
        gen->elementosF = NULL;
        if (gen->elementosI != NULL)
            free(gen->elementosI);
        gen->elementosI = NULL;
        free(gen);
        gen = NULL;
    }

    return;
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric *gen)
{
    printf("\nDigite o vetor:\n");
    for (int i = 0; i < gen->numElementos; i++)
    {
        if (gen->tipo == INT)
        {
            int n;
            scanf("%d ", &n);
            gen->elementosI[i] = n;
        }
        else
        {
            float n;
            scanf("%f ", &n);
            gen->elementosF[i] = n;
        }
    }

    return;
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric *gen)
{

    for (int i = 0; i < gen->numElementos; i++)
    {

        if (gen->tipo == INT)
        {
            printf("%d ", gen->elementosI[i]);
        }
        else
        {
            printf("%.02f ", gen->elementosF[i]);
        }
    }
}
