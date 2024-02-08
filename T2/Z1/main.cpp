// TP 2022/2023: LV 2, Zadatak 1
#include <cmath>
#include <iostream>
#include <vector>
bool DaLiJeProst(int n) {
  int yes = 0;
  if (n <= 1) {
    return false;
  }
  for (int i = 1; i <= std::sqrt(n); i++) {
    if (n % i == 0) {
      yes++;
    }
  }
  if (yes == 1) {
    return true;
  } 
  else {
    return false;
  }
}

std::vector<int> ProstiBrojeviUOpsegu(int a, int b) {
  std::vector<int> v1;
  for (int i = a; i <= b; i++) {
    int l = 0;
    if (DaLiJeProst(i)) {
      v1.push_back(i);
    }
    l++;
    if (i == b) {
      break;
    }
  }
  return v1;
}
int main() {
  int a, b;
  int j = 0;
  bool nema_ih = true;
  std::cout << "Unesite pocetnu i krajnju vrijednost: ";
  std::cin >> a >> b;
  if (ProstiBrojeviUOpsegu(a, b).size() != 0)
    nema_ih = false;
  if (!nema_ih) {
    std::cout << "Prosti brojevi u rasponu od " << a << " do " << b << " su: ";
  } else {
    std::cout << "Nema prostih brojeva u rasponu od " << a << " do " << b
              << "!";
    return 0;
  }
  for (int &i : ProstiBrojeviUOpsegu(a, b)) {

    j++;
    std::cout << i;
    if (j != ProstiBrojeviUOpsegu(a, b).size()) {
      std::cout << ", ";
    }
  }
  std::cout << "\n";

  return 0;
}
