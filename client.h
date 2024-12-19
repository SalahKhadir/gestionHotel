#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <iostream>
#include <ostream>
using namespace std;

class Client {
private:
    int idClient;
    string nom;
    string prenom;
    string adresse;

public:
    Client(int idC = 0, string n = "", string p = "", string a = "") :
    idClient(idC) , nom (n) , prenom(p) , adresse(a) {};
    void setClient();
    void displayClient();


};
#endif //CLIENT_H
