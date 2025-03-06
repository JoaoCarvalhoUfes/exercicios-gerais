#include "conta.h"
#include <stdio.h>

int main(){
    int qtdMaxContas, qtdContas = 0, comando = 0, sair = 0;
    scanf("%d", &qtdMaxContas);

    tConta contas[qtdMaxContas];

    int loops = 0;
    while (!sair)
    {
        loops++;
        if(loops > 10)
            break;
        scanf(" %d", &comando);
        int NumConta = -1;

        switch (comando)
            {
            case 0:
                sair = 1;
                break;
            case 1:
                int saque;
                scanf(" %d %d", &NumConta, &saque);
                for(int i = 0; i < qtdContas; i++)
                {
                    if(VerificaConta(contas[i], NumConta))
                        contas[i] = SaqueConta(contas[i], saque);
                }
                break;
            case 2:
                int deposito;
                scanf(" %d %d", &NumConta, &deposito);
                for(int i = 0; i < qtdContas; i++)
                {
                    if(VerificaConta(contas[i], NumConta))
                        contas[i] = DepositoConta(contas[i], deposito);
                }
                break;
            case 3:
                char cpf[15], nome[50];
                scanf(" %s %s %d", nome, cpf, &NumConta);
                tUsuario user = CriaUsuario(nome, cpf);
                tConta conta = CriaConta(NumConta, user);
                contas[qtdContas] = conta;
                qtdContas++;
                break;
            case 4:
                printf("===| Imprimindo Relatorio |===\n");
                for(int i = 0; i < qtdContas; i++)
                {
                    ImprimeConta(contas[i]);
                }
                break;
            default:
                printf("Comando invalido");
                break;
            }
    }
    

    
}