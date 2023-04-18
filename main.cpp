#include <iostream>
#include <string.h>
#include <vector>
#include <cstdlib>
using namespace std;

class Bicicleta {
private:
    static int contorId;
    const int idBicicleta;
    char* numeBicicleta;
    int pret;
    bool inchiriata;
    string tipBicicleta;
    char culoare;

public:

    // Constructori
    Bicicleta();
    Bicicleta(char* numeBicicleta, int pret, bool inchiriata,
              string tipBicicleta, char culoare);
    Bicicleta(char* numeBicicleta, int pret);
    Bicicleta(int pret);

    // Constructor de copiere
    Bicicleta(const Bicicleta& b);

    ///operatori
    Bicicleta& operator=(const Bicicleta&);
    bool operator<(const Bicicleta&);
    friend ostream& operator<<(ostream& out,const Bicicleta& b);
    friend istream& operator>>(istream& in, Bicicleta& b);
    char operator[](int);
    Bicicleta& operator++();
    Bicicleta operator++(int);
    Bicicleta operator+(const Bicicleta& b);
    Bicicleta operator+(int);
    Bicicleta operator-(const Bicicleta& b);
    Bicicleta operator-(int);
    friend Bicicleta operator+(int,Bicicleta b);
    bool operator==(const Bicicleta& b) const ;
    bool operator>=(const Bicicleta& b);
    operator int();
    operator int() const{return this->pret;}
    void afisare();
    void citire();
    void afiseazaDisponibilitate() const;
    void verificaBuget(int) const;
    friend void afisare2(const Bicicleta& obj);
    // Setters
    void setNumeBicicleta(const char* numeBicicleta) {
        delete[] this->numeBicicleta;
        this->numeBicicleta = new char[strlen(numeBicicleta) + 1];
        strcpy(this->numeBicicleta, numeBicicleta);
    }

    void setPret(int pret) {
        this->pret=pret;
                            }

    void setInchiriata(bool inchiriata) {
        this->inchiriata=inchiriata;
    }

    void setTipBicicleta(string tipBicicleta) {
        this->tipBicicleta=tipBicicleta;
    }

    void setCuloare(char culoare) {
        this->culoare=culoare;
    }

    // Getters
    int getIdBicicleta() const {
        return idBicicleta;
    }
// cosnt char ca sa nu modifice din greseala NumeBicicleta
    const char* getNumeBicicleta() const {
        return numeBicicleta;
    }

    int getPret() const {
        return pret;
    }

    bool getInchiriata() const {
        return inchiriata;
    }

    string getTipBicicleta() const {
        return tipBicicleta;
    }

    char getCuloare() const {
        return culoare;
    }

  // Destructor
    ~Bicicleta();
void citesteDate() {
    cout << "Introdu datele bicicletei:\n";
  ///  cin >> idBicicleta;
    cout << "Nume bicicleta: ";
    cin >>this->numeBicicleta;
    cout << "Pret: ";
    cin >> pret;
    cout << "Tip: ";
    cin >> tipBicicleta;
    cout << "Inchiriata (0 - nu, 1 - da): ";
    int inchiriataTemp;
    cin >> inchiriataTemp;
    inchiriata = static_cast<bool>(inchiriataTemp);
}



};
int contorId=1;
Bicicleta::Bicicleta():idBicicleta(contorId++){
 numeBicicleta=new char[strlen("Anonim")+1];
 strcpy(numeBicicleta,"Anonim");
    pret=100;
    inchiriata=false;
    tipBicicleta="MTB";
    culoare='-';
}
 Bicicleta::Bicicleta(char* numeBicicleta, int pret, bool inchiriata,
                      string tipBicicleta,char culoare)
        : idBicicleta(contorId++){
        this->numeBicicleta=new char[strlen(numeBicicleta) + 1];
        strcpy(this->numeBicicleta, numeBicicleta);
        this->pret=pret;
        this->inchiriata=inchiriata;
        this->tipBicicleta=tipBicicleta;
        this->culoare=culoare;
                                }

Bicicleta::Bicicleta(const Bicicleta& b) : idBicicleta(b.idBicicleta){
         this->numeBicicleta=new char[strlen(b.numeBicicleta) + 1];
         strcpy(this->numeBicicleta, b.numeBicicleta);
         this->pret=b.pret;
         this->inchiriata=b.inchiriata;
         this->tipBicicleta=b.tipBicicleta;
         this->culoare=b.culoare ;
    }

   Bicicleta::Bicicleta(char* numeBicicleta, int pret) : idBicicleta(contorId++) {
        this->numeBicicleta=new char[strlen(numeBicicleta) + 1];
        strcpy(this->numeBicicleta, numeBicicleta);
        this->pret=pret;
        this->inchiriata=false;
        this->tipBicicleta="MTB";
        this->culoare='-';
    }

