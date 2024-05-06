#pragma once
#include "Simobj.h"
#include "Verhalten.h"
//#include "Kreuzung.h"

class Verhalten;
class Weg;

extern double dGlobaleZeit;

class Fahrzeug : public Simobj
{
private:

	static int p_iMaxID;





protected:


	double p_dGesamtStrecke=0.00;
	double p_dGesamtZeit=0.00;
	double p_dGeschwindigkeit = 0;
	double p_dMaxGeschwindigkeit;
	unique_ptr<Verhalten> p_pVerhalten;
	double p_dAbschnittStrecke = 0.00;


	const int L1=5,L2=7,L3=13,L4=15,L5=12;          //vAusgabe und vKopf Distanz zwischen worter
	bool ErMal=1;

public:

	Fahrzeug();						//Erstellung einer Defoult Konstruktor

	Fahrzeug(const Fahrzeug& Frz3);

	Fahrzeug(const std::string sName);

	Fahrzeug(const std::string sName, double p_dMG );	//Konstruktor mit zwei Parametern

	//Fahrzeug( std::string giveName,double p_dMG, double p_dTnkV);

	virtual ~Fahrzeug();

	std::string GetName() const;

	double GetMG() const;

	double GetGesamtStrecke() const;

	double get_p_dAbschnittStrecke();

	int get_p_iID() const;

	double get_p_dZeit() const;

	virtual void vAusgabe() const;

	virtual std::ostream& OAusgabe(std::ostream& output) const;

	static void vKopf();

	virtual double dTanken(double dMenge = -1.0);

	virtual void vSimulieren();

	virtual double dGeschwindigkeit() const;

	void set_dGeschwindigkeit(double p_dGNeu);

	void set_p_dZeit(double z);

	void set_p_dGesamtStrecke(double neuGesStr);

	void vNeueStrecke(Weg& weg);

	void vNeueStrecke(Weg& weg,double dStartzeitpunkt);

	void vFahren(Weg& weg);

	virtual void vZeichnen(const Weg&) const;

	bool operator < (const Fahrzeug& Frz2) const;

	bool operator ==(const Fahrzeug& other) const;

	Fahrzeug& operator = (const Fahrzeug& Frz3);

};

std::ostream& operator<< (std::ostream& output, const Fahrzeug& fahrzeug);
//als parameter erhalten wir nahme von Objekt aus Fahrzeug class
