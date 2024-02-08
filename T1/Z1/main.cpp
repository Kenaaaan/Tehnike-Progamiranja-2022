// TP 2016/2017: LV 1, Zadatak 1
/*Unesite duzinu, sirinu i dubinu bazena u metrima: 5 15 3
Unesite sirinu plocice u centimetrima: 10
Za poplocavanje bazena dimenzija 5x15x3m sa plocicama dimenzija 10x10cm
potrebno je 19500 plocica.

Unesite duzinu, sirinu i dubinu bazena u metrima: 5 15 3
Unesite sirinu plocice u centimetrima: 13
Poplocavanje bazena dimenzija 5x15x3m sa plocicama dimenzija 13x13cm
nije izvodljivo bez lomljenja plocica!
*/
#include <cmath>
#include <iostream>

using namespace std;
int main() {
  int a, b, c, d;
  cout << "Unesite duzinu, sirinu i dubinu bazena u metrima: ";
  cin >> a >> b >> c;
  cout << "Unesite sirinu plocice u centimetrima: " << endl;
  cin >> d;
  int s = 0;
  s = (a * b) + 2 * (c * b) + 2 * (c * a);
  s = s * 10000;
  int dk;
  dk = d * d;
  int x = 0;
  x = s / dk;
  if (s % dk == 0 && a*100%d==0 && b*100%d==0 && c*100%d==0) {
    cout << "Za poplocavanje bazena dimenzija " << a << "x" << b << "x" << c
         << "m sa plocicama dimenzija " << d << "x" << d << "cm" << endl
         << "potrebno je " << x << " plocica." << endl;
  } else {
    cout << "Poplocavanje bazena dimenzija " << a << "x" << b << "x" << c
         << "m sa plocicama dimenzija " << d << "x" << d
         << "cm nije izvodljivo bez lomljenja plocica!" << endl;
  }

  return 0;
}