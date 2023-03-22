#include "Plataforma.hpp"

// IMPLMENTACIÓ DE LA CLASSE PLATAFORMA
// (implementació del codi de tots els mètodes especificats en el fitxer Plataforma.hpp)

// Pre: cert
// Post: el resultat és una Plataforma sense nom, sense films i sense usuaris.
Plataforma::Plataforma(){
    nom = "";
    films = vector<Film>(0);
    usuaris = vector<Usuari>(0);
}

// Pre: cert
// Post: el resultat és una Plataforma igual a p.
Plataforma::Plataforma(const Plataforma &p){
    (*this) = p;
}

// Pre: cert
// Post: el resultat és una Plataforma amb nom a, sense films i sense usuaris.
Plataforma::Plataforma(const string &a){
    nom = a;
    films = vector<Film>(0);
    usuaris = vector<Usuari>(0);
}

// Pre: cert
// Post: el resultat és una Plataforma sense nom, amb f films, i sense usuaris.
Plataforma::Plataforma(const vector<Film> &f){
    nom = "";
    this->films = f;
    usuaris = vector<Usuari>(0);
}
// Pre: cert
// Post: el resultat és una Plataforma sense nom, sense films i amb u usuaris.
Plataforma::Plataforma(const vector<Usuari> &u){
    nom = "";
    films = vector<Film>(0);
    this->usuaris = u;
}

// Pre: cert
// Post: el resultat és una Plataforma sense nom, amb f films, i amb u usuaris.
Plataforma::Plataforma(const vector<Film> &f, const vector<Usuari> &u){
    nom = "";
    this->films = f;
    this->usuaris = u;
}

// Pre: cert
// Post: el resultat és una Plataforma amb nom a, amb f films, i amb u usuaris.
Plataforma::Plataforma(const string &a, const vector<Film> &f, const vector<Usuari> &u){
    this->nom = a;
    this->films = f;
    this->usuaris = u;
}

// Pre: cert
// Post: retorna una plataforma igual a p
Plataforma Plataforma::operator=(const Plataforma &p){
    this->nom = p.nom;
    this->films = p.films;
    this->usuaris = p.usuaris;
    return *this;
}

// Post: esborra automaticament els objectes locals en sortir d'un ambit de visibilitat
Plataforma::~Plataforma(){
}

// Pre: cert
// Post: retorna la llista de films que conte la plataforma
vector<Film> Plataforma::llistaFilms() const{
    return films;
}

// Pre: cert
// Post: retorna la llista d'usuaris que conte la plataforma
vector<Usuari> Plataforma::Usuaris() const{
    return usuaris;
}

// Pre: cert
// Post: retorna la llista de films, dels quals el seu gènere coincideix amb l'especificat a g.
vector<Film> Plataforma::llistaFilmsGenere(const string &g) const{
    vector<Film> gaux;
    for(int i = 0; i < int(films.size()); ++i){
        if (films[i].genereFilm() == g){
            gaux.push_back(films[i]);
        }
    }
    return gaux;
}

// Pre: cert
// Post: retorna el film de la plataforma amb la millor valoració mitjana.
Film Plataforma::MillorFilm() const{
    Film millor;
    int max = 0;
    for(int i = 0; i < int(films.size()); ++i){
        if(max < films[i].punts()){
            max = films[i].punts();
            millor = films[i];
        }
    }
    return millor;
}

// Pre: n > 0
// Post: retorna la llista  d'n films de la plataforma amb les millors valoracions mitjanes, en ordre de millor a pitjor.
vector<Film> Plataforma::MillorsFilms(const int &n) const{
    vector<Film> millors;
    vector<Film> faux = films;
    // Insertion sort
    for(int i = 1; i < int(faux.size()); ++i){
        Film x = faux[i];
        int j = i;
        while(j > 0 and faux[j - 1].punts() > x.punts()){
            faux[j] = faux[j - 1];
            --j;
            // Potser malament
            if(faux[j - 1].punts() == x.punts()){
                if(faux[j - 1].numvots() > x.numvots()){
                    faux[j] = faux[j - 1];
                }
            }
            // Potser malament
        }
        faux[j] = x;
    }
    if(n > int(films.size())){
        millors = faux;
        // for(int i = 0; i < int(films.size()); ++i){}
    }
    else{
        for(int i = n - 1; i >= 0; --i){
            millors.push_back(faux[i]);
        }
    }
    return millors;
}

