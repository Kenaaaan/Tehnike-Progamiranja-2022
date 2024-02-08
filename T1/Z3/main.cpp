// TP 2016/2017: LV 1, Zadatak 3
#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
  int a, b;
  std::cout << "Unesite pocetnu i krajnju vrijednost: " << std::endl;
  std::cin >> a >> b;
  if (a > b || a > 9999 || b > 9999) {
    std::cout << "Ne moze ";
  }
  std::cout << "+---------+----------+----------+-----------+" << std::endl
            << "| Brojevi | Kvadrati | Korijeni | Logaritmi |" << std::endl
            << "+---------+----------+----------+-----------+" << std::endl;
  for (int i = a; i <= b; i++) {
    double korijen = std::sqrt(i), log = std::log(i);
    int kvadrat = i * i;
    std::cout << "| " << std::left << std::setw(8) << i << std::right << "| "
              << std::setw(8) << kvadrat << " |" << std::setw(9)
              << std::setprecision(3) << std::fixed << korijen << " | "
              << std::setw(9) << std::setprecision(5) << std::fixed << log
              << " |" << std::endl;
  }
  std::cout << "+---------+----------+----------+-----------+" << std::endl;
  return 0;
}