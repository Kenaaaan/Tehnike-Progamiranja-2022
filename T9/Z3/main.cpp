//TP 2022/2023: LV 9, Zadatak 1
#include <iostream>
#include <cmath>
class Vektor3d {
double koordinate[3];
mutable int brojac=0;
public:
Vektor3d &PostaviX(double s)
{
    koordinate[0]=s;
    return *this;
}
Vektor3d &PostaviY(double s)
{
    koordinate[1]=s;
    return *this;
}
Vektor3d &PostaviZ(double s)
{
    koordinate[2]=s;
    return *this;
}
 void Postavi(double x, double y, double z) {
 Vektor3d::koordinate[0] = x; Vektor3d::koordinate[1] = y; Vektor3d::koordinate[2] = z;
 }
 void Ocitaj(double &x, double &y, double &z) const {
 x = Vektor3d::koordinate[0]; y = Vektor3d::koordinate[1]; z = Vektor3d::koordinate[2];
 }
 void Ispisi() const {
     brojac++;
 std::cout << "{" << koordinate[0] << "," << koordinate[1] << "," << koordinate[2] << "}";
    
 }
 double DajX() const { return koordinate[0]; }
 double DajY() const { return koordinate[1]; }
 double DajZ() const { return koordinate[2]; }
 double DajDuzinu() const { return std::sqrt(koordinate[0] * koordinate[0] + koordinate[1] * koordinate[1] + koordinate[2] * koordinate[2]); }
Vektor3d &PomnoziSaSkalarom(double s) {
 koordinate[0] *= s; koordinate[1] *= s; koordinate[2] *= s;
 return *this;
 }
 Vektor3d &SaberiSa(const Vektor3d &v) {
 koordinate[0] += v.koordinate[0]; koordinate[1] += v.koordinate[1]; koordinate[2] += v.koordinate[2];
 return *this;
 }
 friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2)
 {
    Vektor3d v3;
    v3.koordinate[0]= v1.DajX()+v2.DajX();
    v3.koordinate[1]=v1.DajY()+v2.DajY();
    v3.koordinate[2]=v1.DajZ()+v2.DajZ();
    return v3;
 }
 int DajBrojIspisa() const {return brojac;}
};
int main ()
{
    Vektor3d v;
    int x,y,z;
    std::cout<<"Unesite koordinate!"<<std::endl;
    std::cin>>x>>y>>z;
    v.Postavi(x,y,z);
    v.Ispisi();
    int s;
    std::cout<<"\nUnesite skalar kojim mnozimo vektor!"<<std::endl;
    std::cin>>s;
    v.PomnoziSaSkalarom(s);
    v.Ispisi();
    std::cout<<"\nUnesite koordinate drugog vektora!"<<std::endl;
    Vektor3d v2;
    std::cin>>x>>y>>z;
    v2.Postavi(x,y,z);
    std::cout<<"Zbir ova dva vektora je: "<<ZbirVektora(v,v2).DajX()<<","<<ZbirVektora(v,v2).DajY()<<","<<ZbirVektora(v,v2).DajZ();
	return 0;
}
