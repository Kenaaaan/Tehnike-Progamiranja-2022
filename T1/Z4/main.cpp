
// TP 2016/2017: LV 1, Zadatak 4
#include <cctype>
#include <cmath>
#include <iostream>
#include <ostream>
int main() {
  double c = 5;

  for (;;) {
    std::cout << "Unesite prirodan broj ili 0 za kraj: ";
    std::cin >> c;
    if (c == 0 && (std::cin)) 
    {
      std::cout << "Dovidjenja!" << std::endl;
      return 0;
    }

    while (static_cast<int>(c) != c) {
      std::cout << "Niste unijeli prirodan broj!\n";
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      std::cout << "Unesite prirodan broj ili 0 za kraj: ";
      std::cin >> c;
    }
    while (!std::cin || c < 1) {
      std::cout << "Niste unijeli prirodan broj!\n";
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      std::cout << "Unesite prirodan broj ili 0 za kraj: ";
      std::cin >> c;
    }
    int suma = 0;
    for (int i = 1; i < c; i++) {
      if ((int)c % i == 0) {
        suma = suma + i;
      }
    }
    if (suma < c) {
      std::cout << "Broj " << c << " je manjkav!" << std::endl;
    }
    if (suma == c) {
      std::cout << "Broj " << c << " je savrsen!" << std::endl;
    }
    if (suma > c) {
      std::cout << "Broj " << c << " je obilan!" << std::endl;
    }
  }

  return 0;
}