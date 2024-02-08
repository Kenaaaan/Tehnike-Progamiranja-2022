#include <iostream>
#include <cmath>
#include <list>
int Poglavica(int n, int m,bool mozda=false)
{
    if(m<=0 || n<1) return 0;
    std::list<int> lista;
    for(int i=1;i<=n;i++) lista.push_back(i);
    std::list<int>::iterator it=lista.begin();
    while(lista.size()>1)
    {
        for(int i{};i<m-1;i++)
        {
            ++it;
            if(it==lista.end()) it=lista.begin();
        }
        if(mozda)std::cout<<*it<<", ";
        it=lista.erase(it);
        if(it==lista.end()) it=lista.begin();
    }
    return *it;
}
int SigurnoMjesto(int m, int N1, int N2)
{   
    if(m<=0 || N1<1 || N2<1 || N2<N1) return 0;
    std::list<int> lista;
    for(int i=N1;i<=N2;i++)lista.push_back(i);
    for(int i=N1;i<=N2;i++)
    {
        auto it=lista.begin();
        while(it!=lista.end())
        {
            if(*it==Poglavica(i,m,false))it=lista.erase(it);
            else it++;
        }
    }
    if(lista.size()==0) return 0;
    return *lista.begin();
}
int main ()
{   
    std::cout<<"Unesite broj punoljetnih clanova za odabir poglavice plemena Wabambe: ";
    int n,m,N1,N2;
    std::cin>>n;
    std::cout<<"Unesite korak razbrajanja: ";
    std::cin>>m;
    std::cout<<"Unesite raspon za odabir (N1 i N2): ";
    std::cin>>N1>>N2;
    std::cout<<"Redni broj osobe koja postaje poglavica: "<<Poglavica(n,m)<<std::endl;
    if(SigurnoMjesto(m,N1, N2)==0){std::cout<<"Zao mi je Mbebe Mgogo, ali nema sigurnog mjesta.";}
    else{std::cout<<"Mbebe Mgogo, stani na sigurno mjesto "<<SigurnoMjesto(m,N1, N2)<<" da ne bi bio poglavica!";}
	return 0;
}
