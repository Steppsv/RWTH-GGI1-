#pragma once
#include "Weg.h"
#include "Fahrzeug.h"
#include <stdexcept>
#include <iostream>

class Fahrausnahme : std::exception
{
protected:
	Fahrzeug& p_pFahrzeug;
	Weg& p_pWeg;

public:
	Fahrausnahme(Fahrzeug& Fzg, Weg& weg);

	virtual ~Fahrausnahme();

	virtual void vBearbeiten() = 0;

	Weg& getWeg() const;

};
