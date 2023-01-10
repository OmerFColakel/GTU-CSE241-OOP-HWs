#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include "gate.h"


class input : public gate
{
    public:
    input();    //  Default Constructor
    input(string newName);  //  Constructor that sets the name of the object
};

#endif