#include "conta.h"
#include <stdio.h>


tConta CriaConta(int numero, tUsuario user)
{
    tConta conta;

    conta.saldo = 0;
    conta.user = user;
    conta.numero = numero;

    return conta;
}

void ImprimeConta(tConta conta)
{
    printf("Conta: %d\nSaldo: R$ %.2f\n", conta.numero, conta.saldo);
    ImprimeUsuario(conta.user);

    return;
}

int VerificaConta(tConta conta, int numero)
{
    if(conta.numero == numero)
        return 1;
    else
        return 0;
}

tConta SaqueConta(tConta conta, float valor)
{
    if(valor > conta.saldo)
    {
        printf("Saldo Insuficiente\n");
        return conta;
    }
    conta.saldo -= valor;
    return conta;
}

tConta DepositoConta(tConta conta, float valor)
{
    conta.saldo += valor;
    return conta;
}