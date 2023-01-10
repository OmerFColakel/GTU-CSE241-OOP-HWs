#include "output.h"
int output::lock2 = 0;
output::output()
{
    name = "NONE";
    in1 = NULL;
}
output::output(string newName)
{
    name = newName;
    in1 = NULL;
}

bool output::evaluate() 
{
    
    if(lock2==0)
    {
        in1->resLock();
        in1->evaluate();
    }else if(lock2==3)
    {
        lock2 = -1; //  decoder sets all output values therefore no need for multiple calls
    }
    ++lock2;
    return value;
}


