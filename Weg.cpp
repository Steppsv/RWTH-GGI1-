#include "Weg.h"
#include "Fahrausnahme.h"


using namespace std;

Weg::Weg()
:	Simobj()
{
	cout << "ya rodilsa";
	p_dLaenge = 0;
	p_eTempolimit = Tempolimit::Autobahn;
}

Weg::Weg(const string sName, const double dLaenge, Tempolimit eLimit,  bool uVerbot)
:	Simobj(sName)
{            //Begrenzung ist ein Type von Daten. eLimit ist die name von Variable
	p_sName = sName;
	p_dLaenge = dLaenge;
	p_eTempolimit = eLimit;
	bUVerbot = uVerbot;
}

Weg::~Weg()
{

}
//const Begrenzung eLimit
double Weg::vgetTempolimit() const
{
	switch(p_eTempolimit){
	case Tempolimit::Innerorts:
		return 50.00;

	case Tempolimit::Landstrasse:
		return 100.00;

	case Tempolimit::Autobahn:
		return 200000000;

	default:
		return 0.0;
	}
}

void Weg::vKopf()
{
	cout << "ID | " << std::left << std::setw(10) << "Name" << "| "
					<< std::setw(8) << "Laenge" << "| "
					<< std::setw(10) << "Fahrzeuge" << "\n";
}

ostream& Weg::ostreamAusgabe(ostream& out) const
{
	Simobj::ostreamAusgabe(out) << std::left << std::setw(9) << p_dLaenge << " ( ";

	for(auto it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); ++it)
	{
		out << (*it)->getName() << " ";
	}

	cout << " ) ";
	return out;
}

void Weg::set_Rueckweg(shared_ptr<Weg> rueckweg) {
    p_pRueckWeg=rueckweg;
}

void Weg::set_Kreuzung(shared_ptr<Kreuzung> kreuzung) {
	p_pZielKreuzung = kreuzung;
}

double Weg::get_p_dLaenge()
{
	return p_dLaenge;
}

int Weg::get_p_iID() const{
	return p_iID;
}

shared_ptr<Kreuzung> Weg::get_Kreuzung() const
{
	return p_pZielKreuzung.lock();
}

shared_ptr<Weg> Weg::get_Rueckweg() const
{
	return p_pRueckWeg.lock();
}
void Weg::vAnnahme(unique_ptr<Fahrzeug> Fzg)
{
	Fzg->vNeueStrecke(*this);
	p_pFahrzeuge.push_back(move(Fzg));

}

void Weg::vAnnahme(unique_ptr<Fahrzeug> Fzg,unsigned int dStartzeitpunkt)
{
	Fzg->vNeueStrecke(*this,dStartzeitpunkt);
	p_pFahrzeuge.push_front(move(Fzg));
}

void Weg::vAbgabe(const Fahrzeug& Fzg)
{
	auto it = find_if(p_pFahrzeuge.begin(), p_pFahrzeuge.end(), [&](const unique_ptr<Fahrzeug>& ptr){
	return ptr && *ptr == Fzg; });
		if(( it != p_pFahrzeuge.end()) && (get_Kreuzung()))
		{
			unique_ptr<Fahrzeug> removedFahrzeug = move(*it);
			p_pFahrzeuge.erase(it);

			auto zuFW = get_Kreuzung()->pZufaelligerWeg(*this);
			zuFW->vAnnahme(move(removedFahrzeug));
		}
}

void Weg::vSimulieren()
{
	//auto it = p_pFahrzeuge.begin();
	for( auto& it : p_pFahrzeuge)
	{
//auto it_c = p_pFahrzeuge.next(it);

		try
		{
			cout << "\n";
			(it)->vSimulieren();
   			(it)->vAusgabe();
   			(it)->vZeichnen(*this);
		}
		catch (Fahrausnahme& e)
		{
			e.vBearbeiten();
		}

//		it = it_c;
		cout << "\n";
	}
	p_pFahrzeuge.vAktualisieren();
	p_dZeit = dGlobaleZeit;

}

bool Weg::operator !=(const Weg& other) const
{
	return this->get_p_iID() != other.get_p_iID();
}
















