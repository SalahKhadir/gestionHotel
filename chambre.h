#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <string>
using namespace std;

class Chambre {
private:
    int idChambre;
    int numeroTel;

public:
    // Constructor:
    Chambre(int idCh = 0, int T = 0) :
    idChambre(idCh), numeroTel(T) {};

    // Getters:
    int getIdChambre() const {return  idChambre;};
    int getNumeroTel() const {return  numeroTel;};

    // Setters :
    int setTel(int T) { numeroTel = T; return numeroTel; }
    int setIdChambre(int T) { idChambre = T; return idChambre; }

    // Functions:
    void ajouterChambre();
    void displayChambre() const;
    bool comparer(const Chambre &ch) const;
};


#endif //CHAMBRE_H