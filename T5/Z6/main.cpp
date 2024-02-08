// TP 2022/2023: LV 5, Zadatak 6
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int sumaCifara(int x)
{
    if (x == 0)
    return 0;
    return (x % 10 + sumaCifara(x / 10));
}

int main() {
  int n;
  std::cout << "Unesite broj elemenata: ";
  std::cin >> n;

  std::vector<int> a(n);
  int x;
  std::cout << "Unesite elemente: ";
  std::for_each(a.begin(),a.end(),[](int &x){std::cin >> x;});

  std::sort(a.begin(), a.end(), [](int x, int y) {
    int sumCif1 = sumaCifara(abs(x)), sumCif2 = sumaCifara(abs(y));
    if (sumCif1 > sumCif2)
      return false;
    else if (sumCif2 > sumCif1)
      return true;
    else if (sumCif1 == sumCif2 && x > y)
      return false;
    else
      return true;
  });

  //    std::cout << std::endl;
  std::cout << "Niz sortiran po sumi cifara glasi: ";
  std::for_each(a.begin(),a.end(),[](const int &x){std::cout << x << " ";});

  std::cout << std::endl << "Unesite broj koji trazite: ";
  int broj;
  std::cin >> broj;

  std::vector<int>::iterator ind =
      std::lower_bound(a.begin(), a.end(), broj, [](int x, int y) {
        int sumCif1 = sumaCifara(abs(x)), sumCif2 = sumaCifara(abs(y));
        if (sumCif1 > sumCif2)
          return false;
        else if (sumCif2 > sumCif1)
          return true;
        else if (sumCif1 == sumCif2 && x > y)
          return false;
        else
          return true;
      });
      
  if (*(ind-1) == broj)
    std::cout << "Trazeni broj nalazi se na poziciji " << ind - a.begin() - 1;
  else
    std::cout << "Trazeni broj ne nalazi se u nizu!";

  return 0;
}
