#include "bulldozer.h"

namespace Robots
{
    int Bulldozer::size = 0;

    Bulldozer::Bulldozer()
    {
        index = size++;
        type = 3;
        strength = 0;
        hp = 0;
    }

    Bulldozer::Bulldozer(int newStrength,int newHp)
    {
        index = size++;
        type = 3;
        strength=newStrength;
        hp = newHp;
    }
    
    ostream& operator<< (ostream& out, const Bulldozer& obj)
    {
        out << "Type: " << obj.getType() << " "  << obj.index << std::endl
            << "Strength: " << obj.getStrength() << std::endl
            << "Hp: " << obj.getHp() << std::endl << std::endl;
        return out;
    }
}