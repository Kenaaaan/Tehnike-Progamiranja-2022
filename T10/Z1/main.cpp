//TP 2022/2023: LV 10, Zadatak 1
#include <iostream>
#include <cmath>
class StedniRacun {

double stanje;
public:
StedniRacun(double pocetno_stanje = 0)
{
    if(pocetno_stanje < 0) 
        throw std::logic_error("Nedozvoljeno pocetno stanje");
        
    stanje = pocetno_stanje;
}
void Ulozi(double iznos)
{
        if(stanje+iznos<0) throw std::logic_error("Transakcija odbijena");
        stanje +=iznos;
}
void Podigni(double iznos)
{
    if( iznos > stanje)
        throw std::logic_error("Transakcija odbijena");

    stanje -= iznos;
}
double DajStanje() const 
{
    return stanje;
}
void ObracunajKamatu(double kamatnastopa)
{
    if(kamatnastopa<0)
        throw std::logic_error("Nedozvoljena kamatna stopa");

    double kamata = stanje*kamatnastopa /100;
    stanje +=kamata;
}
};


int main ()
{


	return 0;
}
