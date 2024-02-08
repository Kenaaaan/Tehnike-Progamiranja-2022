#include <iostream>
#include <cmath>
#include <vector>
#include <memory>
#include <fstream>
#include <algorithm>
class ApstraktnoVozilo{
protected:
    int G;
public:
    ApstraktnoVozilo(int G):G(G){};
    int DajTezinu(){return G;}
    virtual int DajUkupnuTezinu() const = 0;
    virtual ApstraktnoVozilo* DajKopiju() const = 0;
    virtual void IspisiPodatke() const = 0;
    virtual ~ApstraktnoVozilo(){}
};


class Automobil : public ApstraktnoVozilo{
    std::vector<int> tezine;
public:
    Automobil(int G, const std::vector<int> &tezine):ApstraktnoVozilo(G),tezine(tezine){}
    int DajUkupnuTezinu() const override;
    Automobil* DajKopiju() const override{return new Automobil(*this);}
    void IspisiPodatke() const override;
};
int Automobil::DajUkupnuTezinu() const{
    int ukupna = G;
    for(int lol:tezine)
        {ukupna += lol;}
    return ukupna;
}
void Automobil::IspisiPodatke() const{
std::cout<<"Vrsta vozila: Automobil"<<std::endl;
std::cout<<"Vlastita tezina: "<<G<<" kg"<<std::endl;
std::cout<<"Tezine putnika: ";
for(int i=0;i<tezine.size();i++)
{std::cout<<tezine[i]<<" kg";
if(tezine.size()-1!=i)
    std::cout<<", ";}
std::cout<<std::endl;
std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" kg"<<std::endl;
}


class Kamion : public ApstraktnoVozilo{
    int tezina;
public:
    Kamion(int G, int tezina):ApstraktnoVozilo(G),tezina(tezina){}
    int DajUkupnuTezinu() const override{return G+tezina;}
    Kamion *DajKopiju() const override{return new Kamion(*this);}
    void IspisiPodatke() const override;
};
void Kamion::IspisiPodatke() const {
    std::cout<<"Vrsta vozila: Kamion"<<std::endl;
    std::cout<<"Vlastita tezina: "<<G<<" kg"<<std::endl;
    std::cout<<"Tezina tereta: "<<tezina<<" kg"<<std::endl;
    std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" kg"<<std::endl;
}


class Autobus : public ApstraktnoVozilo{
    int putnika;
    int prosjek;
    public:
    Autobus(int G,int putnika,int prosjek):ApstraktnoVozilo(G),putnika(putnika),prosjek(prosjek){}
    int DajUkupnuTezinu() const override{return G+prosjek*putnika;}
    Autobus *DajKopiju() const override{return new Autobus(*this);}
    void IspisiPodatke() const override;
};
void Autobus::IspisiPodatke() const{
    std::cout<<"Vrsta vozila: Autobus"<<std::endl;
    std::cout<<"Vlastita tezina: "<<G<<" kg"<<std::endl;
    std::cout<<"Broj putnika: "<<putnika<<std::endl;
    std::cout<<"Prosjecna tezina putnika: "<<prosjek<<" kg"<<std::endl;
    std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" kg"<<std::endl;
}


class Vozilo{
    ApstraktnoVozilo* lik;
    void Test() const {if(!lik)throw std::logic_error("Greska");}
    public:
    Vozilo():lik(nullptr){}
    ~Vozilo(){delete lik;}
    Vozilo(const ApstraktnoVozilo &lik) : lik(lik.DajKopiju()){}
    Vozilo(const Vozilo &s){
        if(!s.lik) 
            lik =nullptr;
        else 
            lik=s.lik->DajKopiju();
    }
    /* moze i ovo
    Vozilo operator=(Vozilo v){
        std::swap(this->lik,v.lik);
        return *this;
    }*/
    Vozilo &operator=(Vozilo &&v){
        std::swap(lik,v.lik);
        return *this;
    }
    Vozilo &operator=(const Vozilo &v){
        ApstraktnoVozilo *novi=nullptr;
        if(v.lik!=nullptr) 
            novi=v.lik->DajKopiju();
        delete lik;
        lik=novi;
        return *this;
    }
    int DajUkupnuTezinu() const {
        return lik->DajUkupnuTezinu();
    }
    void IspisiPodatke() const {
        lik->IspisiPodatke();
    } 
};


int main ()
{
    std::ifstream tok("VOZILA.TXT");
    std::vector<Vozilo> vozila;
    if(!tok) 
        std::cout<<"Otvaranje nije uspjelo!"<<std::endl;
    else{
        char vrsta;
        while(tok>>vrsta){
            int G;
            tok>>G;
            if(vrsta=='A'){
                int broj;
                tok>>broj;
                std::vector<int> tezine(broj);
                for(int i{};i<broj;i++)
                {
                    tok>>tezine.at(i);
                }
                vozila.push_back(Automobil(G,tezine));
            }
            else if(vrsta=='K')
            {
                int teret;
                tok>>teret;
                vozila.push_back(Kamion(G,teret));
            }
            else if(vrsta=='B')
            {
                int broj, prosjek;
                tok>>broj>>prosjek;
                vozila.push_back(Autobus(G,broj,prosjek));
            }
            else
            {
                std::cout<<"Izuzetak: NEPOSTOJECE VOZILO!";
                return 0;
            }
        }
    tok.close();
    std::vector<int> lol;
    for(const Vozilo &v:vozila){
        lol.push_back(v.DajUkupnuTezinu());
        std::cout<<std::endl;
    }
    std::sort(lol.begin(),lol.end(),std::less<int>());
    for(const int &v:lol)
        std::cout<<v<<std::endl;
    }
    
	return 0;
}
