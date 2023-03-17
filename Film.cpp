#include "Film.hpp"

// IMPLMENTACIÓ DE LA CLASSE FILM
// (implementació del codi de tots els mètodes especificats en el fitxer Film.hpp)

// Constructors

// Pre: cert
// Post: el resultat és un film sense nom, génere i amb 0 valoracions i puntuacio 0.
Film::Film(){
    nom = "";
    genere = "";
    puntuacio = 0;
    nval = 0;
}

// Pre: cert
// Post: el resultat és un film igual a f.
Film::Film(const Film &f){
    *this = f;
}

// Pre: cert
// Post: el resultat és un film amb nom a, de génere b i amb 0 valoracions i puntuacio 0.
Film::Film(const string &a, const string &b){
    nom = a;
    genere = b;
    puntuacio = 0;
    nval = 0;
}

// Pre: cert
// Post: el resultat és un film amb nom a, de génere b i amb puntuacio c i d valoracions.
Film::Film(const string &a, const string &b, const double &c, const int &d){
    nom = a;
    genere = b;
    puntuacio = c;
    nval = d;
}

/*
//Pre: cert
// Post: el resultat és un film sense nom i sense gènere, amb puntuacio c i d valoracions.
Film::Film(const double &c, const int &d){
    nom = "";
    genere = "";
    puntuacio = c;
    nval = d;
}
 */

// Post: esborra automaticament els objectes locals en sortir d'un ambit de visibilitat
Film::~Film();

// Consultors

// Pre: cert
// Post: retorna el títol del film
string Film::NomFilm() const{
    return nom;
}

// Pre: cert
// Post: Retorna el gènere del film
string Film::GenereFilm() const{
    return genere;
}

// Pre: cert
// Post: retorna la puntuació del film
double Film::punts() const{
    return puntuacio;
}

// Pre: cert
// Post: retorna el nombre de vots del film
int Film::numvots() const{
    return nval;
}

// Pre: f té una valoració.
// Post: retorna si f està millor valorat.
bool Film::millorValorat(Film f) const{
    bool millor = false;
    if(this->puntuacio > f.puntuacio){
        millor = true;
    }
    else if(this->puntuacio == f.puntuacio()){
        if(this->nval > f.nval){
            millor = true;
        }
    }
    return millor;
}

// Modificadors

// Pre: novaval té un enter de l'1 al 5.
// Post: puntuacio conté la puntuació mitjana contant la nova valoració, i nval augmenta en 1.
void Film::novaValoracio(const int &novaval){
    puntuacio = ((puntuacio*nval + novaval)/(nval + 1));
    ++nval;
}

// Lectura i escriptura

// Pre: cert (completem els detalls de format quan coneguem la implementacio)
// Post: s'han escrit els atributs del Film f al canal estandard de sortida
ostream& operator<<(ostream &os, const Film &f){
    os << "(" << f.nom << ", " << f.genere << ", " << f.puntuacio << ", " << f.nval << ")" << endl;
    return os;
}

// Pre: cert
// Post: el film f passa a tenir els atributs llegits del canal estandard d'entrada
istream& operator>>(istream &is, Film &f){
    is >> f.nom >> f.genere;
    return is;
}

