#include <iostream>
#include "humanic.h"

namespace Robots
{
    int Humanic::size = 0;

    Humanic::Humanic()
    {
        index = size++;
        type = 5 ;
        strength = 0;
    }

    Humanic::Humanic(int newStrength,int newHp)
    {
        type = 5 ;
        index = size ++;
        strength = newStrength;
        hp = newHp;
    }

    int Humanic::getDamage() const
    {
        int tacNukeAtt = rand() % 10;
        if(tacNukeAtt==0)
            return 50 + Robot::getDamage();
            
        return Robot::getDamage();
    }

    ostream& operator<< (ostream& out, const Humanic& obj)
    {
        out << "Type: " << obj.getType() << " " << obj.index << std::endl
            << "Strength: " << obj.getStrength() << std::endl
            << "Hitpoints: " << obj.getHp() << std::endl << std::endl;
        return out;
    }
}

