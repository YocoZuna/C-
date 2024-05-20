#include <iostream>


// static_cast<type> in c++ is like (type)variable in C
// but it checks if cast is valid on compile time. In C cast 
// is evaluated in runtime
int main(void)
{

    int x,y;
    double result;

    result = static_cast<double>(x/y);
    std::cout<<result<<std::endl;


}