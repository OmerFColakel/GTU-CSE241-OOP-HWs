#include "robocop.h" 

namespace Robots
{
    int RoboCop::size = 0;
    
    RoboCop::RoboCop()
    {
        index = size;
        ++size;
        type = 1;
        strength = 0;
        hp = 0;
    }

    RoboCop::RoboCop(int newStrength,int newHp)
    {
        index = size;
        ++size;
        type = 1;
        strength=newStrength;
        hp = newHp;
    }
    
    ostream& operator<< (ostream& out, const RoboCop& obj)
    {
        out << "Type: " << obj.getType() << " "<< obj.index << std::endl
            << "Strength: " << obj.getStrength() << std::endl
            << "Hp: " << obj.getHp() << std::endl << std::endl;
        return out;
    }
}