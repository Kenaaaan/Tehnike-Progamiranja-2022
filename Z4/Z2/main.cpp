// TP 2022/2023: Zadaća 4, Zadatak 1
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
const double eps = 1e-10;
using par = std::pair<double, double>;
const double pi = 2 * std::acos(0.0);
class NepreklapajuciKrug {
  double poluprecnik;
  static int aktivni;
  par centar;
  NepreklapajuciKrug * prethodni=zadnji;
  static NepreklapajuciKrug *zadnji;
  bool DaLiSePreklapaju(const NepreklapajuciKrug &k) const{
      return RastojanjeCentara(*this,k) <=k.poluprecnik+poluprecnik;
  }
  static bool Jednaki(double a, double b){
    return (std::abs(a-b)<=eps*(std::abs(a)+std::abs(b)));
  }
  bool MakarJedan() const {
      const NepreklapajuciKrug *trazeni=zadnji;
      while(true){
          if(aktivni==1)
      
          if()
      }
  }
public:
  explicit NepreklapajuciKrug(double poluprecnik = 0);
  explicit NepreklapajuciKrug(const std::pair<double, double> &centar, double poluprecnik = 0);
  par DajCentar() const {  return centar; }
  double DajPoluprecnik() const { return poluprecnik; }
  double DajObim() const { return 2 * poluprecnik * pi; }
  double DajPovrsinu() const { return 2 * poluprecnik * poluprecnik * pi; }
  NepreklapajuciKrug &PostaviCentar(const std::pair<double, double> &centar);
  NepreklapajuciKrug &PostaviPoluprecnik(double poluprecnik);
  void Ispisi() const;
  NepreklapajuciKrug &Transliraj(double delta_x, double delta_y);
  NepreklapajuciKrug &Rotiraj(double alpha);
  NepreklapajuciKrug &Rotiraj(const std::pair<double, double> &centar_rotacije, double alpha);
  static double RastojanjeCentara(const NepreklapajuciKrug &k1, const NepreklapajuciKrug &k2);
bool  DaLiSadrzi(const NepreklapajuciKrug &k) const;
};
NepreklapajuciKrug *NepreklapajuciKrug::zadnji=nullptr;
int NepreklapajuciKrug::aktivni=0;
//
NepreklapajuciKrug::NepreklapajuciKrug(double r) {
  if (r <=0)
    throw std::logic_error("Nedozvoljen poluprecnik");
    aktivni++;
  poluprecnik = r;
  centar.first = 0;
  centar.second = 0;
  if(aktivni)
{

}
}
//
NepreklapajuciKrug::NepreklapajuciKrug(const par &p, double r) {
     if (r <=0)
    throw std::logic_error("Nedozvoljen poluprecnik");
  centar.first = p.first;
  centar.second = p.second;
  poluprecnik = r;
}
//
NepreklapajuciKrug &NepreklapajuciKrug::PostaviCentar(const std::pair<double, double> &centar) {
  NepreklapajuciKrug::centar.first = centar.first;
  NepreklapajuciKrug::centar.second = centar.second;
  return *this;
}
//
NepreklapajuciKrug &NepreklapajuciKrug::PostaviPoluprecnik(double poluprecnik) {
  if(poluprecnik<0) throw std::domain_error("Nedozvoljen poluprecnik");
  NepreklapajuciKrug::poluprecnik = poluprecnik;
  return *this;
}
//
void NepreklapajuciKrug::Ispisi() const {
    std::cout<<"{("<<DajCentar().first<<","<<DajCentar().second<<"),"<<DajPoluprecnik()<<"}";
}
NepreklapajuciKrug &NepreklapajuciKrug::Transliraj(double deltax, double deltay){
centar.first=centar.first+deltax;   centar.second=centar.second+deltay;
return *this;
}
NepreklapajuciKrug &NepreklapajuciKrug::Rotiraj(double alfa){
    double stari_x=centar.first;
    double stari_y=centar.second;
    double novi_x=stari_x*std::cos(alfa)-stari_y*std::sin(alfa);
    double novi_y=stari_x*std::asin(alfa)-stari_y*std::cos(alfa);
    centar.first=novi_x;
    centar.second=novi_y;
    return *this;
}
NepreklapajuciKrug &NepreklapajuciKrug::Rotiraj(const par &a,double alfa){
    centar.first=a.first + (centar.first-a.first)*std::cos(alfa)-(centar.second - a.second)*std::sin(alfa);
    centar.second=a.second + (centar.first-a.first)*std::sin(alfa)-(centar.second-a.second)*std::cos(alfa);
    return *this;
}
double NepreklapajuciKrug::RastojanjeCentara(const NepreklapajuciKrug &k1,const NepreklapajuciKrug &k2){
return std::sqrt(std::pow(k2.centar.first - k1.centar.first,2)
+std::pow(k2.centar.second - k1.centar.second,2));
}

