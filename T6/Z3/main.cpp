#include <iostream>
#include <stdexcept>
int **KreirajTrougao(int n){
    if(n<=0) throw std::domain_error("Broj redova mora biti pozitivan");
    int **grbava=nullptr;
    try{
        grbava=new int*[n]{};
        for(int i=0; i<n; i++){
            try{
                grbava[i]=new int [2*i+1];
            }
            catch(...){
                for(int i=0; i<n; i++) delete[] grbava[i];
                delete[] grbava;
                throw;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<2*i+1; j++){
                grbava[i][j]=abs(i-j)+1;
            }
        }
    }
    catch(...){
        throw;
    }
    return grbava;
}
int main ()
{
    try{
        std::cout<<"Koliko zelite redova: ";
        int n;
        std::cin>>n;
        int **grbava=KreirajTrougao(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<2*i+1; j++){
                std::cout<<grbava[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        for(int i=0; i<n; i++) delete[] grbava[i];
        delete[] grbava;
    }
    catch(std::domain_error greska){
        std::cout<<"Izuzetak: "<<greska.what();
    }
    catch(std::bad_alloc){
        std::cout<<"Izuzetak: Nedovoljno memorije!";
    }
	return 0;
}