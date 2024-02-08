//TP 2022/2023: LV 3, Zadatak 8
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>
//
std::string IzdvojiRijec(std::string s, int x)
{
    if(x<=0) throw std::domain_error ("IZUZETAK: Pogresan redni broj rijeci!");
int brojac=0;
std::string g;
for(int i=0;i<s.length();i++)
{

    if(s[i]!=' ')
    {
        brojac++;
        while(s[i]!=' ' && i<s.length()){
            if (brojac == x){
                g.push_back(s[i]);
            }
            i++;
        }
    }

    if(brojac==x) return g;
}
    if(x>brojac) throw std::domain_error ("IZUZETAK: Pogresan redni broj rijeci!");
return g;
}
//
int main ()
{
    try {std::cout<<"Unesite redni broj rijeci: ";
    int n;
    std::cin>>n;
    std::cin.ignore(1000,'\n');
    std::cout<<"Unesite recenicu: ";
    std::string s;
    std::getline(std::cin, s);
    std::string lol =IzdvojiRijec(s,n);
    std::cout<<"Rijec na poziciji "<<n<<" je "<<lol;
    
    } catch (std::domain_error izuzetak) {
std::cout << izuzetak.what() << std::endl;
    }
    
	return 0;
}
