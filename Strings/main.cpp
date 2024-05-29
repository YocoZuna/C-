#include <string>
#include <iostream>


std::string s1; //Empty
std::string s2 {"DawX"}; /* DawX */
std::string s3 {s2}; /* DawX */
std::string s4 {"Dawid",3}; /* Daw */
std::string s5 {s3,0,2}; /* Da */
std::string s6 (3,'X'); /* XXX */

std::string s8 {s3,3}; /* X */

int main(void)
{
    std::cout<<s1<<std::endl;
    std::cout<<s2<<std::endl;
    std::cout<<s3<<std::endl;
    std::cout<<s4<<std::endl;
    std::cout<<s5<<std::endl;
    std::cout<<s6<<std::endl;
    std::cout<<s8<<std::endl;
}