#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include "Film.hpp"
#include "Usuari.hpp"
#include <iostream>
#include <vector>
using namespace std;

class Plataforma {
    // Tipus de mòdul: dades
    // Descripció del tipus: Representa una plataforma de registre de valoracions
    // de films que fan els usuaris. Una plataforma té un nom, està formada per un conjunt
    // d'usuaris i un conjunt de films.

public:

    // ESPECIFICACIÓ DE LA CLASSE PLATAFORMA
    // (especificació Pre/Post de tots els mètodes)


    // Constructors
    
    // Pre: cert
    // Post: el resultat és una Plataforma sense nom, sense films i sense usuaris.
    Plataforma();
    
    // Pre: cert
    // Post: el resultat és una Plataforma igual a p.
    Plataforma(const Plataforma &p);
    
    // Pre: cert
    // Post: el resultat és una Plataforma amb nom a, sense films i sense usuaris.
    Plataforma(const string &a);
    
    // Pre: cert
    // Post: el resultat és una Plataforma sense nom, amb f films, i sense usuaris.
    Plataforma(const vector<Films> &f);
    
    // Pre: cert
    // Post: el resultat és una Plataforma sense nom, sense films i amb u usuaris.
    Plataforma(const vector<Usuari> &u);
    
    // Pre: cert
    // Post: el resultat és una Plataforma sense nom, amb f films, i amb u usuaris.
    Plataforma(const vector<Films> &f, const vector<Usuari> &u);
    
    // Pre: cert
    // Post: el resultat és una Plataforma amb nom a, amb f films, i amb u usuaris.
    Plataforma(const string &a, const vector<Films> &f, const vector<Usuari> &u);
    
    // Pre: cert
    // Post: retorna una Plataforma igual a p
    Plataforma operator=(const Plataforma &p);

    // Destructor
    
    // Post: esborra automaticament els objectes locals en sortir d'un ambit de visibilitat
    ~Plataforma();
                
    // Consultors
    
    // Pre: cert
    // Post: retorna la llista de films que conte la plataforma
    vector<Films> mostrarFilms() const;
    
    // Pre: cert
    // Post: retorna la llista d'usuaris que conte la plataforma
    vector<Usuaris> mostrarUsuaris() const;
    
    // Pre: cert
    // Post: retorna la llista de films, dels quals el seu gènere coincideix amb l'especificat a g.
    vector<Films> mostrarFilmsGenere(const string &g) const;
    
    // Pre: cert
    // Post: retorna el film de la plataforma amb la millor valoració mitjana.
    Film recomanarMillorFilm() const;
    
    // Pre: cert
    // Post: retorna la llista  d'n films de la plataforma amb les millors valoracions mitjanes, en ordre de millor a pitjor.
    vector<Film> mostrarMillorsFilms(const int &n) const;

    // Modificadors
    
    // Pre: 1 <= n >= 5
    // Post: es fa la valoració mitjana del film que correspon a l'string u, emprant l'enter n, i s'augmenta en 1 el nombre de valoracions del film i l'usuari
    void enregistrarValoracio(const int &n, const string &u);  
                
    // Lectura i escriptura
    
    // Pre: cert (completem els detalls de format quan coneguem la implementacio)
    // Post: s'han escrit els atributs de la Plataforma p al canal estandard de sortida
    friend ostream& operator<<(ostream &os, const Plataforma &p);
    
    // Pre: cert
    // Post: la plataforma p passa a tenir els atributs llegits del canal estandard d'entrada
    friend istream& operator>>(istream &is, Plataforma &p);

private:

    // Implementació de la classe Plataforma 
    // (definició del tipus i nom de cada atribut)
    string nom;
    vector<Film> films;
    vector<Usuari> usuaris;
};
#endif
