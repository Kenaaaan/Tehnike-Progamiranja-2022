//TP 2022/2023: LV 9, Zadatak 1
#include <iostream>
#include <cmath>
class Vektor3d {
 double x, y, z;
public:
Vektor3d &PostaviX(double s)
{
    x=s;
    return *this;
}
Vektor3d &PostaviY(double s)
{
    y=s;
    return *this;
}
Vektor3d &PostaviZ(double s)
{
    z=s;
    return *this;
}
 void Postavi(double x, double y, double z) {
 Vektor3d::x = x; Vektor3d::y = y; Vektor3d::z = z;
 }
 void Ocitaj(double &x, double &y, double &z) const {
 x = Vektor3d::x; y = Vektor3d::y; z = Vektor3d::z;
 }
 void Ispisi() const {
 std::cout << "{" << x << "," << y << "," << z << "}";
 }
 double DajX() const { return x; }
 double DajY() const { return y; }
 double DajZ() const { return z; }
 double DajDuzinu() const { return std::sqrt(x * x + y * y + z * z); }
Vektor3d &PomnoziSaSkalarom(double s) {
 x *= s; y *= s; z *= s;
 return *this;
 }
 Vektor3d &SaberiSa(const Vektor3d &v) {
 x += v.x; y += v.y; z += v.z;
 return *this;
 }
 friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2)
 {
    Vektor3d v3;
    v3.x= v1.DajX()+v2.DajX();
    v3.y=v1.DajY()+v2.DajY();
    v3.z=v1.DajZ()+v2.DajZ();
    return v3;
 }
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