Bicicleta::Bicicleta(int pret) : idBicicleta(contorId++) {
        this->numeBicicleta=new char[strlen("Anonim") + 1];
        strcpy(this->numeBicicleta, "Anonim");
        this->pret=pret;
        this->inchiriata=false;
        this->tipBicicleta="MTB";
        this->culoare='-';
    }

// Suprasarcina operatorului =
    Bicicleta& Bicicleta::operator=(const Bicicleta& b) {
        if (this!=&b) {
           if(this->numeBicicleta!=NULL){
                delete[] this->numeBicicleta;
                this->numeBicicleta=NULL;
           }


       this->pret=b.pret;
        this->inchiriata=b.inchiriata;
        this->tipBicicleta=b.tipBicicleta;
        this->culoare=b.culoare;
        }
        return *this;

    }
    void Bicicleta::afisare(){
       cout << "ID: " << this->idBicicleta<<endl;
        cout << "Nume: " << this->numeBicicleta<<endl;
         cout<< "pret: " << this->pret<<endl;
        cout << "Inchiriata: " <<this->inchiriata<<endl;
        cout << "Tip: " << this->tipBicicleta<<endl;
        cout << "Culoare: " << this->culoare<<endl;

    }


    void afisare2(const Bicicleta& b){
     cout << "ID: " << b.idBicicleta<<endl;
        cout << "Nume: " << b.numeBicicleta<<endl;
         cout<< "Pret: " << b.pret<<endl;
        cout << "Inchiriata: " <<b.inchiriata<<endl;
        cout << "Tip: " << b.tipBicicleta<<endl;
        cout << "Culoare: " << b.culoare<<endl;
    }







    void Bicicleta::citire(){
        cout<<"Introduceti numele bicicletei: "<<endl;
        char numeBicicleta[100];
        cin.ignore();
        cin.getline(numeBicicleta,100);
        if(this->numeBicicleta!=NULL){
            delete this->numeBicicleta;
            this->numeBicicleta=NULL;
        }
           this->numeBicicleta = new char[strlen(numeBicicleta) + 1];
        strcpy(this->numeBicicleta, numeBicicleta);
        cout<<"Introduceti pret bicicleta: "<<endl;
        cin>> this->pret;
        cout<<"Introduceti tipul bicicletei: "<<endl;
        cin>> this->tipBicicleta;
        cout<<"Introduceti culoarea bicicletei: "<<endl;
        cin >> this->culoare;
        cout<<"Este inchiriata? "<<endl;
        cin >> this->inchiriata;
        cin.ignore();
    }



    // Suprasarcina operatorilor << și >>
    ostream& operator<<(ostream& out, const Bicicleta& b) {
        out << "ID: " << b.idBicicleta<<endl;
        out << "Nume: " << b.numeBicicleta<<endl;
         out<< "Pret: " << b.pret<<endl;
        out << "Inchiriata: " <<b.inchiriata<<endl;
        out << "Tip: " << b.tipBicicleta<<endl;
        out << "Culoare: " << b.culoare<<endl;
        return out;
    }

     istream& operator>>(istream& in, Bicicleta& b) {
        cout<<"Introduceti numele Bicicletei: "<<endl;
        char numeBicicleta[100];
        in>>numeBicicleta;
if(b.numeBicicleta!=NULL){
    delete b.numeBicicleta;
    b.numeBicicleta=NULL;
}
b.numeBicicleta=new char[strlen(numeBicicleta)+1];
strcpy(b.numeBicicleta,numeBicicleta);
        cout<<"Introduceti pret bicicleta: "<<endl;
        in >> b.pret;
        cout<<"Este inchiriata? "<<endl;
        in >> b.inchiriata;
        cout<<"Introduceti tipul bicicletei: "<<endl;
        in >> b.tipBicicleta;
        cout<<"Introduceti culoarea bicicletei: "<<endl;
        in >> b.culoare;
        return in;
    }
    Bicicleta::~Bicicleta(){
    if(this->numeBicicleta!=NULL){
        delete[] this->numeBicicleta;
        this->numeBicicleta=NULL;
    }

    }
