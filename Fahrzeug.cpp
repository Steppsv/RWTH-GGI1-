#include <iomanip>
#include <iostream>
#include <string>

#include "Fahrzeug.h"
#include "Fahren.h"
#include "Parken.h"
#include "Weg.h"
#include "Verhalten.h"
#include "Losfahren.h"
#include "Streckende.h"




#define defprl std::cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";


	Fahrzeug::Fahrzeug()
			 :	Simobj()												//Erstellung einer Defoult Konstruktor
			 {
				p_dMaxGeschwindigkeit = 0;
				p_dGesamtStrecke = 0;
				p_dGesamtZeit = 0;
				p_dAbschnittStrecke = 0;
				p_pVerhalten = nullptr;
			 }

	Fahrzeug::Fahrzeug( const std::string sName)
			:	Simobj(sName)												//Erstellung einer Defoult Konstruktor
			{
				p_dMaxGeschwindigkeit = 0;
				p_dGesamtStrecke = 0;
				p_dGesamtZeit = 0;
				p_dAbschnittStrecke = 0;
				p_pVerhalten = nullptr;
			}

	Fahrzeug::Fahrzeug( const std::string sName,double p_dMG)		//Konstruktor mit zwei Parametern
	 	: Simobj(sName)
		{
			  	p_dGeschwindigkeit = p_dMG;
			  	p_dMaxGeschwindigkeit = p_dMG;
			  	p_dGesamtStrecke = 0;
			  	p_dGesamtZeit = 0;
			  	p_dAbschnittStrecke = 0;
			  	p_pVerhalten = nullptr;
		  }

	Fahrzeug::~Fahrzeug(){ //Destruktor
		//std::cout << " DDDD ";
			}

	Fahrzeug::Fahrzeug(const Fahrzeug& rhs)
		: Simobj(rhs)
		{
			p_dMaxGeschwindigkeit = 0;
			p_dGesamtStrecke = 0;
			p_dGesamtZeit = 0;
			//p_dAbschnittStrecke = 0;
			p_pVerhalten = nullptr;
			p_sName = rhs.p_sName + " (K)"; // Copy Konstruktor. Markierung von Nahme mit einen K
			p_dMaxGeschwindigkeit = rhs.p_dMaxGeschwindigkeit;
		}

	void Fahrzeug::vKopf(){
							/* L1=5,L2=7,L3=18,L4=15; Sind freie Plätze zwischen Wörtern. Für erleichterte änderungen an Tabelle */
		std::cout << "\n" << std::left << std::setw(5) << " ID" << std::setw(6) << "Name"      //habe ich sie als variaple genommen
				  << std::right << std::setw(13) << "MaxGeschw" << std::setw(15) << "Gesamtstrecke"
				  << std::setw(18) << "Geschwindigkeit" << std::setw(12) << "Verbrauch" << std::setw(12) << "Tankinhalt"
				  << "\n";
		std::cout << std::setw(5+7+13+15+2+12+12+12+6+5) << std::setfill('-')  << "\n";

		std::cout << std::setfill(' ');

	}

	void Fahrzeug::vAusgabe() const {

		std::cout << std::left  << " " << std::setw(5) << p_iID << std::setw(12) << p_sName
				  << std::right << std::setw(13) << std::fixed << std::setprecision(2) << p_dMaxGeschwindigkeit
				  << std::setw(15) << p_dAbschnittStrecke
				  << std::setw(18) << dGeschwindigkeit() << "\n";
		//std::cout.unsetf(std::ios_base::fixed);
	}

	std::ostream& Fahrzeug::OAusgabe(std::ostream& output) const{
		output << std::left  << " " << std::setw(3) << p_iID << std::setw(12) << p_sName
				  << std::left << std::setw(13) << std::fixed << std::setprecision(2) << p_dMaxGeschwindigkeit
				  << std::setw(15) << p_dAbschnittStrecke
				  << std::setw(18) << dGeschwindigkeit() << "\n";
				  //<< std::setw(L5-3)<< "-" << std::setw(L5) << "-"
		return output;
	}


	std::string Fahrzeug::GetName() const {
		return p_sName;
	}

	double Fahrzeug::GetMG() const {
		return p_dMaxGeschwindigkeit;
	}

	double Fahrzeug::GetGesamtStrecke() const
	{
		return p_dGesamtStrecke;
	}

	double Fahrzeug::get_p_dAbschnittStrecke()
	{
		return p_dAbschnittStrecke;
	}
	int Fahrzeug::get_p_iID() const
	{
		return p_iID;
	}

	double Fahrzeug::get_p_dZeit() const
	{
		return p_dZeit;
	}

	double Fahrzeug::dTanken(double dMenge)
	{
		return 0.0;
	}

void Fahrzeug::vSimulieren(){

	if ( dGlobaleZeit > p_dZeit)
	{
			double ddeltaT = dGlobaleZeit - p_dZeit;

			p_dGesamtZeit += ddeltaT;
			p_dZeit = dGlobaleZeit;

			double dStrecke = p_pVerhalten->dStrecke(*this, ddeltaT);

			p_dAbschnittStrecke += dStrecke;
			p_dGesamtStrecke += dStrecke;
	}
}


double Fahrzeug::dGeschwindigkeit() const
{
	double Begrenzung = p_pVerhalten->rWeg.vgetTempolimit();

	return (Begrenzung<p_dGeschwindigkeit)?Begrenzung:p_dGeschwindigkeit;
}

void Fahrzeug::set_dGeschwindigkeit(double p_dGNeu)
{
	p_dGeschwindigkeit = p_dGNeu;
}

void Fahrzeug::set_p_dZeit(double z)
{
	p_dZeit = z;
}

void Fahrzeug::set_p_dGesamtStrecke(double neuGesStr)
{
	p_dGesamtStrecke = neuGesStr;
}

void Fahrzeug::vNeueStrecke(Weg& weg)
{
	p_pVerhalten.reset();
	p_dAbschnittStrecke = 0.0;
	p_pVerhalten = make_unique<Fahren> (weg);
}

void Fahrzeug::vNeueStrecke(Weg& weg,double dStartzeitpunkt)
{
	p_pVerhalten.reset();
	p_dAbschnittStrecke = 0.0;
	p_pVerhalten = make_unique<Parken> (weg,dStartzeitpunkt);
}

void Fahrzeug::vFahren(Weg& weg) {
	p_pVerhalten.reset();
    p_pVerhalten = make_unique<Fahren>(weg);
    this->vSimulieren();
}


std::ostream& operator<< (std::ostream& output,const Fahrzeug& fahrzeug){
	return fahrzeug.OAusgabe(output);
}

bool Fahrzeug::operator < (const Fahrzeug& Frz2) const{
	return (this->p_dGesamtStrecke < Frz2.p_dGesamtStrecke);
}

void Fahrzeug::vZeichnen(const Weg&) const
{

}

bool Fahrzeug::operator ==(const Fahrzeug& other) const
{
	return this->get_p_iID() == other.get_p_iID();
}

Fahrzeug& Fahrzeug::operator = (const Fahrzeug& Frz3){
	Simobj::operator=(Frz3);
	p_dGesamtStrecke = 0;
	p_dGesamtZeit = 0;
	p_dMaxGeschwindigkeit = Frz3.p_dMaxGeschwindigkeit;
	//p_dAbschnittStrecke = 0;
	//p_pVerhalten = Frz3.p_pVerhalten;
return *this;
}
