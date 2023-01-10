#include <iostream>
#include <string.h>

#include "robot.h"

using std::string;

namespace Robots
{
    //  Size is zero at the start
    int Robot::size = 0;

    Robot::Robot()
    {
        // Implementing index value and incrementing the size
        index = size++;
        type  = 4;
        hp = 0;
        strength = 0;
    }

    Robot::Robot(int newType, int newStrength,int newHp)
    {
        //  Setting the values of the object
        index = size++;
        type = newType;
        strength = newStrength;     
        hp = newHp;
    }

    string Robot::getType() const
    {
        switch(type)
        {
            default:    return "unknown";
            case 0:     return "optimusprime";
            case 1:     return "robocop";
            case 2:     return "roomba";
            case 3:     return "bulldozer";
        }
    }

    int Robot::getStrength() const
    {
        return strength;
    }

    void Robot::setStrength(int newStrength) 
    {
        strength = newStrength;
    }

    int Robot::getHp() const 
    {
        return hp;
    }

    void Robot::setHp(int newHp)
    {
        hp = newHp;
    }

    int Robot::getDamage() const
    {
        if(strength > 0)
            return rand() % strength + 1;
        return 0;
    }

    ostream& operator<< (ostream& out, const Robot& obj)
    {
        out << "Type: " << obj.getType() << " " << obj.index << std::endl
            << "Strength: " << obj.getStrength() << std::endl
            << "Hp: " << obj.getHp() << std::endl << std::endl;
        return out;
    }
    
} 
