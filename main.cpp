#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <iomanip>
#include <map>
#include <algorithm>
#include <cmath>
#include <random>

#include "Simobj.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include "Fahrrad.h"
#include "PKW.h"
//#include "SimuClientSocket.h"
#include "SimuClient.h"
//#include "Verhalten.h"
//#include "Fahren.h"
//#include "Parken.h"

using namespace std;

#define NN std::cout << "\n\n";
#define LL std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

double dGlobaleZeit=0;
double dEpsilon = 0.001;
/*2

void vAufgabe_1()
{


	int iAutoSpeed = 60;
	int* iAMS = new int(120);
	// *iAMS = 120;
	std::cout << iAutoSpeed << "\n";
	std::cout << *iAMS << "\n";
	delete iAMS;
	std::cout << *iAMS << "\n\n";      //Es ist leer

	Fahrzeug* Tesla = new Fahrzeug("Model S",280);
	std::cout << "Pointer Fahrzeug: ";
	std::cout << Tesla << std::endl << "Fahrzeug selbst:  |\n"
									<< "                  V\n";
	Fahrzeug::vKopf();
	std::cout << *Tesla;
	delete Tesla;
	NN;

	//Smart pointers erzeugung

		std::shared_ptr<Fahrzeug> Auto1 = std::make_shared<Fahrzeug>("BMW",60);
			std::cout << "Use_count vor Zuweisung: " << Auto1.use_count() << std::endl;
		std::shared_ptr<Fahrzeug> Auto2 = Auto1;
		Fahrzeug::vKopf();
		std::cout << *Auto1 << std::endl;
		std::cout << *Auto2 << std::endl;
			std::cout << "\nUse_count nach Zuweisung: " << Auto2.use_count();
		NN;

		std::unique_ptr<Fahrzeug> Auto3 = std::make_unique<Fahrzeug>("Porsch2",80);
		std::unique_ptr<Fahrzeug> Auto4 = move(Auto3);
		std::cout << "Es ist unmöglich Use_count zu benutzen, denn es ein unique_ptr ist!";
		NN;
		//std::cout << Auto3->GetName() << std::endl;
		std::cout << "Auto 3 ist schon Leer. Da gibt es nur nullptr!" << std::endl;
		std::cout << Auto4->GetName() << std::endl<<std::endl;

		//std::cout << Auto3.use_count() << "\n";
		//std::cout << Auto4.use_count() << "\n\n"; 			cout Nicht möglich, weil unique


		std::vector<std::shared_ptr<Fahrzeug>> sharedV;
		sharedV.push_back(std::move(Auto4));
		sharedV.push_back(Auto1);
		sharedV.push_back(Auto2);


		//Ausgabe von Vector mit 3 elementen, der Shared typ ist///
		for(long long unsigned int i = 0 ; i<sharedV.size() ; i++)
		std::cout << i+1 <<". Vector cout: " << sharedV.at(i)->GetName() << std::endl;
}

void vAufgabe_1a(){

	std::vector<std::unique_ptr<Fahrzeug>> fahrzeuge;

	for( int i = 0 ; i < 2 ; i++ ) {
		std::string FahrzeugN = "";
		double MaxSpeed = 0;
	std::cout << "Enter Fahrzeug Name: " ;
	std::cin  >> FahrzeugN;

	std::cout << "Enter Fahrzeug MaxSpeed: ";
	std::cin  >> MaxSpeed;

	std::unique_ptr<Fahrzeug> DasAuto = std::make_unique<Fahrzeug>(FahrzeugN,MaxSpeed);

	fahrzeuge.push_back(move(DasAuto));

	}

	for( ; dGlobaleZeit < 2 ; dGlobaleZeit+=0.5) {
		Fahrzeug::vKopf();
		for(long long unsigned int i=0 ; i< fahrzeuge.size() ; i++ ){
			fahrzeuge.at(i)->vSimulieren();
			fahrzeuge.at(i)->vSimulieren();
			std::cout << *fahrzeuge.at(i) << std::endl;
		}

	}
}

void vAufgabe_2(){
	int Nf=0,NP=0;
	double dZ=0,di=0;

	std::cout << "\tWie viel Fahrräders möchten Sie erstellen?: ";
	std::cin  >> Nf ;
	std::cout << "\tWie viel PKW möchten Sie erstellen?: ";
	std::cin  >> NP;
	NN;

	std::vector<std::unique_ptr<Fahrzeug>> fahrzeuge;
if(!Nf==0) std::cout << "\tFahrräde\n";
	for( int i=0 ; i < Nf ; i++ ) {
		std::string FahrzeugN; double MaxSpeed;

		std::cout << "Enter Fahrzeug Name: " ;
		std::cin  >> FahrzeugN;
		std::cout << "Enter Fahrzeug MaxSpeed: ";
		std::cin  >> MaxSpeed;

	std::unique_ptr<Fahrrad> fahrrad = std::make_unique<Fahrrad>(FahrzeugN,MaxSpeed);
	fahrzeuge.push_back(move(fahrrad));
	}
if(!NP==0) std::cout << "\tPKW:\n";
	for( int i=0 ; i < NP ; i++ ) {
			std::string FahrzeugN; double MaxSpeed;

			std::cout << "Enter Fahrzeug Name: " ;
			std::cin  >> FahrzeugN;
			std::cout << "Enter Fahrzeug MaxSpeed: ";
			std::cin  >> MaxSpeed;

	std::unique_ptr<PKW> pkw = std::make_unique<PKW>(FahrzeugN,MaxSpeed,1);
	fahrzeuge.push_back(move(pkw));
	} 	//jetzt ist Fahrzeuge vector complet voll

for(dGlobaleZeit = 0 ; dGlobaleZeit <10 ; dGlobaleZeit++){
	Fahrzeug::vKopf();

	dZ += dGlobaleZeit - dZ - 3*di;
	if( dZ >=3 ){
		dZ -= 3; di++;

		for( int i=Nf; i < (Nf+NP) ; i++ ){
			fahrzeuge.at(i)->dTanken();
		}
	}

	for( long long unsigned int i=0 ; i < fahrzeuge.size() ; i++){
		fahrzeuge.at(i)->vSimulieren();
		fahrzeuge.at(i)->vAusgabe();
	}
}
}

void vAufgabe_3(){
	PKW P("BMW",250,5,68);
	Fahrrad F("Yamacha",60);
	Fahrzeug M("Altes Auto",200);
	Fahrzeug O;

	Fahrzeug::vKopf();
	std::cout << P << std::endl << F << std::endl << M << std::endl;
NN;
	for( ; dGlobaleZeit<4 ; dGlobaleZeit++){
		P.vSimulieren(); F.vSimulieren(); M.vSimulieren();
		Fahrzeug::vKopf();
		std::cout << P << std::endl << F << std::endl << M << std::endl;
	}
NN;
	std::cout << "Hat BMW weiter als Altes Auto gefahren?: " << (M<P) << std::endl;

	O = M;

	std::cout << "Ein Copy ist gemacht: \n";

	Fahrzeug::vKopf();

	std::cout << M << std::endl << O << std::endl;

}
*/
void vAufgabe_4()
{
	Weg Road("Road 66",100,Tempolimit::Autobahn);
	NN;

	Road.vKopf();
	cout << Road;
}

