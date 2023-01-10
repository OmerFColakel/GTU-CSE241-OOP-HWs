#include "decoder.h"

decoder::decoder()
{
    name = "DECODER";
    in1 = NULL;
    in2 = NULL;
}

bool decoder::evaluate() 
{
    if(lock)
    {
        lock = false;
        int selection = 2*in1->evaluate() + in2->evaluate();    //  Selecting which output will be 1 or 0
        for(int i=0 ;i<4;++i)
        {
            if(i == selection)
                outArr[i]->setVal(1);   //  Assigning 1 to one of the outputs
            else
                outArr[i]->setVal(0);   //  Assigning 0 to three of the outputs
        }
    }
    
    return 0;
}

void decoder::setInp(gate* obj)
{
    if(size < 4)        //  Taking the addresses of outputs
        outArr[size] = obj;
    else if(size == 4)
        in1 = obj;  //  Taking the address of the first input
    else
        in2 = obj;  //  Taking the address of the second input
    ++size;
}


void decoder::resLock()
{
    in1->resLock();
    in1->resLock();
    lock = true;
}