/// Operatorul de indexare []
   char Bicicleta::operator[](int index) {
       if (index<strlen(numeBicicleta)) {
           return numeBicicleta[index];
       }
        return '\0';
    }

    // Operatorul ++ (forma prefixată)
    Bicicleta& Bicicleta::operator++() {
        pret++;
        return *this;
    }

    // Operatorul ++ (forma postfixată)
    Bicicleta Bicicleta::operator++(int) {
        Bicicleta temp=*this;
        pret++;
        return temp;
    }

    // Operatorii matematici + și -
    Bicicleta Bicicleta::operator+(const Bicicleta& b) {
        Bicicleta aux(*this);
        aux.tipBicicleta+=b.tipBicicleta;
        return aux;
    }

     Bicicleta Bicicleta:: operator-(const Bicicleta& b){
     Bicicleta aux(*this);
     aux.pret-=b.pret;
     return aux;

     }

    // Operatorul cast implicit (la int)
    Bicicleta::operator int()  {
        return pret;
    }

    // Operatorii condiționali < și >=
 bool Bicicleta::operator<(const Bicicleta& b) {
      return this->pret<b.pret;
 }

    bool Bicicleta::operator>=(const Bicicleta& b) {
        return this->pret>=b.pret;
    }

    // Operatorul pentru egalitate ==
    bool Bicicleta::operator==(const Bicicleta& b) const {
        return (strcmp(numeBicicleta, b.numeBicicleta)==0) &&
               (pret==b.pret) &&
               (inchiriata==b.inchiriata) &&
               (tipBicicleta==b.tipBicicleta) &&
               (culoare==b.culoare);
    }
    void Bicicleta::afiseazaDisponibilitate()const{
    if (inchiriata) {
        cout << "Bicicleta " << numeBicicleta << " (ID: " << idBicicleta << ") este inchiriata." << endl;
    } else {
        cout << "Bicicleta " << numeBicicleta << " (ID: " << idBicicleta << ") este disponibila pentru inchiriere." << endl;
    }
}
void Bicicleta::verificaBuget(int bugetClient)const  {
    if (bugetClient>=pret) {
        cout << "Clientul isi poate permite sa inchirieze bicicleta " << numeBicicleta << " (ID: " << idBicicleta << ")." << endl;
    } else {
        cout << "Clientul nu isi poate permite sa inchirieze bicicleta " << numeBicicleta << " (ID: " << idBicicleta << ")." << endl;
    }
}


int Bicicleta::contorId = 1;
class Client{
private:
    static int contorId;
    const int idClient;
    string numeClient;
    char initialaPrenumeTata;
    string prenumeClient;
    int varsta;
    string nrTelefon;
    double bugetClient;

public:

   //constructori
  //fara parametrii
  Client();
  Client(string numeClient,char initialaPrenumeTata,string prenumeClient,
          int varsta,string nrTelefon,double bugetClient);
    Client(string numeClient, char initialaPrenumeTata);
    Client(string numeClient, int varsta);
    Client(const Client& c);
    Client& operator=(const Client&);
    friend ostream& operator<<(ostream& out,const Client& c);
    friend istream& operator>>(istream& in,Client& c);
    Client& operator++();
    Client operator++(int);
    Client operator+(const Client& c);
    Client operator+(int);
    Client operator-(const Client& c);
    Client operator-(int);
    friend Client operator+(int,Client c);
    bool operator==(const Client& c);
    bool operator<=(const Client& c);
    operator int();
    operator int() const{return this->varsta;}
    string operator [](int);

    ///Metode
    void afisare();
    void citire();
    void afiseazaBugetulPeLuni();

    ///Destructor
    ~Client(){
    }

///Setters
   void setNumeClient(string numeClient){
   this->numeClient=numeClient;
                                        }

    void setInitialaPrenumeTata(char initialaPrenumeTata){
    this->initialaPrenumeTata=initialaPrenumeTata;
                        }
    void setPrenumeClient(string prenumeClient){
    this->prenumeClient=prenumeClient;
                                                }
     void setVarsta(int varsta){
    this->varsta=varsta;
                                }

     void setNrTelefon(string nrTelefon){
     this->nrTelefon=nrTelefon;
                                        }
    void setBugetClient(double bugetClient){
    this->bugetClient=bugetClient;
                                            }
///Getters
    int getIdClient() const{
    return idClient;
                            }

    string getNumeClient() const{
    return numeClient;
                                }

    char getInitialaPrenumeTata() const{
    return initialaPrenumeTata;
                                    }
    string getPrenumeClient() const{
    return prenumeClient;
                                    }
    int getVarsta() const {
    return varsta;
                            }
    string getNrTelefon() const {
    return nrTelefon;
                                }

    double getBugetClient() const{
    return bugetClient;
                                }
};
int Client::contorId=1;
Client::Client():idClient(contorId++){
numeClient="Anonim";
initialaPrenumeTata='-';
prenumeClient="Florin";
varsta=18;
nrTelefon="0746040362";
bugetClient=1350;

}
Client::Client(string numeClient,char initialaPrenumeTata,string prenumeClient,
          int varsta,string nrTelefon,double bugetClient): idClient(contorId++){
            this->numeClient=numeClient;
            this->initialaPrenumeTata=initialaPrenumeTata;
            this->prenumeClient=prenumeClient;
            this->varsta=varsta;
            this->nrTelefon=nrTelefon;
            this->bugetClient=bugetClient;

          }
    Client::Client(string numeClient, char initialaPrenumeTata) : idClient(contorId++) {
this->numeClient=numeClient;
this->initialaPrenumeTata=initialaPrenumeTata;
}

Client::Client(string numeClient, int varsta) : idClient(contorId++) {
this->numeClient=numeClient;
this->varsta=varsta;
}



