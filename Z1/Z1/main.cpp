#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <array>
enum class TretmanNegativnih {IgnorirajZnak, Odbaci, PrijaviGresku};

int MultiplikativniDigitalniKorijen(long long int x, int b) {
    if(x<0) x=-x;
    if(x==0) return 0;
    if((int)b!=b || b<2) throw std::domain_error("Neispravna baza");
 long long int rez = 1;
  int k;
  while (true) {
    while (x > 0) {
      k = x % b;
      x = x / b;
      rez = rez * k;
    }
    if (rez <b) return rez;  
    x=rez;
    rez=1;
  }
  return rez;
}
std::array<std::vector<long long int>,10> RazvrstajBrojeve(std::vector<long long int> v,TretmanNegativnih lol)
{
    std::array<std::vector<long long int>,10>  a;
    for(int x:v)
    {   
        for(int i=0;i<10;i++)
        {

            if(i==MultiplikativniDigitalniKorijen(x,10))
            {
                if(x<0)
                {
                    if(lol==TretmanNegativnih::IgnorirajZnak)
                    {
                        x=-x;
                    }
                    else if(lol==TretmanNegativnih::Odbaci)
                    {
                        continue;
                    }
                    else if(lol==TretmanNegativnih::PrijaviGresku)
                    {
                        throw std::domain_error("Nije predvidjeno razvrstavanje negativnih brojeva");
                    }

                }
                a.at(i).push_back(x);
            }
        }  
    }
    return a;
}
int main() {
std::cout<<"Unesite brojeve (bilo koji ne-broj oznacava kraj): "<<std::endl;
std::vector<long long int>  a;
while(std::cin)
{
    int lol;
    std::cin>>lol;
    if(lol<0)   
    {
        std::cout<<"Nije podrzano razvrstavanje negativnih brojeva!";
        return 0;
    }
    if(std::cin)    a.push_back(lol);
}
std::cout<<"Rezultati razvrstavanja po multiplikativnom digitalnom korijenu: ";
try{
std::array<std::vector<long long int>,10> xD=RazvrstajBrojeve(a,TretmanNegativnih::IgnorirajZnak);
for(int i=0;i<10;i++)
{
      if(xD.at(i).size()==0)
    {
        continue;
    }
    std::cout<<i<<": ";
    for(int j=0;j<xD.at(i).size();j++)
    {
        std::cout<<xD.at(i).at(j)<<" ";
    }
    std::cout<<std::endl;
}
}catch(std::domain_error negativan)
{
    std::cout<<negativan.what()<<std::endl;
}
  return 0;
}