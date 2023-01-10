#ifndef AND_H
#define AND_H

#include "gate.h"

class AND : public gate
{
    public:
    AND();  //  Default Constructor
    AND(string newName);    //  Constructor that sets the name of the object
    void setInp(gate* obj);    //  Sets the input pointers
    bool evaluate() ;   //  Takes inputs, evaluates the value with '&&' operator and returns it
    void resLock();
    private:
    gate* in2;  // Holds the address of second input
    int size = 0;   //  If it's 0 than next address will be equal to in1.
                    //  If it's 1 than next address will be equal to in2.
};
#endif
