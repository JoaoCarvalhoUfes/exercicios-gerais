#include <stdio.h>
#include "eleitor.h"

tEleitor CriaEleitor(int id, int votoP, int votoG)
{
    tEleitor novoEleitor;
    novoEleitor.id = id;
    novoEleitor.votoG = votoG;
    novoEleitor.votoP = votoP;

    return novoEleitor;
}

tEleitor LeEleitor()
{


}