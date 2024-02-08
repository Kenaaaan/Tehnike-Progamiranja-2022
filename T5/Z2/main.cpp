//TP 2022/2023: LV 5, Zadatak 2
#include <iostream>
#include <cmath>
#include <deque>
#include <type_traits>
template <typename tip1, typename tip2>
tip2 RazmijeniBlokove(tip1 p1, tip1 p2, tip2 p3)
{
std::remove_reference_t<decltype(*p1)> temp; 
while(p1!=p2)
{
    temp=*p1;
    *p1=*p3;
    *p3=temp;
    p1++;
    if(p1==p2) return p3+1;
    p3++;
}
return p3+1;
}
int main ()
{
int a[]{1, 2, 3, 5, 8, 13}, b[]{21, 34, 55, 89, 144,233};
RazmijeniBlokove(std::begin(a), std::end(a), std::begin(b));
std::cout << "Prvi niz: ";
for(int x : a) std::cout << x << " ";
std::cout << "\nDrugi niz: ";
for(int x : b) std::cout << x << " ";
std::string s1("Ovo je prva recenica."), s2("Ovo je druga recenica.");
RazmijeniBlokove(s1.begin(), s1.end(), s2.begin());
std::cout << "Prvi string: " << s1 << std::endl;
std::cout << "Drugi string: " << s2 << std::endl;
	return 0;
}