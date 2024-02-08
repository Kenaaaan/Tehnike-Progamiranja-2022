//TP 2022/2023: LV 3, Zadatak 6
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
typedef std::vector<std::vector<int>> matrica;
//
matrica definisimatricu(int i,int j)
{
    return matrica(i,std::vector<int>(j));
}
//
int kolone(matrica a)
{
    if(a.size()!=0)  return a[0].size();
    return 0;
}
//
int redovi(matrica a)
{
    return a.size();
}
//
matrica KroneckerovProizvod(std::vector<int> a,std::vector<int> b)
{
    auto m=definisimatricu(a.size(), b.size());
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<b.size();j++)
        {
            m[i][j]=a[i]*b[j];
        }
    }
    return m;
}
//
int NajvecaSirina(matrica m)
{
    int rez=0;
    if(redovi(m)==0) return 0;
for(int i=0;i<redovi(m);i++)
{
    for(int j=0;j<m[i].size();j++)
    {
        int k=0;
        if(m[i][j]<0) k++;
        long int x=abs(m[i][j]);
        while(x!=0)
        {
            x=x/10;
            k++;
        }
        if(k>=rez) rez=k;
    }
}
return rez;
}
//
matrica unesimatricu(int m,int n)
{
    matrica a=definisimatricu(m,n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            std::cin>>a[i][j];
        }
    }
    return a;
}
//
int main ()
{

std::cout<<"Unesite broj elemenata prvog vektora: ";
int m,n;
std::cin>>m;
std::cout<<"Unesite elemente prvog vektora: ";
std::vector<int> v1;
for(int i=0;i<m;i++)
{
    int x;
    std::cin>>x;
    v1.push_back(x);
}
std::cout<<"Unesite broj elemenata drugog vektora: ";
std::cin>>n;
std::cout<<"Unesite elemente drugog vektora: ";
std::vector<int> v2;
for(int i=0;i<n;i++)
{
    int x;
    std::cin>>x;
    v2.push_back(x);
}
auto a=KroneckerovProizvod(v1, v2);

for(int i=0;i<a.size();i++)
{
    std::cout<<std::endl;
    for(int j=0;j<a[i].size();j++)
    {
        std::cout<<std::right<<a[i][j]<<std::setw(NajvecaSirina(a)+1);
       //std::cout<<a[i][j];
    }
}

	return 0;
}
/*Unesite broj elemenata prvog vektora: 4
Unesite elemente prvog vektora: 3 124 -11 9
Unesite broj elemenata drugog vektora: 6
Unesite elemente drugog vektora: 42 1001 0 -213 16 5
 126 3003 0 -639 48 15
 5208 124124 0 -26412 1984 620
 -462 -11011 0 2343 -176 -55
 378 9009 0 -1917 144 45
*/
