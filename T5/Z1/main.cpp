#include <iostream>

using namespace std;

int main() {
  char recenica[1000];//receno je u postavci da se ne smiju koristit stringovi pa ovako se mora unos raditi
  cout << "Unesite recenicu: ";
  cin.getline(recenica, sizeof(recenica), '\n');

  char *pok = recenica;
  //*pok uslov je ako je validan unos tj dok nije \0
  while (*pok && *pok == ' ')
    pok++; // preskacemo pocetne razmake
  while (*pok && *pok != ' ')
    pok++; // preskacemo prvu rijec
  while (*pok && *pok == ' ')
    pok++; // preskacemo razmake prije druge rijeci
  cout << "Recenica bez prve rijeci glasi: " << pok << endl;

  return 0;
}