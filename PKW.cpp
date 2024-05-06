#include "PKW.h"
#include "SimuClient.h"
#include <iomanip>
#include <iostream>
#include <string>


PKW::PKW():Fahrzeug() {

}

PKW::PKW( std::string giveName,double p_dMG,double dVerbrauch):Fahrzeug( giveName , p_dMG ){
	//std::cout << "PKW constructor:\n";
	p_dVerbrauch = dVerbrauch;
	p_dTankvolumen = 55;
	p_dTankinhalt = 0.5 * p_dTankvolumen;
	p_dGeschwindigkeit = p_dMG;
}


PKW::PKW( std::string giveName,double p_dMG,double dVerbrauch,double p_dTnkV):Fahrzeug( giveName , p_dMG ){
	//std::cout << "PKW constructor:\n";
	p_dVerbrauch = dVerbrauch;
	p_dTankvolumen = p_dTnkV;
	p_dTankinhalt = 0.5 * p_dTankvolumen;
	p_dGeschwindigkeit = p_dMG;
}

PKW::PKW(const PKW& Fzg3):
		Fahrzeug(Fzg3)
{
		p_dVerbrauch = Fzg3.p_dVerbrauch;
		p_dTankvolumen = Fzg3.p_dTankvolumen;
		p_dTankinhalt = Fzg3.p_dTankinhalt;

}

PKW::~PKW() {
	//std::cout << "PKW DEconstructed\n";
}

double PKW::dVerbrauch() const
{
	return (p_dGesamtStrecke * p_dVerbrauch / 100);
}


double PKW::dTanken(double dMenge){

	if( (p_dTankvolumen != 0)&& (dMenge != -1.0)){				//if TankVol ist nicht 0,  dMenge < tankVolume nur dann Tanken.

				p_dTankinhalt += dMenge;

		} else {
			dMenge = p_dTankvolumen - p_dTankinhalt;
			p_dTankinhalt = p_dTankvolumen;

		}
	return dMenge;
}

//void PKW::vSimulieren(){
//
//if(!(p_dTankinhalt == 0)){
//	double ddeltaT = dGlobaleZeit - p_dZeit;
//	double dVerbr1 = ((ddeltaT*p_dMaxGeschwindigkeit)/100)*p_dVerbrauch;
//	if(	p_dTankinhalt >= dVerbr1){
//	//std::cout << "Liter geblieben 1: " << p_dTankinhalt<< std::endl;
//
//	} else {
//		 std::cout << "Auto muss getankt werden\n";
//	    //vTanken();
//	}
//	p_dGesamtZeit += ddeltaT;					//Gesamte Zeit des Fahrt
//	p_dGesamtStrecke += (p_dMaxGeschwindigkeit * ddeltaT);	//Gesamte Distanz des Fahrt
//
//
//	p_dTankinhalt -= ((p_dMaxGeschwindigkeit * ddeltaT/100)*p_dVerbrauch);
//	if (p_dTankinhalt < 0)
//		p_dTankinhalt = 0;
//}
//	p_dZeit = dGlobaleZeit;  	//Zeit, zu der das Fahrzeug zuletzt simuliert wurde
//}

void PKW::vSimulieren(){
if(p_dTankinhalt > 0)
{
	double dAbschnittStrecke_C = p_dAbschnittStrecke;
	Fahrzeug::vSimulieren();
	p_dTankinhalt -= (p_dAbschnittStrecke-dAbschnittStrecke_C)/100*p_dVerbrauch;
	if (p_dTankinhalt < 0)
	{
		p_dTankinhalt = 0;
		std::cout << "Auto muss getankt werden\n";
	}
}
}

void PKW::vZeichnen(const Weg&) const
{
	bZeichnePKW(this->p_sName, p_pVerhalten->rWeg.getName(),p_dAbschnittStrecke / p_pVerhalten->rWeg.get_p_dLaenge(),this->p_dGeschwindigkeit, this->p_dTankinhalt);
}


void PKW::vAusgabe() const {
		std::cout << std::left  << " " << std::setw(L1-1) << p_iID << std::setw(L3-3) << p_sName
				  << std::left << std::setw(L2+4) << std::fixed << std::setprecision(2) << p_dMaxGeschwindigkeit << std::setw(L4+1)
				  << p_dAbschnittStrecke << std::setw(L5+6) << dGeschwindigkeit()
				  << std::setw(L5) << dVerbrauch() << std::setw(L5) << p_dTankinhalt
				  << "\n";
		//std::cout.unsetf(std::ios_base::fixed);
}

std::ostream& PKW::OAusgabe(std::ostream& output) const {
	Fahrzeug::OAusgabe(output) << std::setw(L5) << dVerbrauch() << std::setw(L5) << p_dTankinhalt;

	return output;
}

PKW& PKW::operator = (const PKW& Fzg3){
	Fahrzeug::operator=(Fzg3);
	p_dVerbrauch = Fzg3.p_dVerbrauch;
	p_dTankvolumen = Fzg3.p_dTankvolumen;
	p_dTankinhalt = Fzg3.p_dTankinhalt;
	p_dGeschwindigkeit = Fzg3.p_dGeschwindigkeit;
	return *this;
}

