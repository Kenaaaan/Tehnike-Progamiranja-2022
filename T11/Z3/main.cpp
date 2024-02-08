#include <cstring>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <stdexcept>
class Tim{char ime_tima[20];
	int broj_odigranih;
	int broj_pobjeda;
	int broj_nerijesenih;
	int broj_poraza;
	int broj_datih;
	int broj_primljenih;
	int broj_poena;
public:
	Tim(const char ime[]);
	void ObradiUtakmicu(int broj_datih, int broj_primljenih);
	const char *DajImeTima() const{return ime_tima;}
	int DajBrojPoena() const
	{
		return broj_poena;
	}
	int DajGolRazliku() const
	{
		return (broj_datih-broj_primljenih);
	}
	void IspisiPodatke() const;
};
Tim::Tim(const char ime[])
{
	if(strlen(ime)>20) throw std::range_error("Predugacko ime tima");
	strcpy(ime_tima, ime);
	broj_datih=0;
	broj_odigranih=0;
	broj_pobjeda=0;
	broj_poena=0;
	broj_poraza=0;
	broj_primljenih=0;
	broj_datih=0;
	broj_nerijesenih=0;
}
void Tim::ObradiUtakmicu(int broj_datih, int broj_primljenih)
{
	if(broj_datih<0||broj_primljenih<0)	throw std::range_error("Neispravan broj golova");
	Tim::broj_odigranih++;
	Tim::broj_datih+=broj_datih;
	Tim::broj_primljenih+=broj_primljenih;
	if(broj_datih>broj_primljenih) {
		Tim::broj_pobjeda++;
		Tim::broj_poena+=3;
	} else if(broj_primljenih==broj_datih) {
		Tim::broj_poena++;
		Tim::broj_nerijesenih++;
	} else
	Tim::broj_poraza++;
}
void Tim::IspisiPodatke() const {
	std::cout<<std::setw(20)<<std::left<<ime_tima<<std::setw(4)<<std::right<<broj_odigranih<<std::setw(4)<<std::right<<broj_pobjeda
	<<std::setw(4)<<std::right<<broj_nerijesenih<<std::setw(4)<<std::right<<broj_poraza<<std::setw(4)<<std::right<<broj_datih
	<<std::setw(4)<<std::right<<broj_primljenih<<std::setw(4)<<std::right<<broj_poena<<std::endl;
}
int main ()
{   Tim t1("FC Bayern Munchen");
	Tim t2("BVB");
	t1.ObradiUtakmicu(6,1);
	t2.ObradiUtakmicu(7,1);
	t1.IspisiPodatke();
	t2.IspisiPodatke();
	return 0;
}