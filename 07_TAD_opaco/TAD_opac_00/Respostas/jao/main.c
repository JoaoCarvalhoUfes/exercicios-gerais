#include "circulo.h"
#include <stdio.h>

int main()
{
    float cx, cy, r, px, py;
    scanf("%f %f %f %f %f", &cx, &cy, &r, &px, &py);

    tCirculo circulo = Circulo_Cria(cx, cy, r);

    tPonto ponto = Pto_Cria(px, py);

    printf("%d", Circulo_Interior(circulo, ponto));

    Circulo_Apaga(circulo);
    Pto_Apaga(ponto);
}