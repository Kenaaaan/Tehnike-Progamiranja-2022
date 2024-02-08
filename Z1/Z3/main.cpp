#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<int>> matrica;
int najvecasirina(matrica m)
{
    int rez=0;
    if(m.size()==0) return 0;
    for(int i=0;i<m.size();i++)
    {
        for(int j=0;j<m.at(i).size();j++)
        {
        int k=0;
        if(m.at(i).at(j)<0) k++;
        long int x=abs(m.at(i).at(j));
        while(x!=0)
        {
            x=x/10;
            k++;
        }
        if(k>=rez) rez=k;
        }
    }
    return rez;
}
matrica KreirajSpiralnuMatricu(int m, int n, int k, bool maybe) {
  matrica lol(m, std::vector<int>(n));
  if (m <= 0 || n <= 0)
    return matrica(0, std::vector<int>(0));
    int xo=k;
  int i, j, l, z, lijeva = 0, gornja = 0, desna = n - 1, donja = m - 1;
  if (maybe) {
    while (k <=(xo + m * n - 1)) {
      for (i = lijeva; i <= desna; i++) {
        lol.at(gornja).at(i) = k;
        k++;
        if (k > (xo + m * n - 1))
          return lol;
      }
      gornja++;
      for (j = gornja; j <= donja; j++) {
        lol.at(j).at(desna) = k;
        k++;
        if (k > (xo + m * n - 1))
          return lol;
      }
      desna--;
      for (l = desna; l >= lijeva; l--) {
        lol.at(donja).at(l) = k;
        k++;
        if (k > (xo + m * n - 1))
          return lol;
      }
      donja--;
      for (z = donja; z >= gornja; z--) {
        lol.at(z).at(lijeva) = k;
        k++;
        if (k > (xo + m * n - 1))
          return lol;
      }
      lijeva++;
    }
  }
  else 
  {
        while (k <=(xo + m * n - 1)) {

      for (j = gornja; j <= donja; j++) {
        lol.at(j).at(lijeva) = k;
        k++;
        if (k > (xo + m * n - 1))
          return lol;
      }
      lijeva++;

      for (i = lijeva; i <= desna; i++) {
        lol.at(donja).at(i) = k;
        k++;
        if (k > (xo + m * n - 1))
          return lol;
      }
      donja--;

      for (j = donja; j >= gornja; j--) {
        lol.at(j).at(desna) = k;
        k++;
        if (k > (xo + m * n - 1))
          return lol;
      }
      desna--;

      for (l = desna; l >= lijeva; l--) {
        lol.at(gornja).at(l) = k;
        k++;
        if (k > (xo + m * n - 1))
          return lol;
      }
      gornja++;
      
    }
  }
  return lol;
}
bool DaLiJeSpiralnaMatrica(matrica lol)
{
    for(int k=0;k<lol.size()-1;k++)
    {
        if(lol.at(k).size()>lol.at(k+1).size() || lol.at(k).size()<lol.at(k+1).size()) return false;
    }
matrica a=KreirajSpiralnuMatricu(lol.size(), lol.at(0).size(), lol.at(0).at(0), true);     
if (a==lol) return true;
a=KreirajSpiralnuMatricu(lol.size(), lol.at(0).size(), lol.at(0).at(0), false);
if (a==lol) return true;
return false;
}
int main() {

  int m = 5, n = 7;

  matrica a(m, std::vector<int>(n, 0));
  std::cout<<"Unesite broj redova i kolona matrice: ";
  std::cin>>m>>n;
  std::cout<<"Unesite pocetnu vrijednost: ";
  int k;
  std::cin>>k;
  std::cout<<"Unesite L za lijevu, a D za desnu spiralnu matricu: "<<std::endl;
  char c;
  std::cin>>c;
  try{
  if(c=='D'|| c=='d')
  {
     std::cout<<"Kreirana spiralna matrica:"<<std::endl;
 a=KreirajSpiralnuMatricu(m, n, k,true);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cout<<std::fixed<<std::right<<std::setw(najvecasirina(a)+1)<<a.at(i).at(j);
    }
    std::cout << std::endl;
  }
  }
    else if(c=='L' || c=='l') 
  {
      std::cout<<"Kreirana spiralna matrica:"<<std::endl;
a=KreirajSpiralnuMatricu(m, n, k,false);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cout<<std::fixed<<std::right<<std::setw(najvecasirina(a)+1)<<a.at(i).at(j);
    }
    std::cout << std::endl;
  }
  }
  }catch(std::domain_error negativan)
  {
      std::cout<<negativan.what()<<std::endl;
  }
      
  return 0;
}