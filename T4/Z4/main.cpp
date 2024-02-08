#include <cmath>
#include <iostream>
#include <string>

template <typename xD>
void UnosBroja(std::string s1, std::string s2, xD &x) {
  bool mozda = false;
  do {
    std::cout << s1;
    if (!(std::cin >> x) || std::cin.peek() != '\n') {
      std::cout << s2 << std::endl;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      mozda = true;
    } else {
      mozda = false;
    }
  } while (mozda);
}

int main() {
  std::string s1 = "Unesite bazu: ";
  std::string s2 = "Neispravan unos, pokusajte ponovo...";
  double x;
  UnosBroja(s1, s2, x);
  s1 = "Unesite cjelobrojni eksponent: ";
  int n;
  UnosBroja(s1, s2, n);
  double rez = x;
  for (int i = 1; i < std::abs(n); i++)
    rez *= rez;
  if (n < 0)
    rez = 1. / rez;
  std::cout << x << " na " << n << " iznosi " << rez;

  return 0;
}
