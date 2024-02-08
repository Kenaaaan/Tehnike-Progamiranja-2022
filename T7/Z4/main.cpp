#include <iostream>
#include <cstring>
#include <new>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
void sortStrings(char **& vec, int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(std::strcmp(vec[j], vec[j+1]) > 0) {
                char* temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
        }
    }
}
typedef std::shared_ptr<std::string> pametni; 
int main() {
    int n;
    std::cout << "Koliko zelite recenica: ";
    std::cin >> n;
                std::cout << "Unesite recenice: " << std::endl;
    std::cin.ignore(10000, '\n'); 
    try{
        std::unique_ptr<pametni[]> recenice(new pametni[n]);
       for(int i=0;i<n;i++)
       {
           recenice[i]=std::make_shared<std::string>();
           std::getline(std::cin, *recenice[i]);
       }
       //
        std::sort(recenice.get(),recenice.get()+n,[](pametni a, pametni b){return *a<*b;});
       //
        std::cout << "Sortirane recenice: " << std::endl;
        for(int i=0; i<n; i++) std::cout << *recenice[i] << std::endl;
    }catch(...){
        std::cout << "Problemi s memorijom!" << std::endl;
    }
    return 0;
}