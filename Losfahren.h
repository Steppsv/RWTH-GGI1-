#include "Fahrausnahme.h"

class Losfahren: public Fahrausnahme
{
public:

	Losfahren(Fahrzeug& Fzg,Weg& weg);

	~Losfahren();

	void vBearbeiten() override;
};
