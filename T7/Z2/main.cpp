#include <iostream>
#include <cstring>
#include <new>
#include <vector>
#include <string>
#include <algorithm>

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

int main() {


    int n;
    std::cout << "Koliko zelite recenica: ";
    std::cin >> n;
    std::cin.ignore(10000, '\n'); 
    char ** recenice = nullptr;
    try{
            std::cout << "Unesite recenice: " << std::endl;
        recenice =new char*[n] {};
        if(recenice==nullptr) throw ;
        for(int i=0; i<n; i++) {
            char s[1000];
            std::cin.getline(s, sizeof s);
            recenice[i] = new char[std::strlen(s) + 1];
            if(recenice[i]==nullptr) throw;
            std::strcpy(recenice[i], s);
        }
       //
        std::sort(recenice,recenice+n,[](char* a, char* b){
            if(*a==*b)
            {
                int brojac=0;
                while(*a==*b && brojac<std::strlen(a) && brojac<std::strlen(b))
                {
                    brojac++;
                    a++;
                    b++;
                }
                return *a<*b;
            }
            return *a<*b;
        });
       //
        std::cout << "Sortirane recenice: " << std::endl;
        for(int i=0; i<n; i++) std::cout << recenice[i] << std::endl;

         
    for (int i = 0; i < n; i++)
      delete[] recenice[i];
    delete[] recenice;
  } catch (...) {
    if (recenice) { 
      for (int i = 0; i < n; i++)
        if (recenice[i])
          delete[] recenice[i];
      delete[] recenice;
    }
        std::cout << "Problemi s memorijom!" << std::endl;
    }
    return 0;
}