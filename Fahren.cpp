#include "Fahren.h"
#include "Fahrzeug.h"
#include "Streckende.h"
#include <algorithm>

using namespace std;

Fahren::Fahren(Weg& weg)
:Verhalten(weg)
{

}

Fahren::~Fahren()
{

}

double Fahren::dStrecke(Fahrzeug& aFzg, double dZeitIntervall)
{

	double JGeschw      = aFzg.dGeschwindigkeit();
	double JGStrecke    = aFzg.get_p_dAbschnittStrecke();
	double JTeilstrecke = JGeschw * dZeitIntervall;
	double ToGo;

	ToGo = rWeg.get_p_dLaenge() - JGStrecke - JTeilstrecke;
	if(rWeg.get_p_dLaenge() == JGStrecke)
	{
		throw Streckende(aFzg,rWeg);
	}   if (ToGo < 0)
	{
		return rWeg.get_p_dLaenge() - JGStrecke;
	}
	else return JTeilstrecke;
	//return Verhalten::dStrecke(Fzg, dZeitIntervall);
}
