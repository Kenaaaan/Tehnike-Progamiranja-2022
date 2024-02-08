// TP 2022/2023: LV 2, Zadatak 2
#include <cmath>
#include <iostream>
#include <vector>

bool TestPerioda(std::vector<double> v, int p) {
  int brojac = 0;
  int brojac2=0;
  if (v.size() <= p || p < 1)
    return false;
  for (int i = 0; i < v.size()-p; i++) {
    brojac2++;
    if (v[i] == v[i + p]) {
      brojac++;
    }
  }
  if (brojac == brojac2) {
    return true;
  } else {
    return false;
  }
}
int OdrediOsnovniPeriod(std::vector<double> v1) {
  for (int i = 0; i <= v1.size(); i++) {
    if (TestPerioda(v1, i)) {
      return i;
    }
  }
  return 0;
}
int main() { /*Unesite slijed brojeva (0 za kraj): 1 3 1 4 2 1 3 1 4 2 1 3 0
Slijed je periodican sa osnovnim periodom 5.
*/
  std::cout << "Unesite slijed brojeva (0 za kraj): ";
  std::vector<double> v(1);
  int i = 0;
  double a;
  do {
    std::cin >> a;
    v.push_back(a);
    i++;
  } while (v[i] != 0);
  v.erase(v.begin()+i);
  v.erase(v.begin()+0);
  // std::cout<<v.size();
  
  for(int i=0;i<v.size();i++)
{
   // std::cout<<"ovo je "<< i<<v[i]<<std::endl;
}
 // if (TestPerioda(v, 5)) {std::cout << "loooool"<<std::endl; };
  //if (TestPerioda(v, 4)) {std::cout << "loooool2"<<std::endl; };
  if (OdrediOsnovniPeriod(v)) {
    std::cout << "Slijed je periodican sa osnovnim periodom "
              << OdrediOsnovniPeriod(v) << ".";
  } else {
    std::cout << "Slijed nije periodican!";
  }
for(int i=0;i<v.size();i++)
{
    //std::cout<<"ovo je "<< i<<v[i]<<std::endl;
}
  return 0;
}
