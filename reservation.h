#ifndef RESERVATION_H
#define RESERVATION_H

#include "client.h"
#include "chambre.h"
#include <memory>  // For smart pointers
#include <string>
#include <iostream>
using namespace std;

class Reservation {
private:
    Client client;
    unique_ptr<Chambre> room;  // Use smart pointer for safer memory management
    string startDate;
    string endDate;
    bool isReserved;

public:
    // Constructor
    Reservation(const Client& c, const Chambre& r, const string& start, const string& end)
        : client(c), startDate(start), endDate(end), isReserved(true) {
        room = make_unique<Chambre>(r);
    }

    // Getters
    string getStartDate() const { return startDate; }
    string getEndDate() const { return endDate; }

    // Methods
    void verifyReservation() const;
    bool addRoom(const Chambre& newRoom);
    void displayReservation() const;
    int calculateDuration() const;
    void displayDuration() const;
    bool removeRoom();
};

#endif // RESERVATION_H