void vAufgabe_5()
{
	cout << "vAufgabe_5\n";

	unique_ptr<Fahrzeug> F1 = make_unique<Fahrzeug> ("BMW",100);
	unique_ptr<Fahrzeug> F2 = make_unique<Fahrzeug> ("Tesla",250);
	unique_ptr<Fahrzeug> F3 = make_unique<Fahrzeug> ("BMX",25);

	Weg Road("Road66",1000,Tempolimit::Autobahn);
	Road.vAnnahme(move(F1));
	Road.vAnnahme(move(F2),1);
	Road.vAnnahme(move(F3));

	Road.vKopf();
	cout << Road << "\n";

	Fahrzeug::vKopf();
	Road.vSimulieren();
	dGlobaleZeit++;
	Fahrzeug::vKopf();
	Road.vSimulieren();
	dGlobaleZeit++;

}

void vAufgabe_6()
{
	bInitialisiereGrafik(800, 500);
	cout << "vAufgabe_6\n";

	int f[4] = { 700, 250, 100, 350 };
	bInitialisiereGrafik(800, 500);
	bZeichneStrasse( "wegH", "wegR", 25, 2, f );
	    unique_ptr<PKW>      F1 = make_unique<PKW> ("BMW",50);
		unique_ptr<PKW>      F2 = make_unique<PKW> ("Tesla",80);
		unique_ptr<Fahrrad>  F3 = make_unique<Fahrrad> ("BMX",10);

		Weg wegH("wegH", 500, Tempolimit::Autobahn, 0);
		Weg wegR("wegR", 500, Tempolimit::Landstrasse, 0);


		wegH.vKopf();
		wegH.vAnnahme(move(F1));
		wegH.vAnnahme(move(F2),3);
		wegR.vAnnahme(move(F3));

		for(dGlobaleZeit = 0; dGlobaleZeit < 50; dGlobaleZeit++)
		{

			cout << std::endl << "		Simulations Zeit: " << dGlobaleZeit << "Stunden\n" << std::endl;
			cout << wegH << std::endl;
			cout << wegR << std::endl;
			Fahrzeug::vKopf();
			wegH.vSimulieren();
			wegR.vSimulieren();

			vSetzeZeit((double)dGlobaleZeit);
			vSleep(100);
			LL;
		}

}

