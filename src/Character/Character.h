#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
    protected:
        std::string name; 
        int health;
        int attackPower;
        int positionX;
        int positionY;
    public:
        Character();
        void move(int x, int y);
        bool isAlive() const;

}; 
#endif