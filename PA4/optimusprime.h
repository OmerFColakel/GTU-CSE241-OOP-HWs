#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H
#include <iostream>
#include "humanic.h"

namespace Robots
{
    class OptimusPrime : public Humanic
    {
        public:
            
            OptimusPrime();
            
            OptimusPrime(int newStrength,int newHp);
            
            //  Overriden getDamage function
            //  Optimus Prime has 15% chance of inflicting 
            int getDamage() const;
            friend ostream& operator << (ostream& out, const OptimusPrime& obj);
        private:
            static int size;
            int index = -1;

    };
}

#endif