//TP 2022/2023: Zadaća 3, Zadatak 1
#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
std::function<double(double)>LagrangeovaInterpolacija(std::vector<std::pair<double, double>> cvorovi)
{
    int velicina=cvorovi.size();
    for(int i=0;i<velicina-1;i++)
        for(int j=i+1;j<velicina-1;j++)
            if(cvorovi.at(i).first==cvorovi.at(j).first)throw std::domain_error("Neispravni cvorovi");
            
    std::function<double(double)> fun = [=](double x)
    {
        double rez=0;
        for(int i=0;i<velicina;i++)
        {
            double prom=cvorovi.at(i).second;
            for(int j=0;j<velicina;j++)
            {
                if(i!=j)
                {
                    prom*=(x-cvorovi.at(j).first)/(cvorovi.at(i).first-cvorovi.at(j).first);
                }
            }
            rez+=prom;
        }
      return rez;
    };
    return fun;
}
std::function<double(double)>LagrangeovaInterpolacija(const std::function<double(double)> &fun,double a,double b, double delta)
{
    if(delta<=0 || a>b) throw std::domain_error("Nekorektni parametri");

    std::vector<std::pair<double,double>> cvorovi;
    constexpr double Eps = 10e-5;
    for(double x=a;std::abs(x) < Eps + std::abs(b);x+=delta)
    {
        //std::cout<<"lagan"<<std::endl;
        double y=fun(x);
        cvorovi.push_back(std::make_pair(x,y));
    }
    return LagrangeovaInterpolacija(cvorovi);
}

int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int odabir;
    std::cin>>odabir;
    if(odabir==1){
    std::cout<<"Unesite broj cvorova: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite cvorove kao parove x y: ";
    std::vector<std::pair<double,double>> cvorovi(n);
    for(auto &x: cvorovi) std::cin>>x.first>>x.second;
       double x;
      for(int i{};i<cvorovi.size();i++)
      {
        for(int j=i+1;j<cvorovi.size();j++)
            if(cvorovi.at(i).first==cvorovi.at(j).first)
            {
                std::cout<<"Neispravni cvorovi";
                return 0;
            }
      }
    std::cout<<"Unesite argument (ili "<<'"'<<"kraj"<<'"'<<" za kraj): "<<std::endl;
    while(std::cin>>x)
    {
        std::cout<<"f("<<x<<") = "<<LagrangeovaInterpolacija(cvorovi)(x);   
        if(x<cvorovi.at(0).first || x > cvorovi.at(cvorovi.size()-1).first)
        std::cout<<" [ekstrapolacija]"; 
       std::cout<<"\n Unesite argument (ili "<<'"'<<"kraj"<<'"'<<" za kraj): ";
    }
    }else if(odabir==2)
    {
    std::function<double(double)> lol =[](double k){return k*k+std::sin(k)+log(k+1);};
    std::cout<<"Unesite krajeve intervala i korak: "<<std::endl;
    double max,min,n;
    std::cin>>min>>max>>n;
    if(n<=0 || max<min) {
        std::cout<<"Nekorektni parametri";
        return 0;
    }
    std::cout<<"Unesite argument (ili "<<'"'<<"kraj"<<'"'<<" za kraj): ";
    double x;
    while(std::cin>>x)
    {
        std::cout<<"f("<<x<<") = "<<lol(x);
        std::cout<<" P("<<x<<") = "<<LagrangeovaInterpolacija(lol,min,max,n)(x); 
        if(x<min || x>max) std::cout<<" [ekstrapolacija]";
        std::cout<<"\nUnesite argument (ili "<<'"'<<"kraj"<<'"'<<" za kraj): ";
    }
    }
	return 0;
}
