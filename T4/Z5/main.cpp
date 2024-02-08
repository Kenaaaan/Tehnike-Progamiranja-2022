//TP 2022/2023: LV 4, Zadatak 5
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

template <typename xD>
std::vector<xD> Presjek(std::vector<xD> v1, std::vector<xD> v2)
{
    int brojac=0,brojac2=0;
    std::vector<xD> rez;
    for(xD x1:v1)
    {
        for(xD x2:v2)
        {
            if(x1==x2)
            {
                if(brojac2==0) rez.push_back(x1);
                for(xD xrez:rez)
                {
                    brojac2++;
                    if(x1!=xrez) brojac++;
                }
                if(brojac==rez.size()) rez.push_back(x1);
                brojac=0;
            }
        }
    }
    return rez; 
}
int main ()
{

    std::cout<<"Test za realne brojeve..."<<std::endl<<"Unesite broj elemenata prvog vektora: ";
    int m,n;
    std::cin>>m;
    std::vector<int> v1 ,v2,v3;
    std::cout<<"Unesite elemente prvog vektora: ";
    for(int i=0;i<m;i++)
    {
        int x;
        std::cin>>x;
        v1.push_back(x);
    }
    std::cout<<"Unesite broj elemenata drugog vektora: ";
    std::cin>>n;
    std::cout<<"Unesite elemente drugog vektora: ";
    for(int i=0;i<n;i++)
    {
        int x;
        std::cin>>x;
        v2.push_back(x);
    }
    std::cout<<"Zajednicki elementi su: ";
    v3=Presjek(v1, v2);
    for(int x:v3) std::cout<<x<<" ";
    std::cout<<std::endl;
    std::cout<<std::endl<<"Test za stringove..."<<std::endl;
    std::vector<std::string> s1 ,s2,s3;
    int a,b;
    std::cout<<"Unesite broj elemenata prvog vektora: ";
    std::cin>>a;
            std::cin.ignore(10000, '\n');
    std::cout<<"Unesite elemente prvog vektora (ENTER nakon svakog unosa): "<<std::endl;
    for(int i=0;i<a;i++)
    {
        std::string XO;
       std::getline(std::cin, XO);
       s1.push_back(XO);

    }
    std::cout<<"Unesite broj elemenata drugog vektora: ";
    std::cin>>b;
            std::cin.ignore(10000, '\n');

    std::cout<<"Unesite elemente drugog vektora (ENTER nakon svakog unosa): "<<std::endl;
    for(int i=0;i<b;i++)
    {
      std::string XO;
       std::getline(std::cin, XO);
       s2.push_back(XO);

    }
    std::cout<<"Zajednicki elementi su: ";
    s3=Presjek(s1,s2);
   for(std::string ispis: s3) std::cout<<ispis<<std::endl;

	return 0;
}
/*Test za realne brojeve...
Unesite broj elemenata prvog vektora: 10
Unesite elemente prvog vektora: 3 7 2 6 3 4 8 1 6 5
Unesite broj elemenata drugog vektora: 8
Unesite elemente drugog vektora: 4 9 5 9 7 0 4 6
Zajednicki elementi su: 7 6 4 5
Test za stringove...
Unesite broj elemenata prvog vektora: 3
Unesite elemente prvog vektora (ENTER nakon svakog unosa):
asd www xy
xvbb zzz ppe
strstr kvekk
Unesite broj elemenata drugog vektora: 3
Unesite elemente drugog vektora (ENTER nakon svakog unosa):
strstr kvekk
asd www xy
vuuvu
Zajednički elementi su:
asd www xy
strstr kvekk*/