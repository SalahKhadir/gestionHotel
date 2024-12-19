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
    room.push_back(newRoom);
    cout << "Room added successfully." << endl;
    return true;
}

void Reservation::displayReservation() const {
    cout << "Reservation Details:" << endl;
    client.displayClient();
    cout << "Start Date: " << startDate << endl;
    cout << "End Date: " << endDate << endl;
    cout << "Reserved Rooms:" << endl;
    cout << "Duree: " << calculateDuration() << "Jours" << endl;
    for (const auto& r : room) {
        r.displayChambre();
    }

    cout << (isReserved ? "Reservation is active." : "No active reservation.") << endl;
}

int Reservation::calculateDuration() const {
    int startDay, startMonth, startYear;
    int endDay, endMonth, endYear;

    sscanf(startDate.c_str(), "%d/%d/%d", &startDay, &startMonth, &startYear);
    sscanf(endDate.c_str(), "%d/%d/%d", &endDay, &endMonth, &endYear);

    int startDays = startYear * 365 + startMonth * 30 + startDay;
    int endDays = endYear * 365 + endMonth * 30 + endDay;

    return endDays - startDays;
}

bool Reservation::removeRoom() {
    if (room.empty()) {
        cout << "Error: No room is currently reserved." << endl;
        return false;
    }
    room.pop_back();
    cout << "Room has been removed from the reservation." << endl;
    return true;
}

bool Reservation::updateReservation(int newCode, const std::string& newStartDate, const std::string& newEndDate) {
    if (newStartDate.empty() || newEndDate.empty()) {
        std::cout << "Error: Start date or end date cannot be empty." << std::endl;
        return false;
    }

    if (newStartDate >= newEndDate) {
        std::cout << "Error: Start date must be earlier than end date." << std::endl;
        return false;
    }

    reservationCode = newCode;
    startDate = newStartDate;
    endDate = newEndDate;

    std::cout << "Reservation has been updated successfully." << std::endl;
    return true;
}
