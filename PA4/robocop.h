#ifndef ROBOCOP_H
#define ROBOCOP_H
#include <iostream>
#include "humanic.h"

namespace Robots
{
    class RoboCop : public Humanic
    {
        public:
            
            RoboCop();
            
            RoboCop(int newStrength,int newHp);
            
            friend ostream& operator << (ostream& out, const RoboCop& obj);
        
        private:
            
            static int size;
        
            int index = -1;
    };
}

#endif