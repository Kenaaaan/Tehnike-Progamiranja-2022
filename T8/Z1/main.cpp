#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

struct Vrijeme
{
    int sati;
    int minute;
    int sekunde;
};
bool TestirajVrijeme(Vrijeme v)
{
    if(v.sati>23 || v.sati<0 || v.minute>59 || 
    v.minute<0 || v.sekunde>59 || v.sekunde<0) 
    return false;

    return true;

}
void IspisiVrijeme(Vrijeme v)
{
    if(!TestirajVrijeme(v)) throw std::domain_error("Neispravno vrijeme");

   std::cout << std::setfill('0') << std::setw(2) << v.sati << ":"
              << std::setw(2) << v.minute << ":" << std::setw(2) << v.sekunde
              << std::endl;
}
Vrijeme SaberiVrijeme(Vrijeme v1, Vrijeme v2)
{
    if(!TestirajVrijeme(v1)) throw std::domain_error("Neispravno vrijeme");
    if(!TestirajVrijeme(v2)) throw std::domain_error("Neispravno vrijeme");
    Vrijeme rez;
    rez.sekunde = v1.sekunde + v2.sekunde;
    rez.minute = v1.minute + v2.minute;
    rez.sati = v1.sati + v2.sati;

    while (rez.sekunde >= 60) {
        rez.sekunde -= 60;
        rez.minute++;
    }
    while (rez.minute >= 60) {
        rez.minute -= 60;
        rez.sati++;
    }
    while (rez.sati >= 24) {
        rez.sati -= 24;
    }

    if (!TestirajVrijeme(rez)) {
        throw std::domain_error("Neispravno vrijeme");
    }

    return rez;
}


int main()
{
    try{
Vrijeme v1, v2;
std::cout<<"Unesite prvo vrijeme (h m s): ";
std::cin>>v1.sati>>v1.minute>>v1.sekunde;
if(!TestirajVrijeme(v1)) throw std::domain_error("Neispravno vrijeme");
std::cout<<"Unesite drugo vrijeme (h m s): ";
std::cin>>v2.sati>>v2.minute>>v2.sekunde;
if(!TestirajVrijeme(v2)) throw std::domain_error("Neispravno vrijeme");
std::cout<<"Prvo vrijeme: ";
IspisiVrijeme(v1);
std::cout<<"Drugo vrijeme: ";
IspisiVrijeme(v2);
std::cout<<"Zbir vremena: ";
IspisiVrijeme(SaberiVrijeme(v1,v2));
    }
    catch(std::domain_error e)
    {
        std::cout<<e.what()<<std::endl;
    }

return 0;
}
/*Unesite prvo vrijeme (h m s): 3 34 52
Unesite drugo vrijeme (h m s): 4 42 20
Prvo vrijeme: 03:34:52
Drugo vrijeme: 04:42:20
Zbir vremena: 08:17:12
*/