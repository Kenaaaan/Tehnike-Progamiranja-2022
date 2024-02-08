// TP 2022/2023: Zadaća 4, Zadatak 4
#include <cmath>
#include <iostream>
#include <map>
#include <memory>
#include <new>

class Korisnik {
  int clanski_broj;
  std::string ime;
  std::string adresa;
  std::string telefon;

public:
  Korisnik(int a, std::string ime, std::string adresa, std::string telefon) {
    clanski_broj = a;
    Korisnik::ime = ime;
    Korisnik::adresa = adresa;
    Korisnik::telefon = telefon;
  }
  int DajClanskiBroj() const { return clanski_broj; }
  std::string DajImeIPrezime() const { return ime; }
  std::string DajAdresu() const { return adresa; }
  std::string DajTelefon() const { return telefon; }
  void Ispisi();
};
void Korisnik::Ispisi() {
  std::cout << "\nClanski broj: " << DajClanskiBroj() << std::endl
            << "Ime i prezime: " << DajImeIPrezime() << std::endl
            << "Adresa: " << DajAdresu() << "\nTelefon: " << DajTelefon();
}
class Film {
  int evidencijski_broj;
  bool dvd;
  std::string ime_filma;
  std::string zanr;
  int godina;
  Korisnik *zaduzenje = nullptr;

public:
  Film(int a, bool b, std::string c, std::string d, int e) {
    evidencijski_broj = a;
    dvd = b;
    ime_filma = c;
    zanr = d;
    godina = e;
    zaduzenje = nullptr;
  }
  int DajEvidencijskiBroj() const { return evidencijski_broj; }
  std::string DajNaziv() const { return ime_filma; }
  std::string DajZanr() const { return zanr; }
  int DajGodinuProdukcije() const { return godina; }
  bool DaLiJeDVD() const { return dvd; }
  void ZaduziFilm(Korisnik *k) { zaduzenje = k; }
  void RazduziFilm() { zaduzenje = nullptr; }
  bool DaLiJeZaduzen() const{
    if (zaduzenje == nullptr) {
      return false;
    }
    return true;
  }
  Korisnik &DajKodKogaJe() const;
  Korisnik *DajPokKodKogaJe() const { return zaduzenje; }
  void Ispisi()const;
};
Korisnik &Film::DajKodKogaJe() const{
  if (zaduzenje == nullptr)
    throw std::domain_error("Film nije zaduzen");
  return *zaduzenje;
}
void Film::Ispisi()const {
  std::cout << "Evidencijski broj: " << DajEvidencijskiBroj() << std::endl
            << "Medij: ";
  if (dvd) {
    std::cout << "DVD" << std::endl;
  } else {
    std::cout << "Video traka" << std::endl;
  }
  std::cout << "Naziv filma: " << DajNaziv() << std::endl
            << "Zanr: " << DajZanr() << std::endl;
  std::cout << "Godina produkcije: " << DajGodinuProdukcije() << std::endl;
}
class Videoteka {
  std::map<int, std::shared_ptr<Korisnik>> korisnik;
  std::map<int, std::shared_ptr<Film>> film;
public:
  Videoteka() = default;
  Videoteka(const Videoteka &v) {
    for(const auto &pari: v.korisnik){
        korisnik[pari.first] = std::make_shared<Korisnik>(*pari.second);
    }
    for(const auto&pari: v.film){
        film[pari.first]=std::make_shared<Film>(*pari.second);
    }
  }
  Videoteka(Videoteka &&v) {
    this->film = std::move(v.film);
    this->korisnik = std::move(v.korisnik);
  }
  Videoteka &operator=(const Videoteka &v);
  Videoteka &operator=(Videoteka &&v);
  Videoteka &RegistrirajNovogKorisnika(int a, std::string b, std::string c,
                                       std::string d);
  Videoteka &RegistrirajNoviFilm(int a, bool b, std::string c, std::string d,
                                 int e);
  Korisnik &NadjiKorisnika(int broj) const;
  Film &NadjiFilm(int broj)const;
  void IzlistajKorisnike()const;
  void IzlistajFilmove()const;
  Videoteka &ZaduziFilm(int evidencijski_broj, int clanski_broj);
  Videoteka &RazduziFilm(int broj);
  void Ispisi() const;
  void PrikaziZaduzenja(int clanski)const;

};

