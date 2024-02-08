// TP 2022/2023: Zadaća 2, Zadatak 2
#include <cmath>
#include <iostream>

bool prime(int n) {
  if (n < 2)
    return false;
  for (int i = 2; i <= std::sqrt(n); i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}
void RastavaBroja(int n, int &p, int &q) {
  int provjera = n;
  p = 1;
  q = 1;
  int brojac = 0;
  int prost = 2;
  bool mozda = false;
  if (n < 0) {
    mozda = true;
    n = -n;
  }
  if (prime(n)) {
    p  =n;
    q = 1;
    if (mozda)
    p = -p;
    }
  else {
  while (n > 1) {
    if (prime(prost)) {
      while (n % prost == 0) {
        n = n / prost;
        brojac++;
      }
    }
    if (brojac > 0) {
      if (brojac == 1)
        p = p * prost;

      else if (brojac % 2 == 1) {
        p = p * prost;
        brojac = brojac - 1;
        q = q * std::pow(prost, brojac);
      } else {
        q = q * std::pow(prost, brojac);
      }
    }
    prost++;
    brojac = 0;
  }
  q = std::sqrt(q);
  if (mozda)
    p = -p;
  if (provjera == 0) {
    p = 0;
    q = 1;
  }
  }
  
}
int main() {
  int n, q, p;
  std::cout << "Unesi broj: " << std::endl;
  std::cin >> n;
  RastavaBroja(n, p, q);

  std::cout << n << " = " << p << "*" << q << "^2";

  return 0;
}