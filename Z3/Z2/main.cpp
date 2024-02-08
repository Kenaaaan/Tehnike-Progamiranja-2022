//TP 2022/2023: Zadaća 3, Zadatak 2
#include <cctype>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <tuple>
#include <string>
#include <set>
typedef std::map<std::string,std::vector<std::string>> Knjiga;
typedef std::map<std::string,std::set<std::tuple<std::string,int,int>>> indekspojmova;

indekspojmova KreirajIndeksPojmova(Knjiga knjiga)
{
//k<string,vector<string>>  k["XIV"][5]   XIV=poglavlje
// XIV prvi string, 5 znaci peti vektor, a jedan vektor je jedna stranica
//indeks<string,tuple<string,int,int>> prvi string rijec drugi poglavlje pa strana pa pocetak
std::map<std::string,std::set<std::tuple<std::string,int,int>>> indeks;
int pocetak_rijeci=0;
for(auto& poglavlje_petlja: knjiga)
{
    int stranica=1;
    std::string Ime_poglavlja = poglavlje_petlja.first;
    std::vector<std::string> Stranica = poglavlje_petlja.second;
    for(int i{};i<Stranica.size();i++)
    {
        std::string rijec = Stranica.at(i);
        int mjesto = 0;
        while(mjesto<rijec.size())
        {

        
        while(mjesto<rijec.size() && !(isalpha(rijec.at(mjesto)) || isdigit(rijec.at(mjesto))))
        {
            if(mjesto>=rijec.size())
            break;
            mjesto++;
        }
        if(mjesto>=rijec.size())break;
        int duzina=0;
        while(duzina+mjesto<rijec.length() && 
        (isalpha(rijec.at(mjesto+duzina)) || isdigit(rijec.at(mjesto+duzina))))
            duzina++;

            std::string rijec_indeks = rijec.substr(mjesto,duzina);
            for(int l{};l<rijec_indeks.length();l++)
                rijec_indeks.at(l)=std::tolower(rijec_indeks.at(l));

            indeks[rijec_indeks].insert(std::make_tuple(Ime_poglavlja,stranica,mjesto));
            mjesto=mjesto+duzina;
        }
 stranica++;    }
   
}
return indeks;
}
std::set<std::tuple<std::string,int,int>> PretraziIndeksPojmova(std::string s,indekspojmova m)
{
    if(m.count(s)==0) throw std::logic_error("Pojam nije nadjen");
    return m.at(s);
}
void IspisiIndeksPojmova(const indekspojmova& indeks)
{
    for(auto it=indeks.begin() ;it!=indeks.end();it++)
    {
        std::cout<<it->first<<": ";
        std::set<std::tuple<std::string,int,int>> lolcina=it->second;
        for(auto it2=lolcina.begin();it2!=lolcina.end();it2++)
    {
        std::string poglavlje;
        int stranica, pozicija;
        std::tie(poglavlje,stranica, pozicija) = *it2;
        std::cout<<poglavlje<<"/"<<stranica<<"/"<<pozicija;
        if(it2!=std::prev(lolcina.end()))
            std::cout<<", ";
    }
    if(it!=--indeks.end())
    std::cout<<std::endl;
    }
}
int main ()
{
Knjiga knjiga;
std::string poglavlje;
while(true)
{std::cout<<"\nUnesite naziv poglavlja: ";
std::getline(std::cin, poglavlje);
if(poglavlje ==".")break;
int nesto=1;
std::string stranica;
while(true)
{
std::cout<<"\nUnesite sadrzaj stranice "<<nesto++<<": ";
std::getline(std::cin,stranica);
if(stranica==".")break;
knjiga[poglavlje].push_back(stranica);
}
}

indekspojmova indeks=KreirajIndeksPojmova(knjiga);
//int nesto=1;
std::cout<<"Kreirani indeks pojmova: \n";
IspisiIndeksPojmova(indeks);
std::string rijec;
while(true)
{
    std::cout<<"\nUnesite rijec: ";
    std::getline(std::cin,rijec);
    if(rijec==".")break;
    try
    {
        for(int i{};i<rijec.length();i++)
        {
            rijec.at(i)=std::tolower(rijec.at(i));
        }
        std::set<std::tuple<std::string,int,int>> pozicije =PretraziIndeksPojmova(rijec,indeks);
        std::cout<<"\n";
        for(const auto& pozicija : pozicije)
        {
            std::cout<<std::get<0>(pozicija)<<"/"<<std::get<1>(pozicija)<<"/"<<std::get<2>(pozicija)<<" ";
        }
        //std::cout<<std::endl;
    }catch(std::logic_error e)
    {
        std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
    }
}
	return 0;
}