#include <iostream>
#include <stdexcept>
class Sat
{
	int sati,minute,sekunde;
public:
	Sat();
	Sat(int h,int m, int s);
	static bool DaLiJeIspravno(int &h, int &m, int &s)
	{
		return h>=0 && h<24 && m>=0 && m<60 && s>=0 && s<60;
	}
	void Postavi(int h, int m, int s);
	void PostaviNormalizirano(int h, int m, int s);
	Sat &operator ++();
	Sat &operator --();
	Sat operator +=(int n);
	Sat operator -=(int n);
	friend std::ostream &operator <<(std::ostream &tok, const Sat &sat);
	int DajSate() const
	{
		return sati;
	}
	int DajMinute() const
	{
		return minute;
	}
	int DajSekunde() const
	{
		return sekunde;
	}
	friend int operator -(const Sat &s1, const Sat &s2);
	Sat operator + (int n);
	Sat operator - (int n);
	Sat operator -- (int);
	Sat operator ++ (int);
};
void Sat::Postavi(int h, int m, int s)
{
	if(!DaLiJeIspravno(h,m,s)) throw std::domain_error("Neispravno vrijeme");
	sati=h;
	minute=m;
	sekunde=s;
}
void Sat::PostaviNormalizirano(int h, int m, int s)
{
	m+=s/60;
	h+=m/60;
	s=s%60;
	if(s<0) {
		s=60+s;
		m--;
	}
	m=m%60;
	if(m<0) {
		m=60+m;
		h--;
	}
	h=h%24;
	if(h<0) h+=24;
	sati=h;
	minute=m;
	sekunde=s;
}
Sat::Sat()
{
	sati=0;
	minute=0;
	sekunde=0;
}
Sat::Sat(int h, int m, int s)
{
	PostaviNormalizirano(h,m,s);
}
Sat &Sat::operator ++()
{
	sekunde++;
	PostaviNormalizirano(sati,minute,sekunde);
	return *this;
}
Sat &Sat::operator --()
{
	sekunde--;
	PostaviNormalizirano(sati,minute,sekunde);
	return *this;
}
Sat Sat::operator +=(int n)
{
	sekunde+=n;
	PostaviNormalizirano(sati,minute,sekunde);
	return *this;
}
Sat Sat::operator -=(int n)
{
	return operator +=(-n);
}
std::ostream &operator <<(std::ostream &tok,const Sat &sat)
{
	if(sat.DajSate()<10)
		tok<<0;
	tok<<sat.DajSate()<<":";
	if(sat.DajMinute()<10)
		tok<<0;
	tok<<sat.DajMinute()<<":";
	if(sat.DajSekunde()<10)
		tok<<0;
	tok<<sat.DajSekunde();
	return tok;
}
int operator -(const Sat &s1, const Sat &s2)
{
	return (s1.DajSate()-s2.DajSate())*3600+(s1.DajMinute()-s2.DajMinute())*60 + s1.DajSekunde()-s2.DajSekunde();
}
Sat Sat::operator + (int n)
{
	Sat sat(sati,minute,sekunde+n);
	return sat;
}
Sat Sat::operator - (int n)
{
	Sat sat(sati,minute,sekunde-n);
	return sat;
}
Sat Sat::operator -- (int)
{
	Sat sat(sati, minute, sekunde);
	PostaviNormalizirano(sati,minute,sekunde-1);
	return sat;
}
Sat Sat::operator ++ (int)
{
	Sat sat(sati, minute, sekunde);
	PostaviNormalizirano(sati,minute,sekunde+1);
	return sat;
}
int main()
{
	return 0;
}