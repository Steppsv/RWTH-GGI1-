#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <list>
#include "Weg.h"
//#include "Fahrzeug.h"

extern double dGlobaleZeit;
using namespace std;
class Fahrzeug;
class Weg;

class Verhalten
{
public:
	Weg& rWeg;

	Verhalten(Weg& weg);

	virtual ~Verhalten();

	virtual double dStrecke(Fahrzeug& Fzg, double dZeitIntervall) = 0;

};