Client::Client(const Client& c): idClient(c.idClient){
    this->numeClient=c.numeClient;
    this->initialaPrenumeTata=c.initialaPrenumeTata;
    this->prenumeClient=c.prenumeClient;
    this->varsta=c.varsta;
    this->nrTelefon=c.nrTelefon;
    this->bugetClient=c.bugetClient;
    }




///supraincarcarea operatoruui << si >>
    ostream& operator<<(ostream& out,const Client& c){
    out<< "ID: "<< c.idClient<<endl;
    out<< "nume:"<<c.numeClient<<endl;
    out<< "initiala tatalui: "<<c.initialaPrenumeTata<<endl;
    out<< "prenume: "<<c.prenumeClient<<endl;
    out<< "varsta: "<<c.varsta<<endl;
    out<< "Telefon: "<<c.nrTelefon<<endl;
    out<< "buget: "<<c.bugetClient<<endl;
       return out;
}
    istream& operator>>(istream& in, Client& c){
        cout<< "Introduceti numele: "<<endl;
        in>>c.numeClient;
        cout<< "Introduceti initiala tatalui: "<<endl;
        in>>c.initialaPrenumeTata;
        cout<< "Introduceti prenumele sub forma prenume1_prenume2: "<<endl;
        in>>c.prenumeClient;
        cout<< "Ce varsta aveti? "<<endl;
        in>>c.varsta;
        cout<< "Va rugam sa ne lasati un numar de telefon: "<<endl;
        in>>c.nrTelefon;
        cout<< "Care este bugetul dumneavoastra? "<<endl;
        in>>c.bugetClient;
        return in;

}
///supraincarcare operatorului =
Client& Client::operator=(const Client& c){
        if(this== &c){
            return *this;
                    }
    numeClient=c.numeClient;
    initialaPrenumeTata=c.initialaPrenumeTata;
    prenumeClient=c.prenumeClient;
    varsta=c.varsta;
    nrTelefon=c.nrTelefon;
    bugetClient=c.bugetClient;
    return *this;

  //toate copiate corect in destinatie
}
///operatorul de indexare []
string Client::operator[](int index) {
if(index<numeClient.length()){
    return numeClient.substr(index,1);
}
return "";
}
///operatorul ++(prefixat)
Client& Client::operator++(){
this->bugetClient++;
return *this;
}
///forma postfixata
Client Client::operator++(int){
 Client aux(*this);///aux primeste *this
 this->bugetClient++;
 return aux;
}
///operator +
Client Client::operator+(const Client& c){
    Client aux(*this);
    aux.varsta+=c.varsta;
    return aux;

}
Client Client::operator+(int x){
Client aux(*this);
aux.varsta+=x;
return aux;
}
///operator -
Client Client::operator-(const Client& c){
    Client aux(*this);
    aux.bugetClient-=c.bugetClient;
    return aux;}
Client Client::operator-(int x){
Client aux(*this);
aux.bugetClient-=x;
return aux;
}
///operator cast implicit la int
Client::operator int() {
return varsta;
}
//operator <=
bool Client::operator <=(const Client& c) {
return this->bugetClient<=c.bugetClient;
}
bool Client::operator ==(const Client& c){
return this->numeClient==c.numeClient;
}
void Client::afiseazaBugetulPeLuni() {
    cout << "Bugetul clientului pe luna este de: " << bugetClient/12 << " lei." << endl;
}




class Inchiriere {
    string datainceputInchiriere;
    string datasfarsitInchiriere;
    int zileInchiriere;
    float* numarOreZInchiriere;
public:
    Inchiriere();
    Inchiriere(string datainceputInchiriere, string datasfarsitInchiriere,
               int zileInchiriere, float* numarOreZInchiriere);
     Inchiriere(string datainceputInchiriere, string datasfarsitInchiriere);
    Inchiriere(string datainceputInchiriere, int zileInchiriere);
    Inchiriere(const Inchiriere& i);
    Inchiriere& operator=(const Inchiriere&);
    friend ostream& operator<<(ostream& out, const Inchiriere& i);
    friend istream& operator>>(istream& in, Inchiriere& i);
    Inchiriere& operator++();
    Inchiriere operator++(int);
    Inchiriere operator+(const Inchiriere& i);
    Inchiriere operator+(int);
    Inchiriere operator-(const Inchiriere& i);
    Inchiriere operator-(int);
    bool operator<=(const Inchiriere&);
    friend Inchiriere operator+(int, Inchiriere& i);
    bool operator==(const Inchiriere&);
    string operator[](int);
    operator int();
    operator int() const { return this->zileInchiriere; };

    void afisare();
    void citire();
    ~Inchiriere();

