
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
class SparseVector  
{
public:
    
    SparseVector(); // Creates an empty object
  
    SparseVector(vector <double> tempVec); // Takes a vector full of data, and makes an assigns it to datavec
     
    SparseVector(string line,int linenum); // Takes a string from some SparseMatrix objects
     
    SparseVector(string filename); // Takes a string as input from main function
     
    double getData(int index) const; // A getter that returns data from datavec according to index

    int getSize() const; // A function that returns vector's size 

    void dataAdder(int size); // Adds zeros to datavec to match the sizes in SparseMatrixx objects
    
    // ==============================================
    // Overloaded Operators 
    // ==============================================
    friend SparseVector operator +(const SparseVector &c1,const SparseVector &c2);
    
    friend SparseVector operator -(const SparseVector &c1,const SparseVector &c2);
    
    SparseVector operator -();
    
    SparseVector& operator=(const  SparseVector& other);
    
    friend ostream & operator << (ostream &out, const SparseVector &c1);

    // Dot Product
    friend double dot(const SparseVector &c1,const SparseVector &c2);
    
    // Reads input strings
    void lineReader(string line);
    
private:
    vector <double> datavec;
    
};

// ==============================================
// Default Constructor
// Creates empty object
// ==============================================
SparseVector::SparseVector()
{ 
}

// ==============================================
// Second Constructor
// Takes a vector full of data, and makes an assigns it to datavec.
// It was made to add a SparseVector object to the vector in SparseMatrix.
// ==============================================
SparseVector::SparseVector(vector <double> tempVec)
{ 
        for(int i=0;i<tempVec.size();++i)
            datavec.push_back(tempVec[i]);
} 

// ==============================================
// Third Constructor
// Takes a string as input from SparseMatrix objects
// that was constructed with a file name. It splits 
// the line to indexes and datas ,and adds these 
// elements to datavec. lineNum used to seperate this 
// constructor from fourth constructor.
// ==============================================
SparseVector::SparseVector(string line,int lineNum)
{ 
	lineReader(line); // Sends line to read
}

// ==============================================
// Fourth Constructor
// Takes a string as input from main function to 
// read input to indexes and datas. Also adds these
// elements to datavec.
// ==============================================
SparseVector::SparseVector(string filename)
{
    string line;
    char limiter=':';
    int index;
    double data;
    ifstream file (filename);
    if(file.is_open())
    {
    	getline(file,line); // Takes first line of file 
        lineReader(line); // Sends that line to lineReader
    }
    else
    {
        file.close();
        exit(0); // If it can't open a file program exits
    }
    file.close();
} 

// ==============================================
// A getter that returns data from datavec
// according to index. 
// ==============================================
double SparseVector::getData(int index) const
{
    return datavec[index];
}

int SparseVector::getSize() const
{
    return datavec.size();
}
// ==============================================
//	Reads strings from SparseVector and SparseMatrix.
//	Adds elements to datavec.
// ==============================================
void SparseVector::lineReader(string line)
{
    // Temporary variables to put into the datavec
    int index;
    double data;

    char limiter=':';
    string temp="";
    if(line.size()==0) exit(0); // If line is empty exits the program
    for(int i=0;i<=line.size();++i)
    {
        if(line[i]==':')	// Reading line until ':'
        {
        	for(int i=0;i<temp.size();++i) // Checks if the index value is valid or not
            	if(!isdigit(temp[i]))
            		exit(0);	// If it's not valid then exits
            limiter=' '; // Since we read until ':', now we should read until ' '
            index=stoi(temp);  // Turning the temp string to integer and assigning it to index
            temp="";	// Resetting temp string

        }
        else if(line[i]==' ' || i==line.size())	// Reading line until ':'
        {
        	bool flag=false;
        	for(int i=0;i<temp.size();++i) // Checks if the data value is valid or not
        	{
            	if(temp[i]=='.' && flag==false)
            		flag=true;
            	else if((!isdigit(temp[i]) && flag && temp[i]=='.') || 
            		((temp[i]<'0' || temp[i]>'9') && (temp[i]!='.' && temp[i]!='-')))
            		exit(0);	// If it's not valid then exits
            }
            limiter=':';	// Since we read until ' ', now we should read until ':'
            data=stod(temp);	// Turning the temp string to double and assigning it to data
            temp="";	// Resetting temp string
            for(int i=datavec.size();i<index;i++)
                    datavec.push_back(0); // Putting zero(s) to datavec until it reaches to index value
                    
                datavec.push_back(data);	// Putting data to datavec since we reached to index value
            }
        else 
        {
            temp+=line[i]; // Adding a character to temp string since loop couldn't reach to ' ' or ':'
        }
           
    }

}

// ==============================================
// Overloaded operators 
// ==============================================
//
// Adds two numbers with same indexes if the sizes
// of the vectors are same. If it's not same then
// exits the program.
//
// ==============================================
SparseVector operator +(const SparseVector &c1,const SparseVector &c2)
{
    SparseVector obj;
    if(c1.datavec.size()==c2.datavec.size())
    {
        for(int i=0;i<c1.datavec.size();++i)
            obj.datavec.push_back(c1.datavec[i]+c2.datavec[i]);
    }
    else
    {
        exit(0);
    }
    return obj;    
}

// ==============================================
//
// Substracts two numbers with same indexes if
// the sizes of the vectors are same. If it's not 
// same then exits the program.
//
// ==============================================
SparseVector operator -(const SparseVector &c1,const SparseVector &c2)
{
    SparseVector obj;
    if(c1.datavec.size()==c2.datavec.size())
    {
        for(int i=0;i<c1.datavec.size();++i)
        {
            obj.datavec.push_back(c1.datavec[i]-c2.datavec[i]);
        }
    }
    else
    {
        exit(0);
    }
    return obj;
}

// ==============================================
//
// Multiplying every element of a vector with -
// and returning it.
//
// ==============================================
SparseVector SparseVector::operator -()
{
    SparseVector obj;
    for(int i=0;i<datavec.size();++i)
    {
        if(datavec[i]!=0)
            obj.datavec.push_back(-datavec[i]);
        else
            obj.datavec.push_back(0);
    } 
    return obj;
}

// ==============================================
//
// Clears the object on the left side and adds 
// every element of the object on the right side
// to that object.
//
// ==============================================
SparseVector& SparseVector::operator=(const  SparseVector& other)
{
    if(this != &other)
    {
        datavec.clear();
        for(int i=0;i<other.getSize();++i)
            datavec.push_back(other.datavec[i]);
     }
    return *this;
}

// ==============================================
//
// Prints the objects
//
// ==============================================
ostream & operator << (ostream &out, const SparseVector &c1)
{
    for(int i=0;i<c1.datavec.size();++i)
    {   
        if(c1.datavec[i]!=0)    out << i << ":" << c1.datavec[i] << " ";
    }
    out << endl;
    return out;
}

// ==============================================
//
// Takes two vectors and calculates dot product
// of them if the sizes are same.
//
// ==============================================
double dot(const SparseVector &c1,const SparseVector &c2)
{
    double sum=0;
    if(c1.getSize()==c2.getSize())
    {
        int size= c1.getSize();
        for(int i=0;i<size;++i)
        {
            sum+= c1.datavec[i]*c2.datavec[i];
        }
    }else
    {
        exit(0);
    }
    return sum;
}

void SparseVector::dataAdder(int size)
{
    for(int i=getSize();i<size;++i)
        datavec.push_back(0);
}

