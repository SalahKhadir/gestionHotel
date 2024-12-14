#ifndef RESERVATION_H
#define RESERVATION_H
#include "client.h"
#include "chambre.h"
#include <string>
#include <iostream>
using namespace std;


class Reservation {
private:
    Client client;
    Chambre room;
    string startDate;
    string endDate;

public:
    // Constructor :
    Reservation(const Client& c, Chambre& r, string& start, string& end)
        : client(c), room(r), startDate(start), endDate(end) {};




};


#endif //RESERVATION_H
