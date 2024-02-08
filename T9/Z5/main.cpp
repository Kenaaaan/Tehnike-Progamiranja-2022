#include <iostream>
#include <cmath>
#include <iomanip>

class Sat
{
    int sec;
    
    public:
    //bez static nije radilo sto?? pitaj!
    static bool DaLiJeIspravno(int sati, int minute, int sekunde)
    {   if(sati>23 || sati<0 || minute<0 || minute>59 || sekunde<0 || sekunde>59) return false;
        return true;
    }
    Sat Postavi(int sati, int minute, int sekunde){
        if(!DaLiJeIspravno(sati,minute,sekunde)) throw std::domain_error("Neispravno vrijeme");
        sec =sekunde +minute*60+sati*3600;
            return *this;
    }
  Sat PostaviNormalizirano(int sati, int minute, int sekunde) {
    while (sekunde < 0) {
        sekunde += 60;
        minute--;
    }
    while (minute < 0) {
        minute += 60;
        sati--;
    }
    while (sati < 0) {
        sati += 24;
    }
   while(sekunde>59)
   {
       sekunde-=60;
       minute++;
   }
   while(minute>59)
   {
       minute-=60;
       sati++;
   }
   while(sati>23)sati-=24;
            sec =sekunde +minute*60+sati*3600;
     return *this;
}
    Sat Sljedeci(){
       sec++;
        PostaviNormalizirano(DajSate(),DajMinute(),DajSekunde());
        return *this;
    }
    Sat Prethodni() {
     sec--;
        PostaviNormalizirano(DajSate(),DajMinute(),DajSekunde());
        return *this;
    }
    Sat PomjeriZa(int pomak) {
     if(pomak>0)
     for(int i=0;i<pomak;i++)
     Sljedeci();
     else {
     for(int i=0;i>pomak;i--)
     Prethodni();
     }
        return *this;
    }

    void Ispisi() const {
        int sati=DajSate(),minute=DajMinute(),sekunde=DajSekunde();
        std::cout << std::setfill('0') << std::setw(2) << sati << ":"
        << std::setfill('0') << std::setw(2) << minute << ":"
        << std::setfill('0') << std::setw(2) << sekunde;
}
    int DajSate() const {
        return sec/3600;
    }
    int DajMinute() const {
        return (sec-DajSate()*3600)/60;
    }
    int DajSekunde() const {
        return  sec-DajSate()*3600-DajMinute()*60;
    }
    friend int BrojSekundiIzmedju(const Sat &s1, const Sat &s2) {
    int razlika=(s1.DajSate()*3600)+(s1.DajMinute()*60)+s1.DajSekunde()-(s2.DajSekunde())-(s2.DajSate()*3600)-(s2.DajMinute()*60);

    return razlika;
    }
    static int Razmak(const Sat &s1, const Sat &s2) {
    int razlika=(s1.DajSate()*3600)+(s1.DajMinute()*60)+s1.DajSekunde()-(s2.DajSekunde())-(s2.DajSate()*3600)-(s2.DajMinute()*60);
    return razlika;
}

};

int main ()
{
    std::cout<<"Unesite sate minute i sekunde: ";
    int h,m,s;
    std::cin>>h>>m>>s;
    Sat vrijeme;
    vrijeme.Postavi(h, m, s);
    if(!Sat::DaLiJeIspravno(h,m,s)){
        std::cout<<"Pogresno vrijeme";
        return 0;
    }
    vrijeme.Ispisi();
    vrijeme.Sljedeci();
    vrijeme.Prethodni();
    vrijeme.Ispisi();
    std::cout<<"za koliko zelite pomjeriti dato vrijeme: ";
    int pomak;
    std::cin>>pomak;
    vrijeme.PomjeriZa(pomak);
    vrijeme.Ispisi();
    std::cout<<"unesite jos jedno vrijeme da vidimo razliku u sekundama izmedju ova dva vremena!";
    std::cin>>h>>m>>s;
    Sat vrijeme2;
    vrijeme2.Postavi(h,m,s);
    std::cout<<"Razlika je: "<<Sat::Razmak(vrijeme , vrijeme2);


	return 0;
}
