#include "Fahrausnahme.h"



Fahrausnahme::Fahrausnahme(Fahrzeug& Fzg, Weg& weg)
:p_pFahrzeug(Fzg),p_pWeg(weg)
{

}

Fahrausnahme::~Fahrausnahme()
{

}

Weg& Fahrausnahme::getWeg() const
{
	return p_pWeg;
}
