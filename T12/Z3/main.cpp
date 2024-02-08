//TP 2022/2023: LV 12, Zadatak 3
#include <iostream>

enum Dani {Ponedjeljak, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
std::string pok[]{"Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja"};

Dani &operator ++(Dani &d)
{
    return d = Dani((int(d) + 1) %7);
}
Dani operator ++(Dani &d, int)
{
    Dani pomocni(d);
    ++d;
    return pomocni;
}
Dani operator +(Dani d, int n)
{
    return Dani((int(d) + n) % 7);
}
std::ostream& operator << (std::ostream& ispis, Dani d)
{
    ispis << pok[d];
    return ispis;
}
int main ()
{
    for(Dani d = Ponedjeljak; d <= Nedjelja; d++){ std::cout << d << std::endl; if(d ==Nedjelja) break; }
    return 0;
}