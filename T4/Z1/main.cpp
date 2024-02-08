//TP 2022/2023: LV 4, Zadatak 1
#include <iostream>
#include <cmath>
int Cifre(long long int n, int& b, int& a)
{
   
    int k;
    if(n<0) n=-n;
     int brojac=0;
     a=n%10;
          b=n%10;

do
{
    k=n%10;
    n=n/10;
    brojac++;
    if(abs(k)>abs(a)) a=abs(k);
    if(abs(k)<abs(b)) b=abs(k);
}while(n!=0);

return brojac;
}

int main ()
{
    //Unesite broj: Broj -54746639 ima 8 cifara, najveca je 9 a najmanja 3.
std::cout<<"Unesite broj: ";
long long int n;
std::cin>>n;
int c_min,c_max;
int &b=c_min;
int &a=c_max;
std::cout<<"Broj "<<n<<" ima "<<Cifre(n, b,a)<<" cifara, najveca je "<<c_max<<" a najmanja "<<c_min<<".";


	return 0;
}
