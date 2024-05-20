#include <iostream>


// static_cast<type> in c++ is like (type)variable in C
// but it checks if cast is valid on compile time. In C cast 
// is evaluated in runtime
int main(void)
{

    const int x{1};
    int*y = const_cast<int*>(&x);
    *y= 3;
    std::cout<<*y;

    
}