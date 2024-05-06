#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <list>
#include <mutex>
#include <algorithm>
#include <limits>
#include <iomanip>


#include "Simobj.h"
#include "Fahrzeug.h"
#include "Kreuzung.h"
#include "vertagt_liste.h"
#include "Temposlimit.h"

using namespace std;
extern double dGlobaleZeit;

class Fahrzeug;

class Weg : public Simobj
{

public:


double p_dLaenge;

vertagt::VListe<unique_ptr<Fahrzeug>> p_pFahrzeuge;

Tempolimit p_eTempolimit;

bool bUVerbot = 0;

weak_ptr<Weg>p_pRueckWeg;

Weg();

Weg(const string sName, const double dLaenge, Tempolimit eLimit = Tempolimit::Autobahn, bool uVerbot = 0);

virtual ~Weg();
//const Begrenzung eLimit
double vgetTempolimit() const;

virtual ostream& ostreamAusgabe(ostream& out) const;

virtual void vKopf();

void set_Rueckweg(shared_ptr<Weg> rueckweg);

void set_Kreuzung(shared_ptr<Kreuzung> kreuzung);

shared_ptr<Kreuzung> get_Kreuzung() const;

shared_ptr<Weg> get_Rueckweg() const;

double get_p_dLaenge();

int get_p_iID() const;

void vAnnahme(unique_ptr<Fahrzeug> Fzg);

void vAnnahme(unique_ptr<Fahrzeug> Fzg,unsigned int dStartzeitpunkt);

void vAbgabe(const Fahrzeug& Fzg);

void vUmstellen(const Fahrzeug& fahrzeug);

bool operator !=(const Weg& other) const;

virtual void vSimulieren() override;

private:

	weak_ptr<Kreuzung>p_pZielKreuzung;

};
