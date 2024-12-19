#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <string>
#include <iostream>
#include <ostream>
using namespace std;

class Chambre {
private:
    int idChambre;
    int numeroTel;

public:
    Chambre(int idCh = 0, int T = 0) : idChambre(idCh), numeroTel(T) {};
    void setChambre();
    void displayChambre();
    bool comparer(const Chambre &ch) const;
};


#endif //CHAMBRE_H
