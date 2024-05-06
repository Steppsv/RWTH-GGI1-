#pragma once
#include "Fahrzeug.h"
#include <iomanip>
#include <iostream>
#include <string>
//не будет снимать скорость если меньше 20 км за раз

class Fahrrad : public Fahrzeug {

	private:



	protected:

	public:

	Fahrrad();

	Fahrrad( std::string giveName,double p_dMG );

	Fahrrad( std::string giveName,double p_dMG , double p_dGeschw);

	virtual ~Fahrrad();

	virtual void vSimulieren() override;

	virtual double dGeschwindigkeit() const override;

	void vZeichnen(const Weg&) const override;

};
