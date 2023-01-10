#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
#include <string.h>
using std::string;
using std::ostream;

namespace Robots
{
    class Robot
    {
        
        public:
        //  Default Constructor
        //  Sets all the values to zero
        Robot();

        //  Constructor
        //  Sets the values of variables type,strength and hitpoints
        Robot(int newType, int newStrength,int newHp);
        
        //  Returns the type of object
        string getType() const;

        //  Returns the strength of object
        int getStrength() const;

        //  Sets the strength of object
        void setStrength(int newStrength) ;

        //  Returns the hitpoints of object
        int getHp() const;

        //  Sets the hitpoints of object
        void setHp(int newHp);

        //  Returns the damage that a robot inflict in one round
        //  Damage values are between 0 and strength+1.
        virtual int getDamage() const;

        //  Returns the properties of the object
        friend ostream& operator << (ostream& out, const Robot& obj);
        
        //  The member data types that we want to inherit
        protected:
        int type;   //  Holds the type 
        int strength;   //  Holds the strength
        int hp;     //  Holds the hitpoints
        //  The member data types that we don't want to inherit
        private : 
        //  Since we can declare multiple objects from one class,
        //  i wanted a way to separate them.
        static int size ;   //  Size keeps the number of objects created from this class
        int index;  //  keeps the index of the object
    };
}

#endif


