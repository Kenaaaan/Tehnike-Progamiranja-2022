//TP 2022/2023: Zadaća 5, Zadatak 1
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <tuple>
#include <complex>
const double pi = std::acos(-1);
class Sinusoida{
double A;
double frek;
double fi;
public:
Sinusoida(double A,double frek,double fi);
double DajAmplitudu()const{return A;}
double DajFrekvenciju()const{return frek;}
double DajFazu()const{return fi;}
std::tuple<double,double,double>DajParametre()const{return std::make_tuple(A,frek,fi);}
Sinusoida &PostaviAmplitudu(double A);
Sinusoida &PostaviFrekvenciju(double frek);
Sinusoida &PostaviFazu(double fi);
Sinusoida &PostaviParametre(std::tuple<double,double,double> t);
friend Sinusoida operator-(Sinusoida &s);
friend Sinusoida operator+(const Sinusoida &s1,const Sinusoida &s2);
friend Sinusoida operator-(const Sinusoida &s1,const Sinusoida &s2);
friend Sinusoida operator*(const Sinusoida &s, const double broj);
friend Sinusoida operator/(const Sinusoida &s,const double broj);
friend Sinusoida &operator*=(Sinusoida &s,const double broj);
friend Sinusoida &operator-=(Sinusoida &s1,const Sinusoida &s2);
friend Sinusoida &operator+=(Sinusoida &s1,const Sinusoida &s2);
friend Sinusoida &operator/=(Sinusoida &s,const double broj);
double operator()(double t) const;
double operator[](const std::string &s) const;
double &operator[](const std::string &s);
};
Sinusoida::Sinusoida(double A,double frek,double fi){
    if(A<0){
        A=-A;
        fi+=pi;
        } 
    if(frek<0)
   {
       frek=-frek;
       fi=-fi;
       fi+=pi;
   }
    while(fi>pi)
        {fi-=2*pi;}
    while(fi<-pi)
        {fi+=2*pi;}
  
    this->A=A;      this->frek=frek;    this->fi=fi;
}
Sinusoida &Sinusoida::PostaviAmplitudu(double A){
    if(A<0){
        A=-A;
        fi+=pi;
    }
    this->A=A;
    while(fi>pi)    
        {fi-=2*pi;}
    while(fi<-pi)
       {fi+=2*pi;}

    return *this;
}
Sinusoida &Sinusoida::PostaviFrekvenciju(double frek){
    if(frek<0){
        frek=-frek;
        fi=-fi;
        fi+=pi;
    }
    this->frek=frek;
    return *this;
}
Sinusoida &Sinusoida::PostaviFazu(double fi){
    while(fi>pi) 
        {fi-=2*pi;}
    while(fi<-pi)
        {fi+=2*pi;}
    this->fi=fi;
    return *this;
}
Sinusoida &Sinusoida::PostaviParametre(std::tuple<double, double, double> t){
    double A,frek,fi;
    std::tie(A,frek,fi)=t;
    Sinusoida cener(A,frek,fi);
    *this=cener;
    return *this;
}
Sinusoida operator-(Sinusoida &s){
    Sinusoida rez(-s.A,s.frek,s.fi);
    return rez;
}
Sinusoida operator+(const Sinusoida &s1,const Sinusoida &s2){
    if(std::abs(s1.frek-s2.frek)>0)
        throw std::domain_error("Razlicite frekvencije");
    std::complex<double> p1(s1.A*std::cos(s1.fi),s1.A*std::sin(s1.fi));
    std::complex<double> p2(s2.A*std::cos(s2.fi),s2.A*std::sin(s2.fi));
    std::complex<double> sum=p1+p2;
    double amp=std::abs(sum);
    double phase=std::arg(sum);
    return Sinusoida(amp,s1.frek,phase);
}
Sinusoida operator-(const Sinusoida &s1,const Sinusoida &s2){
    if(std::abs(s1.frek-s2.frek)>0)
        throw std::domain_error("Razlicite frekvencije");
    std::complex<double> p1(s1.A*std::cos(s1.fi),s1.A*std::sin(s1.fi));
    std::complex<double> p2(s2.A*std::cos(s2.fi),s2.A*std::sin(s2.fi));
    std::complex<double> sum=p1-p2;
    double amp=std::abs(sum);
    double phase=std::arg(sum);
    return Sinusoida(amp,s1.frek,phase);
}
Sinusoida operator*(const Sinusoida &s,const double broj){
    return Sinusoida(s.A*broj,s.frek,s.fi);
}
Sinusoida operator/(const Sinusoida &s,const double broj){
    if(std::abs(broj)<1e-8)
    throw std::domain_error("Dijeljenje sinusoidom s nulom nije dozvoljeno.");

    return Sinusoida(s.A/broj,s.frek,s.fi);
}
inline Sinusoida &operator+=(Sinusoida &s1,const Sinusoida &s){
    s1=s1+s;
    return s1;
}
inline Sinusoida &operator-=(Sinusoida &s1,const Sinusoida &s){
s1=s1-s;
    return s1;
}
inline Sinusoida &operator*=(Sinusoida &s,const double broj){
s=s*broj;
    return s;
}
Sinusoida &operator/=(Sinusoida &s,const double broj){
    if(std::abs(broj)<1e-8)
    throw std::domain_error("Dijeljenje sinusoidom s nulom nije dozvoljeno.");

s=s/broj;
    return s;
}
double Sinusoida::operator()(double t)const{
    return A*std::sin(t);
}
double &Sinusoida::operator[](const std::string &s){
if(s=="A")
    return A;
else if(s=="w")
    return frek;
else if(s=="omega")
    return frek;
else if(s=="fi")
    return fi;
else if(s=="phi")
    return fi;
else
    throw std::domain_error("Neispravan naziv parametra");
}
double Sinusoida::operator[](const std::string &s) const{
if(s=="A")
    return A;
else if(s=="w")
    return frek;
else if(s=="omega")
    return frek;
else if(s=="fi")
    return fi;
else if(s=="phi")
    return fi;
else
    throw std::domain_error("Neispravan naziv parametra");
}
Sinusoida operator*(const double broj,const Sinusoida &s){
    return s*broj;
}
Sinusoida operator/(const double broj,const Sinusoida &s){
    if(std::abs(s.DajAmplitudu())<1e-8)
    throw std::domain_error("Dijeljenje sinusoidom s nulom nije dozvoljeno.");

    return Sinusoida(broj/s.DajAmplitudu(),s.DajFrekvenciju(),s.DajFazu());
}
int main ()
{
    
    return 0;
}