    //setters
    void setDatainceputInchiriere(string datainceputInchiriere) {
        this->datainceputInchiriere = datainceputInchiriere;
    }
    void setDatasfarsitInchiriere(string datasfarsitInchiriere) {
        this->datasfarsitInchiriere = datasfarsitInchiriere;
    }
    void setZileInchiriere(int zileInchiriere) {
        this->zileInchiriere = zileInchiriere;
    }
    void setNumarOreZInchiriere(float* numarOreZInchiriere) {
        this->numarOreZInchiriere = numarOreZInchiriere;
    }
    //getters
    string getDatainceputInchiriere() const {
        return datainceputInchiriere;
    }
    string getDatasfarsitInchiriere() const {
        return datasfarsitInchiriere;
    }
    int getZileInchiriere() const {
        return zileInchiriere;
    }
    const float* getNumarOreZInchiriere() const {
        return this->numarOreZInchiriere;
    }

};
Inchiriere::Inchiriere(){
datainceputInchiriere="03.19.2023";
datasfarsitInchiriere="06.19.2023";
zileInchiriere=3;
numarOreZInchiriere=NULL;
}
Inchiriere::Inchiriere(string datainceputInchiriere,string datasfarsitInchiriere,
                       int zileInchiriere,float* numarOreZInchiriere){
                       this->datainceputInchiriere=datainceputInchiriere;
                       this->datasfarsitInchiriere=datasfarsitInchiriere;
                       this->zileInchiriere=zileInchiriere;
                       for(int i=0;i<zileInchiriere;i++)
                                this->numarOreZInchiriere[i]=numarOreZInchiriere[i];
                       }
  Inchiriere::Inchiriere(string datasfarsitInchiriere, int zileInchiriere) {
this->datasfarsitInchiriere=datasfarsitInchiriere;
this->zileInchiriere=zileInchiriere;
this->numarOreZInchiriere=NULL;
}

Inchiriere::Inchiriere(string datainceputInchiriere, string datasfarsitInchiriere) {
this->datainceputInchiriere=datainceputInchiriere;
this->datasfarsitInchiriere=datasfarsitInchiriere;
this->numarOreZInchiriere=NULL;
}
 Inchiriere::Inchiriere(const Inchiriere& i) {
    this->datainceputInchiriere=i.datainceputInchiriere;
    this->datasfarsitInchiriere=i.datasfarsitInchiriere;
    this->zileInchiriere=i.zileInchiriere;

    if (i.numarOreZInchiriere!=NULL) {
        this->numarOreZInchiriere=new float[i.zileInchiriere];
        for (int j=0;j<i.zileInchiriere; j++) {
            this->numarOreZInchiriere[j]=i.numarOreZInchiriere[j];
        }
    } else {
        this->numarOreZInchiriere=NULL;
    }
}


/// operator << și >>
ostream& operator<<(ostream& out, const Inchiriere& i){
    out << "Data inceput: " << i.datainceputInchiriere << endl;
    out << "Data sfarsit: " << i.datasfarsitInchiriere << endl;
    out << "Numar zile: " << i.zileInchiriere << endl;
    out << "Ore: ";
    for (int j = 0; j < i.zileInchiriere; j++)
        out << i.numarOreZInchiriere[j] << " ";
    out << endl;
    return out;
}

istream& operator>>(istream& in, Inchiriere& i){
    cout << "Introduceti data de inceput inchiriere: " << endl;
    in >> i.datainceputInchiriere;
    cout << "Introduceti data de sfarsit inchiriere: " << endl;
    in >> i.datasfarsitInchiriere;
    cout << "Introduceti numarul de zile: " << endl;
    in >> i.zileInchiriere;
    cout << "Introduceti numar ore: " << endl;
    if (i.numarOreZInchiriere != NULL) {
        delete[] i.numarOreZInchiriere;
        i.numarOreZInchiriere = NULL;
    }
    i.numarOreZInchiriere = new float[i.zileInchiriere];
    for (int j=0;j<i.zileInchiriere;j++)
        in>>i.numarOreZInchiriere[j];

    return in;
}

 Inchiriere::~Inchiriere(){
  if(this->numarOreZInchiriere!=NULL){
    delete[] this->numarOreZInchiriere;
    numarOreZInchiriere=NULL;
  }

 }
 Inchiriere& Inchiriere::operator=(const Inchiriere& i) {
    if (this!=&i) {
        this->datainceputInchiriere=i.datainceputInchiriere;
        this->datasfarsitInchiriere=i.datasfarsitInchiriere;
        this->zileInchiriere=i.zileInchiriere;

        if (this->numarOreZInchiriere!=NULL) {
            delete[] this->numarOreZInchiriere;
            numarOreZInchiriere=NULL;
        }

        this->numarOreZInchiriere = new float[i.zileInchiriere];
        for (int j=0; j<i.zileInchiriere; j++) {
            this->numarOreZInchiriere[j]=i.numarOreZInchiriere[j];
        }
    }
    return *this;
}

