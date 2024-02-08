// TP 2022/2023: LV 5, Zadatak 7
#include <cmath>
#include <deque>
#include <iostream>
#include <stdexcept>
#include <string>
#include <type_traits>

template <typename Iter>
auto SumaBloka(Iter p1, Iter p2) -> typename std::remove_reference<decltype(*p1)>::type {
  if (p1 == p2)
    throw(std::range_error("Blok je prazan"));
  typename std::remove_reference<decltype(*p1)>::type suma = *p1++;

  for (Iter pok = p1; pok != p2; pok++) {
    suma += *pok;
  }
  return suma;
}

int main() {
  try{ int n;
   std::cin >> n;

   std::deque<double> a;
   double x;
   for (int i = 0;i < n; i++){ std::cin >> x; a.push_back(x);}

   auto suma = SumaBloka(a.begin(),a.end());
   std::cout << suma;}
   catch(std::range_error izuzetak){
       std::cout << "GRESKA: " << izuzetak.what() << "!";
   }


  return 0;
}
