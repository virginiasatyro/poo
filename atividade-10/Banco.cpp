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
    double saque = 99.99;
    minha_poupanca.saca(saque);
    cout << "Saldo: " << minha_poupanca.get_Saldo() << endl;

    return 0;
}