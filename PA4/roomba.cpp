#include "roomba.h"

namespace Robots
{
    int Roomba::size = 0;
    Roomba::Roomba()
    {
        index = size++;
        type = 2;
        strength = 0;
        hp = 0;

    }
    Roomba::Roomba(int newStrength,int newHp)
    {
        index = size++;   
        type = 2;
        strength=newStrength;
        hp = newHp;
    }

    int Roomba::getDamage() const
    {
        return Robot::getDamage() + Robot::getDamage();
    }
    
    ostream& operator<< (ostream& out, const Roomba& obj)
    {
        out << "Type: " << obj.getType() << " " << obj.index <<  std::endl
            << "Strength: " << obj.getStrength() << std::endl
            << "Hp: " << obj.getHp() << std::endl << std::endl;
        return out;
    }
}