//op de indexare[]
string Inchiriere::operator[](int index){
if(index<datainceputInchiriere.length()){
    return datainceputInchiriere.substr(index,1);

}
}
//operaator ++(pre
Inchiriere& Inchiriere::operator++(){
        this->zileInchiriere++;
         return *this;
               }
//postfixat
Inchiriere Inchiriere::operator++(int){
    Inchiriere aux(*this);
    this->zileInchiriere++;
    return aux;
}
/// operator +
Inchiriere Inchiriere::operator+(const Inchiriere& i) {
    Inchiriere aux(*this);
    aux.zileInchiriere += i.zileInchiriere;
    return aux;
}

Inchiriere Inchiriere::operator+(int x) {
    Inchiriere aux(*this);
    aux.zileInchiriere += x;
    return aux;
}

/// operator -
Inchiriere Inchiriere::operator-(const Inchiriere& i) {
    Inchiriere aux(*this);
    aux.zileInchiriere -= i.zileInchiriere;
    return aux;
}

Inchiriere Inchiriere::operator-(int x) {
    Inchiriere aux(*this);
    aux.zileInchiriere -= x;
    return aux;
}
Inchiriere::operator int(){
return zileInchiriere;
}
/// operator <=
bool Inchiriere::operator<=(const Inchiriere& i){
return this->zileInchiriere<=i.zileInchiriere;
}
bool Inchiriere::operator==(const Inchiriere& i) {
    return this->datainceputInchiriere == i.datainceputInchiriere &&
           this->datasfarsitInchiriere == i.datasfarsitInchiriere &&
           this->zileInchiriere == i.zileInchiriere;
}
void Inchiriere::afisare(){
cout<<"Data Inceput: "<<this->datainceputInchiriere<<endl;
cout<<"Data Sfarsit: "<<this->datasfarsitInchiriere<<endl;
cout<<"Zile: "<<this->zileInchiriere<<endl;
cout<<"Ore: "<<endl;
for(int i=0;i<this->zileInchiriere;i++)
    cout<<this->numarOreZInchiriere[i]<<" ";
cout<<endl;
}
void Inchiriere::citire(){
cout<<"Introduceti data de inceput: "<<endl;
cin>>this->datainceputInchiriere;
cout<<"Intrdouceti data de sfarsit: "<<endl;
cin>>this->datasfarsitInchiriere;
cout<<"Introduceti nr de zile: "<<endl;
cin>>this->zileInchiriere;
cout<<"Introduceti ore: "<<endl;
if(this->numarOreZInchiriere!=NULL){
    delete[] this->numarOreZInchiriere;
    this->numarOreZInchiriere=NULL;

}
this->numarOreZInchiriere=new float[this->zileInchiriere];
for(int i=0;i<this->zileInchiriere;i++)
    cin>>this->numarOreZInchiriere[i];

}
class Factura{
    static int contorId;
    const int idFactura;
    string inceput;
    string sfarsit;
    float cost;
    string adresaFactura;
public:
    Factura();
    Factura(string inceput,string sfarsit,float cost,
            string adresaFactura);
    Factura(string inceput, float cost);
    Factura(float cost);
    Factura(const Factura& f);
    Factura& operator=(const Factura&);
    friend ostream& operator<<(ostream& out,const Factura&);
    friend istream& operator>>(istream& in, Factura&);
    Factura& operator++();
    Factura operator++(int);
    Factura operator+(const Factura& f);
    Factura operator+(int);
    Factura operator-(const Factura& f);
    Factura operator-(int);
    bool operator<(const Factura& f);
    bool operator>=(const Factura&);
    friend Factura operator+(int, Factura& f);
    bool operator==(const Factura&);
    string operator[](int);
    operator float();
    operator int()const{return this->cost;};
    void afisare();
    void citire ();
    friend void afisare2(const Factura& f);
    ~Factura();

//setters
void setInceput(string inceput){
this->inceput=inceput;
    }
void setSfarsit(string sfarsit){
this->sfarsit=sfarsit;
}
void setCost(float cost){
this->cost=cost;
}
void setAdresaFactura(string adresaFactura){
this->adresaFactura=adresaFactura;
}

///getters
string getInceput() const{
return inceput;
}
string getSfarsit() const{
return sfarsit;
}
float getCost() const{
return cost;
}
string getAdresaFactura() const{
return adresaFactura;
}
int getIdFactura() const{
return idFactura;
}
};
int Factura::contorId=1;
Factura::Factura():idFactura(contorId++){
inceput="03.19.2023";
sfarsit="06.19.2023";
cost=230;
adresaFactura="BadestiArgesRomania";
}
Factura::Factura(string inceput,string sfarsit,float cost,
            string adresaFactura):idFactura(contorId++){
            this->inceput=inceput;
            this->sfarsit=sfarsit;
            this->cost=cost;
            this->adresaFactura=adresaFactura;
            }
