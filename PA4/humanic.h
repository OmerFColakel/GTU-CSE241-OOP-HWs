#ifndef HUMANIC_H
#define HUMANIC_H
#include <iostream>
#include "robot.h"

namespace Robots
{
    class Humanic : public Robot
    {
        public:
            
            Humanic();
            
            Humanic(int newStrength,int newHp);  
            
            //  Overridden getDamage function
            //   Humanic robots have 10% chance of inflicting 50 damage more
            int getDamage() const;
            
            friend ostream& operator << (ostream& out, const Humanic& obj);
        private:
        static int size;
        int index = -1;
    };
}

#endif