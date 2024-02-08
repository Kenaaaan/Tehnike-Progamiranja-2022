#include <iostream>
#include <functional>

std::function<double(double)> plus2 (double x) {
 return [x](double y) { return x+y; };
}

std::function<std::function<double(double)>(double)> plus3 (double x){
    return [x](double y){return [x,y](double z){return x+y+z;};};
}

int main ()
{
    std::cout<<plus2(1)(9)<<std::endl;
    std::cout<<plus3(5)(1)(2)<<std::endl;
	return 0;
}