#ifndef SPARSEVECTOR_H
#define SPARSEVECTOR_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class SparseVector  
{
public:
    
    SparseVector();
     
    SparseVector(vector <double> tempVec);

    SparseVector(string line,int linenum );
    
    SparseVector(string filename);
         
    double getData(int index) const;
    
    int getSize() const;
    
    void dataAdder(int size);
    
    friend SparseVector operator +(const SparseVector &c1,const SparseVector &c2);
    
    friend SparseVector operator -(const SparseVector &c1,const SparseVector &c2);
    
    friend ostream & operator << (ostream &out, const SparseVector &c1);
    
    SparseVector operator -();
    
    SparseVector& operator=(const  SparseVector& other);
    
    friend double dot(const SparseVector &c1,const SparseVector &c2);
    
    void lineReader(string line);
private:
    vector <double> datavec;
    
};

#endif
