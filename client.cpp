#include "client.h"
#include <string>
#include <iostream>
#include <ostream>
using namespace std;


void Client::ajouterClient() {
    cout << "Entrer le id du Client: " << endl;
    cin >> idClient;
    cout << "Entrer le nom du Client: " << endl;
    cin >> nom;
    cout << "Entrer le prenom du Client: " << endl;
    cin >> prenom;
    cout << "Entrer l'adresse du Client: " << endl;
    cin >> adresse;
}


void Client::displayClient() const {
    cout << "Le id du Client: " << idClient << endl;
    cout << "Le nom du Client: " << nom << endl;
    cout << "Le prenom du Client: " << prenom << endl;
    cout << "L'adresse du Client: " << adresse << endl;
}
