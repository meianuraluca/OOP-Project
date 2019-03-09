#include <iostream>
#include <vector>
struct data
{ int zi;
 int luna;
 int an;

};
using namespace std;
class persoana
{protected:
  string prenume;
  string nume;
  int varsta;
  string adresa;
  int colesterol;
  int tensiune;
  data analiza;
  string risc;
  public:
      persoana();
      persoana(string,string,int,string,int,int,data);
      ~persoana();
      friend istream& operator>>(istream&, persoana&);
      friend ostream& operator<<(ostream&, persoana&);
     virtual  void citire();
      virtual void afisare();
      void risc_c();

};
void persoana::risc_c()
{ int nr=0;
if(tensiune>139 || tensiune<130)
    nr++;
if(colesterol>240 || colesterol<200)
    nr++;
if(nr>=2)
    risc="ridicat";
else
    risc="scazut";
}
persoana::persoana()
{
    varsta=0;
    colesterol=0;
    tensiune=0;
    analiza.an=0;
    analiza.zi=0;
    analiza.luna=0;
}
persoana::persoana(string a, string b,int c , string d, int e, int f, data g)
{  prenume=a;
nume=b;
varsta=c;
adresa=d;
colesterol=e;
tensiune=f;
analiza.an=g.an;
analiza.luna=g.luna;
analiza.zi=g.zi;
}
persoana::~persoana()
{
     varsta=0;
    colesterol=0;
    tensiune=0;
    analiza.an=0;
    analiza.zi=0;
    analiza.luna=0;
    nume.clear();
    prenume.clear();
    adresa.clear();
}
istream& operator>>(istream&in, persoana&a)
{ cout<<"Dati nume si prenumele persoanei ";
  in>>a.nume>>a.prenume;
  cout<<"Dati varsta";
  in>>a.varsta;
  cout<<"Dati adresa persoanei ";
  in>>a.adresa;
  cout<<"Dati data la care a facut analizele ";
  in>>a.analiza.zi>>a.analiza.luna>>a.analiza.an;
cout<<"Dati colesterolul si tensiunea ";
   in>>a.colesterol>>a.tensiune;
   return in;
}
ostream& operator<<(ostream&out,persoana&a)
{ cout<<"FISA MEDICALA "<<endl;
  cout<<"Nume:";
  out<<a.nume<<endl;
  cout<<"Prenume:";
  out<<a.prenume<<endl;
  cout<<"Varta:";
  out<<a.varsta<<endl;
  cout<<"Adresa:";
  out<<a.adresa<<endl;
  cout<<"Data ultimelor analiza:";
  out<<a.analiza.zi<<"."<<a.analiza.luna<<"."<<a.analiza.an<<endl;
  cout<<"Colesteroul:";
  out<<a.colesterol<<endl;
  cout<<"Tensiunea:";
  out<<a.tensiune<<endl;
return out;
}
void persoana::citire()
{
    cin>>*this;
}
void persoana::afisare()
{
    cout<<*this;
}
class copil:public persoana{
   string pt,pm;
   int preced;
   data prot;
   float proteina;
public:
    copil():persoana(){preced=0; prot.an=0; prot.zi=0; prot.luna=0;  proteina=0;}
    copil(string a, string b, int c,data d,float e,string a1,string b1,string c1, int d1, int d2, int d3, data f):persoana(a1,b1,d1,c1,d2,d3,f)
    {pt=a; pm=b; preced=c;
    proteina=e; prot.an=d.an;prot.luna=d.luna;
    prot.zi=d.zi;
    }
    ~copil();
    friend istream& operator>>(istream&,copil&);
    friend ostream& operator<<(ostream&,copil&);
    void risc_card();
    void afisare();
};
void copil::afisare()
{  persoana::afisare();
  cout<<"Prenume tata:";
  cout<<pt<<endl;
  cout<<"Prenume mama:";
  cout<<pm<<endl;
  cout<<"Numarul de persoane bolnave in familie:";
  cout<<preced<<endl;
  cout<<"Data analizelor pentru proteina C:";
  cout<<prot.zi<<"."<<prot.luna<<"."<<prot.an<<endl;
  cout<<"Proteina C:";
  cout<<proteina<<endl;
  risc_card();
  cout<<"Risc cardiovascular:";
  cout<<risc<<endl;

}
void copil::risc_card()
{ int nr=0;
if(tensiune>139 || tensiune<130)
    nr++;
if(colesterol>240 || colesterol<200)
    nr++;
if(preced==1 || preced==2)
    nr++;
if(nr>=2)
    risc="ridicat";
else
    risc="scazut";
}
copil::~copil()
{ pt.clear();
  pm.clear();
  prot.an=0;
  prot.zi=0;
  prot.luna=0;
  proteina=0;
  preced=0;
}
istream& operator>>(istream&in,copil &a)
{  a.citire();
   cout<<"Dati numele parintilor ";
   in>>a.pt>>a.pm;
   cout<<"0-pentru niciun parinte bolnav"<<endl;
   cout<<"1-pentru un parinte bolnav"<<endl;
   cout<<"2-daca amandoi au fot bolnavi"<<endl;
   in>>a.preced;
   cout<<"Dati data pentru proteina  ";
   in>>a.prot.zi>>a.prot.luna>>a.prot.an;
   cout<<"Dati proteina ";
   in>>a.proteina;
   return in;
}
ostream& operator<<(ostream& out, copil&a)
{  a.afisare();
    cout<<"Prenume tata:";
  out<<a.pt<<endl;
  cout<<"Prenume mama:";
  out<<a.pm<<endl;
  cout<<"Numarul de persoane bolnave in familie:";
  out<<a.preced<<endl;
  cout<<"Data analizelor pentru proteina C:";
  out<<a.prot.zi<<"."<<a.prot.luna<<"."<<a.prot.an<<endl;
  cout<<"Proteina C:";
  out<<a.proteina<<endl;
  cout<<"Risc cardiovascular:";
  out<<a.risc<<endl;
    return out;
}
class batrani:public persoana
{   int sed;
    int fumat;
public:
    batrani():persoana(){sed=0; fumat=0;}
    batrani(int a, int b,string a1,string b1,string c1, int d1, int d2, int d3, data f):persoana(a1,b1,d1,c1,d2,d3,f){sed=a; fumat=b;}
    ~batrani();
    friend istream& operator>>(istream&,batrani&);
    friend ostream& operator<<(ostream&,batrani&);
    void risc_card();
   void afisare();
   // void citire();

};
void batrani::afisare()
{ persoana::afisare();
    cout<<"Grad sedentarism:";
  cout<<sed<<endl;
  cout<<"Fumator:";
  cout<<fumat<<endl;
  risc_card();
  cout<<"Risc cardiovascular:";
  cout<<risc<<endl;
}
void batrani::risc_card()
{ int nr=0;
if(tensiune>139 || tensiune<130)
    nr++;
if(colesterol>240 || colesterol<200)
    nr++;
if(fumat==1)
    nr++;
if(sed==3)
    nr++;
if(nr>=2)
    risc="ridicat";
else
    risc="scazut";
}

