#ifndef OR_H
#define OR_H

#include <iostream>
#include "gate.h"

class OR : public gate
{
    public:
    OR();   //  Default Constructor
    OR(string newName); //  Constructor that sets the name of the object
    void setInp( gate* obj);     //  Sets the input pointers
    bool evaluate() ;   //  Evaluating and returning new value
    void resLock();
    private:
    gate* in2;  // Holds the address of second input
    int size = 0;   //  If it's 0 than next address will be equal to in1.
                    //  If it's 1 than next address will be equal to in2.
};
#endif
