#ifndef FILM_H
#define FILM_H
#include <iomanip>    // per indicar nombre de dígits en la part decimal amb setprecision()
#include <iostream>
using namespace std;

class Film {
    // Tipus de mòdul: dades
    // Descripció del tipus: Representa un film del que s'indiquen 
    // el seu títol, gènere, puntuació total obtinguda en les valoracions i
    // nombre de valoracions que ha rebut

    public:

    // ESPECIFICACIÓ DE LA CLASSE FILM
    // (especificació Pre/Post de tots els mètodes)


    // Constructors

    // Pre: cert
    // Post: el resultat és un film sense nom, génere i amb 0 valoracions i puntuacio 0.
    Film();

    // Pre: cert
    // Post: el resultat és un film amb nom a, de génere b i amb 0 valoracions i puntuacio 0.
    Film(const string &a, const string &b);

    // Pre: cert
    // Post: el resultat és un film amb nom a, de génere b i amb c valoracions i puntuacio d.
    Film(const string &a, const string &b, const double &c, const int &d);


    // Destructor
    ~Film();

            
    // Consultors
    
    // Pre: cert
    // Post: retorna el títol del film
    string NomFilm() const;
    
    // Pre: cert
    // Post: Retorna el gènere del film
    string GenereFilm() const;
    
    // Pre: cert
    // Post: retorna la puntuació del film
    double punts() const;
    
    // Pre: cert
    // Post: retorna el nombre de vots del film
    int numvots() const;
    
    // Pre: f té una valoració.
    // Post: retorna si f està millor valorat.
    bool millorValorat(Film f) const;
    
    // Modificadors
    
    // Pre: novaval té un enter de l'1 al 5.
    // Post: puntuacio conté la puntuació mitjana contant la nova valoració, i nval augmenta en 1.
    void novaValoracio(const int &novaval);
    /*puntuacio = ((puntuacio*nval + novaval)/(nval + 1));
    ++nval;*/
            
    // Lectura i escriptura
    
    // Pre: cert (completem els detalls de format quan coneguem la implementacio)
    // Post: s'han escrit els atributs del Film f al canal estandard de sortida
    friend ostream& operator<<(ostream &os, const Film &f);
    
    friend istream& operator>>(istream &is, Film &f);
    // Pre: cert
    // Post: el film f passa a tenir els atributs llegits del canal estandard d'entrada



    private:

    // Implementació de la classe Film 
    // (definició del tipus i nom de cada atribut)
    string titol;
    string genere;
    double puntuacio;
    int nval;
};
#endif
