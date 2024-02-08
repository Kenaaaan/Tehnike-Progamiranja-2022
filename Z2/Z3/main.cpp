//TP 2022/2023: Zadaća 2, Zadatak 3
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <limits>
std::string g(std::string a, std::string b)
{
    return a + "*" + b;
}
int najveca_duzina(std::vector<std::vector<std::string>> s)
{
    int xo=0;
    int lol;
    for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<s.at(i).size();j++)
        {
            lol=s.at(i).at(j).size();
            if(lol>xo)xo=lol;
        }
    }
    return xo;
}
template <typename tip1,typename tip2, typename f1, typename f2>
auto GeneraliziraniMatricniProizvod
    (std::vector<std::vector<tip1>> m1,
    std::vector<std::vector<tip2>> m2,f1 f, f2 g)
{
    using novi= decltype(g(m1.at(0).at(0),m2.at(0).at(0))+g(m1.at(0).at(0),m2.at(0).at(0)));
    if(m1.size()==0 || m2.size()==0) return   std::vector<std::vector <novi>> ();
    
    if(m1.size()==0 || m2.size()==0 || m1.size()!=m2.at(0).size()) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    for(int i=0;i<m1.size();i++)
    {
        if(m1.at(i).size()!=m1.at(0).size()) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    }
    for(int i=0;i<m2.size();i++)
    {
        if(m2.at(i).size()!=m2.at(0).size()) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    }


    std::vector<std::vector < novi>> c(m1.size(),std::vector<novi>(m2.at(0).size()));
    try{
    for(int i=0;i<m1.size();i++)
    {
        for(int j=0;j<m2.at(0).size();j++)
        {
             novi x,y;
            for(int l=0;l<m2.size();l++)
            {
              
                x=g(m1.at(i).at(l),m2.at(l).at(j));
                if(l==0) y=x;
                else
                    y=f(y,x);       
                
            }
            c.at(i).at(j)=y;
        }
    }
    }catch(...) {throw std::runtime_error("Neocekivani problemi pri racunanju");}
    return c;
}
int main ()
{
std::cout<<"Unesite broj redova prve matrice: "<<std::endl;
int m,n,p;
std::cin>>m;
std::cout<<"Unesite broj kolona prve matrice, ujedno broj redova druge matrice: "<<std::endl;
std::cin>>n;
std::cout<<"Unesite broj kolona druge matrice: "<<std::endl;
std::cin>>p;
std::cout<<"Unesite elemente prve matrice: ";
std::vector<std::vector<std::string>> s1(m,std::vector<std::string>(n));
std::vector<std::vector<std::string>> s2(n,std::vector<std::string>(p));
for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {
        std::cin>>s1.at(i).at(j);
    }
}
std::cout<<"Unesite elemente druge matrice: "<<std::endl;
for(int i=0;i<n;i++)
{
    for(int j=0;j<p;j++)
    {
        std::cin>>s2.at(i).at(j);
    }
}
std::cout<<"Matricni proizvod: "<<std::endl;
try{
    auto pok = g;
auto s3=GeneraliziraniMatricniProizvod(s1,s2,[](std::string s1,std::string s2){
    if(s1.size()==0)
    { 
    return s1+s2;
    }
    else
    {
        return s1 + "+" + s2; 
    }
},g);
for(int i=0;i<m;i++)
{
    for(int j=0;j<p;j++)
    {
        std::cout<<std::left<<std::setw(najveca_duzina(s3)+2)<<s3.at(i).at(j);
    }
    std::cout<<std::endl;
}
}
catch(std::domain_error e)
{
    std::cout<<e.what();
}
catch(std::runtime_error e)
{
    std::cout<<e.what();
}
	return 0;
}