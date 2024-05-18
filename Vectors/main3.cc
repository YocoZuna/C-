#include <iostream>
#include <vector>


using namespace std;

int main(void)
{
    vector <int> hello{1,2,3};
    //vector <vector>int>>  vector of vectors
    int score{0};
    
    cin>> score;

    hello.push_back(score);
    //Test
    
    cout<<hello[0]<<endl; // Does not do bound checking
    cout<<hello[1]<<endl;
    cout<<hello[2]<<endl;
    cout<<hello[3]<<endl;
    //cout<<hello.at(3)<<endl; // does bound checking 
    hello.push_back(10); // adding new element at te end

    cout<< "Size of hello " << hello.size() << endl;

    cout << "Update values" <<endl;
    cin>>hello.at(0);
    cin>>hello.at(1);
    cin>>hello.at(2);


    cout << "\nNew vals" <<endl;
    cout<<hello[0]<<endl; // Does not do bound checking
    cout<<hello[1]<<endl;
    cout<<hello[2]<<endl; 
    cin>>hello.at(3);




}