int ZufZahl(){
	static std::mt19937 device(0);
	std::uniform_int_distribution<int> dist(1, 10);
	return dist(device);
}

void vAufgabe_6a(){

	vertagt::VListe <int> vListe;

	for (int i = 0; i < 10; ++i) {
		vListe.push_back(ZufZahl());
	}
vListe.vAktualisieren();
	// Liste vor den Aktionen ausgeben
	cout << "Liste vor den Aktionen:" << endl;

	for (const auto& Zahl : vListe) {
		cout << Zahl << " ";
	}

	cout << endl;


	for(auto it = vListe.begin() ; it != vListe.end() ; it++) {
		if (*it > 5) {
			vListe.erase(it);
		}
	}

     // Liste nach dem Löschen ausgeben (sollte die gleiche Ausgabe wie vorher sein)

     std::cout << "Liste nach dem Löschen (ohne vAktualisieren()):" << std::endl;
     for (const auto& Zahl : vListe) {
    	 std::cout << Zahl << " ";
     	 }
     std::cout << std::endl;

     // vAktualisieren() auf die Liste anwenden
vListe.vAktualisieren();


     // Liste nach dem Aktualisieren ausgeben (sollte sich geändert haben)
     std::cout << "Liste nach dem Aktualisieren:" << std::endl;
     for (const auto& Zahl : vListe) {
         std::cout << Zahl << " ";
     }
     std::cout << std::endl;

     // Am Anfang und am Ende der Liste zwei beliebige (verschiedene) Zahlen einfügen
     for(int i = 0 ; i<=1 ; i++){
     vListe.push_front(ZufZahl());
     vListe.push_back(ZufZahl());
     }

vListe.vAktualisieren();
     // Liste zur Kontrolle nochmal ausgeben
     std::cout << "Liste nach dem Einfügen:" << std::endl;
     for (const auto& Zahl : vListe) {
         std::cout << Zahl << " ";
         }
     std::cout << std::endl;
};



