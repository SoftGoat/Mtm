#include <iostream>
#include <cstring>
class Player
{
private:
    char* name;
    int level;
    int force;
    int hp;
    int maxHp;
    int coins;
    const char* DEFAULT_NAME = "player";
    const int DEFAULT_LEVEL = 1;
    const int DEFAULT_FORCE = 5;
    const int DEFAULT_HP = 100;
    const int DEFAULT_MAXHP = 100;
    const int DEFAULT_COINS = 0;
    const int MAXIMUM_LEVEL = 10;
    const int MINIMUM_LEVEL = 1;
    const int MINIMUM_FORCE = 0;
    const int MINIMUM_HP = 0;
    const int MINIMUM_MAXHP = 1;
    const int MINIMUM_COINS = 0;
    //test someting
public:
    Player(char* name_, int level, int force, int hp, int maxHp, int coins);
    Player(char* name_, int force, int maxHp);
    Player(char* name_, int maxHp);
    Player(char* name_);
    Player();
    Player(const Player& other); // Copy constructor 
    ~Player();
    void printInfo();
    Player& operator=(const Player& other);
    void levelUp();
    int getLevel();
    void buff(int attack);
    void heal(int potion);
    void damage(int dmg);
    void isKnockedOut();
    void addCoins(int money);
    bool pay(int transaction);
    int getAttackStrength();

private:
    bool inputValidation(char*& name, int& level, int& force, int& hp, int& maxHp, int& coins);
    void printPlayerInfo(const char* name, int level, int force, int hp, int coins);

};

Player::Player(char* name_, int level, int force, int hp, int maxHp, int coins)
{
    char* name = new char[strlen(name_) + 1];
    strcpy(name, name_);
    inputValidation(name, level, force, hp, maxHp, coins);
    this->name = name;
    this->level = level;
    this->force = force;
    this->hp =hp;
    this->maxHp = maxHp;
    this->coins = coins;
}

Player::Player(char* name_, int force, int maxHp){

    int hp = maxHp;
    int coins = DEFAULT_COINS;
    int level = DEFAULT_LEVEL;
    char* name = new char[strlen(name_) + 1];
    strcpy(name, name_);
    inputValidation(name, level, force, hp, maxHp, coins);
    this->name = name;
    this->level = level;
    this->force = force;
    this->hp = hp;
    this->maxHp = maxHp;
    this->coins = coins;


}

Player::Player(char* name_, int maxHp){

    int hp = maxHp;
    int coins = DEFAULT_COINS;
    int level = DEFAULT_LEVEL;
    int force = DEFAULT_FORCE;
    char* name = new char[strlen(name_) + 1];
    strcpy(name, name_);
    inputValidation(name, level, force, hp, maxHp, coins);
    this->name = name;
    this->level = level;
    this->force = force;
    this->hp = hp;
    this->maxHp = maxHp;
    this->coins = coins;


}

Player::Player(char* name_){

    int hp = maxHp;
    int coins = DEFAULT_COINS;
    int level = DEFAULT_LEVEL;
    int force = DEFAULT_FORCE;
    int maxHp = DEFAULT_MAXHP;
    char* name = new char[strlen(name_) + 1];
    strcpy(name, name_);
    inputValidation(name, level, force, hp, maxHp, coins);
    this->name = name;
    this->level = level;
    this->force = force;
    this->hp = hp;
    this->maxHp = maxHp;
    this->coins = coins;

}

Player::Player(){
    int maxHp = DEFAULT_MAXHP;
    int hp = maxHp;
    int coins = DEFAULT_COINS;
    int level = DEFAULT_LEVEL;
    int force = DEFAULT_FORCE;
    char* name = new char[strlen(DEFAULT_NAME) + 1];
    strcpy(name, DEFAULT_NAME);
    inputValidation(name, level, force, hp, maxHp, coins);
    this->name = name;
    this->level = level;
    this->force = force;
    this->hp = hp;
    this->maxHp = maxHp;
    this->coins = coins;

}

Player::Player(const Player& other){

    this->level = other.level;
    this->force = other.force;
    this->hp = other.hp;
    this->maxHp = other.maxHp;
    this->coins = other.coins;
    delete[] this->name; // named should be always not null
    this->name = new char[strlen(other.name) + 1];
    strcpy(name,other.name);
}


