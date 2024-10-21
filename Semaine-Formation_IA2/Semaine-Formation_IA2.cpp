#include <iostream>
#include <vector>

class Enemy
{
    std::string mName;
    int mMaxHp;
    int mHp;

public:

    Enemy(std::string name, int max_hp) :
        mName(name),
        mMaxHp(max_hp),
        mHp(mMaxHp)
    {
        std::cout << "create enemy: " << "Name: " << name << " Max Hp: " << max_hp << std::endl;
    }

    virtual ~Enemy()
    {
        std::cout << "destroy enemy" << std::endl;
    }

    int getHp() const
    {

        return mHp;

    }

    int getMaxHp() const
    {

        return mMaxHp;

    }

    std::string getName() const
    {

        return mName;

    }

    void SetHp(int h) 
    {

        mHp = h;

    }

    virtual void takeDamage(unsigned int damage) = 0;

    virtual void print(std::ostream& os) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Enemy& enemy) {
        enemy.print(os); // Call virtual method for dynamic behavior
        return os;
    }
};

class Minion : public Enemy
{
public:
    Minion() :
        Enemy("Minion", 2)
    {
        std::cout << "created a new Minion()" << std::endl;
    }
    ~Minion()
    {
        std::cout << "waargh" << std::endl;
    }

    void takeDamage(unsigned int damage)
    {
        if (this->getHp() <= 0) {
            this->~Minion();
        }

        std::cout << "ouch" << std::endl;
        this->SetHp(this->getHp() - damage);
    }

    void print(std::ostream& os) const override {
        os << "Print: [" << getName() << ", " << getMaxHp() << ", " << getHp() << "]";
    }

};

class WildDog : public Enemy
{
public:
    WildDog() :
        Enemy("WildDog", 10)
    {
        std::cout << "created a new WildDog()" << std::endl;
    }
    ~WildDog()
    {
        std::cout << "YELP" << std::endl;
    }

    void takeDamage(unsigned int damage)
    {
        if (this->getHp() <= 0) {
            this->~WildDog();
        }

        std::cout << "yelp" << std::endl;
        this->SetHp(this->getHp() - damage);
    }

    void print(std::ostream& os) const override {
        os << "Print: [" << getName() << ", " << getMaxHp() << ", " << getHp() << "]";
    }
};

int main()
{
    std::vector<Enemy*> enemy_container;
    enemy_container.push_back(new Minion());
    enemy_container.push_back(new WildDog());

    for (int i = 0; i < enemy_container.size(); ++i)
    {
        enemy_container[i]->takeDamage(1);
        std::cout << *enemy_container[i] << std::endl;
    }

    for (int i = 0; i < enemy_container.size(); ++i)
    {
        delete enemy_container[i];
    }
}


