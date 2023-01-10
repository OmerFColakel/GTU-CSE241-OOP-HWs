#ifndef GATE_H
#define GATE_H

#include <iostream>


using std::string;
using std::endl;
using std::cout;
using std::ostream;

class gate
{
    public:
    
    gate();
    
    //  Getter and setter for value
    bool getVal() const ;
    void setVal(bool newVal) ;

    //  Getter and setter for name
    string getName() const;
    void setName(string newName);

    //  Evaluate functions are implementing the value according to other gate objects or inputs from user
    virtual bool evaluate() ;

    //  Takes a pointer to a gate object and assigning it to inputs
    virtual void setInp(gate* obj) ;
    
    void print () const;
    
    virtual void resLock();	//	Resetting lock (setting it to "true"). Evaluate functions can call other evaluate functions
    
    virtual void setLock();	//	Sets the lock (setting it to "false"). Evaluate functions can't call other evaluate functions but returns last value.
    
    protected:
    bool lock = true;
    gate* in1;      //  Holds where the input will come from
    string name;    //  Holds the name of the object
    bool value;     //  Holds the output value of the object
};

#endif
