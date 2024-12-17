#include "reservation.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

using namespace std;

void Reservation::verifyReservation() const {
    cout << (isReserved ? "Reserved" : "Not Reserved") << endl;
}

bool Reservation::addRoom(const Chambre& newRoom) {
    if (isReserved) {
        cout << "Error: Room is already reserved." << endl;
        return false;
    }
    room = make_unique<Chambre>(newRoom);
    isReserved = true;
    cout << "Room added successfully." << endl;
    return true;
}

void Reservation::displayReservation() const {
    if (isReserved && room) {
        room->displayChambre();
    }
    client.displayClient();
    cout << "Start Date: " << startDate << endl;
    cout << "End Date: " << endDate << endl;
    cout << (isReserved ? "The room is reserved." : "No room reserved.") << endl;
}

int Reservation::calculateDuration() const {
    tm start = {}, end = {};
    istringstream(startDate) >> get_time(&start, "%d/%m/%Y");
    istringstream(endDate) >> get_time(&end, "%d/%m/%Y");

    time_t start_time = mktime(&start);
    time_t end_time = mktime(&end);

    return static_cast<int>(difftime(end_time, start_time) / (60 * 60 * 24));
}

void Reservation::displayDuration() const {
    cout << "Duration: " << calculateDuration() << " day(s)" << endl;
}

bool Reservation::removeRoom() {
    if (!isReserved || !room) {
        cout << "Error: No room is currently reserved." << endl;
        return false;
    }
    room.reset();
    isReserved = false;
    cout << "Room has been removed from the reservation." << endl;
    return true;
}
