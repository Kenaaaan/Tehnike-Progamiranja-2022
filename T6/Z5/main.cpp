//TP 2022/2023: LV 6, Zadatak 5
#include <iostream>
#include <cmath>
#include <new>
#include <type_traits>
#include <vector>
#include <deque>
template <typename tip>
auto KreirajDinamickuKopiju2D(tip m)
{
    std::remove_reference_t<decltype(m.at(0).at(0))> **mat=nullptr;
    try{
        mat = new std::remove_reference_t<decltype(m.at(0).at(0))>*[m.size()];
        try{
            for(int i=0;i<m.size();i++)
               mat[i] = new std::remove_reference_t<decltype(m.at(0).at(0))>[m.at(i).size()];

                 for(int i=0;i<m.size();i++)
                for(int j=0;j<m.at(i).size();j++)mat[i][j]=m.at(i).at(j);
            
        }catch(...){
            for(int i=0;i<m.size();i++){
                delete[] mat[i];
            }delete[] mat; throw;           
        }

    }catch(...){throw;}
    
    
    return mat;
}
int main(){return 0;}