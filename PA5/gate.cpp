#include "gate.h"

gate::gate()
{
    name = "NONE";
    value = false;
    in1 = NULL;
}

string gate::getName() const
{
    return name;
}

bool gate::getVal()  const
{
    return value;
}

void gate::setVal(bool  newVal) 
{
    value = newVal;
}

void gate::setName( string newName)
{
    name = newName;
}

void gate::print () const
{
    cout <<  name << "  " << value << endl;
}

bool gate::evaluate() 
{
    return value;
}

void gate::setInp(gate* obj) 
{
    in1 = obj;
}

void gate::setLock()
{
    if(lock)
        lock = false;
}

void gate::resLock()
{
    if(!lock)
    {
        in1->resLock();
        lock = true;
    }
    
}


