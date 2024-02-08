//TP 2022/2023: Zadaća 5, Zadatak 2
#include <iostream>
#include <cmath>
#include<vector>
#include<functional>
#include <algorithm>
#include <stdexcept>
int greska(int a){
    if(a<0)
        throw std::domain_error("Nekorektan rezultat operacije");
    return a;
}
class Padavine {
std::vector<int> kolicine;
int max;
public:
explicit Padavine(int max);
void RegistrirajPadavine(int a);
int DajBrojRegistriranihPadavina() const;
void BrisiSve();
int DajMinimalnuKolicinuPadavina() const;
int DajMaksimalnuKolicinuPadavina() const;
int DajBrojDanaSaPadavinamaVecimOd(int a)const;
void Ispisi() const;
int operator[](int index)const;
friend Padavine &operator++(Padavine &p);
friend Padavine operator++(Padavine &p,int);
friend Padavine &operator--(Padavine &p);
friend Padavine operator--(Padavine &p, int);
friend Padavine operator+(Padavine &p1,int n);//
friend Padavine operator+(int n,Padavine &p1);//
friend Padavine operator-(int n,Padavine &p1);//
friend Padavine operator-(Padavine &p1,int n);//
friend Padavine operator+(const Padavine &p1,const Padavine &p2);//
friend Padavine operator-(const Padavine &p1,const Padavine &p2);//
friend bool operator==(const Padavine &p1,const Padavine &p2);//
friend bool operator!=(const Padavine &p1,const Padavine &p2);//
friend Padavine &operator+=(Padavine &p1,const Padavine &p2);//
friend Padavine &operator-=(Padavine &p1,const Padavine &p2);//
friend Padavine &operator+=(Padavine &p1,int n);//
friend Padavine &operator-=(Padavine &p1,int n);//
friend Padavine &operator-(Padavine &p);//
};
Padavine &operator++(Padavine &p){
    std::transform(p.kolicine.begin(),p.kolicine.end(),p.kolicine.begin(),std::bind(std::plus<int>(),std::placeholders::_1,1));
    p.max=p.max+1;
    return p;
}
Padavine operator++(Padavine &p,int){
    Padavine rez=p;
    ++(p);
    return rez;
}
Padavine &operator--(Padavine &p){
    std::transform(p.kolicine.begin(),p.kolicine.end(),p.kolicine.begin(),std::bind(std::minus<int>(),std::placeholders::_1,1));
    p.max=p.max-1;
    return p;
}
Padavine operator--(Padavine &p,int){
    Padavine rez=p;
    --(p);
    return rez;
}
Padavine &operator-(Padavine &p){
    std::transform(p.kolicine.begin(),p.kolicine.end(),p.kolicine.begin(),std::bind(std::minus<int>(),p.max,std::placeholders::_1));
    return p;
}
bool operator!=(const Padavine &p1,const Padavine &p2){
    return !(p1==p2);
}
bool operator==(const Padavine &p1,const Padavine &p2){
    if(p1.kolicine.size()!=p2.kolicine.size())
        return false;
  //  return std::all_of(p1.kolicine.begin(),p1.kolicine.end(),p2.kolicine.begin(),std::bind(std::equal_to<int>(),std::placeholders::_1,std::placeholders::_2));
    return p1.kolicine==p2.kolicine;
}
Padavine &operator-=(Padavine &p1,int n){
    p1=p1-n;
    return p1;
}
Padavine &operator-=(Padavine &p1,const Padavine &p2){
    p1=p1-p2;
    return p1;
}
Padavine &operator+=(Padavine &p1,int n){
    p1=p1+n;
    return p1;
}
Padavine &operator+=(Padavine &p1,const Padavine &p2){
    p1=p1+p2;
    return p1;
}
Padavine operator-(const Padavine &p1,const Padavine &p2){
    if(p1.kolicine.size()!=p2.kolicine.size() || (std::equal(p1.kolicine.begin(),p1.kolicine.end(),p2.kolicine.begin(),std::less<int>())))
        throw std::domain_error("Nesaglasni operandi");
    
    Padavine rez(p1.max);
    rez.kolicine.resize(p1.kolicine.size());
    std::transform(p1.kolicine.begin(),p1.kolicine.end(),p2.kolicine.begin(),rez.kolicine.begin(),std::minus<int>());
    return rez;
}
Padavine operator+(const Padavine &p1,const Padavine &p2){
    Padavine rez(p1.max);
    rez.kolicine.resize(p1.kolicine.size());
    std::transform(p1.kolicine.begin(),p1.kolicine.end(),p2.kolicine.begin(),rez.kolicine.begin(),std::bind(std::plus<int>(),std::placeholders::_1,std::placeholders::_2));
    return rez;
}
Padavine operator+(Padavine &p1,int n){
    p1=n+p1;
    return p1;
}
Padavine operator+(int n,Padavine &p1){ 
    Padavine novi(p1.max+n);
    novi.kolicine=p1.kolicine;
    std::transform(p1.kolicine.begin(),p1.kolicine.end(),novi.kolicine.begin(),std::bind(std::plus<int>(),std::placeholders::_1,n));
    if(!std::all_of(novi.kolicine.begin(),novi.kolicine.end(),std::bind(std::greater<int>(),std::placeholders::_1,0)))
        throw std::domain_error("Nekorektan rezultat operacije");
    return novi;
    //OVDJE SAM SAMO KOPIRAO VEC URADJENU FUNKCIJU GORE JER SU ISTE IMPLEMENTACIJE!!    ali sam pogrijesio pa sam je ipak morao mijenjati :/
}
Padavine operator-(Padavine &p1,int n){
    Padavine novi(p1.max-n);
    novi.kolicine=p1.kolicine;
    std::transform(p1.kolicine.begin(),p1.kolicine.end(),novi.kolicine.begin(),std::bind(std::minus<int>(),std::placeholders::_1,n));
    if(!std::all_of(novi.kolicine.begin(),novi.kolicine.end(),std::bind(std::greater<int>(),std::placeholders::_1,0)))
        throw std::domain_error("Nekorektan rezultat operacije");
    
    return novi;
}
Padavine operator-(int n,Padavine &p1){
    Padavine novi(p1.max-n);
    novi.kolicine=p1.kolicine;
    std::transform(p1.kolicine.begin(),p1.kolicine.end(),novi.kolicine.begin(),std::bind(std::minus<int>(),std::placeholders::_1,n));
    if(!std::all_of(p1.kolicine.begin(),p1.kolicine.end(),std::bind(std::greater<int>(),std::placeholders::_1,0)))
        throw std::domain_error("Nekorektan rezultat operacije");
    
    return novi;
}
Padavine::Padavine(int max):max(max){if(max<=0)throw std::range_error("Ilegalna maksimalna kolicina");}
void Padavine::RegistrirajPadavine(int kolicina){
    if(kolicina<0 || kolicina>max)
        throw std::range_error("Ilegalna kolicina padavina");
    kolicine.push_back(kolicina);
}
int Padavine::DajBrojRegistriranihPadavina() const{return kolicine.size();}

