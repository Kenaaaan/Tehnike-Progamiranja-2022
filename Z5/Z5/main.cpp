#include <iostream>
#include <cmath>
#include <fstream>
#include <functional>
#include <vector>
template <typename TipElemenata>
 class DatotecniKontejner {
 std::fstream tok;
 public:
 DatotecniKontejner(const std::string &ime_datoteke){
        tok.open(ime_datoteke, std::ios::binary | std::ios::in | std::ios::out);
        if(!tok)
 {
    tok.clear();
    std::ofstream lol(ime_datoteke, std::ios::binary);
    if(!lol)
        throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");

    tok.open(ime_datoteke, std::ios::binary | std::ios::in | std::ios::out);
    if(!tok)
         throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
 }
 }
 void DodajNoviElement(const TipElemenata &element){
     tok.seekp(0,std::ios::end);
     tok.write(reinterpret_cast<const char*>(&element),sizeof(TipElemenata));
     tok.flush();
 }
 int DajBrojElemenata(){//dobra 100% znaci radi dobro!!
     tok.seekg(0,std::ios::end);
     int velicina = tok.tellg();
     return velicina/sizeof(TipElemenata);
 }
 TipElemenata DajElement(int pozicija){
     if(pozicija < 0 || pozicija >= DajBrojElemenata())
        throw std::range_error("Neispravna pozicija");
    
    tok.seekg(pozicija*sizeof(TipElemenata),std::ios::beg);
    TipElemenata element;
    tok.read(reinterpret_cast<char *>(&element),sizeof(TipElemenata));
    tok.flush();
    return element;
 }
 void IzmijeniElement(int pozicija, const TipElemenata &element){
     if(pozicija <0 || pozicija >=DajBrojElemenata())
        throw std::range_error("Neispravna pozicija");

    tok.seekp(pozicija * sizeof(TipElemenata),std::ios::beg);
    tok.write(reinterpret_cast<const char*>(&element),sizeof(TipElemenata));
    tok.flush();
 }
 void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)>
 kriterij = std::less<TipElemenata>()){
     int broj=DajBrojElemenata();
     for(int i=0;i<broj-1;i++){
         for(int j=0;j<broj-1-i;j++){
             if(!kriterij(DajElement(j),DajElement(j+1))){
                 TipElemenata temp = DajElement(j);
                 IzmijeniElement(j,DajElement(j+1));
                 IzmijeniElement(j+1,temp);
             }
         }
  }  tok.flush(); 
 }
 };

int main ()
{
    
	return 0;
}
