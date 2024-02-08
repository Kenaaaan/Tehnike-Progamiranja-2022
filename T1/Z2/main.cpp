// TP 2016/2017: Tutorijal 1, Zadatak 2
#include <cmath>
#include <iostream>
#include <math.h>

int main() {
  double a, b, c;
  std::cout << "Unesite tri broja: ";
  std::cin >> a >> b >> c;
  if (a <= 0 || b <= 0 || c <= 0) {
    std::cout << "Ne postoji trougao cije su duzine stranica " << a << ", " << b
              << " i " << c << "!" << std::endl;
    return 0;
  }
  if ((a + b) <= c) {
    std::cout << "Ne postoji trougao cije su duzine stranica " << a << ", " << b
              << " i " << c << "!" << std::endl;
    return 0;
  } else if ((a + c) <= b) {
    std::cout << "Ne postoji trougao cije su duzine stranica " << a << ", " << b
              << " i " << c << "!" << std::endl;
    return 0;
  } else if ((c + b) <= a) {
    std::cout << "Ne postoji trougao cije su duzine stranica " << a << ", " << b
              << " i " << c << "!" << std::endl;
    return 0;
  }

  double s, o, p, ua, ub, uc;
  o = a + b + c;
  s = (a + b + c) / 2;
  p = sqrt(s * (s - a) * (s - b) * (s - c));
  std::cout << "Obim trougla sa duzinama stranica " << a << ", " << b << " i "
            << c << " iznosi " << o << '.' << std::endl;
  std::cout << "Njegova povrsina iznosi " << p << "." << std::endl;

  uc = (-(c * c) + a * a + b * b) / (2 * a * b);
  ub = (-(b * b) + c * c + a * a) / (2 * a * c);
  ua = (-(a * a) + c * c + b * b) / (2 * c * b);
  uc = acos(uc);
  ua = acos(ua);
  ub = acos(ub);
  int min, sec, deg;
  /*
ua=round(ua);
ub=round(ub);
uc=round(uc);
*/
  if (ua <= ub && ua <= uc) {
    int totalsec = (int)(ua * 360 * 60 * 60 / (2 * (4 * atan(1))));
    sec = totalsec % 60;
    min = (totalsec / 60) % 60;
    deg = totalsec / (60 * 60);
  } else if (uc <= ub && uc <= ua) {
    int totalsec = (int)(uc * 360 * 60 * 60 / (2 * (4 * atan(1))));
    sec = totalsec % 60;
    min = (totalsec / 60) % 60;
    deg = totalsec / (60 * 60);
  } else if (ub <= uc && ub <= ua) {
    int totalsec = (int)(ub * 360 * 60 * 60 / (2 * (4 * atan(1))));
    sec = totalsec % 60;
    min = (totalsec / 60) % 60;
    deg = totalsec / (60 * 60);
  }

  std::cout << "Njegov najmanji ugao ima " << deg << " stepeni, " << min
            << " minuta i " << sec << " sekundi.";

  // Njegov najmanji ugao ima 21 stepeni, 47 minuta i 12 sekundi.

  return 0;
}