#pragma once
#include "Simobj.h"
//#include "Fahrzeug.h"
//#include "Weg.h"
#include "Temposlimit.h"

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <random>
#include <list>
#include <string>
#include <mutex>

class Weg;
class Fahrzeug;

class Kreuzung : public Simobj
{
private:
	list<shared_ptr<Weg>> p_pWege;
public:

	double p_dTankstelle;
	Kreuzung(string sName, double dTankvolumen); //Конструкторы
	Kreuzung(const Kreuzung &f)=delete;
	virtual ~Kreuzung();


	void vSimulieren() override;
	static void vVerbinde(string sName, string sRueckName, double dWegLaenge,shared_ptr<Kreuzung> startKreuzung, shared_ptr<Kreuzung> zielKreuzung, Tempolimit dGeschwBegr , bool bUeberholV);


	double dTanken(Fahrzeug& fahrzeug);
	void vAnnahme(unique_ptr<Fahrzeug> fahrzeug);
	double get_Tankstelle();

	shared_ptr<Weg> pZufaelligerWeg(Weg& weg);



};
