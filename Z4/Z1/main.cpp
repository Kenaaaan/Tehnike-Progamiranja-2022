// TP 2022/2023: Zadaća 4, Zadatak 1
#include <cmath>
#include <iostream>
#include <new>
#include <utility>
#include <vector>
#include <algorithm>
const double pi=std::acos(-1);
const double eps = 1e-10;
using par = std::pair<double, double>;
const double PI = 2 * std::acos(0.0);
class Krug {
  double poluprecnik;
  par centar;
  static bool Jednaki(double a, double b){
    return (std::abs(a-b)<=eps*(std::abs(a)+std::abs(b)));
  }
public:
  explicit Krug(double poluprecnik = 0);
  explicit Krug(const std::pair<double, double> &centar, double poluprecnik = 0);
  par DajCentar() const {  return centar; }
  double DajPoluprecnik() const { return poluprecnik; }
  double DajObim() const { return 2 * poluprecnik * pi; }
  double DajPovrsinu() const { return  poluprecnik * poluprecnik * pi; }
  Krug &PostaviCentar(const std::pair<double, double> &centar);
  Krug &PostaviPoluprecnik(double poluprecnik);
  void Ispisi() const;
  Krug &Transliraj(double delta_x, double delta_y);
  Krug &Rotiraj(double alpha);
  Krug &Rotiraj(const std::pair<double, double> &centar_rotacije, double alpha);
  static double RastojanjeCentara(const Krug &k1, const Krug &k2);
  static bool DaLiSuIdenticni(const Krug &k1, const Krug &k2);
  static bool DaLiSuPodudarni(const Krug &k1, const Krug &k2);
  static bool DaLiSuKoncentricni(const Krug &k1, const Krug &k2);
  static bool DaLiSeDodirujuIzvani(const Krug &k1, const Krug &k2);
  static bool DaLiSeDodirujuIznutri(const Krug &k1, const Krug &k2);
  static bool DaLiSePreklapaju(const Krug &k1, const Krug &k2);
  static bool DaLiSeSijeku(const Krug &k1, const Krug &k2);
  bool DaLiSadrzi(const Krug &k) const;
  friend Krug TransliraniKrug(const Krug &k, double delta_x, double delta_y);
  friend Krug RotiraniKrug(const Krug &k, double alpha);
  friend Krug RotiraniKrug(const Krug &k, const std::pair<double, double> &centar_rotacije, double alpha);
};
//
Krug::Krug(double r):poluprecnik(r),centar(std::make_pair(0,0)){
  if (r <0)
    throw std::domain_error("Nedozvoljen poluprecnik");
}
//
Krug::Krug(const par &p, double r) {
     if (r <0)
    throw std::domain_error("Nedozvoljen poluprecnik");
  centar.first = p.first;
  centar.second = p.second;
  poluprecnik = r;
}
//
Krug &Krug::PostaviCentar(const std::pair<double, double> &centar) {
  Krug::centar.first = centar.first;
  Krug::centar.second = centar.second;
  return *this;
}
//
Krug &Krug::PostaviPoluprecnik(double poluprecnik) {
  if(poluprecnik<0) throw std::domain_error("Nedozvoljen poluprecnik");
  Krug::poluprecnik = poluprecnik;
  return *this;
}
//
void Krug::Ispisi() const {
    std::cout<<"{("<<DajCentar().first<<","<<DajCentar().second<<"),"<<DajPoluprecnik()<<"}";
}
Krug& Krug::Transliraj(double deltax, double deltay){
centar.first+=deltax;   centar.second+=deltay;
return *this;
}
Krug &Krug::Rotiraj(double alfa){

    double stari_x=centar.first;
    double stari_y=centar.second;
    double novi_x=stari_x*std::cos(alfa)-stari_y*std::sin(alfa);
    double novi_y=stari_x*std::sin(alfa)+stari_y*std::cos(alfa);
    centar.first=novi_x;
    centar.second=novi_y;
    return *this;
}
Krug &Krug::Rotiraj(const par &a,double alfa){
    if(alfa==0)
        return *this;
    double stari_x=centar.first;
    double stari_y=centar.second;
    centar.first=a.first + (stari_x-a.first)*std::cos(alfa)-(stari_y - a.second)*std::sin(alfa);
    centar.second=a.second + (stari_x-a.first)*std::sin(alfa)+(stari_y-a.second)*std::cos(alfa);
    return *this;
}
double Krug::RastojanjeCentara(const Krug &k1,const Krug &k2){
return std::sqrt(std::pow(k2.centar.first - k1.centar.first,2)
+std::pow(k2.centar.second - k1.centar.second,2));
}
//
bool Krug::DaLiSuIdenticni(const Krug &k1, const Krug &k2){
    return std::fabs(k1.centar.second-k2.centar.second)<=eps &&
    std::fabs(k1.centar.first-k2.centar.first)<=eps && std::fabs(k1.poluprecnik-k2.poluprecnik)<=eps;
}
//
bool Krug::DaLiSuPodudarni(const Krug &k1, const Krug &k2){
    return Jednaki(k1.poluprecnik,k2.poluprecnik);
}
//
bool Krug::DaLiSuKoncentricni(const Krug &k1, const Krug &k2){
    return (Jednaki(k1.centar.first,k2.centar.first) && Jednaki(k1.centar.second,k2.centar.second));
}
//
bool Krug::DaLiSeDodirujuIzvani(const Krug &k1, const Krug &k2){
    return (Jednaki(RastojanjeCentara(k1,k2) , (k1.poluprecnik+k2.poluprecnik)));
}
//
bool Krug::DaLiSeDodirujuIznutri(const Krug &k1, const Krug &k2){
    return (Jednaki(RastojanjeCentara(k1,k2),std::abs((k1.poluprecnik-k2.poluprecnik))));
}
//
bool Krug::DaLiSePreklapaju(const Krug &k1, const Krug &k2){
    if(RastojanjeCentara(k1,k2)<std::abs(k1.poluprecnik-k2.poluprecnik))
        return true;
    if(RastojanjeCentara(k1,k2) < k1.poluprecnik+k2.poluprecnik)
        return true;
    return false;
}
//
bool Krug::DaLiSeSijeku(const Krug &k1, const Krug &k2){
    double d=RastojanjeCentara(k1, k2);
   return (k1.poluprecnik+k2.poluprecnik-d>eps && d-std::fabs(k1.poluprecnik - k2.poluprecnik)>eps) ;
}
//
bool Krug::DaLiSadrzi(const Krug &k) const{
    if(RastojanjeCentara(*this,k) +(k.poluprecnik<poluprecnik
    || Jednaki(k.poluprecnik,poluprecnik)))
        return true;
    return false;
}
//
Krug TransliraniKrug(const Krug &k, double deltax, double deltay){
    Krug rez;
    rez.centar.first=k.centar.first+deltax;    rez.centar.second=k.centar.second+deltay;
    return rez;
}
//
Krug RotiraniKrug(const Krug &k, double alfa){
    Krug rez;
    rez.centar.first=k.centar.first*std::cos(alfa)-k.centar.second*std::sin(alfa);
    rez.centar.second=k.centar.first*std::sin(alfa)-k.centar.second*std::cos(alfa);
    return rez;
}
//
Krug RotiraniKrug(const Krug &k, const par &a,double alfa){
    Krug rez;
    rez.centar.first=a.first + (k.centar.first-a.first)*std::cos(alfa)-(k.centar.second-a.second)*std::sin(alfa);
    rez.centar.second=a.second+(k.centar.first-a.first)*std::sin(alfa)-(k.centar.second-a.second)*std::cos(alfa);
    return rez;
}
int main()
{
    
    
  int n;
  std::cout<<"Unesite broj krugova: ";
  std::cin>>n;
    if(n<=0) {std::cout<<"Uneseni broj nije prirodan!";return 0; }
    Krug **krugovi=nullptr;
  try{Krug **krugovi= new Krug*[n];
  for(int i{};i<n;i++)
  {
      double x,y,r;
      par lagan;
          std::cout<<"Unesite centar "<<i+1<<". kruga: ";
          std::cin>>x>>y;
          while(!std::cin){
            std::cin.ignore(1000,'\n');
            std::cin.clear();
            std::cout<<"Neispravne koordinate centra! Pokusajte ponovo: \n";
          std::cout<<"Unesite centar "<<i+1<<". kruga: ";
          std::cin>>x>>y;
          }
      
          std::cout<<"Unesite poluprecnik "<<i+1<<". kruga: ";
          std::cin>>r;
          while((!std::cin)||r<=0){
            std::cout<<"Neispravan poluprecnik! Pokusajte ponovo: \n";
            std::cin.ignore(1000, '\n');
          std::cin.clear();
          std::cout<<"Unesite centar "<<i+1<<". kruga: ";
          std::cin>>x>>y;
            std::cout<<"Unesite poluprecnik "<<i+1<<". kruga: ";
          std::cin>>r;
          }
      lagan=std::make_pair(x,y);
      try{
        krugovi[i] = new Krug(lagan,r);
      }catch(std::domain_error){std::cout<<"greska!"<<std::endl;i--;}
     
  }
  //krugovi[0]->Ispisi();
  double deltax,deltay;
  std::cout<<"Unesite parametre translacije (delta_x,delta_y): ";
  std::cin>>deltax>>deltay;
  for(int i{};i<n;i++){
      krugovi[i]->Transliraj(deltax,deltay);
  }
  double alfa;
  std::cout<<"Unesite ugao rotacije oko tacke (0,0) u stepenima: ";
  std::cin>>alfa;
   alfa=alfa*(PI/180);
  for(int i{};i<n;i++){
      krugovi[i]->Rotiraj(alfa);
  }
  std::sort(krugovi,krugovi+n,[](Krug*k1,Krug*k2){return k1->DajPovrsinu()<k2->DajPovrsinu();});
std::cout<<"Parametri krugova nakon obavljene transformacije su:\n";
for(int i{};i<n;i++)
    {
        krugovi[i]->Ispisi();
        std::cout<<std::endl;
    }
    Krug* max_obim = nullptr;
    if(n>1) max_obim = krugovi[0];
    for(int i=1;i<n;i++)
    {
        if(krugovi[i]->DajObim()>max_obim->DajObim())
            max_obim=krugovi[i];
    }
//
std::cout<<"Krug sa najvecim obimom je: ";
max_obim->Ispisi();
std::cout<<std::endl;
//
bool mozda=false;
for(int i{};i<n;i++)
{
    for(int j=i+1;j<n;j++)
    {
        if(Krug::DaLiSeSijeku(*krugovi[i],*krugovi[j])  || Krug::DaLiSeDodirujuIznutri(*krugovi[i],*krugovi[j]) || Krug::DaLiSeDodirujuIzvani(*krugovi[i],*krugovi[j]))
        {mozda=true;
        std::cout<<"Presjecaju se krugovi:\n";
        krugovi[i]->Ispisi();
        std::cout<<" i ";
        krugovi[j]->Ispisi();
        std::cout<<std::endl;
        }
    }
}
if(!mozda){std::cout<<"Ne postoje krugovi koji se presjecaju!"<<std::endl;}
for(int i=0;i<n;i++){
    delete krugovi[i];
}
    
delete [] krugovi;
  }catch(std::bad_alloc){std::cout<<"Problemi sa alokacijom memorije!";}
  return 0;
}