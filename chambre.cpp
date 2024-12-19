#include "chambre.h"
#include <string>
#include <iostream>
#include <ostream>
using namespace std;

void Chambre::ajouterChambre() {
    cout << "Entrer le id de la Chambre: " << endl;
    cin >> idChambre;
    cout << "Entrer le numero du telephone de la Chambre: " << endl;
    cin >> numeroTel;
}


void Chambre::displayChambre() const {
    cout << "Le id de la Chambre: " << idChambre << endl;
    cout << "le numero du telephone de la Chambre: " << numeroTel << endl;
}

bool Chambre::comparer(const Chambre &ch) const {
    return idChambre == ch.idChambre;
}
