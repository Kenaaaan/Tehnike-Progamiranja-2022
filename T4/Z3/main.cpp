// TP 2022/2023: LV 4, Zadatak 3
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

std::string UVelikaSlova(std::string s){
  std::string str;
  for(int i=0; i<s.length(); i++){
    str.push_back(toupper(s.at(i)));
  }
  return str;
}

void IzdvojiKrajnjeRijeci(std::vector<std::string> v, std::string &prva,
                          std::string &zadnja) {
  if (v.size() == 0) {
    prva = "";
    zadnja = "";
  } else {
    prva = v.at(0);
    std::string prva_poredbena=UVelikaSlova(prva);
    zadnja = v.at(0);
    std::string zadnja_poredbena = prva_poredbena;
    
    for (int i = 1; i < v.size(); i++) {
      std::string poredbena = UVelikaSlova(v.at(i));
      if (poredbena < prva_poredbena) {
        prva = v.at(i);
        prva_poredbena = poredbena;
      }
      if (poredbena > zadnja_poredbena) {
        zadnja = v.at(i);
        zadnja_poredbena = poredbena;
      }
    }
  }
}

void ZadrziDuplikate(std::vector<std::string> &v) {
  std::vector<std::string> v_kopija{};
  for(int i=0; i<v.size(); i++){
    for(int j=i; j<v.size(); j++){
      if(v.at(i)==v.at(j) && i!=j){
        bool nema_ga=true;
        for(auto x:v_kopija){
          if(x==v.at(i)) nema_ga=false;
        }
        if(nema_ga) v_kopija.push_back(v.at(i));
      }
    }
  }
  v=v_kopija;
}

int main() {
  std::cout << "Koliko zelite unijeti rijeci: ";
  int x;
  std::cin >> x;
  std::cout << "Unesite rijeci: ";
  std::vector<std::string> lista;
  for (int i = 0; i < x; i++) {
    std::string rijec;
    std::cin >> rijec;
    lista.push_back(rijec);
  }
  std::string prva_rijec, zadnja_rijec;
  IzdvojiKrajnjeRijeci(lista, prva_rijec, zadnja_rijec);
  ZadrziDuplikate(lista);
  std::cout << "Prva rijec po abecednom poretku je: " << prva_rijec
            << std::endl;
  std::cout << "Posljednja rijec po abecednom poretku je: " << zadnja_rijec
            << std::endl;
  std::cout << "Rijeci koje se ponavljaju su: ";
  for (int i = 0; i < lista.size(); i++) {
    std::cout << lista.at(i) << " ";
  }

  return 0;
}