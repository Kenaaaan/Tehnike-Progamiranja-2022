//TP 2022/2023: Zadaća 4, Zadatak 3
#include <initializer_list>
#include <ios>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <string>
#include <stdexcept>
class Polazak{
std::string odrediste;
std::string oznaka_voznje;
int broj_perona;
int sati;
int minute;
int trajanje;
int kasnjenje;
public:
Polazak(std::string odrediste, std::string oznaka_voznje, int broj_perona,
int sat_polaska, int minute_polaska, int trajanje_voznje){ 
    if(broj_perona<0 || sat_polaska<0 || sat_polaska>23 || minute_polaska<0 || minute_polaska>59
    || trajanje_voznje<1 || broj_perona<1 || broj_perona>15) throw std::domain_error("greska!");

     Polazak::odrediste=odrediste;  
    Polazak::oznaka_voznje=oznaka_voznje;   Polazak::broj_perona=broj_perona;
    sati=sat_polaska; minute=minute_polaska; trajanje=trajanje_voznje; kasnjenje=0;
}
void PostaviKasnjenje(int kasnjenje){if(kasnjenje<0)throw std::logic_error("greska");
Polazak::kasnjenje=kasnjenje;};
bool DaLiKasni() const{return(kasnjenje>0);}
int DajTrajanje() const{return trajanje;};
void OcekivanoVrijemePolaska(int &sati, int &minute) const;
void OcekivanoVrijemeDolaska(int &sati, int &minute) const;
void Ispisi() const;
};
void Polazak::OcekivanoVrijemePolaska(int &sati,int &minute) const{
   int ukupno_minute=(this->sati*60 + this->minute+kasnjenje)%1440;
    sati=ukupno_minute/60;
    minute=ukupno_minute%60;
}
void Polazak::OcekivanoVrijemeDolaska(int &sati, int &minute) const{
    int ukupno_minute=(this->sati*60 + this->minute+trajanje+kasnjenje)%1440;
    sati=ukupno_minute/60;
    minute=ukupno_minute%60;
}
void Polazak::Ispisi() const{
    int sati,minute;
    if(kasnjenje>0){
        OcekivanoVrijemePolaska(sati,minute);
        std::cout<<std::setw(10)<<std::left<<oznaka_voznje<<std::left<<
        std::setw(30)<<odrediste;
        std::cout<<std::right<<std::setw(10)<<sati<<":";
        std::cout<<std::setw(2)<<std::setfill('0')<<minute<<std::setfill(' ');
        std::cout<<" (Planirano "<<Polazak::sati<<":"<<std::setw(2)<<std::setfill('0')
        <<Polazak::minute<<std::setfill(' ');
        std::cout<<", Kasni "<<kasnjenje<<" min)"<<std::endl;
    }else{
        OcekivanoVrijemeDolaska(sati,minute);
        std::cout<<std::setw(10)<<std::left<<oznaka_voznje<<std::left
        <<std::setw(30)<<odrediste<<std::right<<std::setw(10)<<Polazak::sati<<":";
        std::cout<<std::setw(2)<<std::setfill('0')<<Polazak::minute<<std::setfill(' ')
        <<std::right<<std::setw(10)<<sati<<":";
        std::cout<<std::setw(2)<<std::setfill('0')<<minute<<std::setfill(' ')<<std::setw(8)<<broj_perona<<std::endl;
    }
}
class Polasci{
    int max_broj_polazaka;
    Polazak **polasci=nullptr; 
    int broj_polazaka=0;
    public:
explicit Polasci(int max_broj_polazaka) : max_broj_polazaka(max_broj_polazaka),broj_polazaka(0){
    polasci = new Polazak*[max_broj_polazaka];
}
Polasci(std::initializer_list<Polazak> lista_polazaka);
~Polasci(){for(int i{};i<broj_polazaka;i++){
    delete polasci[i];
}delete[] polasci;
broj_polazaka--;
}
Polasci(const Polasci &polasci);
Polasci(Polasci &&polasci);
Polasci &operator =(const Polasci &polasci);
Polasci &operator =(Polasci &&polasci);
void RegistrirajPolazak(std::string odrediste, std::string oznaka_voznje,
 int broj_perona, int sat_polaska, int minute_polaska, int trajanje_voznje);
void RegistrirajPolazak(Polazak *polazak);
int DajBrojPolazaka() const{return broj_polazaka;}
int DajBrojPolazakaKojiKasne() const;
Polazak &DajPrviPolazak();
Polazak DajPrviPolazak() const;
Polazak &DajPosljednjiPolazak();
Polazak DajPosljednjiPolazak() const;
void Ispisi() const;
void IsprazniKolekciju();
};
void Polasci::IsprazniKolekciju(){
for(int i{};i<broj_polazaka;i++)
    {
        if(polasci[i]!=nullptr)
        delete polasci[i];
    }
   if(polasci!=nullptr) 
    broj_polazaka=0;
}

