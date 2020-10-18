#include "professor.h"
#include "integral.h"
#include "horista.h"

using namespace std;

int main()
{
    ProfHorista h1("horista1", 2, 200);
    cout << "Nome: " << h1.getName() << " Salario: " << h1.getSalario() << endl;

    ProfIntegral i1("integral1", 1000);
    cout << "Nome: " << i1.getName() << " Salario: " << i1.getSalario() << endl;

    return 0;
}