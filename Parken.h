#pragma once
#include "Verhalten.h"


using namespace std;
class Fahrzeug;
//class Verhalten;

class Parken : public Verhalten {
public:

Parken(Weg& weg,double dStartzeitpunkt);

virtual ~Parken();

virtual double dStrecke(Fahrzeug& Fzg, double dZeitIntervall) override;

private:
double p_dStartzeitpunkt;
};
