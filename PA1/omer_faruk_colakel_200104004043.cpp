// This program works in two ways according to user's input.
//
// If user runs program with "-r" also with a valid number then
// program will create a valid number with that number of digits
// which each digit is unique. Then the user tries to find that
// number. Program checks every input of the user. And if it's 
// valid then program first checks if the input is same or not 
// with the number created. If it's same , the program prints how
// many rounds did it take to find it and if it's not same then
// says how many digits were in the exact place or misplaced.
//
// If user runs program with "-u" also with a valid number then 
// the user tries to find that number. Program checks every input
// of the user. And if it's valid then program first checks if 
// the input is same or not with the number given by user.
// If it's same , the program prints how many rounds did it take 
// and if it's not same then says how many digits were in the
//exact place or misplaced.


#include <iostream>
#include <ctime>


using namespace std;

// checker function
// input: input string , int N(to pass the size of that the input string should be)
// output: 1,0 or -1
// 1 is being used as boolean true, 0 as boolean false and -1 to exit the whole program
int checker(string input, int N);


// game function
// this function is basically instersection of -r and -u
// this function works after randNum and strToIntArr functions
// it takes answers from user, sends it to checker function
// if it's valid but wrong then gives hints to user,
// if it's valid and right then says "FOUND" and exits program
// it counts every iteration and exits after the 100th iteration
void game(int N,int num[]);

// randNum  function
// input: N(holds number of digits in the number)
// if user runs the program with -r(also with valid number size)
// this function will run and generate a random number
// and pass that number to game function
void randNum(int N);

// strToIntArr  function
// input: the number that was given by user when running the program with -u
// converts string to integer array
// after conversion integer array is being sent to game function
void strToIntArr(string input);

// main function
// takes first parameters from user checks them
// and if they're valid then calls necessary functions.
// If they're not valid then exits the program
int main(int argc,char** argv){

    // randomizing numbers according to time 
    srand(time(NULL));
    string input = argv[1];
    
    if(argc==3){

        // checking which type of game will be played
        if(input=="-r") {

            // checking if the input for first option to play the game(-r) is valid or not
            int N=0;
            input = argv[2];
            if(input.size()==1)    N = (int)input[0]-48;
            if(N>0 && N<10)
                randNum(N);
            else // exiting program if the input for number of digit is wrong
                cout << "E0" << endl;
        }else if(input == "-u"){
            input = argv[2];

            // checking if the input number is valid or not
            if(checker(input,input.size())){
                strToIntArr(input);
            }
               
            
        }
        // exiting if user runs the program with invalid input
        else
            cout << "E0\n";
        
    }
    // exiting if user runs the program with less or more input than needed
    else
    
        cout << "E0" << endl;
    
    
}

int checker(string input, int N){

    // checking if the size of input is whether right or wrong
    //  if it's wrong then whole program will stop with E1
    if(input.size()==N){

        // checking if the number is negative or first digit of it zero or not
        if(input[0]=='-'){
            cout << "E0" << endl;
            return 0;
        }else if(input[0]!='0'){
            for(int i=0;i<N;++i){

                // checking if there is any letters in the number
                if(input[i]<'0' || input[i]>'9'){
                    cout << "E2" << endl;
                    return 0;
                }else{
                    // checking if the number has unique digits or not
                    for(int k=i+1;k<N;++k){
                        if(input[i]==input[k])
                        {
                            cout << "E0" << endl;
                            return  0;
                        }
                            
                    }
                }
            }
        }else 
        {
            cout << "E0" << endl;
            return 0;
        }
    }else{

        // exiting the program if input has more or less digits than expected
        cout << "E1" << endl;
        return -1;
    }
    // if the function didn't return 0 or -1 till this point then input  is valid 
    // which means it should return 1
    return 1;
 }

void randNum(int N){

    // Creating integer array with N numbers
    int num[N];
    for(int i = 0;i<N;++i)
        num[i]=0;

    for(int i=0;i<N;){

        // creating a random number
        int randNum = rand() % 10;

        // checking if the first digit is zero or not. First digit can't be zero since it makes a number with N-1 digit(s)
        if(i==0 && randNum!=0){           
            num[0]=randNum;
            ++i;
        }else if(i!=0){

            // checking whether a digit is used 2 times or not 
            bool flag = false;
            for(int k=0;k<i;++k){
                
                if(randNum==num[k]){
                    flag = true;
                    break;
                }
            }
            if(flag==false){
                num[i] = randNum;
                ++i;
            }
        } 
    }

    // used these two lines while testing the program
    // it prints the number created
    /*for(int i =0 ;i < N ;++i)   cout << num[i];
    cout <<endl;*/

    game(N,num);
}

void game(int N,int num[]){
    int misplaced=0, exact=0;
    int iteration=1;
    bool flag = true;
    do{
        
        string input;
        cout << "Input:";
        cin >> input;

        // sending input to checker function
        int check = checker(input,N);
        if(check==1){
            
            for(int i=0;i<N;++i){
                
                for(int k=0;k<N;++k){
                    if(num[i]==((int)input[k]-48)){

                        // if two same digits are in the same spot then exact gets incremented
                        if(i==k)
                            exact++;

                        // if two same digits are in the number but in diffrent places then misplaced gets incremented
                        else if(i!=k)
                            misplaced++;
                    }
                }
            }

            // printing hints for user
            cout << exact << " " << misplaced << endl;
        if(exact==N){

            // if user finds the number then program says how many iterations did it take and exits the program
            cout << "FOUND " << iteration << endl;
            flag= false;
        }else if(iteration <101){

            // iteration increases every time user gives a valid but wrong answer
            iteration++;
        }else{

            // if user can't find the number in 100 iteration then program will say that (s)he is failed and exits program
            cout << "FAILED" << endl;
            flag=false;
        }

        // resetting misplaced and exact after every try
        misplaced=0,exact=0;

        }else if(check == 0)
        {
            // iteration increases every time user gives an invalid answer
            ++iteration;
        }else if(check != 0){
            
            // exiting program when check funtion returns -1
            return;
        }   
    }while (flag);
}

void strToIntArr(string input){
    int N = input.size();
    int num[N];
    for(int i=0;i<N;++i)
        num[i]=(int)input[i]-48;
    game(N,num);
}