#include "imagem.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura para representar uma imagem.
 */
struct tImagem
{
    void *valores;
    int L;
    int C;
    Tipo tipo;
};

/**
 * @brief Função para ler uma imagem de um arquivo binário e aloca-la na memória.
 * @param path O caminho para o arquivo de imagem.
 * @return Um ponteiro para a imagem lida. Se houver erro (de leitura ou alocação de memória), a função imprime uma mensagem de erro e termina o programa.
 */
Imagem *LerImagem(const char *caminho)
{
    FILE *file = fopen(caminho, "rb");

    if (!file)
    {
        printf("erro ao ler arquivo");
        exit(1);
    }

    Imagem *novaImagem = (Imagem *)malloc(sizeof(Imagem));

    if (file == NULL || novaImagem == NULL)
    {
        printf("Erro ao alocar memoria");
        exit(1);
    }

    fread(&novaImagem->L, sizeof(int), 1, file);
    fread(&novaImagem->C, sizeof(int), 1, file);
    fread(&novaImagem->tipo, sizeof(int), 1, file);

    int numPixels = novaImagem->C * novaImagem->L;
    if (novaImagem->tipo == INT)
    {
        novaImagem->valores = malloc(numPixels * sizeof(int));
        fread(novaImagem->valores, sizeof(int), numPixels, file);
    }
    else
    {
        novaImagem->valores = malloc(numPixels * sizeof(float));
        fread(novaImagem->valores, sizeof(float), numPixels, file);
    }

    fclose(file);

    return novaImagem;
}

/**
 * @brief Função para destruir uma imagem.
 * @param img A imagem a ser destruída.
 */
void DestruirImagem(Imagem *img)
{

    if (img != NULL)
    {
        if (img->valores != NULL)
        {
            free(img->valores);
            img->valores = NULL;
        }
        free(img);
        img = NULL;
    }

    return;
}

/**
 * @brief Função para obter a altura de uma imagem.
 * @param img A imagem.
 * @return A altura da imagem.
 */
int ObterAlturaImagem(Imagem *img)
{
    return img->L;
}

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img A imagem.
 * @return A largura da imagem.
 */
int ObterLarguraImagem(Imagem *img)
{
    return img->C;
}

/**
 * @brief Função para obter o tipo de uma imagem.
 * @param img A imagem.
 * @return O tipo da imagem.
 */
Tipo ObterTipoImagem(Imagem *img)
{
    return img->tipo;
}

/**
 * @brief Função para obter os dados de uma imagem.
 * @param img A imagem.
 * @return Um ponteiro para os dados da imagem.
 */
void *ObterDadosImagem(Imagem *img)
{
    return img->valores;
}