void vAufgabe_7(){
	bInitialisiereGrafik(1000, 1000);

	bZeichneKreuzung( 680,  40);
	bZeichneKreuzung( 680,  30);
	bZeichneKreuzung( 680,  570);
	bZeichneKreuzung( 320,  300);


	int a[4]={ 680, 40, 680, 300 };
	bZeichneStrasse( "W12","W21", 40, 2, a);
	//bZeichneStrasse( "W21","W12", 40, 2, a);

	int b[12]={680,300,850, 300, 970, 390, 970, 500, 850, 570, 680, 570};
	bZeichneStrasse( "W23a","W32a", 115, 6, b);
	//bZeichneStrasse( "W32a","W23a", 115, 6, b);

	int c[4]={680, 300, 680, 570 };
	bZeichneStrasse( "W23b","W32b", 40, 2, c);
	//bZeichneStrasse( "W32b","W23b", 40, 2, c);

	int d[4]={680, 300, 320, 300};
	bZeichneStrasse( "W24","W42", 55, 2, d);
	//bZeichneStrasse( "W42","W24", 55, 2, d);

	int e[10]={ 680, 570, 500, 570, 350,510,320,420,320,300 };
	bZeichneStrasse( "W34","W43", 85, 5, e);
	//bZeichneStrasse( "W43","W34", 85, 5, e);

	int g[14]={320, 300, 170, 300, 70, 250, 80, 90, 200, 60, 320, 150, 320,300};
	bZeichneStrasse( "W44a","W44b", 130, 7, g);
	//bZeichneStrasse( "W44b","W44a", 130, 7, g);


	shared_ptr<Kreuzung> Kr1 = std::make_shared<Kreuzung>("Kr1",0);
	shared_ptr<Kreuzung> Kr2 = std::make_shared<Kreuzung>("Kr2",1000);
	shared_ptr<Kreuzung> Kr3 = std::make_shared<Kreuzung>("Kr3",0);
	shared_ptr<Kreuzung> Kr4 = std::make_shared<Kreuzung>("Kr4",0);

	Kr1->vVerbinde("W12", "W21", 40, Kr1, Kr2, Tempolimit::Innerorts, 0);
	Kr2->vVerbinde("W23a", "W32a", 115, Kr2, Kr3, Tempolimit::Autobahn, 0);
	Kr2->vVerbinde("W23b", "W32b", 40, Kr2, Kr3, Tempolimit::Innerorts, 0);
	Kr2->vVerbinde("W24", "W42", 55, Kr2, Kr4, Tempolimit::Innerorts, 0);
	Kr3->vVerbinde("W34", "W43", 85, Kr3, Kr4, Tempolimit::Autobahn, 0);
	Kr4->vVerbinde("W44a", "W44b", 130, Kr4, Kr4, Tempolimit::Landstrasse, 0);
	unique_ptr<Fahrzeug> bmw = std::make_unique<PKW>("BMW",10,2,60);
	unique_ptr<Fahrzeug> audi = std::make_unique<PKW>("Audi",7,1.7,60);
	unique_ptr<Fahrzeug> bmx = std::make_unique<Fahrrad>("BMX",2);

	Kr1->vAnnahme(move(bmw));
	Kr1->vAnnahme(move(audi));
	Kr1->vAnnahme(move(bmx));

	for (dGlobaleZeit = 0; dGlobaleZeit < 300; dGlobaleZeit++)
		{

			LL;
			cout << "Simulieren Zeit: " << dGlobaleZeit << " Stunden" << endl;
			Fahrzeug::vKopf();
			Kr1->vSimulieren();
			Kr2->vSimulieren();
			Kr3->vSimulieren();
			Kr4->vSimulieren();

			vSetzeZeit((double)dGlobaleZeit);
			vSleep(100);
		}
};


int main(){

char Wahl = 'g';

NN;
std::cout << "Wehlen Sie bitte die aufgaben Nummer: \n";
std::cout << "1.Aufgabe_6()  -> 1" << std::endl
		  << "2.Aufgabe_6a() -> 2" << std::endl
		  << "3.Aufgabe_7()  -> 3" << std::endl
		  << "0.Exit         -> e" << std::endl;
std::cin  >> Wahl;
NN;

switch (Wahl) {
case '1':
	vAufgabe_6();
	break;
case '2':
	vAufgabe_6a();
	break;
case '3':
	vAufgabe_7();
	break;
default:
	return 0;
	break;
}
}