//

int main()
{
    
  int n;
  std::cout<<"Unesite broj NepreklapajuciKrugova: ";
  std::cin>>n;
    if(n<=0) {std::cout<<"Uneseni broj nije prirodan!";return 0; }
  NepreklapajuciKrug **NepreklapajuciKrugovi= new NepreklapajuciKrug*[n];
  for(int i{};i<n;i++)
  {
      double x,y,r;
      par lagan;
          std::cout<<"Unesite centar "<<i+1<<". NepreklapajuciKruga: ";
          std::cin>>x>>y;
          while(!std::cin){
            std::cin.ignore(1000,'\n');
            std::cin.clear();
            std::cout<<"Neispravne koordinate centra! Pokusajte ponovo: \n";
          std::cout<<"Unesite centar "<<i+1<<". NepreklapajuciKruga: ";
          std::cin>>x>>y;
          }
      
          std::cout<<"Unesite poluprecnik "<<i+1<<". NepreklapajuciKruga: ";
          std::cin>>r;
          while((!std::cin)||r<=0){
            std::cout<<"Neispravan poluprecnik! Pokusajte ponovo: \n";
            std::cin.ignore(1000, '\n');
          std::cin.clear();
          std::cout<<"Unesite centar "<<i+1<<". NepreklapajuciKruga: ";
          std::cin>>x>>y;
            std::cout<<"Unesite poluprecnik "<<i+1<<". NepreklapajuciKruga: ";
          std::cin>>r;
          }
      lagan=std::make_pair(x,y);
      try{
        NepreklapajuciKrugovi[i] = new NepreklapajuciKrug(lagan,r);
      }catch(...){std::cout<<"greska!"<<std::endl;i--;}
  }
  double deltax,deltay;
  std::cout<<"Unesite parametre translacije (delta_x,delta_y): ";
  std::cin>>deltax>>deltay;
  for(int i{};i<n;i++){
      NepreklapajuciKrugovi[i]->Transliraj(deltax,deltay);
  }
  double alfa;
  std::cout<<"Unesite ugao rotacije oko tacke (0,0) u stepenima: ";
  std::cin>>alfa;
  for(int i{};i<n;i++){
      NepreklapajuciKrugovi[i]->Rotiraj(alfa);
  }
  std::sort(NepreklapajuciKrugovi,NepreklapajuciKrugovi+n,[](NepreklapajuciKrug*k1,NepreklapajuciKrug*k2){return k1->DajPovrsinu()<k2->DajPovrsinu();});
std::cout<<"Parametri NepreklapajuciKrugova nakon obavljene transformacije su:\n";
for(int i{};i<n;i++)
    {
        NepreklapajuciKrugovi[i]->Ispisi();
        std::cout<<std::endl;
    }
    NepreklapajuciKrug* max_obim = nullptr;
    if(n>1) max_obim = NepreklapajuciKrugovi[0];
    for(int i=1;i<n;i++)
    {
        if(NepreklapajuciKrugovi[i]->DajObim()>max_obim->DajObim())
            max_obim=NepreklapajuciKrugovi[i];
    }

std::cout<<"NepreklapajuciKrug sa najvecim obimom je: ";
max_obim->Ispisi();
std::cout<<std::endl;

bool mozda=false;
for(int i{};i<n;i++)
{
    for(int j=i+1;j<n;j++)
    {
       // if(NepreklapajuciKrug::DaLiSeSijeku(*NepreklapajuciKrugovi[i],*NepreklapajuciKrugovi[j]))
        {mozda=true;
        std::cout<<"NepreklapajuciKrug "<<i+1<<" i NepreklapajuciKrug "<<j+1<<std::endl;
        }
    }
}
if(!mozda){std::cout<<"Ne postoje NepreklapajuciKrugovi koji se presjecaju!"<<std::endl;}
for(int i=0;i<n;i++){
    delete NepreklapajuciKrugovi[i];
}
    
delete [] NepreklapajuciKrugovi;

  return 0;
}