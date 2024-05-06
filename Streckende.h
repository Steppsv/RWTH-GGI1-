#include "Fahrausnahme.h"

class Streckende : public Fahrausnahme
{
public:
	Streckende(Fahrzeug& Fzg,Weg& weg)
	:Fahrausnahme(Fzg,weg)
	{

	}

	virtual ~Streckende()
	{

	}

	void vBearbeiten() override
	{
		std::cout << "\nStreckende - Ausnahme: Fahrzeug " << p_pFahrzeug.get_p_iID()
				  << " auf dem Weg: " << p_pWeg.get_p_iID() << "\n";
		p_pWeg.vAbgabe(p_pFahrzeug);
		//		p_pWeg.vUmstellen(p_pFahrzeug);
	}
};
