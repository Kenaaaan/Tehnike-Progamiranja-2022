//TP 2022/2023: LV 10, Zadatak 2
#include <iostream>
#include <cmath>
#include <iomanip>
const double pi = std::acos(-1);
class Krug 
{
    double poluprecnik;
    public:
    Krug(double r);
    void Postavi(double r);
    double DajPoluprecnik() const;
    double DajObim() const;
    double DajPovrsinu() const;
    void Skaliraj(double f);
    void Ispisi() const;
};
Krug::Krug(double r)
{
    if(r<=0)
        throw std::domain_error("Neispravan poluprecnik");
    poluprecnik=r;
}
void Krug::Postavi(double r) {
    if (r<=0) 
        throw std::domain_error("Neispravan poluprecnik");
    
    poluprecnik = r;
}

double Krug::DajPoluprecnik() const {
    return poluprecnik;
}

double Krug::DajObim() const {
    return 2 * pi * poluprecnik;
}
double Krug::DajPovrsinu() const 
{
    return poluprecnik*poluprecnik*pi;
}
void Krug::Skaliraj(double f)
{
    if(f<=0)
        throw std::domain_error("Neispravan faktor skaliranja");
    poluprecnik*=f;
}
void Krug::Ispisi() const
{
    std::cout <<std::setprecision(5)<<std::fixed<< "R=" << poluprecnik << " O=" << DajObim() << " P=" << DajPovrsinu();
}
class Valjak {
private:
    Krug baza;
    double visina;
public:
    explicit Valjak(const Krug& krug, double h) : baza(krug), visina(h) {
        if (krug.DajPoluprecnik()<= 0)
            throw std::domain_error("Neispravan poluprecnik");
        if (h <= 0)
            throw std::domain_error("Neispravna visina");
}

    void Postavi(double r, double h) {
        if (r<= 0)
            throw std::domain_error("Neispravan poluprecnik");
        if (h <= 0)
            throw std::domain_error("Neispravna visina");
        baza.Postavi(r);
        visina = h;
    }

    Krug DajBazu() const {
        return baza;
    }

    double DajPoluprecnikBaze() const {
        return baza.DajPoluprecnik();
    }

    double DajVisinu() const {
        return visina;
    }

    double DajPovrsinu() const {
        return 2 * baza.DajPovrsinu() + baza.DajObim() * visina;
    }

    double DajZapreminu() const {
        return baza.DajPovrsinu() * visina;
    }

    void Skaliraj(double faktor) {
        if (faktor <= 0)
            throw std::domain_error("Neispravan faktor skaliranja");
        baza.Skaliraj(faktor);
        visina *= faktor;
    }

    void Ispisi() const {
        std::cout<<std::setprecision(5) <<std::fixed<< "R=" << baza.DajPoluprecnik() << " H=" << visina
                  << " P=" << DajPovrsinu() << " V=" << DajZapreminu() << std::endl;
    }
};
int main ()
{


	return 0;
}
