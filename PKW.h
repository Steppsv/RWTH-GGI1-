#pragma once
#include "Fahrzeug.h"

#include <iomanip>
#include <iostream>
#include <string>

extern double dGlobaleZeit;

class PKW : public Fahrzeug {

	private:



	protected:

	double p_dVerbrauch = 1;
	double p_dTankvolumen = 0;
	double p_dTankinhalt = 0;

	public:

	PKW();

	PKW( std::string giveName,double p_dMG,double dVerbrauch = 1.0);

	PKW( std::string giveName,double p_dMG,double dVerbrauch, double p_dTnkV);

	PKW(const PKW& Fzg3);

	double dVerbrauch() const;

	virtual ~PKW();

	virtual double dTanken(double dMenge = -1.0);

	virtual void vSimulieren() override;

	virtual void vAusgabe() const override;

	virtual void vZeichnen(const Weg&) const override;

	virtual std::ostream& OAusgabe(std::ostream& output) const override;

	PKW& operator = (const PKW& Fzg3);
};
