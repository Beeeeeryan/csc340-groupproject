#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

struct Position {  // Struct to represent (x, y) coordinates
    int x;
    int y;
};

class Character {
    protected:
        std::string name; 
        int health;
        int attackPower;
        int positionX;
        int positionY;
    public:
        Character();
        Character(std::string name, int health, int attackPower, int positionX, int positionY);
        void move(int x, int y);
        bool isAlive() const;
        std::string getName() const;
        int getAttackPower() const;
        Position getPosition() const;  // Use Position struct instead of std::pair
};

#endif
