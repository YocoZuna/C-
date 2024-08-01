#include <iostream>
#include <vector>


class Player{

    /* attributes*/
    public:
        std::string name;
        int health;
        int xp;

        /*methods*/
        void talk(std::string);
        bool is_dead();
        //void TellYourName(void);
};


int main(void)
{

    Player Frank;
    Player* Bart = new Player;

    Frank.name = "Frank";
    Frank.xp = 1000;
    Frank.health = 1010;

    //Frank.TellYourName();
    Frank.talk("Hello");
    Bart->talk("Hello world");
    delete Bart;
    //std::vector<Player> Pleyers{Frank};
    //Pleyers.push_back(Bart);



}

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