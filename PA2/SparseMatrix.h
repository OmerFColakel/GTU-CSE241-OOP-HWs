#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include "SparseVector.h"
class SparseMatrix
{
public:
    SparseMatrix();
    
    SparseMatrix(string filename);
    
    int size() const;
    
    friend SparseMatrix operator +(const SparseMatrix &c1,const SparseMatrix &c2);
    
    friend SparseMatrix operator -(const SparseMatrix &c1,const SparseMatrix &c2);
    
    SparseMatrix operator -();
    
    SparseMatrix& operator=(const  SparseMatrix& other);
    
    friend ostream & operator << (ostream &out, const SparseMatrix &c1);
    
    friend SparseMatrix operator *(const SparseMatrix &c1,const SparseMatrix &c2);
    
    SparseMatrix transpose();
    
private:
    vector <SparseVector> vec;
};

#endif
