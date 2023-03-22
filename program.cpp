#include "Film.hpp"
#include "Usuari.hpp"
#include "Plataforma.hpp"
#include <iostream>
using namespace std;

int main() {

	// llegir_dades_plataforma (nom, films i usuaris)
	Plataforma p;
	cin >> p;
	cout << p;
	// llegir_opció
	string opcio;
	cin >> opcio;
	// mentre opció != acabar:
	while(opcio != "acabar"){
	//	tractar_opció
		if(opcio == "mostrarFilms"){
			
		}
		else if(opcio == "mostrarUsuaris"){
			
		}
		else if(opcio == "mostrarUsuaris"){
			
		}
		else if(opcio == "mostrarFilmsGenere"){
			
		}
		else if(opcio == "enregistrarValoracio"){
			
		}
		else if(opcio == "recomanarMillorFilm"){
			
		}
		else if(opcio == "mostrarMillorsFilms"){
			
		}
		else{
			cout << "Error: Opció no vàlida" << endl;
		}
	//  llegir_opció
		cin >> opcio;
	}
}
