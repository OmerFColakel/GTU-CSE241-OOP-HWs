#include "flipflop.h"

flipflop::flipflop()
{
    name = "NONE";
    in1 = NULL;
    value = 0;
}

flipflop::flipflop(string newName)
{
    name = newName;
    in1 = NULL;
    value = 0;
}

bool flipflop::evaluate()
{
    
    if(lock)    //  Lock used because if flipflop's output needed multiple times 
                //  it shouldn't work multiple times since it would change it's output
    {   
        lock = false;
        bool input = in1->evaluate();
        if(value == input)
            value = 0;
        else
            value = 1;
        
    }
    return value;
}




