#include <cctype>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
std::string smanji_ga(std::string s) {
  std::string s1;
  for (int i = 0; i < s.length(); i++) {
    s1.push_back(tolower(s.at(i)));
  }
  return s1;
}
std::string Cenzura(std::string s, std::vector<std::string> s1) {
for(std::string pomocni :s1)
{
    for(char a:pomocni)
    {
        if(a!='.' && (a<'a' || a>'z') && (a<'0' || a>'9') && (a<'A' || a>'Z')) throw std::logic_error("Neispravna riječ");
    }
}
  int pocetni = 0;
  int kraj = 0;
  int brojac = 0;
  bool mozda = false;
  for (int i = 0; i < s.length(); i++) {
    if (s.at(i) != ' ') {
      pocetni = i;
      std::string pomocni_iz_prvog;
      while (i < s.length() && ((s.at(i)>='a' && s.at(i)<='z') || (s.at(i)>='A' && s.at(i)<='Z') || (s.at(i)<='0' && s.at(i)>='9'))) {
        if ((s.at(i)>='a' && s.at(i)<='z') || (s.at(i)>='A' && s.at(i)<='Z') || (s.at(i)<='0' && s.at(i)>='9')) {
          pomocni_iz_prvog.push_back(s.at(i));
          brojac++;
        }
        i++;
      }
      //
      kraj = brojac + pocetni;
      brojac = 0;
      for (std::string pomocni_iz_drugog : s1) {
        std::string xo1 = smanji_ga(pomocni_iz_prvog),
                    xo2 = smanji_ga(pomocni_iz_drugog);
        if (xo1 == xo2) {
          for (int j = pocetni; j < kraj; j++) {
            s.at(j) = '*';
          }
        }
      }
    }
  }
  return s;
}

int main() {

  std::cout << "Unesite recenicu:";
  std::string s1;
  std::vector<std::string> s2;
  std::getline(std::cin, s1);
  std::cout << "\nUnesite zabranjene rijeci (. za kraj): ";
  int i = 0;
  bool mozda = false;
  while (true) {
    std::string pomocni;
    std::cin >> pomocni;
    s2.push_back(pomocni);
    for (int i = 0; i < pomocni.length(); i++) {
        if((!isalpha(pomocni.at(i))) && (!isdigit(pomocni.at(i))) && pomocni.at(i)!='.') {
            std::cout<<"GRESKA: Nelegalne zabranjene rijeci!";
            return 0;
        }

      if (pomocni.at(i) == '.')
        mozda = true;
    }
    if (mozda)
      break;
  }

  try {
    std::cout << "\nCenzurisana recenica: " << Cenzura(s1, s2);
  } catch (std::logic_error greska) {
    std::cout << greska.what();
  }
  /*Unesite recenicu:
Unesite zabranjene rijeci (. za kraj):
Cenzurisana recenica: On je potpuni *****, stoga ga treba dobro *********!*/
  return 0;
}
