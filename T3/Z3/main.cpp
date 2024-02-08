// TP 2022/2023: LV 3, Zadatak 1
#include <cmath>
#include <iostream>
#include <deque>

std::deque<int> IzdvojiElemente(std::deque<int> v, bool maybe) {
    std::deque<int>rez;
    long int k=0;
    long int l;
    int  brojac=0;
    if (maybe)
    {   
        for(long int x:v)
        {
            //
            if(x<0)
            {
                l=-x;
            }
            else
            {
                l=x;
            }
            //
            while(l>0)
            {   
                k=k+(l%10);
                l=l/10;
            }
            if(k%2==0)
            {
                rez.push_back(x);
                brojac++;
            }
            k=0;
        }
    }
    else
    {   
        for(long int x:v)
        {
            //
            if(x<0)
            {
                l=-x;
            }
            else
            {
                l=x;
            }
            //
            while(l>0)
            {   
                k=k+(l%10);
                l=l/10;
            }
            if(k%2!=0)
            {
                rez.push_back(x);
                brojac++;
            }
            k=0;
        }
    }
    return rez;
}

int main() {
    int k=0;
    std::cout<<"Koliko zelite unijeti elemenata: ";
    int n;
    std::cin>>n;
    if(n<=0)
    {
        std::cout<<"Broj elemenata mora biti veci od 0!";
        return 0;
    }
    std::cout<<"Unesite elemente: ";
    std::deque<int> a;
    for(int i=0;i<n;i++)
    {
        int l;
        std::cin>>l;
        a.push_back(l);
    }
    std::deque<int>b=IzdvojiElemente(a,true),c=IzdvojiElemente(a,false);
    int brojac1=0;
    for(int x:b)
    {
        
        std::cout<<x;
        if(brojac1==b.size()-1)
        {
            break;
        }
        std::cout<<",";
        brojac1++;
    }
    std::cout<<std::endl;
    brojac1=0;
    for(int x:c)
    {
        std::cout<<x;
         if(brojac1==c.size()-1)
        {
            break;
        }
        std::cout<<",";
        brojac1++;
    }
    

return 0;
}
/*Koliko zelite unijeti elemenata: 12
Unesite elemente: 15 23 18 -26 0 142 -333 73 11111 -312 9 5555555
15 -26 0 73 -312
23 18 142 -333 11111 9 5555555
*/