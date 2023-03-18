#ifndef USUARI_H
#define USUARI_H
#include "Film.hpp"
#include <iostream>
using namespace std;

class Usuari {
    // Tipus de mòdul: dades
    // Descripció del tipus: Representa un usuari enregistrat a la plataforma
    // per fer una valoració d'algun film.
        
public:

    // ESPECIFICACIÓ DE LA CLASSE USUARI
    // (especificació Pre/Post de tots els mètodes)
        
        
    // Constructors
    
    // Pre: cert
    // Post: el resultat és un usuari amb sobrenom buit, amb identificador 0 i sense cap valoració enregistrada.
    Usuari();
    
    // Pre: cert
    // Post: el resultat és un usuari igual a u.
    Usuari(const Usuari &u);
    
    // Pre: cert
    // Post: el resultat és un usuari amb sobrenom a, amb identificador 0 i sense cap valoració enregistrada.
    Usuari(const string &a);
    
    // Pre: cert
    // Post: el resultat és un usuari amb sobrenom a, amb identificador i, amb 0 valoracions enregistrades.
    Usuari(const string &a, const int &i);
    
    // Pre: cert
    // Post: retorna un punt igual a u.
    Usuari operator=(const Usuari &u);
    
    /*
     * // Pre: cert
     * // Post: el resultat és un usuari amb sobrenom buit, amb identificador i, amb 0 valoracions enregistrades.
     * Usuari(int i);
     * 
     * 
     * // Pre: cert
     * // Post: // Post: el resultat és un usuari amb sobrenom buit, amb identificador i, amb n valoracions enregistrades.
     * Usuari(int i, int n);
     */
    
    //...
        
    // Destructor
    
    // Post: esborra automaticament els objectes locals en sortir d'un ambit de visibilitat
    ~Usuari();
                
    // Consultors
    
    // Pre: cert
    // Post: retorna l'identificador de l'usuari.
    int identificador() const;
    
    // Pre: cert
    // Post: retorna el sobrenom de l'usuari.
    string sobrenom() const;
    
    // Pre: cert
    // Post: retorna el nombre de valoracions enregistrades per l'usuari.
    int valoracions() const;
    
    // Modificadors
    
    // Pre: cert
    // Post: el nombre de valoracions enregistrades augmenta en 1
    void augmentaValoracions();
    
    // Pre: cert
    // Post: s'assigna l'identificador i a l'usuari.
    void assignaIdentificador(const int &i);
                
    // Lectura i escriptura
    
    // Pre: cert (completem els detalls de format quan coneguem la implementacio)
    // Post: s'han escrit els atributs de l'Usuari u al canal estandard de sortida
    friend ostream& operator<<(ostream &os, const Usuari &u);
    
    // Pre: cert
    // Post: l'Usuari u passa a tenir els atributs llegits del canal estandard d'entrada
    friend istream& operator>>(istream &is, Usuari &u);

private:
        
    // Implementació de la classe Usuari 
    // (definició del tipus i nom de cada atribut)
    
    int id;
    string nickname;
    int numval;
};
#endif
