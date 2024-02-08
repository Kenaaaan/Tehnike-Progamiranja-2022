#include <iostream>
#include <new>
#include <forward_list>
#include <type_traits>
#include <vector>
template <typename tip>
auto KreirajIzvrnutiNiz(tip p1, tip p2){
    tip pom=p1;
    int n=0;
    while(pom!=p2){
        n++;
        pom++;
    }
    tip niz;
    try{
        niz=new typename std::remove_reference<decltype(*p1)>::type [n];
    }catch(...){
        throw std::domain_error("nije uspjela alokacija");
    }
    for(int i=n-1;i>=0;i--)
    {
        niz[i]=*p1++;
    }
    return niz;
}


