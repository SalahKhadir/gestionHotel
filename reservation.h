#ifndef RESERVATION_H
#define RESERVATION_H

#include "client.h"
#include "chambre.h"
#include <string>
#include <vector>
using namespace std;

class Reservation {
private:
    int reservationCode;
    Client client;
    vector<Chambre> room;
    string startDate;
    string endDate;
    bool isReserved;

public:
    // Constructor
    Reservation(int code, const Client& c, const Chambre& r, const string& start, const string& end)
        : reservationCode(code), client(c), startDate(start), endDate(end), isReserved(true) {
        room.push_back(r);
    }

    // Getters
    int getReservationCode() const { return reservationCode; }
    string getStartDate() const { return startDate; }
    string getEndDate() const { return endDate; }
    Client getClient() const { return client; }

    // Functions
    void verifyReservation() const;
    bool addRoom(const Chambre& newRoom);
    void displayReservation() const;
    int calculateDuration() const;
    bool removeRoom();
    bool updateReservation(int newCode, const string& newStartDate, const string& newEndDate);

};

#endif // RESERVATION_H
