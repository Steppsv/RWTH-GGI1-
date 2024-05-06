#include "Simobj.h"

#include <iomanip>
#include <iostream>

using namespace std;

int Simobj::p_iMaxID = 0;

Simobj::Simobj()
{
	p_sName = "";
	p_iID = ++p_iMaxID;
	p_dZeit = dGlobaleZeit;
}

Simobj::Simobj(const Simobj& rhs)
{
	p_sName = rhs.p_sName + " (K)";
	p_iID = ++p_iMaxID;
	p_dZeit = dGlobaleZeit;
}

Simobj::Simobj(const string giveName)
{
	p_sName = giveName;
	p_iID = ++p_iMaxID;
	p_dZeit = dGlobaleZeit;
}

Simobj::~Simobj()
{

}

void Simobj::vAusgabe() const
{
	std::cout << std::left << " " << std::setw(3)  << p_iID
			  << std::left  << std::setw(10) << p_sName << ": ";
}

ostream& Simobj::ostreamAusgabe(ostream& out) const
{
		  out << std::left << " " << std::setw(3)  << p_iID << " "
			  << std::left  << std::setw(10) << p_sName << ": ";
	return out;
}

string Simobj::getName() const
{
	return p_sName;
}

void Simobj::vSimulieren()
{
	p_dGesamtZeit = dGlobaleZeit;
}






ostream& operator << (ostream& out, const Simobj& so)
{
	return so.ostreamAusgabe(out);
}











