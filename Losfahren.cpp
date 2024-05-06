#include "Losfahren.h"
#include "Weg.h"

	Losfahren::Losfahren(Fahrzeug& Fzg,Weg& weg)
	:Fahrausnahme(Fzg,weg)
	{

	}

	Losfahren::~Losfahren()
	{

	}

	void Losfahren::vBearbeiten()
	{
		cout << "Losfahren-Ausnahme: Fahrzeug " << p_pFahrzeug.get_p_iID()
			 << " Auf dem Weg " << p_pWeg.get_p_iID() << "\n";
		p_pFahrzeug.vFahren(p_pWeg);
		//p_pWeg.vAnnahme(move(p_pWeg.vAbgabe(p_pFahrzeug)));
	}
