//TP 2022/2023: LV 4, Zadatak 2
#include <iostream>
#include <cmath>
#include <string>
void IzvrniString (std::string &s)
{
    int n=s.length();
    for(int i=0;i<n/2;i++)
    {
        char temp =s[i];
        s[i]=s[n-i-1];
        s[n-1-i]=temp;
    }    
}

int main ()
{
std::cout<<"Unesi string: ";
std::string s;
std::getline(std::cin,s);
IzvrniString(s);
std::cout<<"Izvrnuti string je: "<<s;
	return 0;
}