// Pre: cert
// Post: retorna true si a la plataforma existeix algun film de nom f
bool Plataforma::existeixFilm(const string &f) const{
    bool trobat = false;
    int i = 0;
    while(not trobat and i < int(films.size())){
        if(f == films[i].nomFilm()){
            trobat = true;
        }
        ++i;
    }
    return trobat;
}

// Pre: cert
// Post: retorna true si a la plataforma existeix algun film amb gènere g
bool Plataforma::existeixGenere(const string &g) const{
    bool trobat = false;
    int i = 0;
    while(not trobat and i < int(films.size())){
        if(g == films[i].genereFilm()){
            trobat = true;
        }
        ++i;
    }
    return trobat;
}

// Pre: cert
// Post: retorna true si a la plataforma existeix algun usuari de nom u
bool Plataforma::existeixUsuari(const string &u) const{
    bool trobat = false;
    int i = 0;
    while(not trobat and i < int(usuaris.size())){
        if(u == usuaris[i].sobrenom()){
            trobat = true;
        }
        ++i;
    }
    return trobat;
}

// Pre: cert
// Post: retorna true si la plataforma conté algun film
bool Plataforma::hiHaFilms() const{
    bool trobat = false;
    if(int(films.size()) != 0){
        trobat = true;
    }
    return trobat;
}

// Pre: cert
// Post: retorna true si la plataforma conté algun usuari
bool Plataforma::hiHaUsuaris() const{
    bool trobat = false;
    if(int(usuaris.size()) != 0){
        trobat = true;
    }
    return trobat;
}

/* Post: es calcula la valoració mitjana d'aquell film que el seu nom correspon a l'string f, afegint l'enter n al càlcul.
* També s'augmenten en 1 el nombre de valoracions d'aquest film, i el nombre de valoracions enregistrades d'aquell usuari que el seu nom correspon a 
* l'string u.
*/
void Plataforma::enregistrarValoracio(const string &u, const string &f, const int &n){
    bool trobat = false;
    int i = 0;
    while(not trobat and i < int(usuaris.size())){
        if(u == usuaris[i].sobrenom()){
            trobat = true;
            usuaris[i].augmentaValoracions();
        }
    }
    trobat = false;
    i = 0;
    while(not trobat and i < int(films.size())){
        if(f == films[i].nomFilm()){
            trobat = true;
            films[i].novaValoracio(n);
        }
    }
}

// Pre: hi ha com un usuari enretrat a la plataforma
// Post: Assgina els identifacdors dels usuaris, en ordre de registre.
void Plataforma::assignaIdentificadors(){
    for(int i = 0; i < int(usuaris.size()); ++i){
        usuaris[i].assignaIdentificador(i + 1);
    }
}

// Pre: cert (completem els detalls de format quan coneguem la implementacio)
// Post: s'han escrit els atributs de la Plataforma p al canal estandard de sortida
ostream& operator<<(ostream &os, const Plataforma &p){
    os << "Films a " << p.nom << " (ordre d'alta):" << endl;
    for(int i = 0; i < int(p.films.size()); ++i){
        os << p.films[i];
    }
    for(int i = 0; i < int(p.usuaris.size()); ++i){
        os << p.usuaris[i];
    }
    return os;
}

// Pre: cert
// Post: la plataforma p passa a tenir els atributs llegits del canal estandard d'entrada
istream& operator>>(istream &is, Plataforma &p){
    is >> p.nom;
    int n;
    is >> n;
    p.films = vector<Film>(n);
    for(int i = 0; i < n; ++i){
        is >> p.films[i];
    }
    is >> n;
    p.usuaris = vector<Usuari>(n);
    for(int i = 0; i < n; ++i){
        is >> p.usuaris[i];
        p.usuaris[i].assignaIdentificador(i + 1);
    }
    return is;
}