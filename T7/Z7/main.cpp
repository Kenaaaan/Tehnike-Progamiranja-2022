//TP 2022/2023: LV 7, Zadatak 7
#include <iostream>
#include <cmath>
#include <set>
template <typename tip>
std::set<tip> Presjek(std::set<tip> s1, std::set<tip> s2)
{
    std::set<tip> rez;
       for(tip x:s1)
       {
           for(tip y:s2)
           {
               if(x==y) rez.insert(x);
           }
        }
        return rez;
}
template <typename tip>
std::set<tip> Unija(std::set<tip> s1, std::set<tip> s2)
{
    std::set<tip> rez;
       for(tip x:s1)
       {
           rez.insert(x);
        }
         for(tip y:s2)
           {
             rez.insert(y);
           }
        return rez; 
}

int main ()
{


	return 0;
}
