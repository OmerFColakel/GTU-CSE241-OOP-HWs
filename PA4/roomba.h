#ifndef ROOMBA_H
#define ROOMBA_H
#include <iostream>
#include "robot.h"

namespace Robots
{
    class Roomba : public Robot
    {
        public:

            Roomba();

            Roomba(int newStrength,int newHp);

            //  Overridden getDamage function
            //  Since roomba is fast it attacks two times in one round
            int getDamage() const;

            friend ostream& operator << (ostream& out, const Roomba& obj);

        private:

            static int size;
            
            int index = -1;
    };
}

#endif