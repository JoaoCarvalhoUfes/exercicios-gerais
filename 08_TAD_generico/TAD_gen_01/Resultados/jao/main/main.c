#include "tadgen.h"
#include <stdio.h>

main()
{

    int tipo, nElem;

    printf("tad_gen_01\nDigite o tipo e numero de elementos: ");

    scanf("%d %d\n", &tipo, &nElem);

    Type type;
    if (tipo)
        type = INT;
    else
        type = FLOAT;

    tGeneric *gen = CriaGenerico(type, nElem);

    LeGenerico(gen);

    ImprimeGenerico(gen);

    DestroiGenerico(gen);

    return;
}