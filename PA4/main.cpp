#include <iostream>
#include <time.h>
#include "robot.h"
#include "bulldozer.h"
#include "roomba.h"
#include "humanic.h"
#include "optimusprime.h"
#include "robocop.h"

using namespace Robots;
using std::cout;
using std::endl;

//  Match function returns 0 if the robot1 wins,
//  and returns 1 if the robot2 wins.
//  A robot wins when the other has 0 or less hitpoint(s) left.
bool match(const Robot& robot1,const Robot& robot2);

int main()
{
    //  Randomizing random values from rand function according to time
    srand(time(NULL));
    
    //  Declaring objects for diffrent types of classes
    Robot ro1,ro2(2,10,100);
    Roomba room1(10,100),room2(10,100);
    Humanic hum1,hum2(10,100);
    OptimusPrime Prime1(100,100);
    Bulldozer bull;
    RoboCop cop(10,100);

    //  Testing overloaded insertion operator
    cout << ro1 << ro2 << room1 << room2 << hum1 << hum2 << Prime1 << bull << cop;

    //  Testing match function
    if(match(ro1,ro2))
    {
        cout << "Ro2 has won." << endl;
    }else
    {
        cout << "Ro1 has won." << endl;
    }
    if(match(room1,room2))
    {
        cout << "Room2 has won." << endl;
    }else
    {
        cout << "Room1 has won." << endl;
    }
    if(match(room1,Prime1))
    {
        cout << "Prime1 has won." << endl;
    }else
    {
        cout << "Room1 has won." << endl;
    }
    if(match(hum2,bull))
    {
        cout << "bulldozer has won." << endl;
    }else
    {
        cout << "hum2 has won." << endl;
    }
    if(match(cop,Prime1))
    {
        cout << "Prime1 has won." << endl;
    }else
    {
        cout << "cop has won." << endl;
    }

}

bool match(const Robot& robot1,const Robot& robot2)
{
    //  Taking the hp of both robots
    int firstHp = robot1.getHp();
    int secondHp = robot2.getHp();

    //  While loop works until one of them dies
    while(1)
    {
        //  It's kind of a turn based combat because first 
        //  robot has higher priority.
        if(secondHp <= 0)
        {
            return 0;
        }else if(firstHp <= 0)
        {
            return 1;
        }else
        {
            //  Decrementing hitpoints from both of them
            secondHp -= robot1.getDamage();
            firstHp -= robot2.getDamage();
        }
    }
    return 0;
}