Factura::Factura(float cost) : idFactura(contorId++) {
    inceput="";
    this->cost=cost;
    sfarsit="";
    adresaFactura="";}
    Factura::Factura(string sfarsit, float cost) : idFactura(contorId++) {
    inceput="";
    this->cost=cost;
    this->sfarsit=sfarsit;
    adresaFactura="";}

Factura::Factura(const Factura& f): idFactura(f.idFactura){
            this->inceput=f.inceput;
            this->sfarsit=f.sfarsit;
            this->cost=f.cost;
            this->adresaFactura=f.adresaFactura;
}
///op =
Factura& Factura::operator=(const Factura& f){
    if(this != &f){
        this->inceput=f.inceput;
        this->sfarsit=f.sfarsit;
        this->cost=f.cost;
        this->adresaFactura=f.adresaFactura;
    }
    return *this;
}
void Factura::afisare(){
    cout<<"ID: "<<this->idFactura<<endl;
    cout<<"Inceput: "<<this->inceput<<endl;
    cout<<"Sfarsit: "<<this->sfarsit<<endl;
    cout<<"Cost: "<<this->cost<<endl;
    cout<<"Adresa: "<<this->adresaFactura<<endl;
}
void afisare2(const Factura& f){
    cout<<"ID: "<<f.idFactura<<endl;
    cout<<"Inceput: "<<f.inceput<<endl;
    cout<<"Sfarsit: "<<f.sfarsit<<endl;
    cout<<"Cost: "<<f.cost<<endl;
    cout<<"Adresa: "<<f.adresaFactura<<endl;
}
void Factura::citire(){
cout<<"Introduceti data de inceput: "<<endl;
cin>>this->inceput;
cout<<"Introduceti data de sfarsit: "<<endl;
cin>>this->sfarsit;
cout<<"Introduceti cost: "<<endl;
cin>>this->cost;
cout<<"Introduceti adresa de facturare: "<<endl;
cin>>this->adresaFactura;
}
///op << si >>
ostream& operator<<(ostream& out,const Factura& f){
    out<<"ID: "<<f.idFactura<<endl;
    out<<"Inceput: "<<f.inceput<<endl;
    out<<"Sfarsit: "<<f.sfarsit<<endl;
    out<<"Cost: "<<f.cost<<endl;
    out<<"Adresa: "<<f.adresaFactura<<endl;
}
istream& operator>>(istream& in,Factura& f){
    cout<<"Introduceti data de inceput: "<<endl;
    in>>f.inceput;
    cout<<"Introduceti data de sfarsit: "<<endl;
    in>>f.sfarsit;
    cout<<"Introduceti cost: "<<endl;
    in>>f.cost;
    cout<<"Introduceti adresa de facturare: "<<endl;
    in>>f.adresaFactura;
    return in;
}
///operatorul de indexare []
string Factura::operator[](int index){
if(index<inceput.length()){
    return inceput.substr(index,1);
}
}
//op ++ (prefixata)
Factura& Factura::operator++(){
    cost++;
    return *this;
}
//++(post)
Factura Factura::operator++(int){
Factura aux=*this;
cost++;
return aux;
}
//operator + si -
Factura Factura::operator+(const Factura& f){
Factura aux(*this);
aux.cost+=f.cost;
return aux;
}
Factura Factura:: operator-(const Factura& f){
Factura aux1(*this);
aux1.cost-=f.cost;
return aux1;
}
///cast implicit
Factura::operator float(){
return cost;
}
//op conditionali < si>=
bool Factura::operator<(const Factura& f){
return this->cost<f.cost;
}
bool Factura::operator>=(const Factura& f){
return this->cost>=f.cost;
}
//operator pentru ==
bool Factura::operator==(const Factura& f){
return (inceput==f.inceput) &&
        (sfarsit==f.sfarsit) &&
        (cost==f.cost) &&
        (adresaFactura==adresaFactura);
}


void afisareMeniu() {
    cout << "Meniu interactiv Biciclete:\n";
    cout << "1. Adauga o bicicleta\n";
    cout << "2. Afiseaza bicicletele\n";
    cout << "3. Modifica o bicicleta\n";
    cout << "4. Sterge o bicicleta\n";
    cout << "5. Verifica disponibilitatea unei biciclete\n";
    cout << "6. Verifica daca un client isi poate permite o bicicleta\n";
    cout << "0. Iesire\n";
}

