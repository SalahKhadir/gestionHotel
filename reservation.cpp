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
    rooms.push_back(newRoom);
    isReserved = true;
    cout << "Room added successfully." << endl;
    return true;
}

void Reservation::displayReservation() const {
    client.displayClient();
    cout << "Start Date: " << startDate << endl;
    cout << "End Date: " << endDate << endl;
    cout << "Number of rooms: " << rooms.size() << endl;

    if (isReserved && !rooms.empty()) {
        cout << "\nRooms in this reservation:" << endl;
        for (size_t i = 0; i < rooms.size(); ++i) {
            cout << "\nRoom " << (i + 1) << ":" << endl;
            rooms[i].displayChambre();
        }
    } else {
        cout << "No rooms reserved." << endl;
    }
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

bool Reservation::removeRoom(size_t index) {
    if (!isReserved || rooms.empty()) {
        cout << "Error: No rooms are currently reserved." << endl;
        return false;
    }

    if (index >= rooms.size()) {
        cout << "Error: Invalid room index." << endl;
        return false;
    }

    rooms.erase(rooms.begin() + index);
    if (rooms.empty()) {
        isReserved = false;
    }
    cout << "Room has been removed from the reservation." << endl;
    return true;
}
