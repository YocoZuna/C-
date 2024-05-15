#include <vector>
#include <iostream>





int main(void){

std::vector <int> vector1,vector2;

vector1.push_back(10);
vector1.push_back(20);

std::cout<<"Vector1\n" << vector1.at(0) << "\n" <<vector1.at(1)<<std::endl;

vector2.push_back(100);
vector2.push_back(200);

std::cout<<"Vector2\n" << vector2.at(0) << "\n" <<vector2.at(1)<<std::endl;


std::vector <std::vector<int>> vector3;

vector3.push_back(vector1);
vector3.push_back(vector2);

std::cout<<"Vector3\n" << vector3.at(0).at(0) << "\n" <<vector3.at(1).at(0)<<std::endl;

vector1.at(0) = 1000;

std::cout<<"Vector3\n" << vector3.at(0).at(0) << "\n" <<vector3.at(1).at(0)<<std::endl;
std::cout<<"Vector1\n" << vector1.at(0) << "\n" <<vector1.at(1)<<std::endl;

}