batrani::~batrani()
{
    sed=0;
    fumat=0;
}
istream& operator>>(istream&in,batrani&a)
{
    a.citire();
    cout<<"1-sedentarismul scăzut"<<endl;
    cout<<"2-sedentarismul mediu"<<endl;
    cout<<"3-sedentarismul ridicat"<<endl;
    in>>a.sed;
    cout<<"1-fumator"<<endl;
    cout<<"0-nefumator"<<endl;
    in>>a.fumat;
    return in;
}
ostream& operator<<(ostream&out, batrani&b)
{ b.afisare();
  cout<<"Grad sedentarism:";
  out<<b.sed<<endl;
  cout<<"Fumator:";
  out<<b.fumat<<endl;
  cout<<"Risc cardiovascular:";
  out<<b.risc<<endl;
  return out;
}
template<class T> class medic;
template<class T> istream& operator>>(istream&,medic<T>&);
template<class T> ostream& operator<<(ostream&,medic<T>&);
template <class T>
class medic
{ vector<T*> pacienti;
  int nr_pacienti;
  public:
  medic();
  medic(vector<T*>, int);
  ~medic();
  friend istream& operator>> <>(istream&,medic<T>&);
  friend ostream& operator<< <>(ostream&,medic<T>&);
  void operator+=(T*);
  void afisare();
  void citire();
};
template<class T>
medic<T>::medic()
{
    nr_pacienti=0;
}
template<class T>
medic<T>::medic(vector<T*> a, int b)
{
    nr_pacienti=b;
    for(int i=0;i<a.size();i++)
        pacienti[i]=a[i];
}
template<class T>
medic<T>::~medic()
{
    nr_pacienti=0;
    pacienti.clear();
}
template<class T>
istream& operator>>(istream&in,medic<T>&a)
{ cout<<"Numarul de pacienti este";
 in>>a.nr_pacienti;
 for(int i=0;i<a.nr_pacienti;i++)
    { T*b;
      b=new T;
      cin>>(*b);
      a.pacienti.push_back(b);
    }
 return in;
}
template<class T>
ostream& operator<<(ostream&out,medic<T>&a)
{
  for(int i=0;i<a.pacienti.size();i++)
        a.pacienti[i]->afisare();
  return out;
}
template<class T>
void medic<T>::operator+=(T*a)
{
    pacienti.push_back(a);
}
template<class T>
void medic<T>::citire()
{  cin>>*this;

}
template<class T>
void medic<T>::afisare()
{  cout<<*this;

}
int main()
{ medic<persoana> vec;
int n,op;
       cout<<"Dati numarul de pacienti ";
       cin>>n;
for(int i=0;i<n;i++)
    {  cout<<"1-copil"<<endl;
    cout<<"2-batrani"<<endl;
    cout<<"3-persoane sub 40 de ani"<<endl;
    cin>>op;
     if(op==1)
        {  copil *a;
           a=new copil;
           cin>>(*a);
           persoana *pp=static_cast<persoana*>(a);
           vec+=pp;

        }
          if(op==2)
        {  batrani *a;
           a=new batrani;
           cin>>(*a);
           persoana *pp=static_cast<persoana*>(a);
           vec+=pp;

        }
        if(op==3)
        { persoana*a;
          a=new persoana;
          cin>>(*a);
          vec+=a;

        }
    }
    vec.afisare();
    return 0;
}