void afisareMeniuClient() {
    cout<<"Meniu interactiv Clienti: "<<endl;
    cout<<"1. Adauga un client"<<endl;
    cout<<"2. Afiseaza clientii"<<endl;
    cout<<"3. Modifica un client"<<endl;
    cout<<"4. Sterge un client"<<endl;
    cout<<"0. Iesire"<<endl;
}
void afisareMeniuPrincipal() {
    cout<<"------------------------"<<endl;
    cout<<"Meniu Principal"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"1. Gestionare biciclete"<<endl;
    cout<<"2. Gestionare clienti"<<endl;
    cout<<"0. Iesire"<<endl;
    cout<<"------------------------"<<endl;
}
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
int main() {
    int a;
    do {
        afisareMeniuPrincipal();
        cout<<"Alege optiune: ";
        cin>>a;
        switch (a) {
            case 1: {
                clearScreen();
                vector<Bicicleta>listaBiciclete;
                int optiune;
                do{

                    afisareMeniu();
                    cout<<"Alege optiunea: ";
                    cin>>optiune;
                clearScreen();
                    switch(optiune){
                        case 1:{
                            clearScreen();
                            Bicicleta bicicletaNoua;
                            bicicletaNoua.citesteDate();
                            listaBiciclete.push_back(bicicletaNoua);
                            break;
                        }
                        case 2:{
                            clearScreen();
                            for(const auto& bicicleta:listaBiciclete){
                                cout<<bicicleta<<endl;
                            }
                            break;
                        }
                        case 3:{
                            clearScreen();
                            int idBicicleta;
                            cout<<"Introdu ID-ul bicicletei pe care vrei sa o modifici: ";
                            cin>>idBicicleta;
                            for (auto& bicicleta:listaBiciclete){
                                if(bicicleta.getIdBicicleta()==idBicicleta){
                                    cin>>bicicleta;
                                    break;
                                }
                            }
                            break;
                        }
                        case 4:{
                            clearScreen();
                            int idBicicleta;
                            cout<<"Introdu ID-ul bicicletei pe care vrei sa o stergi: ";
                            cin>>idBicicleta;
                            for (size_t i=0;i<listaBiciclete.size();i++){
                                if (listaBiciclete[i].getIdBicicleta()==idBicicleta){
                                    listaBiciclete.erase(listaBiciclete.begin()+i);
                                    break;
                                }
                            }
                            break;
                        }
                        case 5:{
                            clearScreen();
                            int idBicicleta;
                            cout<<"Introdu ID-ul bicicletei pentru a verifica disponibilitatea: ";
                            cin>>idBicicleta;

                            for (const auto& bicicleta:listaBiciclete) {
                                if (bicicleta.getIdBicicleta()==idBicicleta) {
                                    bicicleta.afiseazaDisponibilitate();
                                    break;
                                }
                            }
                            break;
                        }
                        case 6:{
                            clearScreen();
                            int idBicicleta,bugetClient;
                            cout<<"Introdu ID-ul bicicletei: ";
                            cin>>idBicicleta;
                            cout<<"Introdu bugetul clientului: ";
                            cin>>bugetClient;

                            for (const auto& bicicleta:listaBiciclete) {
                                if (bicicleta.getIdBicicleta()==idBicicleta) {
                                    bicicleta.verificaBuget(bugetClient);
                                    break;
                                }
                            }
                            break;
                        }
                        case 0:{
                            clearScreen();
                            cout<<"Iesire din program...\n";
                            break;
                        }
                        default:{
                            clearScreen();
                            cout<<"Optiune invalida. Te rog sa incerci din nou.\n";
                        }
                    }
                } while (optiune != 0);
                break;
            }
            case 2:{
                clearScreen();
                vector<Client>listaClienti;
                int alegere;
      do {
    afisareMeniuClient();
    cout<<"Alege optiunea: ";
    cin>>alegere;

    switch(alegere){
        case 1:{
            clearScreen();
            Client clientNou;
            cin>>clientNou;
            listaClienti.push_back(clientNou);
            break;
        }
        case 2:{
            clearScreen();
            for(const auto& client:listaClienti) {
                cout<<client<<endl;
            }
            break;
        }
        case 3:{
            clearScreen();
            int idClient;
            cout<<"Introdu ID-ul clientului pe care vrei sa il modifici: ";
            cin>>idClient;
            for(auto& client:listaClienti) {
                if (client.getIdClient()==idClient) {
                    cin>>client;
                    break;
                }
            }
            break;
        }
        case 4:{
            clearScreen();
            int idClient;
            cout<<"Introdu ID-ul clientului pe care vrei sa il stergi: ";
            cin>>idClient;

            for (size_t i=0;i<listaClienti.size();i++){
                if (listaClienti[i].getIdClient()==idClient){
                    listaClienti.erase(listaClienti.begin()+i);
                    break;
                }
            }
            break;
        }
        case 0:{
            clearScreen();
            cout<<"La revedere!"<<endl;
            break;
        }
        default:{
            clearScreen();
            cout<<"Optiune invalida. Te rog sa alegi din meniu."<<endl;
        }
    }
} while(alegere != 0);
break;
}
case 0:{
    clearScreen();
    cout<<"Iesire din program...\n";
    break;
}
default:{
    clearScreen();
    cout<<"Optiune invalida. Te rog sa incerci din nou.\n";
}
}
} while (a!=0);
return 0;
}

