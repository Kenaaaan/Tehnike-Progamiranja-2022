// TP 2022/2023: LV 2, Zadatak 3
#include <cmath>
#include <complex>
#include <iostream>


int main() {
  std::cout << "Unesite broj elemenata: "<<std::endl;
  std::complex<double> z(0, 0);
  std::complex<double> z1(0, 0);

  int a;
  std::cin >> a;
  for (int i = 1; i <= a; i++) {
    double re, im;
    std::cout << "Z_" << i << " = ";
    std::cin>>z1;
    
   
    z = z + 1. / z1;
  }

  std::cout <<std::endl<< "Paralelna veza ovih elemenata ima impedansu Z_ = "<< 1. / z<<".";

  return 0;
}
