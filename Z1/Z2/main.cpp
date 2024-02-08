//TP 2022/2023: Zadaća 1, Zadatak 2
#include <iomanip>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>
typedef std::vector<std::vector<double>> matrica;
matrica UsrednjavajuciFilter(matrica v, int n)
{
    if(n<0) throw std::domain_error("Neispravan red filtriranja");
    double brojac=0,suma=0;
    matrica v1=v;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.at(i).size();j++)
        {
            for(int k=i-n;k<=i+n;k++)
            {
                if(k<0 || k>v.size()-1) continue;
                for(int l=j-n;l<=j+n;l++)
                {
                    if(l<0 || l>v.at(k).size()-1) continue;
                    brojac++;
                    suma=suma+v.at(k).at(l);
                }
            }
            v1.at(i).at(j)=(suma/brojac);
            brojac=0;
            suma=0;
        }
    }
    return v1;
}

int main ()
{
std::cout<<"Unesite broj redova i kolona matrice: ";
int m =0,n=0;
std::cin>>m>>n;
std::cout<<"Unesite elemente matrice: ";
matrica v(m,std::vector<double>(n));
matrica v1(m,std::vector<double>(n));
for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {   
       std::cin>>v.at(i).at(j);
    }
}
std::cout<<"Unesite red filtriranja: ";
int x;
std::cin>>x;
try{
v1=UsrednjavajuciFilter(v,x);
std::cout<<"Matrica nakon filtriranja: "<<std::endl;
for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {
        std::cout<<std::fixed<<std::right<<std::setw(7)<<std::setprecision(2)<<v1.at(i).at(j)<<"  ";
    }
    std::cout<<std::endl;
}
}catch(std::domain_error negativan)
{
    std::cout<<"GRESKA: "<<negativan.what()<<"!"<<std::endl;
}

	return 0;
}
