//TP 2022/2023: LV 3, Zadatak 7
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <string>

//
typedef std::vector<std::vector<int>> matrica;
//
matrica definisimatricu(int i,int j)
{
    return matrica(i,std::vector<int>(j));
}
//
int NajvecaSirina(matrica m)
{
    int rez=0;
    if(m.size()==0) return 0;
for(int i=0;i<m.size();i++)
{
    for(int j=0;j<m[i].size();j++)
    {
        int k=0;
        if(m[i][j]<0) k++;
        long int x=abs(m[i][j]);
        while(x>0)
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
matrica PascalovTrougao(int n)
{

    if(n<0) throw std::domain_error ("Broj redova ne smije biti negativan");
    matrica a=definisimatricu(n,0);
   
for(int i=0;i<n;i++)
    {
        for(int j=0;j<i+1;j++)
        {   
            if(i<2 || i==j || j==0) 
            {
            a[i].push_back(1);
            continue;
            }
            a[i].push_back(a[i-1][j-1]+a[i-1][j]);

        }
    }
    return a;
}
//
int main ()
{
    try{
    std::cout<<"Unesite broj redova: ";
    int n;
    std::cin>>n;

    matrica a=PascalovTrougao(n);
    for(int i=0;i<n;i++)
    {
        std::cout<<std::endl;
        for(int j=0;j<i+1;j++)
        std::cout<<std::right<<std::setw(NajvecaSirina(a)+1)<<a[i][j];
    }
     }catch(std::domain_error izuzetak){
std::cout << izuzetak.what() << std::endl;
   }
    

	return 0;
}
