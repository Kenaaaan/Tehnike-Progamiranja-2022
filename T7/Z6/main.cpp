//TP 2022/2023: LV 7, Zadatak 6
#include <iostream>
#include <cmath>
#include <list>

template <typename tip>
std::list<tip> SortirajListu(std::list<tip> &lista)
{
    typename std::list<tip>::iterator it=lista.begin();
    while(it!=lista.end())
    {
        it++;
    typename std::list<tip>::iterator it2=it;
    it--;
    auto min=it;
    while(it2 !=lista.end())
    {
        if(*it2<*min)
        {
            min = it2;
        }
        it2++;
    }
    auto pomocni =*it;
    *it=*min;
    *min=pomocni;
    it++;
    }
    return lista;
}

int main ()
{
    std::cout<<"Koliko ima elemenata: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite elemente: ";
    std::list<int> lista(n);
    std::list<int>::iterator it = lista.begin();
    for(int i=0;i<n;i++)
    {
        std::cin>>*it++;
    }
 lista=SortirajListu(lista);
        std::cout<<"Sortirana lista: ";
        std::list<int>::iterator it2=lista.begin();
        for(int i=0;i<n;i++) std::cout<<*it2++<<" ";

	return 0;
}
/*Koliko ima elemenata: 5
Unesite elemente: 3 1 7 6 2
Sortirana lista: 1 2 3 6 7*/