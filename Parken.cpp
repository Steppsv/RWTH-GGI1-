#include "Parken.h"
#include "Fahrzeug.h"
#include "Fahrausnahme.h"
#include "Losfahren.h"

using namespace std;
//extern double dGlobaleZeit;

Parken::Parken(Weg& weg,double dStartzeitpunkt)
:Verhalten(weg), p_dStartzeitpunkt(dStartzeitpunkt)
{

}

Parken::~Parken()
{

}


double Parken::dStrecke(Fahrzeug& Fzg1, double dZeitIntervall)
{
	if( dGlobaleZeit > p_dStartzeitpunkt )
	{
		Fzg1.set_p_dZeit(p_dStartzeitpunkt);
		throw Losfahren(Fzg1, this->rWeg);

	}
		return 0.0;
}

//global 1.7
//dzint 1.6
//start zeit 1
//answer 0.7
