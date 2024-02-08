#include <iostream>
#include <stdexcept>
class StedniRacun
{
	double stanjeRacuna;
	static int brojKreiranih;
	static int brojAktivnih;
public:
	StedniRacun()
	{
		stanjeRacuna=0;
		brojAktivnih++;
		brojKreiranih++;
	}
	StedniRacun(const StedniRacun &racun);
	StedniRacun(double pocetnoStanje);
	void Ulozi(double iznos)
	{
		if(iznos<0 && iznos*-1>stanjeRacuna)	throw std::logic_error("Transakcija odbijena");
		stanjeRacuna+=iznos;
	}
	void Podigni(double iznos);
	double DajStanje () const
	{
		return stanjeRacuna;
	}
	void ObracunajKamatu(double kamatnaStopa);
	static int DajBrojKreiranih()
	{
		return brojKreiranih;
	}
	static int DajBrojAktivnih()
	{
		return brojAktivnih;
	}
	~StedniRacun()
	{
		brojAktivnih--;
	}
};
int StedniRacun::brojAktivnih(0);
int StedniRacun::brojKreiranih(0);
StedniRacun::StedniRacun(const StedniRacun &racun)
{
	if(racun.DajStanje()<0)  throw std::logic_error("Nedozvoljeno pocetno stanje");
	else {
		stanjeRacuna=racun.DajStanje();
		brojAktivnih++;
		brojKreiranih++;
	}
}
StedniRacun::StedniRacun(double pocetnoStanje)
{
	if(pocetnoStanje<0)  throw std::logic_error("Nedozvoljeno pocetno stanje");
	else {
		stanjeRacuna=pocetnoStanje;
		brojAktivnih++;
		brojKreiranih++;
	}
}
void StedniRacun::Podigni(double iznos)
{
	if(iznos>stanjeRacuna) throw std::logic_error("Transakcija odbijena");
	else stanjeRacuna-=iznos;
}
void StedniRacun::ObracunajKamatu(double kamatnaStopa)
{
	if(kamatnaStopa<=0) throw std::logic_error("Nedozvoljena kamatna stopa");
	else stanjeRacuna+=stanjeRacuna*kamatnaStopa/100.;
}
int main ()
{
	StedniRacun s1, s2(100);
	{
		StedniRacun s3(50);
	}
	std::cout << StedniRacun::DajBrojKreiranih() << " " << StedniRacun::DajBrojAktivnih();
	return 0;
}