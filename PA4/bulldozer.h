#ifndef BULLDOZER_H
#define BULLDOZER_H
#include <iostream>
#include "robot.h"

namespace Robots
{
    class Bulldozer : public Robot
    {
        public:
        
            Bulldozer();

            Bulldozer(int newStrength,int newHp);

            friend ostream& operator<< (ostream& out, const Bulldozer& obj);

        private:
            static int size;
            int index = -1;
    };
}

#endif