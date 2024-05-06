#include "Fahrrad.h"
#include "SimuClient.h"
#include <iomanip>
#include <iostream>
#include <string>


Fahrrad::Fahrrad():Fahrzeug() {
	//std::cout << "Fahrrad constructor:\n";
}

Fahrrad::Fahrrad( std::string giveName,double p_dMG):Fahrzeug( giveName , p_dMG ){
	//std::cout << "Fahrrad constructor:\n";

	p_dGeschwindigkeit = p_dMG;
	p_dZeit = dGlobaleZeit;
}

Fahrrad::Fahrrad( std::string giveName,double p_dMG, double p_dGeschw ):Fahrzeug( giveName , p_dMG ){
	//std::cout << "Fahrrad constructor:\n";
	if( p_dMG > p_dGeschw )
	p_dGeschwindigkeit = p_dGeschw;
	else  p_dGeschwindigkeit = p_dMG;
}

Fahrrad::~Fahrrad() {
	//std::cout << "Fahrrad DEconstructed\n";
}

//void Fahrrad::vSimulieren(){                //alte vSimulieren
//			//Wenn wir dieses Fahrt zuerst Simulieren - Global Zeit ist=0 & p_dZeit= Global Zeit
//if(ErMal){
//	p_dZeit = dGlobaleZeit;
//	ErMal=0;
//}
//int n=0;
//
//while(true){
//		double ddeltaT = dGlobaleZeit - p_dZeit;   //Zeit unterschied zwischen letzte simulation und jetzt
//		double ddeltaS = ddeltaT*p_dGeschwindigkeit; //distanz untershied
//		n++; if(n>100) {std::cout << "\n\n\tError endless cycle of simulations\n\n"; break; }
//if(!(ddeltaT==0)){	// wenn simulation 2 time aufgeruft ist - es gibt kein sinn es zu simulieren
//
//		//%20 mit double can man nicht nutzen,also machen wir es selbst
//
//		int Temp = p_dGesamtStrecke/20;
//		double Rest = p_dGesamtStrecke-(Temp*20);//analog zu p_dGesamtStrecke%20 funktion, die kann nich mit double arbeiten
//		double dis_bis_20 = 20-(Rest); //Weg - distanz bis nächste 20km punkt
//
//		if( ddeltaS < dis_bis_20){
//			p_dGesamtStrecke += ddeltaS;	//Gesamte Distanz des Fahrt
//			p_dZeit = dGlobaleZeit;   	//Zeit, zu der das Fahrzeug zuletzt simuliert wurde
//			p_dGesamtZeit += ddeltaT;	//Gesamte Zeit des Fahrt
//			//std::cout << "Distanz ist kleiner als nächste 20 km\n";
//			break;
//		} else {
//			p_dGesamtStrecke += dis_bis_20;
//			p_dZeit += dis_bis_20/ p_dGeschwindigkeit;
//			p_dGeschwindigkeit = dGeschwindigkeit();
//			//std::cout << "Ges.str:" << p_dGesamtStrecke << "speed: "<< p_dGeschwindigkeit<<"\n";	//std::cout << ". ";
//		}
//} else break;
//
//	}
//}

void Fahrrad::vSimulieren(){

		double p_dGesamtStrecke_C = p_dGesamtStrecke;  // copie
		Fahrzeug::vSimulieren();
		double distanz = p_dGesamtStrecke - p_dGesamtStrecke_C;

		double dTemp = p_dGesamtStrecke_C/20;
		int iTemp = dTemp;
		double dis_bis_20 = (dTemp - iTemp) * 20;
		if ( distanz > dis_bis_20 )     //wenn fahrrad fahrt > 20 km => speed down
			p_dGeschwindigkeit = dGeschwindigkeit();
}



double Fahrrad::dGeschwindigkeit() const
{
	if( p_dGeschwindigkeit > p_pVerhalten->rWeg.vgetTempolimit())
		return p_pVerhalten->rWeg.vgetTempolimit();
	if( p_dGeschwindigkeit == 12 )
		return 12;
	if( p_dGeschwindigkeit > 12 ){
		if(p_dGeschwindigkeit*0.9>12)
		return p_dGeschwindigkeit*0.9;
		else return 12;}
	return p_dGeschwindigkeit;
}

void Fahrrad::vZeichnen(const Weg&) const
{
	bZeichneFahrrad(this->p_sName, p_pVerhalten->rWeg.getName(),p_dAbschnittStrecke / p_pVerhalten->rWeg.get_p_dLaenge(),this->p_dGeschwindigkeit);
}
