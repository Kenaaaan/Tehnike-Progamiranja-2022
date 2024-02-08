#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits>
#include <vector>
template <typename tip>
using matrica = std::vector<std::vector<tip>>;
bool F1(int n)
{
   // matrica<int> m;
int k=std::sqrt(n);
return (k*k==n);
}
//
bool F2(int n,int m)
{
    return (floor(log10(fabs(n))+1)<floor(log10(fabs(m))+1));
}
//
int F3(int x)
{
    if(3!=floor(log10(fabs(x))+1))std::cout<<x<<" ";
    return 0;
}
//
void Unos(int &x)
{
    std::cin>>x;
}
int main ()
{
    //matrica<double> dm;
    std::cout<<"Unesite broj elemenata (max. 1000): ";
    int n;
    std::cin>>n;
    int a[1000];
    int *p1;
    p1=&a[0];
    auto pok=Unos;
    std::cout<<"Unesite elemente: ";
    std::for_each(p1,p1+n,pok);
    int b[1000];
    int *p3=b;
    std::cout<<"Najveci element niza je "<<*std::max_element(p1,p1+n)<<std::endl;
    std::cout<<"Najmanji element niza se pojavljuje "<<std::count(p1,p1+n,*std::min_element(p1,p1+n))<<" puta u nizu"<<std::endl;
    auto pok_F1=F1;
    auto pok_F2=F2;
    auto pok_F3=F3;
    std::cout<<"U nizu ima "<<std::count_if(p1,p1+n,pok_F1)<<" brojeva koji su potpuni kvadrati"<<std::endl;
    std::cout<<"Prvi element sa najmanjim brojem cifara je "<<*std::min_element(p1,p1+n,pok_F2)<<std::endl;
    std::cout<<"Elementi koji nisu trocifreni su: ";
    std::transform(p1,p1+n,p3,pok_F3);
	return 0;
}
