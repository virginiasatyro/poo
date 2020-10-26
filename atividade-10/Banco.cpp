#include <iostream>

#include "ContaBancaria.h"

using namespace std;

int main()
{
    int senha = 1234;
    ContaPoupanca minha_poupanca(senha);
    cout << "Numero conta: " << minha_poupanca.get_numeroConta() << endl;
    cout << "Senha: " << minha_poupanca.get_Senha() << endl;
    cout << "Saldo: " << minha_poupanca.get_Saldo() << endl;
    cout << "Taxa rendimento: " << minha_poupanca.get_taxa_rend() << endl;

    double deposito = 1000.00;
    minha_poupanca.deposita(deposito);
    cout << "Saldo: " << minha_poupanca.get_Saldo() << endl;
    cout << "Extrato poupanca: " << endl;
    minha_poupanca.tiraExtrato();

    double saque = 99.99;
    cout << "********************************************************" << endl;
    minha_poupanca.saca(saque);
    cout << "Saldo: " << minha_poupanca.get_Saldo() << endl;
    cout << "Extrato poupanca: " << endl;
    minha_poupanca.tiraExtrato();

    minha_poupanca.saca(saque);
    cout << "Saldo: " << minha_poupanca.get_Saldo() << endl;
    cout << "Extrato poupanca: " << endl;
    minha_poupanca.tiraExtrato();

    // minha_poupanca.deposita(deposito);
    // cout << "Saldo poupanca: " << minha_poupanca.get_Saldo() << endl;
    // cout << "Extrato poupanca: " << endl;
    // minha_poupanca.tiraExtrato();

    // minha_poupanca.saca(saque);
    // cout << "Saldo: " << minha_poupanca.get_Saldo() << endl;
    // cout << "Extrato poupanca: " << endl;
    // minha_poupanca.tiraExtrato();

    int senha2 = 4321;
    ContaCorrente minha_conta(senha2);
    cout << "Numero conta: " << minha_conta.get_numeroConta() << endl;
    cout << "Senha: " << minha_conta.get_Senha() << endl;
    cout << "Saldo: " << minha_conta.get_Saldo() << endl;

    minha_conta.deposita(deposito);
    cout << "Saldo: " << minha_conta.get_Saldo() << endl;
    cout << "Extrato: " << endl;
    minha_conta.tiraExtrato();
    minha_conta.saca(saque);
    cout << "Saldo: " << minha_conta.get_Saldo() << endl;
    cout << "Extrato: " << endl;
    minha_conta.tiraExtrato();

    return 0;
}