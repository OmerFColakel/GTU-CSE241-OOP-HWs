#ifndef NOT_H
#define NOT_H

#include "gate.h"

class NOT : public gate
{
    public: 
    NOT();  //  Default Constructor
    NOT(string newName);    //  Constructor that sets the name of the object
    bool evaluate();     //  Evaluating and returning new value
};
#endif 
