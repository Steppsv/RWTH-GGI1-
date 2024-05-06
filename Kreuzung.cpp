#include "Kreuzung.h"
#include "vertagt_liste.h"
#include "Fahrzeug.h"
#include "Weg.h"


Kreuzung::Kreuzung(string sName, double dTankvolumen): Simobj(sName), p_dTankstelle(dTankvolumen){
}

Kreuzung::~Kreuzung() {

}

void Kreuzung::vSimulieren(){

	for (auto& weg : p_pWege) {
	        weg->vSimulieren();
	        cout << *weg << endl;
	    }
}

void Kreuzung::vVerbinde(string sName, string sRueckName, double dWegLaenge, shared_ptr<Kreuzung> startKreuzung, shared_ptr<Kreuzung> zielKreuzung, Tempolimit dGeschwBegr , bool bUeberholV)
{

	auto weg = make_shared<Weg>(sName, dWegLaenge, dGeschwBegr, bUeberholV);
	auto rueckweg = make_shared<Weg>(sRueckName, dWegLaenge, dGeschwBegr, bUeberholV);

	 weg->set_Rueckweg(rueckweg);
	 rueckweg->set_Rueckweg(weg);
	 weg->set_Kreuzung(zielKreuzung);
	 rueckweg->set_Kreuzung(startKreuzung);
	 startKreuzung->p_pWege.push_back(weg);
	 zielKreuzung->p_pWege.push_back(rueckweg);
}

double Kreuzung::dTanken(Fahrzeug& Fzg){
	if(p_dTankstelle > 0)
	return p_dTankstelle -= Fzg.dTanken();
    return 0.0;
}

void Kreuzung::vAnnahme(unique_ptr<Fahrzeug> Fzg){
	dTanken(*Fzg);
	auto ptr = p_pWege.begin();
	ptr->get()->vAnnahme(move(Fzg));

}
shared_ptr<Weg> Kreuzung::pZufaelligerWeg(Weg& weg){

	vector<shared_ptr<Weg>> availableWege;

	for (const auto& wege : weg.get_Kreuzung()->p_pWege) {
			//if ((wege.get() != &weg) && (wege.get() = weg.get_Rueckweg())) {
			if (wege.get()->get_p_iID() != weg.p_pRueckWeg.lock()->get_p_iID()) {
				availableWege.push_back(wege);
			}
	}

	if (availableWege.empty()) {
		std::cerr << "Fehler: Keine verfügbaren Wege außer dem eingehenden Weg." << std::endl;
	        // Hier können Sie je nach Anforderung einen Standardweg zurückgeben oder eine Ausnahme werfen.
	        return weg.get_Rueckweg();
	    }
	// Zufälligen Weg auswählen
	    std::random_device rd;
	    std::mt19937 gen(rd());
	    std::uniform_int_distribution<> dis(0, availableWege.size() - 1);
	    int Zahl = dis(gen);

	    return availableWege[Zahl];
}
double Kreuzung::get_Tankstelle(){
	return p_dTankstelle;
}
