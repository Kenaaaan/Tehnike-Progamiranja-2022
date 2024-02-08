#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits>
#include <deque>
int main ()
{
    std::cout<<"Unesite broj elemenata: ";
    int n;
    std::cin>>n;
    std::deque<int> d;
    std::deque<int>::iterator it=d.begin();
    std::cout<<"Unesite elemente: ";
    std::for_each(it,it+n,[](int &x){std::cin>>x;});
    std::deque<int> b;
    std::deque<int>::iterator p3=b.begin();
    std::cout<<"Najveci element deka je "<<*std::max_element(it,it+n)<<std::endl;
    std::cout<<"Najmanji element deka se pojavljuje "<<std::count(it,it+n,*std::min_element(it,it+n))<<" puta u deku"<<std::endl;
    std::cout<<"U deku ima "<<std::count_if(it,it+n,[](int n){int k=std::sqrt(n);return (k*k==n); })<<" brojeva koji su potpuni kvadrati"<<std::endl;
    std::cout<<"Prvi element sa najmanjim brojem cifara je "<<*std::min_element(it,it+n,[](int n,int m){return (floor(log10(fabs(n))+1)<floor(log10(fabs(m))+1));})<<std::endl;
    std::cout<<"Elementi koji nisu trocifreni su: ";
    std::transform(it,it+n,p3,[](int x){if(3!=floor(log10(fabs(x))+1))std::cout<<x<<" ";return 0;});  
	return 0;
}