void Videoteka::PrikaziZaduzenja(int clanski) const{
  int brojac = 0;
  NadjiKorisnika(clanski);
  for (auto it = film.begin(); it != film.end(); it++) {
    if (it->second->DajPokKodKogaJe() == korisnik.at(clanski).get()) {
      it->second->Ispisi();
      brojac++;
    }
  }
  if (brojac == 0)
    std::cout << "Korisnik nema zaduzenja!";
}
Videoteka &Videoteka::RazduziFilm(int broj) {
    NadjiFilm(broj);
  if (NadjiFilm(broj).DaLiJeZaduzen())
    NadjiFilm(broj).Film::RazduziFilm();
  else
    throw std::logic_error("Film nije zaduzen");
  return *this;
}
Videoteka &Videoteka::ZaduziFilm(int evidencijski, int clanski) {
  if (NadjiFilm(evidencijski).DaLiJeZaduzen())
    throw std::logic_error("Film vec zaduzen");
  Korisnik *p = &NadjiKorisnika(clanski);
  NadjiFilm(evidencijski).Film::ZaduziFilm(p);
  return *this;
}
void Videoteka::IzlistajFilmove() const{
  for (auto it = film.begin(); it != film.end(); it++) {
    it->second->Ispisi();
    if (it->second->DaLiJeZaduzen()) {
      std::cout << "Zaduzen kod korisnika: "
                << it->second->DajKodKogaJe().DajImeIPrezime() << " ("
                << it->second->DajKodKogaJe().DajClanskiBroj() << ")"
                << std::endl;
    }
    std::cout << std::endl << std::endl;
  }
}
void Videoteka::IzlistajKorisnike() const {
  for (auto it = korisnik.begin(); it != korisnik.end(); it++) {
    it->second->Ispisi();
    std::cout << std::endl << std::endl;
  }
}
Film &Videoteka::NadjiFilm(int broj) const{
  auto it = film.find(broj);
  if (it == film.end())
    throw std::logic_error("\nFilm nije nadjen");
  return *film.at(broj);
}
Korisnik &Videoteka::NadjiKorisnika(int broj) const {
  auto it = korisnik.find(broj);
  if (it == korisnik.end())
    throw std::logic_error("\nKorisnik nije nadjen");
  return *korisnik.at(broj);
}
Videoteka &Videoteka::operator=(const Videoteka &v) {
  if (&v != this) {
      this->film.clear();
      this->korisnik.clear();
    for(const auto &pair:v.film){
        film[pair.first]=std::make_shared<Film>(*pair.second);
    }
    for(const auto&pair:v.korisnik){
        korisnik[pair.first]=std::make_shared<Korisnik>(*pair.second);
    }
  }
  return *this;
}
Videoteka &Videoteka::operator=(Videoteka &&v) {
  if (&v != this) {
    this->film =std::move(v.film);
    this->korisnik = std::move(v.korisnik);
  }
  return *this;
}
Videoteka &Videoteka::RegistrirajNovogKorisnika(int broj, std::string b,
                                                std::string c, std::string d) {
  std::shared_ptr<Korisnik> p = std::make_shared<Korisnik>(broj, b, c, d);
  auto it = korisnik.find(broj);
  if (it == korisnik.end())
    this->korisnik[broj] = p;
  else
    throw std::logic_error("Vec postoji korisnik s tim clanskim brojem");
  return *this;
}
Videoteka &Videoteka::RegistrirajNoviFilm(int a, bool b, std::string c,
                                          std::string d, int e) {
  std::shared_ptr<Film> p = std::make_shared<Film>(a, b, c, d, e);
  auto it = film.find(a);
  if (it == film.end())
    this->film[a] = p;
  else
    throw std::logic_error("Film s tim evidencijskim brojem vec postoji");
  return *this;
}
void Videoteka::Ispisi() const { std::cout << "lol"; }

int main() {
  Videoteka V;
  V.RegistrirajNovogKorisnika(123, "N N", "Nedodjija BB", "000/000-000");
  V.RegistrirajNovogKorisnika(124, "D D", "Nedodjija BB", "000/000-001");
  V.RegistrirajNoviFilm(123, true, "Terminator 3", "akcija", 2003);
  V.RegistrirajNoviFilm(124, 0, "Terminator", "akcija", 1984);
  try {
    V.ZaduziFilm(123, 123);
  } catch (std::logic_error e) {
    std::cout << e.what() << std::endl;
  }

  if (true) {
    std::cout << "V3" << std::endl;
    Videoteka V3(V);
    V3.RazduziFilm(123);
    V3.IzlistajFilmove();
    try {
      V3.NadjiFilm(123).RazduziFilm();
    } catch (std::logic_error e) {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << "V" << std::endl;
  V.IzlistajFilmove();
  return 0;
}
