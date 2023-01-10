#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include "gate.h"

using std::string;
using std::ostream;
using std::endl;

class output : public gate
{
    public:
    static int lock2;
    output();   //  Default Constructor
    output(string newName);     //  Constructor that sets the name of the object
    bool evaluate();    //  Takes input from other gate objects and holds the outputs
};

#endif
