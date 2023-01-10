#include "and.h"

AND::AND()
{
    name = "NONE";
    in1 = 0;
    in2 = 0;
}

AND::AND(string newName)
{
    name = newName;
    in1 = 0;
    in2 = 0;
}

void AND::setInp(gate* obj)
{
    if(size == 0)
    {
        in1 = obj;
        ++size;
    }else if(size == 1)
    {
        in2 = obj;
        ++size;
    }else
    {
        cout << "Error" << endl;    //  It means that something tried to add a third input
        exit(0);
    }
}

bool AND::evaluate() 
{
    if(lock)
    {
        lock = false;
        if(in1 != NULL && in2 != NULL)  //  Checking if pointers are actually pointing to something or not to prevent crashes
            setVal(in1->evaluate() && in2->evaluate()); //  Setting a new value for value. '&&' operator used for AND gate
    }
    
    return value;   //  Returning new value
}

void AND::resLock()
{
    in1->resLock();
    in2->resLock();
    lock = true;
}

