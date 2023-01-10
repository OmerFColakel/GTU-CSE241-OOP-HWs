#include "SparseVector.h"

class SparseMatrix
{
public:
    SparseMatrix(); // Creates an empty object

    SparseMatrix(string filename);// Takes a string as input from main function
    
    int size() const    // returns the size of vec
    {
        return vec.size();
    }

    // ==============================================
    // Overloaded Operators
    // ==============================================
    friend SparseMatrix operator +(const SparseMatrix &c1,const SparseMatrix &c2);
    
    friend SparseMatrix operator -(const SparseMatrix &c1,const SparseMatrix &c2);
    
    SparseMatrix operator -();
    
    SparseMatrix& operator=(const  SparseMatrix& other);
    
    friend ostream & operator << (ostream &out, const SparseMatrix &c1);
    
    friend SparseMatrix operator *(const SparseMatrix &c1,const SparseMatrix &c2);

    // Returns transpose of a matrix
    SparseMatrix transpose();
    
private:
    vector <SparseVector> vec;
};

// ==============================================
// Default Constructor
// Creates empty object
// ==============================================
SparseMatrix::SparseMatrix()
{

}

// ==============================================
// Second Constructor
// Takes file's name to read. If it can't find it
// exits the program. Reads the lines as whole and
// sends them to third constructor in Sparsevector.
// Also checks if the sizes of every row is same
// or not. If they are not same then exits.
// ==============================================
SparseMatrix::SparseMatrix(string filename)
{
    string line;
    int lineNum=0; // Counting total lines
    bool flag= false;
    ifstream file (filename);
    if(file.is_open()) // Opening file
    {

        while(getline(file,line)) // Loop working until the of file
        {    
            SparseVector emptyObj;
            for(;lineNum<stoi(line)-1;++lineNum)
            {
                vec.push_back(emptyObj);
            }
            while(line[0]!=' ')
            {
                line.erase(0,1);
            }
            line.erase(0,1);
            SparseVector obj(line,lineNum); // Sending line to split it in SparseVector
            vec.push_back(obj); // Adding the object to the vec
            lineNum++;
        }
        int max=0;

        // Rows can't be empty in order to make this program works.
        // First loop finds maximum number of columns.
        // Second one adds elements  ccording to this maximum number.
        // Of course every row must have same number of elements,
        // last loop checks if every row have same number of elements.
        for(int i=0;i<lineNum;++i)
        {
            if(vec[i].getSize()!=0 && vec[i].getSize()>max)
                max=vec[i].getSize();
        }
        for(int i=0;i<lineNum;++i)
        {
            if(vec[i].getSize()<max)
            {
                vec[i].dataAdder(max);
            }

        }
        // Checking if every row have same amount of elements 
        int oldTemp=0,newTemp=0;
        for(int i=0;i<lineNum;++i)
        {
            if(i==0)
            {
                oldTemp=vec[i].getSize();
            }else 
            {
                newTemp=vec[i].getSize();
                if(oldTemp==newTemp)
                {
                    oldTemp==newTemp;
                }else
                    exit(0);
            }

        }  
    }
    else
    {
        file.close();
        exit(0);      
    }
    file.close();
}


// ==============================================
// Overloaded operators 
// ==============================================
//
// Adds two rows with same indexes if the sizes
// of the rows are same. If it's not same then
// exits the program.
//
// ==============================================
SparseMatrix operator +(const SparseMatrix &c1,const SparseMatrix &c2)
{
    SparseMatrix obj;
    if(c1.size()==c2.size())
    {
        for(int i=0;i<c1.size();++i)
        {
            obj.vec.push_back(c1.vec[i]+c2.vec[i]);
        }
    }else
        exit(0);
    return obj;  
}

// ==============================================
//
// Substracts two rows with same indexes if
// the sizes of the rows are same. If it's not 
// same then exits the program.
//
// ==============================================
SparseMatrix operator -(const SparseMatrix &c1,const SparseMatrix &c2)
{
        SparseMatrix obj;
        if(c1.size()==c2.size())
        {
            for(int i=0;i<c1.size();++i)
            {
                obj.vec.push_back(c1.vec[i]-c2.vec[i]);
            }
        }else
            exit(0);
        
        return obj;  
}

// ==============================================
//
// Multiplying rows' every element with -
// and returning it.
//
// ==============================================
SparseMatrix SparseMatrix::operator -()
{
    SparseMatrix obj;
    for(int i=0;i<vec.size();++i)
        obj.vec.push_back(-vec[i]);
    return obj;
}

// ==============================================
//
// Clears the object on the left side and adds 
// every element of the object on the right side
// to that object.
//
// ==============================================
SparseMatrix& SparseMatrix::operator=(const  SparseMatrix& other)
{
    if(this != &other)
    {
        vec.clear();
        for(int i=0;i<other.size();++i)
            vec.push_back(other.vec[i]);
    }
    return *this;
}

// ==============================================
//
// Prints the objects
//
// ==============================================
ostream & operator << (ostream &out, const SparseMatrix &c1)
{
    bool flag=false;
    for(int i=0;i<c1.vec.size();++i)
    {
        for(int j=0;j<c1.vec[i].getSize();++j)
        {
            if(c1.vec[i].getData(j)!=0)
            {
                flag=true;
                break;
            }
        }
        if(flag)    out << i+1 << " "<<c1.vec[i];
        flag=false;
    }    
    return out;
}

// ==============================================
//
// Takes two matrices and multiplies them
//
// ==============================================
SparseMatrix operator *(const SparseMatrix &c1,const SparseMatrix &c2)
{
    SparseMatrix obj;
    if(c2.size()+1==c1.vec[0].getSize())
    {
        for(int i=0;i<c1.size();++i)  //Row
        {
            vector <double> datavec;
            for(int j=0;j<c2.vec[0].getSize();++j) //Column
            {
                double temp=0;
                int l=0;
                for(int k=0;k<c2.vec[0].getSize()+1;++k)
                {
                    temp+=c1.vec[i].getData(k+1)*c2.vec[k].getData(j);
                    ++l;
                }
                datavec.push_back(temp);
            }  
            obj.vec.push_back(SparseVector(datavec));
        }
    }else
        exit(0);
    return obj;
}


// ==============================================
//
//  returns transpose of a matrix
//
// ==============================================
SparseMatrix SparseMatrix::transpose()
{

    SparseMatrix obj;
    for(int i=1;i<vec[0].getSize();++i) // 10
    {
        vector <double> datavec;
        for(int j=0;j<vec.size();++j) // 3
        {
            if(j==0)    datavec.push_back(0);
            datavec.push_back(vec[j].getData(i));
        }
        obj.vec.push_back(datavec);
    }
    return obj;
}