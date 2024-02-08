//TP 2022/2023: Zadaća 3, Zadatak 3
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <new>
#include <iomanip>
template <typename TipElemenata>
struct Matrica {
    char ime_matrice;
    int br_redova, br_kolona;
    TipElemenata **elementi =nullptr;
};
template <typename TipElemenata>
void UnistiMatricu (Matrica<TipElemenata> &mat)
{
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata>StvoriMatricu(int br_redova, int br_kolona, char ime=0)
{
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova; mat.br_kolona=br_kolona; mat.ime_matrice =ime;
    mat.elementi = new TipElemenata*[br_redova]{};
    try{
        for(int i=0;i<br_redova;i++)
        mat.elementi[i] = new TipElemenata[br_kolona];
    }
    catch(...)
    {
        UnistiMatricu(mat);
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu(Matrica<TipElemenata> &mat)
{
    for(int i=0;i<mat.br_redova;i++)
        for(int j=0;j<mat.br_kolona;j++)
            {
                std::cout<<mat.ime_matrice<<"A("<<i+1<<","<<j+1<<") = "<<std::endl;
                std::cin>>mat.elementi[i][j];
            }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost =6, bool mozda =false)
{
    //std::cout;
    for(int i=0;i<mat.br_redova;i++)
    {
        for(int j=0;j<mat.br_kolona;j++)
        {
             std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        }
        std::cout<<"\n";
    }
   
    if(mozda){
        auto pomocni=mat;
      UnistiMatricu(pomocni);
    } 
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) 
    throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3 = StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona);
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m1.br_kolona;j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    
    return m3;
}
template <typename TipElemenata>
void MnoziSkalarom(Matrica<TipElemenata> &m,double s)
{
    for(int i{};i<m.br_redova;i++)
        for(int j{};j<m.br_kolona;j++)   
                m.elementi[i][j]=m.elementi[i][j]*s;
}
template <typename TipElemenata>
Matrica<TipElemenata>ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona!=m2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3=StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona);
    for(int i=0;i<m1.br_redova;i++)
    {
        for(int j=0;j<m2.br_kolona;j++)
        {
            m3.elementi[i][j]=0;
            for(int k=0;k<m1.br_kolona;k++)
            {
                m3.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
            }
        }
    }
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> MatricniHarmonijskiPolinom(const Matrica<TipElemenata> &m, int n)
{
    if(m.br_redova!=m.br_kolona)   throw std::domain_error("Matrica nije kvadratna");
    if(n<0) throw std::domain_error("Pogresan parametar n");
    Matrica<TipElemenata> pomocna1,rez,pomocna2;
    pomocna1.elementi=nullptr;
    rez.elementi=nullptr;
    try{
    pomocna1=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
    for(int i{};i<m.br_redova;i++)
        for(int j{};j<m.br_kolona;j++)
            pomocna1.elementi[i][j]=m.elementi[i][j];
        pomocna2=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);/////
    for(int i{};i<m.br_redova;i++)
        for(int j{};j<m.br_kolona;j++)
            pomocna2.elementi[i][j]=m.elementi[i][j];/////
    rez=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
    for(int i{};i<m.br_redova;i++)
        for(int j{};j<m.br_kolona;j++)
            rez.elementi[i][j]=m.elementi[i][j];
    for(int i=2;i<=n;i++)
    {
        Matrica<TipElemenata> temp;
        temp=ProduktMatrica(pomocna2,m);
        for(int i{};i<m.br_redova;i++)
            for(int j{};j<m.br_kolona;j++){
               pomocna1.elementi[i][j]=temp.elementi[i][j];
                pomocna2.elementi[i][j]=temp.elementi[i][j];
            }
        UnistiMatricu(temp);
        MnoziSkalarom(pomocna1,1./i);
        temp=ZbirMatrica(rez,pomocna1);
        for(int i{};i<m.br_redova;i++)
            for(int j{};j<m.br_kolona;j++)
                rez.elementi[i][j]=temp.elementi[i][j];

        UnistiMatricu(temp);
    }
   UnistiMatricu(pomocna2);
    UnistiMatricu(pomocna1);
    return rez;
    }
    catch(...){
        UnistiMatricu(pomocna1);
        UnistiMatricu(pomocna2);
        UnistiMatricu(rez);
    throw;}
}
int main ()
{
   std::cout<<"Unesite dimenziju kvadratne matrice: "<<std::endl;
   int n;
   std::cin>>n;
   std::cout<<"Unesite elemente matrice A:"<<std::endl;
   auto A=StvoriMatricu<double>(n,n); 
   Matrica<double> rez;
    try{
   UnesiMatricu(A);
   std::cout<<"Unesite red polinoma: "<<std::endl;
   int lol;
   std::cin>>lol;
   std::cout<<"Matricni harmonijski polinom: "<<std::endl;
   rez=MatricniHarmonijskiPolinom(A,lol);
   IspisiMatricu(rez,10);
   UnistiMatricu(A);
   UnistiMatricu(rez);
    }
    catch(std::domain_error e)
    {
        UnistiMatricu(rez);
        UnistiMatricu(A);
        std::cout<<e.what();
    }
	return 0;
}