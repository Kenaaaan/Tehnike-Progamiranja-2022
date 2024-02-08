// TP 2022/2023: LV 2, Zadatak 3
#include <cmath>
#include <complex>
#include <iostream>

int main() {
  std::cout << "Unesite broj elemenata: " << std::endl;
  std::complex<double> z(0, 0);
  std::complex<double> z1(0, 0);

  int a;
  std::cin >> a;
  for (int i = 1; i <= a; i++) {
    double re, im;
    std::cout << "R" << i << " = ";
    std::cin >> re;

    std::cout << "X" << i << " = ";
    std::cin >> im;
    std::cout << std::endl;
    z1.real(re);
    z1.imag(im);

    z=1./z1+z;
  }
z=1./z;
  std::cout << "Paralelna veza ovih elemenata ima R = " << z.real()
            << " i X = " << z.imag() << ".";

  return 0;
}
