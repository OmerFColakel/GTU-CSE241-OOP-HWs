#include "main.h"

void read(vector <gate*> &circuit,int& numOfOut)
{
    string line,word;
    ifstream text ("circuit.txt");
    int numOfInputs = 0;  
    while(getline(text,line,'\n'))  //  Reads lines of circuit.txt until it ends
    {
        int i=0;
        int lineSize = line.size();
        word = "";
        for(;line[i] != ' ';++i)    //  Takes the first word of the line
        {
            word += line[i];    
        }
        ++i;
        if(word == "INPUT") //  Adding inputs to circuit
        {
            word = "";
            for(;i<lineSize;++i)
            {  
                if(line[i] != ' ')  //  Takes other words from line
                    word += line[i];
                else
                { 
                    ++numOfInputs;  //  Counting the number of inputs
                    circuit.push_back(new input(word)); //  Adding input gates
                    word = "";
                }
            }
            ++numOfInputs;  //  Counting the number of inputs
            circuit.push_back(new input(word)); //  Adding the last input

        }else if(word == "OUTPUT")  //  Adding outputs to circuit
        {
            word = "";
            for(;i<lineSize;++i)
            {
                if(line[i] != ' ')  //  Takes other words from line
                    word += line[i];
                else
                { 
                    ++numOfOut; //  Counting the number of outputs
                    circuit.push_back(new output(word));    //  Adding output gates
                    word = "";
                }
            }
            circuit.push_back(new output(word));    //  Adding an output gate
            ++numOfOut; //  Counting the number of outputs
            
        }else if(word == "AND") //  Adding and gates to circuit
        {
            word = "";
            bool counter = false;
            for(;i<lineSize;++i)
            {  
                if(line[i] != ' ')  //  Takes other words from line
                    word += line[i];
                else
                { 
                    if(!counter)    //  Separating the name of and gate and it's inputs
                    {
                        circuit.push_back(new AND(word));   //  Adding an and gate to circuit
                        counter = true;
                    }
                    else 
                        for(int i=0;i<circuit.size();++i)   //  Finding the input and saving it's address to input gate
                            if(word == circuit[i]->getName())
                                    circuit[circuit.size()-1]->setInp(circuit[i]);
                                
                    word = "";
                }
            }
            for(int i=0;i<circuit.size();++i)   //  Finding other input and saving it's address to input gate
                if(word == circuit[i]->getName())
                        circuit[circuit.size()-1]->setInp(circuit[i]);
        }else if(word == "OR")  //  Adding or gates to circuit
        {
            word = "";
            bool counter = false;
            for(;i<lineSize;++i)
            {  
                if(line[i] != ' ')
                    word += line[i];
                else
                { 
                    if(!counter)
                    {
                        circuit.push_back(new OR(word));    //  Separating the name of or gate and it's inputs
                        counter = true;
                    }
                    else 
                        for(int i=0;i<circuit.size();++i)   //  Finding the input and saving it's address to or gate
                            if(word == circuit[i]->getName())
                                    circuit[circuit.size()-1]->setInp(circuit[i]);
                                
                    word = "";
                }
            }
            for(int i=0;i<circuit.size();++i)       //  Finding other input and saving it's address to or gate
                if(word == circuit[i]->getName())
                        circuit[circuit.size()-1]->setInp(circuit[i]);

        }else if(word == "NOT") //  Adding not gates to circuit
        {
            word = "";
            for(;i<lineSize;++i)
            {  
                if(line[i] != ' ')
                    word += line[i];
                else
                { 
                    circuit.push_back(new NOT(word));   //  Adding not gate to circuit
                    word = "";
                }
            }
            for(int i=0;i<circuit.size()-1;++i)   //  Finding the input and saving it's address to not gate
                if(circuit[i]->getName() == word)
                    circuit[circuit.size()-1]->setInp(circuit[i]);

        }else if(word == "FLIPFLOP")    //  Adding flipflops to circuit
        {
            word = "";
            for(;i<lineSize;++i){
                if(line[i]!= ' ')
                {
                    word += line[i];
                }else
                {
                    circuit.push_back(new flipflop(word));  //  Adding flipflop to circuit
                    word = "";
                }
            }
            for(int j=0;j<circuit.size()-1;++j) //  Finding the input and saving it's address to flipflop 
                if(word == circuit[j]->getName())     
                        circuit[circuit.size()-1]->setInp(circuit[j]);

        }else if(word == "DECODER") //  Adding decoder to circuit
        {
            word = "";
            circuit.push_back(new decoder); //  Adding decoder to circuit
            for(;i<lineSize;++i)
            {  
                if(line[i] != ' ')
                    word += line[i];
                else
                { 
                    for(int i=0;i<circuit.size();++i)   //  Decoder object gets the addresses of outputs and outputs get the address of decoder
                        if(word == circuit[i]->getName())
                        {
                            circuit[circuit.size()-1]->setInp(circuit[i]);
                            if(i>numOfInputs-1 && i<numOfInputs+4)
                                circuit[i]->setInp(circuit[circuit.size()-1]);
                        }          
                    word = "";
                }
            }
            for(int i=0;i<circuit.size();++i)   
            {
                if(word == circuit[i]->getName())
                    circuit[circuit.size()-1]->setInp(circuit[i]);
                
            }

            
        }else
            return ;
    }
    text.close();
}

void readInput(vector <gate*> &circuit,const int& numOfOut)
{
    int counter = 0;
    string line;
    ifstream input ("input.txt");
    while(getline(input,line)){ //  Reading input.txt line by line until it ends
        counter = 0;
        for(int i=0;i<line.size();++i)  // Assuming that first objects are inputs and 
                                        //  there are enough bits in txt file
        {   
            if(i%2==0)  
            {
                circuit[counter]->setVal(((int)line[i]-48));    //  Giving values to inputs 
                ++counter;
            }
        }
        for(int i=counter;i<numOfOut+counter;++i) //  Evaluating output objects
            circuit[i]->evaluate();
        
        for(int i=counter;i<numOfOut+counter;++i)  //  Printing the values of every object
                circuit[i]->print();
                
        cout << endl;


    }
    input.close();
}

int main()
{
    vector <gate*> circuit;     //  Keeps the addresses of gate objects
    int numOfOut=0;     //  Keeps the data of how many output gates there are
    read(circuit,numOfOut); //  Reading the circuit.txt
    readInput(circuit,numOfOut);    //  Reading input.txt
    
}