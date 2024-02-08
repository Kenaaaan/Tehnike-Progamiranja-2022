#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

template <typename tip> tip proizvodreda(std::vector<tip> v) {
  tip suma = v.at(0);
  for (int j = 1; j < v.size(); j++) {
    suma = suma * v.at(j);
  }
  return suma;
}

template <typename tip> 
bool Kriterij(std::vector<tip> a, std::vector<tip> b) {
    if(a.size()==0 || b.size()==0) return false;
  if (proizvodreda(a) == proizvodreda(b)) {
    return a < b;
  }
  return proizvodreda(a) <= proizvodreda(b);
}

template <typename tip>
void SortirajPoProizvoduRedova(std::vector<std::vector<tip>> &m) {
  std::sort(m.begin(), m.end(), Kriterij<tip>);
}
int main() {
  int x;
  bool kraj = false;
  std::cout
      << "Unesi elemente (* za kraj reda, * na pocetku reda za kraj unosa): "
      << std::endl;
  std::vector<std::vector<int>> m;
  for (;;) {
    int prvi = 0;
    std::vector<int> v;
    if (kraj)
      break;
    while (true) {
      std::cin >> x;
      prvi++;
      if (!std::cin && prvi == 1) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        kraj = true;
        break;
      } else if (!std::cin) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        m.push_back(v);
        break;
      }
      v.push_back(x);
    }
  }
  SortirajPoProizvoduRedova(m);
  std::cout << "\nMatrica nakon sortiranja: " << std::endl;
  for (int i = 0; i < m.size(); i++) {
    for (int j = 0; j < m.at(i).size(); j++) {
      std::cout << m.at(i).at(j) << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "\nUnesite elemente sekvence koja se trazi (* za kraj reda): "
            << std::endl;
  std::vector<int> v;
  while (true) {
    std::cin >> x;
    if (!std::cin) {
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      break;
    }
    v.push_back(x);
  }
  int brojac = 0;
  auto it = std::lower_bound(m.begin(), m.end(), v, Kriterij<int>);
  if (it != m.end() && *it == v) {
    int indeks = it - m.begin();
    std::cout << "Trazena sekvenca se nalazi u " << indeks + 1
              << ". redu (nakon sortiranja)";
  } else {
    std::cout << "Trazena sekvenca se ne nalazi u matrici" << std::endl;
  }

  return 0;
}
