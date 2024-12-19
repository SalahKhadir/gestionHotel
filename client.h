#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <ostream>
using namespace std;

class Client {
private:
    int idClient;
    string nom;
    string prenom;
    string adresse;

public:
    // Constructor:
    Client(int idC = 0, string n = "", string p = "", string a = "") :
    idClient(idC) , nom (n) , prenom(p) , adresse(a) {};

    // Getters:
    int getIdClient() const { return idClient; };
    string getNom() {return nom;};
    string getPrenom() {return prenom;};
    string getAdresse() {return adresse;};

    // Setters :
    void setIdClient(int idC) {idClient = idC;};
    void setNom(string n) {nom = n;};
    void setPrenom(string p) {prenom = p;};
    void setAdresse(string a) {adresse = a;};

    // Functions:
    void ajouterClient();
    void displayClient() const;


};
#endif //CLIENT_H