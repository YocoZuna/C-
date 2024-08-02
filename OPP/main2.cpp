#include <iostream>
#include <vector>


class Player{

    /* attributes*/
    public:
        std::string name;
        int health;
        int xp;

        Player();

        /*methods*/
        void talk(std::string);
        bool is_dead();
        //void TellYourName(void);
};





int main(void)
{

    Player Frank;
    Player* Bart = new Player;


    std::cout<<Frank.name<<std::endl;


}
Player::Player():name{"None"},health{1000},xp{0}{}; // constructor inicialization list # remark does not work with defualt constructor
void Player::talk(std::string mess)
{
    std::cout<<"Message is :"<<mess<<std::endl;
}
/*
void Player::TellYourName(void)
{
    std::cout<<"My name is"<<this->name<<std::endl;
}
*/