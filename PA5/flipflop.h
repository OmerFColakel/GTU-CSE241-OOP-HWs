#ifndef FLIPFLOP_H
#define FLIPFLOP_H

#include "gate.h"

class flipflop : public gate
{
    
    public:
    flipflop(); //  Default Constructor
    flipflop(string newName);   //  Constructor that sets the name of the object
    bool evaluate() ;   //  Evaluating and returning new value
};
#endif