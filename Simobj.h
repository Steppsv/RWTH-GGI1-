#pragma once
#include <iostream>
#include <string>

using namespace std;

extern double dGlobaleZeit;

class Simobj {
private:
	static int p_iMaxID;
protected:
	int p_iID;
	string p_sName;
	double p_dZeit;
	double p_dGesamtZeit = 0.00;

public:
	Simobj();
	//Kopie-Konstruktor erstellt ein neues Obj nach Vorlage der rhs
	Simobj(const Simobj& rhs);

	Simobj(const string giveName);

	virtual ~Simobj();

	virtual void vAusgabe() const;

	virtual ostream& ostreamAusgabe(ostream& out) const;

	virtual string getName() const;

	virtual void vSimulieren();
};

ostream& operator << (ostream& out, const Simobj& so);