Polasci::Polasci(std::initializer_list<Polazak> lista):max_broj_polazaka(lista.size()), 
broj_polazaka(0){
polasci=new Polazak*[max_broj_polazaka]{};
for(const Polazak& polazak: lista){
    polasci[broj_polazaka] = new Polazak(polazak);
    broj_polazaka++;
}
}
Polasci::Polasci(const Polasci &polasci): max_broj_polazaka(polasci.max_broj_polazaka),
broj_polazaka(polasci.broj_polazaka){
    this->polasci = new Polazak*[max_broj_polazaka]{};
    for(int i{};i<broj_polazaka;i++)
        this->polasci[i]= new Polazak(*polasci.polasci[i]);
}
Polasci::Polasci(Polasci &&polasci):polasci(polasci.polasci),
max_broj_polazaka(polasci.max_broj_polazaka),broj_polazaka(polasci.broj_polazaka){
polasci.polasci=nullptr; polasci.broj_polazaka=0; polasci.max_broj_polazaka=0;
}
Polasci &Polasci::operator=(const Polasci &p){
    if(&p!=this){
        for(int i{};i<max_broj_polazaka;i++)
            {delete polasci[i];}
        delete[] polasci;
        max_broj_polazaka=p.max_broj_polazaka;
        broj_polazaka=p.broj_polazaka;
        polasci= new Polazak*[max_broj_polazaka]{};
        for(int i{};i<broj_polazaka;i++)
        {
            polasci[i]=new Polazak(*p.polasci[i]);
        }
    }
    return *this;
}
Polasci &Polasci::operator=(Polasci &&p){
    if(&p!=this){
        for(int i{};i<max_broj_polazaka;i++)
            {delete polasci[i];}
        delete [] polasci;
        max_broj_polazaka=p.max_broj_polazaka;
        broj_polazaka=p.broj_polazaka;
        polasci=p.polasci;
        p.polasci=nullptr;
        p.broj_polazaka=0;
        p.max_broj_polazaka=0;
    }
    return *this;
}
void Polasci::RegistrirajPolazak(std::string odrediste, std::string oznaka_voznje,
int broj_perona,int h,int min,int trajanje){
    if(broj_polazaka>=max_broj_polazaka) 
        {throw std::range_error("Dostignut maksimalan broj polazaka");}
    polasci[broj_polazaka]=
     new Polazak(odrediste,oznaka_voznje,broj_perona,h,min,trajanje);
    broj_polazaka++;
}
void Polasci::RegistrirajPolazak(Polazak* p){
    if(broj_polazaka>=max_broj_polazaka)
        throw std::range_error("Dostignut maksimalan broj polazaka");
    polasci[broj_polazaka]=p;
    broj_polazaka++;
}
int Polasci::DajBrojPolazakaKojiKasne()const{
    return std::count_if(polasci,polasci+broj_polazaka,[](Polazak *p){return p->DaLiKasni();});
}
Polazak &Polasci::DajPrviPolazak(){
    auto f=[](Polazak* p1,Polazak *p2){
        int sati1, minute1,sati2,minute2;
        p1->OcekivanoVrijemePolaska(sati1,minute1);
        p2->OcekivanoVrijemeDolaska(sati2,minute2);
        return sati1<sati2 || (sati1==sati2 && minute1<minute2);
    };
    return **std::min_element(polasci,polasci+broj_polazaka,f);
}
Polazak Polasci::DajPrviPolazak() const {
    auto f=[](const Polazak *p1, const Polazak* p2){
        int sati1, sati2, minute1, minute2;
        p1->OcekivanoVrijemePolaska(sati1,minute1);
        p2->OcekivanoVrijemeDolaska(sati2,minute2);
        return sati1<sati2 || (sati1==sati2&&minute1<minute2);
    };
    return **std::min_element(polasci,polasci+broj_polazaka,f);
}
Polazak &Polasci::DajPosljednjiPolazak(){
    auto f=[](Polazak *p1,Polazak *p2){
        int sati1, sati2,minute1, minute2;
        p1->OcekivanoVrijemePolaska(sati1,minute1);
        p2->OcekivanoVrijemeDolaska(sati2, minute2);
        return sati1<sati2 || (sati1==sati2 && minute1<minute2);
    };
    return **std::max_element(polasci,polasci+broj_polazaka,f);
}
Polazak Polasci::DajPosljednjiPolazak() const{
    auto f=[](const Polazak *p1,const Polazak *p2){
        int sati1, sati2, minute1, minute2;
        p1->OcekivanoVrijemePolaska(sati1,minute1);
        p2->OcekivanoVrijemeDolaska(sati2,minute2);
        return sati1<sati2 || (sati1==sati2 && minute1<minute2);
    };
    return **std::max_element(polasci,polasci+broj_polazaka,f);
}
void Polasci::Ispisi() const {
    std::sort(polasci,polasci+DajBrojPolazaka(),[](Polazak *p1,Polazak*p2){
        int sati1,minute1,sati2,minute2;
        p1->OcekivanoVrijemePolaska(sati1,minute1);
        p2->OcekivanoVrijemePolaska(sati2,minute2);
        if(sati1 == sati2)
            return minute1<minute2;
        else
            return sati1<sati2;
    });
std::cout<<std::setw(10)<<std::right<<"Voznja";
std::cout<<std::right<<std::setw(30)<<"Odrediste";
std::cout<<std::right<<std::setw(10)<<"Polazak";
std::cout<<std::setw(10)<<std::right<<"Dolazak";
std::cout<<std::setw(8)<<"Peron"<<std::endl;
std::cout<<"----------------------------------------------------------------------\n";
for(int i{};i<broj_polazaka;i++)
    {if(polasci[i]!=nullptr)
        polasci[i]->Ispisi();}
}
int main ()
{
Polazak p1("Zagreb","123",2,6,14,120);
Polazak p2("Sarajevo","123",1,5,16,111);
Polazak p3= p1;
Polazak p4("Banja Luka","789", 3,16,0,90);
std::cout<<"Polazak 1:";
p1.Ispisi();
Polasci polasci(5);
polasci.RegistrirajPolazak("Zadar", "202",2,12,40,120);
polasci.RegistrirajPolazak("Par Selo", "202",1,11,30,140);
polasci.RegistrirajPolazak("Beograd", "202",1,2,20,110);
Polasci polasci2={p1,p2,p3,p4};
Polasci polasci3(polasci);
Polasci polasci4(std::move(polasci));
Polasci polasci5(3);
polasci5=polasci3;
Polasci polasci6(2);
polasci6=std::move(polasci4);
polasci.Ispisi();
polasci2.Ispisi();
polasci3.Ispisi();
polasci4.Ispisi();
polasci5.Ispisi();
polasci6.Ispisi();
	return 0;
}
