#include <iostream>
#include <string>
#include <algorithm>

std::string IzvrniBezRazmaka(std::string s) {
    std::string p;
    remove_copy(s.begin(), s.end(), inserter(p, p.begin()), ' ');
    reverse(p.begin(), p.end());
    return p;
}

int main() {
    std::string s = "Evo pada kiša";
    std::cout << IzvrniBezRazmaka(s) <<std::endl; 
    return 0;
}