Player::~Player()
{
    delete[] name;
}


Player& Player::operator=(const Player& other) {
    if(this!=&other){
        delete[] name;
        level = other.level;
        force = other.force;
        hp = other.hp;
        maxHp = other.maxHp;
        coins = other.coins;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

    }
    return *this;
}


void Player::printPlayerInfo(const char* name, int level, int force, int hp, int coins){

    std::cout << "Player Details:\n" << std::endl;
    std::cout << "Name: " << name << "\n"<< std::endl;
    std::cout << "Level: " << level << "\n"<< std::endl;
    std::cout << "Force: " << force << "\n"<< std::endl;
    std::cout << "HP: " << hp << "\n"<< std::endl;
    std::cout << "Coins: " << coins << "\n"<< std::endl;
    std::cout << "------------------------\n" << std::endl;


}

void Player::printInfo(){
    printPlayerInfo(this->name,this->level,this->force,this->hp,this->coins);
}

void Player::levelUp(){
    if(this->level<MAXIMUM_LEVEL){
        this->level++;
    }
    else{
        std::cout << "Player already reached max level: " <<std::endl;
    }
}

int Player::getLevel(){
    return this->level;
}

void Player::buff(int attack){
    this->force+=attack;
}

void Player::heal(int potion){
    int temp = this->hp+potion;
    this->hp = temp > this->maxHp ? this->maxHp : temp;
}

void Player::damage(int attack){
    int temp = this->hp-attack;
    this->hp = temp < MINIMUM_HP ? MINIMUM_HP : temp;
}

void Player::isKnockedOut(){
    if(this->hp == MINIMUM_HP){  // shoudnt be sincero that hp < MINIMUM_HP
        std::cout << "Player is knocked out";
    }
    else{
        std::cout << "Player is not knocked out";
    }
}

void Player::addCoins(int money){
    this->coins+=money;
}

bool Player::pay(int transaction){
    int temp = this->coins-transaction;
    if (temp < MINIMUM_COINS)
    {
        std::cout << "Not enough coins";
        return false;
    }
    this->coins = temp;
    std::cout << "Transaction made successfully" <<std::endl;
    return true;
}


int Player::getAttackStrength(){
    return this->force+this->level;
}

bool Player::inputValidation(char*& name, int& level, int& force, int& hp, int& maxHp, int& coins)
{
    bool unchanged = true;
    if (level < MINIMUM_LEVEL || level > MAXIMUM_LEVEL)
    {
        level = DEFAULT_LEVEL;
        unchanged = false;
        std::cout << "The value of 'level' is invalid value changed to default setting:  " << DEFAULT_LEVEL << std::endl;
    }

       if (force < MINIMUM_FORCE)
    {
        force = DEFAULT_FORCE;
        unchanged = false;
        std::cout << "The value of 'force' is invalid, value changed to default setting:  " << DEFAULT_FORCE << std::endl;

    }

        if (maxHp < MINIMUM_MAXHP)
    {
        maxHp = DEFAULT_MAXHP;
        unchanged = false;
        std::cout << "The value of 'maxHp' is invalid, value changed to default setting:  " << DEFAULT_MAXHP << std::endl;
    }

        if (hp < MINIMUM_HP || hp > maxHp)
    {
        hp = maxHp;
        unchanged = false;
        std::cout << "The value of 'hp' is invalid, value changed to maxHp value :  " << maxHp << std::endl;
    }
        if (coins < MINIMUM_COINS)
    {
        coins = DEFAULT_COINS;
        unchanged = false;
        std::cout << "The value of 'coins' is invalid, value changed to default setting:  " << DEFAULT_COINS << std::endl;
    }
    char* temp = name;
    bool nameIsValid =true;
    while(temp != '\0' && nameIsValid){
        if(*temp < 'a' || *temp > 'z' ){
            unchanged = false;
            std::cout << "The value of 'name' is invalid, value changed to default setting:  " << DEFAULT_NAME << std::endl;
            nameIsValid =false;
        }
        temp++;
    }
    return unchanged;
}