void Padavine::BrisiSve(){kolicine.resize(0);}

int Padavine::DajMinimalnuKolicinuPadavina() const{
    if(kolicine.size()==0)
        throw std::range_error("Nema registriranih padavina");
    
    return *std::min_element(kolicine.begin(),kolicine.end());
}
int Padavine::DajMaksimalnuKolicinuPadavina() const{
    if(kolicine.size()==0)
        throw std::range_error("Nema registriranih padavina");
    
    return *std::max_element(kolicine.begin(),kolicine.end());
}
int Padavine::DajBrojDanaSaPadavinamaVecimOd(int s) const {
    if(kolicine.size()==0)
        throw std::range_error("Nema registriranih padavina");
    
    return std::count_if(kolicine.begin(),kolicine.end(),
    std::bind(std::greater<int>(),std::placeholders::_1,s));
}
void Padavine::Ispisi() const{
    if(kolicine.size()==0)
        throw std::range_error("Nema registriranih padavina");
    std::vector<int> pomocna=kolicine;
    std::sort(pomocna.begin(),pomocna.end(),std::bind(std::greater<int>(),std::placeholders::_1,std::placeholders::_2));
for(int x:pomocna)
    std::cout<<x<<std::endl;
}
int Padavine::operator[](int index) const{
    if(index<1 || index>static_cast<int>(kolicine.size()))
        throw std::range_error("Neispravan indeks");
    
    return kolicine[index-1];
}
int main ()
{


	return 0;
}