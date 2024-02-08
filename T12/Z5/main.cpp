#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
int main ()
{
	std::cout<<"Koliko zelite elemenata: ";
	int n;
	std::cin>>n;
	std::vector<double> v(n);
	std::cout<<"Unesite elemente: ";
	for(int i=0; i<n; i++) std::cin>>v.at(i);
	std::transform(v.begin(),v.end(),v.begin(),std::bind(std::divides<double>(),1,std::placeholders::_1));
	std::cout<<"Transformirani elementi: ";
	for(auto x : v)
	std::cout<<x<<" ";
	return 0;
}