#pragma once
#include "Verhalten.h"


using namespace std;
class Fahrzeug;
//class Verhalten;

class Fahren : public Verhalten {
public:

Fahren(Weg& weg);

virtual ~Fahren();

virtual double dStrecke(Fahrzeug& Fzg, double dZeitIntervall) override;




};
