#include "client.h"
#include "chambre.h"
#include "reservation.h"
#include <iostream>
using namespace std;

int main() {
    // Création d'un client avec la méthode ajouterClient
    cout << "=== Création d'un client ===" << endl;
    Client client1;
    client1.ajouterClient();
    client1.displayClient();
    cout << endl;

    // Création d'une chambre avec la méthode ajouterChambre
    cout << "=== Création d'une chambre ===" << endl;
    Chambre chambre1;  // Utilisation du constructeur par défaut
    chambre1.ajouterChambre();  // Appel à la méthode pour entrer les informations de la chambre
    chambre1.displayChambre();  // Affichage des informations de la chambre
    cout << endl;

    // Création interactive d'une réservation
    cout << "=== Création d'une réservation ===" << endl;
    string startDate, endDate;
    cout << "Entrer la date de début de la réservation (jj/mm/aaaa) : ";
    cin >> startDate;
    cout << "Entrer la date de fin de la réservation (jj/mm/aaaa) : ";
    cin >> endDate;

    // Création de la réservation avec les données saisies
    Reservation reservation1(client1, chambre1, startDate, endDate);
    reservation1.displayReservation();  // Affichage des informations de la réservation
    cout << endl;

    // Vérification de la réservation
    cout << "=== Vérification de la réservation ===" << endl;
    reservation1.verifyReservation();
    cout << endl;

    // Calcul de la durée de la réservation
    cout << "=== Calcul de la durée de la réservation ===" << endl;
    reservation1.displayDuration();
    cout << endl;

    // Suppression de la chambre de la réservation
    cout << "=== Suppression de la chambre de la réservation ===" << endl;
    reservation1.removeRoom();
    reservation1.displayReservation();
    cout << endl;

    // Ajout d'une nouvelle chambre
    cout << "=== Ajout d'une nouvelle chambre ===" << endl;
    Chambre chambre2;
    chambre2.ajouterChambre();
    if (reservation1.addRoom(chambre2)) {
        reservation1.displayReservation();
    }
    cout << endl;

    // Création d'un tableau de réservations
    cout << "=== Tableau de réservations ===" << endl;
    Reservation reservations[3] = {
        Reservation(client1, chambre1, "15/12/2024", "20/12/2024"),
        Reservation(client1, chambre2, "21/12/2024", "25/12/2024"),
        Reservation(client1, chambre1, "01/01/2025", "05/01/2025")
    };

    for (int i = 0; i < 3; ++i) {
        cout << "--- Réservation " << i + 1 << " ---" << endl;
        reservations[i].displayReservation();
        cout << endl;
    }

    // Recherche d'une réservation pour un client
    cout << "=== Recherche d'une réservation pour un client ===" << endl;
    bool found = false;
    for (int i = 0; i < 3; ++i) {
        if (reservations[i].getStartDate() == "15/12/2024") {  // Exemple de recherche par date
            cout << "Réservation trouvée:" << endl;
            reservations[i].displayReservation();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Aucune réservation trouvée pour le client." << endl;
    }
    cout << endl;

    // Fin du programme principal
    cout << "=== Fin du test ===" << endl;

    return 0;
}
