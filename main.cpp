#include "reservation.h"
#include "client.h"
#include "chambre.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Display the main menu
void afficherMenuPrincipal() {
    cout << "===== Menu principal =====" << endl;
    cout << "1. Menu Client" << endl;
    cout << "2. Menu Chambre" << endl;
    cout << "3. Menu Reservation" << endl;
    cout << "0. Quitter" << endl;
    cout << "Choix: ";
}

// Display the client menu
void afficherMenuClient() {
    cout << "===== Menu Client =====" << endl;
    cout << "1. Ajouter un client" << endl;
    cout << "2. Afficher les informations d'un client" << endl;
    cout << "0. Retour au menu principal" << endl;
    cout << "Choix: ";
}

// Display the room menu
void afficherMenuChambre() {
    cout << "===== Menu Chambre =====" << endl;
    cout << "1. Ajouter une chambre" << endl;
    cout << "2. Afficher les informations d'une chambre" << endl;
    cout << "0. Retour au menu principal" << endl;
    cout << "Choix: ";
}

// Display the reservation menu
void afficherMenuReservation() {
    cout << "===== Menu Reservation =====" << endl;
    cout << "1. Ajouter une reservation" << endl;
    cout << "2. Afficher une reservation" << endl;
    cout << "3. Supprimer une reservation" << endl;
    cout << "4. Modifier une reservation" << endl;
    cout << "0. Retour au menu principal" << endl;
    cout << "Choix: ";
}

int main() {
    vector<Client> clients;
    vector<Chambre> chambres;
    vector<Reservation> reservations;

    bool continuer = true;
    while (continuer) {
        int choixPrincipal;
        afficherMenuPrincipal();
        cin >> choixPrincipal;

        switch (choixPrincipal) {
            case 1: {
                // Client menu
                int choixClient;
                do {
                    afficherMenuClient();
                    cin >> choixClient;

                    if (choixClient == 1) {
                        int id;
                        string nom, prenom, adresse;
                        cout << "ID du client: ";
                        cin >> id;
                        cout << "Nom: ";
                        cin >> nom;
                        cout << "Prenom: ";
                        cin >> prenom;
                        cout << "Adresse: ";
                        cin.ignore();
                        getline(cin, adresse);
                        clients.emplace_back(id, nom, prenom, adresse);
                        cout << "Client ajoute avec succes!" << endl;
                    } else if (choixClient == 2) {
                        // Display client information
                        cout << "ID du client a afficher: ";
                        int id;
                        cin >> id;
                        bool found = false;
                        for (const auto& client : clients) {
                            if (client.getIdClient() == id) {
                                client.displayClient();
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            cout << "Client non trouve!" << endl;
                        }
                    } else if (choixClient != 0) {
                        cout << "Choix inexistant dans le menu Client!" << endl;
                    }
                } while (choixClient != 0);
                break;
            }
            case 2: {
                // Room menu
                int choixChambre;
                do {
                    afficherMenuChambre();
                    cin >> choixChambre;

                    if (choixChambre == 1) {
                        // Add a new room
                        int id, tel;
                        cout << "ID de la chambre: ";
                        cin >> id;
                        cout << "Numero de telephone: ";
                        cin >> tel;
                        chambres.emplace_back(id, tel);
                        cout << "Chambre ajoutee avec succes!" << endl;
                    } else if (choixChambre == 2) {
                        // Display room information
                        cout << "ID de la chambre a afficher: ";
                        int id;
                        cin >> id;
                        bool found = false;
                        for (const auto& chambre : chambres) {
                            if (chambre.getIdChambre() == id) {
                                chambre.displayChambre();
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            cout << "Chambre non trouvee!" << endl;
                        }
                    } else if (choixChambre != 0) {
                        cout << "Choix inexistant dans le menu Chambre!" << endl;
                    }
                } while (choixChambre != 0);
                break;
            }
            case 3: {
    // Reservation menu
    int choixReservation;
    do {
        afficherMenuReservation();
        cin >> choixReservation;

        if (choixReservation == 1) {
            // Add a new reservation
            int reservationCode, idClient, idChambre;
            string startDate, endDate;

            cout << "Code de la reservation: ";
            cin >> reservationCode;

            cout << "ID du client pour la reservation: ";
            cin >> idClient;

            cout << "ID de la chambre pour la reservation: ";
            cin >> idChambre;

            cout << "Date de debut (dd/mm/yyyy): ";
            cin >> startDate;

            cout << "Date de fin (dd/mm/yyyy): ";
            cin >> endDate;

            Client* client = nullptr;
            Chambre* chambre = nullptr;

            for (auto& c : clients) {
                if (c.getIdClient() == idClient) {
                    client = &c;
                    break;
                }
            }

            for (auto& ch : chambres) {
                if (ch.getIdChambre() == idChambre) {
                    chambre = &ch;
                    break;
                }
            }

            if (client && chambre) {
                reservations.emplace_back(reservationCode, *client, *chambre, startDate, endDate);
                cout << "Reservation ajoutee avec succes!" << endl;
            } else {
                cout << "Erreur: Client ou chambre introuvable." << endl;
            }
        } else if (choixReservation == 2) {
            // Display a reservation
            cout << "Code de la reservation a afficher: ";
            int code;
            cin >> code;

            bool found = false;
            for (const auto& reservation : reservations) {
                if (reservation.getReservationCode() == code) {
                    reservation.displayReservation();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Reservation non trouvee!" << endl;
            }
        } else if (choixReservation == 3) {
            // Delete a reservation
            cout << "Code de la reservation a supprimer: ";
            int code;
            cin >> code;

            auto it = remove_if(reservations.begin(), reservations.end(),
                                [code](const Reservation& r) {
                                    return r.getReservationCode() == code;
                                });

            if (it != reservations.end()) {
                reservations.erase(it, reservations.end());
                cout << "Reservation supprimee avec succes!" << endl;
            } else {
                cout << "Reservation non trouvee!" << endl;
            }
        } else if (choixReservation == 4) {
            // Mettre à jour une réservation
            cout << "Code de la reservation à mettre à jour: ";
            int code;
            cin >> code;

            bool found = false;
            for (auto& reservation : reservations) {
                if (reservation.getReservationCode() == code) {
                    found = true;

                    // Demander les nouvelles informations
                    int newCode;
                    string newStartDate, newEndDate;

                    cout << "Nouveau code de reservation: ";
                    cin >> newCode;

                    cout << "Nouvelle date de debut (dd/mm/yyyy): ";
                    cin >> newStartDate;

                    cout << "Nouvelle date de fin (dd/mm/yyyy): ";
                    cin >> newEndDate;

                    // Mise à jour de la réservation
                    if (reservation.updateReservation(newCode, newStartDate, newEndDate)) {
                        cout << "Reservation mise à jour avec succès!" << endl;
                    } else {
                        cout << "Erreur lors de la mise à jour de la reservation." << endl;
                    }
                    break;
                }
            }

            if (!found) {
                cout << "Reservation avec le code donné introuvable." << endl;
            }
        } else if (choixReservation != 0) {
            cout << "Choix inexistant dans le menu Reservation!" << endl;
        }
    } while (choixReservation != 0);
                break;
}
            case 0:
                continuer = false;
                break;
            default:
                cout << "Choix inexistant dans le menu principal!" << endl;
        }
    }

    cout << "Programme termine. Merci d'avoir utilise notre application!" << endl;
    return 0;
}
