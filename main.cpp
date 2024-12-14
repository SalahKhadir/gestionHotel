#include <iostream>
#include "client.h"
using namespace std;

int main()
{
    Client c1, c2;

    cout << "Saisie de le premier Client : " << endl;
    c1.setClient();

    cout << "Saisie de la deuxième Client : " << endl;
    c2.setClient();

    cout << "\nAffichage des informations des clients : " << endl;
    c1.displayClient();
    c2.displayClient();
}
