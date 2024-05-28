#include <iostream>
#include <vector>


const char menu[] {'p','P','a','A','m','M','l','L','s','S','q','Q'};

void Display( const std::vector <int> vec)
{
    if(vec.size()!=0)
    {   
        std::cout<<"[";
        for(auto i:vec)
            std::cout<<" "<<i<<" ";
        std::cout<<"]\n";
    }
    else
        std::cout<<"Vec is empty"<<std::endl;
        

}

void Added(int numToAdd,std::vector<int>*vec)
{
    vec->push_back(numToAdd);
    if (vec->back()==numToAdd)
        std::cout<<"Added "<<numToAdd<<std::endl;
}

void Smalest(std::vector<int>vec)
{
    if(vec.size()!=0)
    {
        int smallest = vec.at(0);
        for(auto i: vec)
            (i < smallest)? smallest = i : i=i;

        std::cout<<"Smalest number is "<<smallest<<std::endl;
    }
    else
        std::cout<<"List is empty\n";
}

void Largest(std::vector<int>vec)
{
    if(vec.size()!=0)
    {
        int smallest = vec.at(0);
        for(auto i: vec)
            (i > smallest)? smallest = i : i=i;

        std::cout<<"Largest number is "<<smallest<<std::endl;
    }
    else
        std::cout<<"List is empty\n";
}
void Mean(const std::vector<int>vec)
{
    int result{0};
    if(vec.size()==0)
        std::cout<<"I cant compute this"<<std::endl;
    else{
        for(auto i: vec)
            result+=i;
        
        result /= vec.size();
        std::cout<<"Mean value " <<result<<"\n";
    }
    
}
int main(void)
{

    std::vector <int> vc {};

    char selection;
    do
    {
            std::cout<<"Program menu\n"
    "P - print numbers\n"
    "A - add number\n"
    "M - display mean of numbers\n"
    "S - display the smalest number\n"
    "L - display the largest number\n"
    "Q - quit"<<std::endl;
        std::cin>>selection;
        if(selection=='P' or selection=='p')
            Display(vc);
        else if (selection=='a' or selection=='A')
        {
            std::cout<<"Enter number to add ";
            int a;std::cin>>a;
            Added(a,&vc);
        }
        else if(selection=='s' or selection=='S')
            Smalest(vc);

        else if(selection=='l' or selection=='L')
            Largest(vc);
        else if(selection=='m' or selection=='M')
            Mean(vc);
    }while(selection != 'q' or selection!='Q');

}