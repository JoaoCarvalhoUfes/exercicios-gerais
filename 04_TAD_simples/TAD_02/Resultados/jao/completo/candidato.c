#include <stdio.h>
#include "candidato.h"
#include <string.h>

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id)
{
    tCandidato novoCandidato;
    novoCandidato.cargo = cargo;
    novoCandidato.id = id;
    strcpy(novoCandidato.partido, partido);
    strcpy(novoCandidato.nome, nome);
    novoCandidato.votos = 0;

    return novoCandidato;
}

tCandidato LeCandidato()
{

    char nome[50], partido[50], cargo;
    int id, votos;

    scanf(" %[^,], %[^,], %c, %d", nome, partido, &cargo, &id);

    

   tCandidato candidato = CriaCandidato(nome, partido, cargo, id);

   return candidato;

}

int VerificaIdCandidato(tCandidato candidato, int id)
{
    if (candidato.id == id)
        return 1;
    else 
        return 0;
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2)
{
    if(candidato1.id == candidato2.id)
        return 1;
    else 
        return 0;
       
}

char ObtemCargo(tCandidato candidato)
{
    return candidato.cargo;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato)
{
    candidato.votos++;
    return candidato;
}

int ObtemVotos(tCandidato candidato)
{
    return candidato.votos;
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos)
{   
    return ((float)ObtemVotos(candidato)/(float)totalVotos)*100;
}

void ImprimeCandidato (tCandidato candidato, float percentualVotos)
{
    printf("%s (%s), %d voto(s), %.2f%%\n", candidato.nome, candidato.partido, ObtemVotos(candidato), percentualVotos);
}