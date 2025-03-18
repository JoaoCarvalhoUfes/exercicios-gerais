#include "base_alunos.h"
#include <stdio.h>

int main(){

    char nomeArquivo[100];

    scanf("%s", nomeArquivo);


    tBaseAlunos*base = CriarBaseAlunos();
    LerBaseAlunos(base, nomeArquivo);

    printf("Coeficiente de Rendimento Medio da base de alunos: %.02f", GetCoeficienteRendimentoMedioBaseAlunos(base));

    DestruirBaseAlunos(base);

    return;


}