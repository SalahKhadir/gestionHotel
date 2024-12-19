#ifndef RESERVATION_H
#define RESERVATION_H

#include <vector>
#include <string>
#include "chambre.h"
#include "client.h"
.
class Reservation {
private:
    int Code;
    int NbrChambres;
    std::vector<Chambre> DonneeChambres;
    Client C;
    std::string EtatReservation;
    Date DateDebutReservation;
    Date DateFinReservation;

public:
    Reservation(int code, int nbrChambres, const std::string& etatReservation, const Client& c, const Date& dateDebutReservation, const Date& dateFinReservation);

    void setCode(int code);
    int getCode() const;

    void setNbrChambres(int nbrChambres);
    int getNbrChambres() const;

    void setDonneeChambres(const std::vector<Chambre>& donneechambres);
    std::vector<Chambre> getDonneeChambres() const;

    void setEtatReservation(const std::string& etatReservation);
    std::string getEtatReservation() const;

    void setDateDebutReservation(const Date& dateDebutReservation);
    Date getDateDebutReservation() const;

    void setDateFinReservation(const Date& dateFinReservation);
    Date getDateFinReservation() const;

    void setClient(const Client& c);
    Client getClient() const;

    void ajoutChambre(const Chambre& ch);
    void afficheReservation() const;
    int calculDureeReservation() const;
    void supprimeChambre(const Chambre& ch);
    void modifierEtatReservation(const std::string& nouvelEtat);
};

#endif // RESERVATION_H
