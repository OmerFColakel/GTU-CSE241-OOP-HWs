#include "or.h"

OR::OR()
{
    name = "NONE";
    in1 = 0;
    in2 = 0;
}

OR::OR(string newName)
{
    name = newName;
    in1 = 0;
    in2 = 0;
}

void OR::setInp(gate* obj)
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
        cout << "Error" << endl;    //  It means that something tried to add a new input
        exit(0);
    }
}


bool OR::evaluate() 
{
    if(lock)
    {
        if(in1 != NULL && in2 != NULL)  //  Checking if pointers are actually pointing to something or not to prevent crashes
            setVal(in1->evaluate() || in2->evaluate());     //  Setting a new value for value
    }
    
    return value;   //  Returning new value
}

void OR::resLock()
{
    in1->resLock();
    in2->resLock();
    lock = true;
}

