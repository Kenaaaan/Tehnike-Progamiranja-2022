#include <initializer_list>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string.h>
#include <algorithm>
class Tim{
    char ime_tima[20];
    int broj_odigranih;
    int broj_pobjeda;
    int broj_nerijesenih;
    int broj_poraza;
    int broj_datih;
    int broj_primljenih;
    int broj_poena;
public:
    Tim(const char ime[]);
    void ObradiUtakmicu( int broj_datih, int broj_primjlenih);
    const char *DajImeTima() const{ return ime_tima;}
    int DajBrojPoena() const{return broj_poena;}
    int DajGolRazliku() const{return broj_datih-broj_primljenih;}
    void IspisiPodatke() const;
};

Tim::Tim(const char ime[]){
    if(strlen(ime)>20)throw std::range_error("Predugacko ime tima");
    strcpy(ime_tima,ime);
    broj_datih=0; broj_nerijesenih=0; broj_odigranih=0; broj_poena=0;
    broj_pobjeda=0; broj_poraza=0; broj_primljenih=0;
}

void Tim::ObradiUtakmicu(int dati, int primljeni){
    if(dati<0 || primljeni<0)   
        throw std::range_error("Neispravan broj golova");
        broj_odigranih++;
        broj_datih+=dati;
        broj_primljenih+=primljeni;
        if(dati>primljeni){
            broj_pobjeda++;
            broj_poena+=3;
        }
        else if(primljeni==dati){
            broj_nerijesenih++;
            broj_poena++;
        }
        else
            broj_poraza++;
}
void Tim::IspisiPodatke() const{
    std::cout<<std::setw(20)<<std::left<<ime_tima<<
                std::setw(4)<<std::right<<broj_odigranih<<
                std::setw(4)<<broj_pobjeda<<
                std::setw(4)<<broj_nerijesenih<<
                std::setw(4)<<broj_poraza<<
                std::setw(4)<<broj_datih<<
                std::setw(4)<<broj_primljenih<<
                std::setw(4)<<broj_poena<<std::endl;
}

bool kriterij(Tim *tim1, Tim *tim2){
    if(tim1->DajBrojPoena()==tim2->DajBrojPoena()){
        if(tim1->DajGolRazliku()>tim2->DajGolRazliku()) return true;
        else if(tim1->DajGolRazliku()<tim2->DajGolRazliku())return false;
        else{
            if(strcmp(tim1->DajImeTima(), tim2->DajImeTima())<0) return true;
            else
                return false;
        }
    }
    return tim1->DajBrojPoena()>tim2->DajBrojPoena();
}
class Liga{
    int broj_timova;
    const int max_broj_timova;
    Tim **timovi;
public:
    explicit Liga(int velicina_lige):max_broj_timova(velicina_lige){
        timovi=new Tim*[velicina_lige];
        broj_timova=0;
    }
    explicit Liga(std::initializer_list<Tim> lista_timova);
    ~Liga();
    Liga( const Liga &l);
    Liga(Liga &&l);
    Liga &operator= (const Liga &l){
        if(max_broj_timova< l.broj_timova)
            throw std::logic_error("Nesaglasni kapaciteti liga");
        if(broj_timova>=l.broj_timova){
            for(int i=0; i<l.broj_timova; i++) delete timovi[i];
            delete [] timovi;
            timovi=new Tim*[l.broj_timova];
            for(int i=0; i<l.broj_timova; i++)
                timovi[i]=new Tim(*(l.timovi[i]));
        } else{
            for ( int i=0; i<broj_timova; i++) delete timovi[i];
            delete [] timovi;
            timovi=new Tim*[l.broj_timova];
            for(int i=0; i<l.broj_timova; i++)
                timovi[i]=new Tim(l.timovi[i]->DajImeTima());
        }
        broj_timova=l.broj_timova;
        return *this;
    }
    Liga &operator = (Liga &&l){
        if(max_broj_timova< l.broj_timova) throw std::logic_error("Nesaglasni kapaciteti liga");
        for(int i=0; i<broj_timova; i++) delete timovi[i];
        delete [] timovi;
        timovi=new Tim*[l.broj_timova];
        if(broj_timova>=l.broj_timova)
            for(int i=0; i<l.broj_timova; i++)
                timovi[i]=new Tim(*(l.timovi[i]));
        else
            for(int i=0; i<l.broj_timova; i++)
                timovi[i]=new Tim(l.timovi[i]->DajImeTima());
        broj_timova=l.broj_timova;
        l.timovi=nullptr;
        return *this;
    }
    void DodajNoviTim(const char ime[]);
    void RegistrirajUtakmicu( const char tim1[], const char tim2[],int rez1, int rez2);
    void IspisiTabelu();
};

Liga::Liga(std::initializer_list<Tim> lista_timova):max_broj_timova(lista_timova.size()){
    timovi= new Tim*[lista_timova.size()];
        auto it=lista_timova.begin();
        for (int i{}; i<lista_timova.size(); i++){
            timovi [i]= new Tim(it->DajImeTima());
            it++;
        }
        broj_timova=lista_timova.size();
    }

Liga::Liga(const Liga &l):max_broj_timova(l.max_broj_timova){
    timovi=new Tim*[l.broj_timova];
    for (int i=0; i < l.broj_timova; i++)
        timovi[i]=new Tim(*(l.timovi[i]));
    broj_timova=l.broj_timova;
}


Liga::~Liga(){
    for(int i=0; i<broj_timova; i++) delete timovi[i];
    delete [] timovi;
}

Liga::Liga(Liga &&l): max_broj_timova(l.max_broj_timova){
    timovi=new Tim*[l.broj_timova];
    for ( int i=0; i<l.broj_timova; i++)
        timovi[i]= new Tim(*(l.timovi[i]));
    broj_timova=l.broj_timova;
    l.timovi=nullptr;
}

void Liga::DodajNoviTim ( const char ime_tima[]){
    if(broj_timova>max_broj_timova-1) throw std::range_error("Liga popunjena");
    try{
        timovi[broj_timova]=new Tim(ime_tima);
        broj_timova++;
    }catch(std::range_error){
        throw;
    }
}

void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[],int rez1, int rez2 ){
    bool prvi=false, drugi=false;
    int mjesto1=0, mjesto2=0;
    for(int i=0; i<broj_timova; i++){
        if(strcmp(timovi[i]->DajImeTima(),tim1)==0){
            prvi=true;
            mjesto1=i;
        }
        if(strcmp(timovi[i]->DajImeTima(), tim2)==0){
            drugi=true;
            mjesto2=i;
        }
    }
    if(!prvi || !drugi) throw std::logic_error("Tim nije nadjen");
    timovi[mjesto1]->ObradiUtakmicu(rez1,rez2);
    timovi[mjesto2]->ObradiUtakmicu(rez2,rez1);
}

void Liga::IspisiTabelu(){
    std::sort(timovi, timovi+broj_timova, kriterij);

    for(int i=0; i<broj_timova; i++)
        timovi[i]->IspisiPodatke();
}
int main ()
{
	return 0;
}