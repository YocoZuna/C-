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
    std::string sh = "Helloworld";
    std::string concat  = sh+s2+s3; // String concat in C++
    //std:: string concat = "Elo" + "Siema" ; // This is forbiden 
    concat.at(10) = 'X';
    std::cout<<concat<<std::endl;
    std::string s69 = concat.substr(3,3);  // (Inex,lenght)
    concat += sh;
    std::cout<<concat.find("Helloworld")<<std::endl; // return index if not find return string::npos
    std::cout<<concat.find("Helloworld",3)<<std::endl; // return index of first occurenc starting for index 3
    std::cout<<s69; 
    
   
    std::cout<<concat.erase(5,8)<<std::endl; // Delates chars form given postion to length
    concat.clear(); // clears whole var
    std::cout<<concat<<std::endl;
    std::cout<<std::boolalpha;
    std::cout<<(concat == concat);
}