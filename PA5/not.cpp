#include "not.h"

NOT::NOT()
{
    name = "NONE";
    in1 = NULL;
}

NOT::NOT(string newName)
{
    name = newName;
    in1 = NULL;
}

bool NOT::evaluate() 
{
    if(lock)
    {
        if(in1 != NULL )    //  Avoiding crashes
        {
            if(!in1->evaluate())    //  True becomes false and false becomes true
                value = 1;
            else
                value = 0;
        }
    }

    
    return value;
}



