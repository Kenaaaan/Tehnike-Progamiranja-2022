// TP 2022/2023: LV 2, Zadatak 3
#include <cmath>
#include <complex>
#include <iostream>


int main() {
  std::cout << "Unesite broj elemenata: " << std::endl;
  std::complex<double> z(0, 0);
  double x;
  double fi;
  int a;
  std::cin >> a;
  for (int i = 1; i <= a; i++) {
    double re, im;
    std::cout << "Z"<<i<<" = ";
    std::cin >> x;

    std::cout << "fi" << i << " = "<<std::endl;
    std::cin >> fi;
    fi=fi*((atan(1) * 4)/180);
    z=z+1./(std::polar(x,fi));
  }
//#define pi = atan(1) * 4;
z=1./z;
  std::cout <<"Paralelna veza ovih elemenata ima Z = " << abs(z)<<" i fi = "<< 180*arg(z)/(atan(1) * 4)
            << ".";

  return 0;
}
//Paralelna veza ovih elemenata ima Z = 2.57147 i fi = -33.7613.
