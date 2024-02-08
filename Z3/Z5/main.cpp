//TP 2022/2023: Zadaća 3, Zadatak 5
#include <iostream>
#include <cmath>
#include <list>
struct Cvor{
    int redni_broj;
    Cvor *sljedeci;
};
int Poglavica(int n,int m,bool mozda=false)
{
    if(m<=0 || n<1) return 0;
    if(m==1)return n;
    Cvor *pocetak=nullptr,*prethodni=nullptr;
    for(int i=1;i<=n;i++)
    {
        Cvor *novi = new Cvor{i,nullptr};
        if(!pocetak) pocetak=novi; //samo se u prvoj iteraciji petlje ispise u biti 
        else prethodni->sljedeci =novi;
        prethodni=novi;
        if(i==n)novi->sljedeci=pocetak; //jer je ulancana ne mora inace bit ako je obicna
    }
    Cvor *trenutni=pocetak;
    prethodni=nullptr;
    while(n>1)
    {
        for(int i{};i<m-1;i++)
        {
            prethodni=trenutni;
            trenutni=trenutni->sljedeci;
        }
        prethodni->sljedeci=trenutni->sljedeci;
        Cvor*izbaci = trenutni;
        if(mozda)std::cout<<trenutni->redni_broj<<", ";
        trenutni=trenutni->sljedeci;
        delete izbaci;
        n--;
    }  
    int a=trenutni->redni_broj;
    delete trenutni;
    return a;
}
int SigurnoMjesto(int m,int N1,int N2)
{
    if(m<=0 || N1<1 || N2<1|| N2<N1) return 0;
    std::list<int> lista;
    for(int i=N1;i<=N2;i++)lista.push_back(i);
    for(int i=N1;i<=N2;i++)
    {
        auto it=lista.begin();
        while(it!=lista.end())
        {
            if(*it==Poglavica(i,m))it=lista.erase(it);
            else it++;
        }
    }
    if(lista.size()==0)
    return 0;
    return *lista.begin();
}
int main ()
{
    std::cout<<"Unesite broj punoljetnih clanova za odabir poglavice plemena Wabambe: ";
    int m,n,N1,N2;
    std::cin>>n;
    std::cout<<"Unesite korak razbrajanja: ";
    std::cin>>m;
    std::cout<<"Unesite raspon za odabir (N1 i N2): ";;
    std::cin>>N1>>N2;
    std::cout<<"Redni broj osobe koja postaje poglavica: "<<Poglavica(n,m)<<std::endl;
    if(SigurnoMjesto(m,N1,N2)==0)
    {
        std::cout<<"Zao mi je Mbebe Mgogo, ali nema sigurnog mjesta.";
    }
    else
    {
        std::cout<<"Mbebe Mgogo, stani na sigurno mjesto "<<SigurnoMjesto(m,N1,N2)<<" da ne bi bio poglavica!";
    }

	return 0;
}
