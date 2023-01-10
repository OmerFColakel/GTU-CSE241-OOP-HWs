#include "optimusprime.h" 

namespace Robots
{
    int OptimusPrime::size = 0;

    OptimusPrime::OptimusPrime()
    {
        index = size;
        ++size;
        type = 0;
        strength = 0;
        hp = 0;
    }

    OptimusPrime::OptimusPrime(int newStrength,int newHp)
    {
        index = size;
        ++size;
        type = 0;
        strength=newStrength;
        hp = newHp;
    }
    
    int OptimusPrime::getDamage() const
    {
        int doubleTheDamage = rand() % 100;
        if(doubleTheDamage < 15)
            return Humanic::getDamage()*2;
        return Humanic::getDamage();
    }

    ostream& operator<< (ostream& out, const OptimusPrime& obj)
    {
        out << "Type: " << obj.getType() << " "<< obj.index << std::endl
            << "Strength: " << obj.getStrength() << std::endl
            << "Hp: " << obj.getHp() << std::endl << std::endl;
        return out;
    }
}