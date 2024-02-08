//TP 2022/2023: LV 6, Zadatak 1
#include <exception>
#include <iostream>
#include <cmath>
#include <new>
#include <stdexcept>
#include <limits>
template <typename tip>
tip *GenerirajStepeneDvojke(int n)
{
    if(n<=0) throw std::domain_error("Broj elemenata mora biti pozitivan");
    if(n> std::numeric_limits<tip>::max()) throw std::overflow_error("Prekoracen dozvoljeni opseg");
    tip *p;
   try {
   tip *xD=new tip[n];
   p=xD;
   } catch (...) {
   throw std::runtime_error("Alokacija nije uspjela");
   }
    for(int i=0;i<n;i++)
    {
        if(std::pow(2,i)>std::numeric_limits<tip>::max())
        {
            delete [] p;
            throw std::overflow_error("Prekoracen dozvoljeni opseg");
        }
        p[i]=std::pow(2,i);
    }
    return p;
}
int main ()
{ 
    try {
    std::cout<<"Koliko zelite elemenata: ";
    int n;
    std::cin>>n;
    auto p = GenerirajStepeneDvojke<int>(n);
    for(int i=0;i<n;i++) std::cout<<p[i]<<" ";
    delete [] p;
    } catch (std::domain_error lol) 
    {
        std::cout<<"Izuzetak: "<<lol.what();
    }
    catch(std::overflow_error e) 
    {
    std::cout << "Izuzetak: " << e.what();
    }
    catch(...)
    {
        std::cout << "Pogrešan izuzetak!";
    }
	return 0;
}
