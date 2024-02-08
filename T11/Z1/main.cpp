//TP 2022/2023: LV 11, Zadatak 1
#include <iostream>
#include <cmath>
class NeobicnaKlasa
{
    public:
    explicit NeobicnaKlasa(int &&x)
    {
        std::cout<<"Direktna inicijalizacija"<<std::endl;
    }
    NeobicnaKlasa(const int &x)
    {
        std::cout<<"Kopirajuca inicijalizacija"<<std::endl;
    }
};
int main ()
{
    //int a=6;
    NeobicnaKlasa k(6);


	return 0;
}
