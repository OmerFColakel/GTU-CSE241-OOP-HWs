#ifndef DECODER_H
#define DECODER_H

#include "gate.h"

class decoder : public gate
{
    public:
    decoder();  //  Default Constructor
    bool evaluate() ;   //  Evaluating and returning new value
    void setInp( gate* obj);    //  Sets the input and output pointers
    void resLock();
    private:
    gate* in2;  // Holding Second Input's Address
    gate** outArr = new gate*[4];   //  Holding the addresses of 4 outputs
    int size = 0;   
};
#endif
