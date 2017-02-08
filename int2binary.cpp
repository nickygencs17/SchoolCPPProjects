#include<iostream>
#include <cstdlib>

using namespace std;

void binary(int num)//recursive funtion to change int to binary 
{
    int rem;
    
    if (num <= 1)
    {
        cout << num;
        return;
    }
    rem = num % 2;
    binary(num / 2);
    cout << rem;
}
void bogusInput(string programName, string binaryString)
{
    for (int i = binaryString.length()-1; i >= 0; i--)
    {
        if (binaryString.at(i) =='.')
        {
            cerr << programName
            << ": argument must be a a positive integer.\n";
            exit(EXIT_FAILURE);
        }
    }
}


int main(int argc, char *argv[])
{
    //int bin;
    if(argc != 2)
    {
        cerr<< "Invalid number of arguments"<<endl;
        cerr<< "Correct usage: "<< string(argv[0]) << "positive integer" <<endl;
        exit(EXIT_FAILURE);
        
    }
    bogusInput(string(argv[0]), string(argv[1]));
    
    int dec = atoi(argv[1]);// converts string to int easier 2 handle
    
    if (dec < 0)
    {
        cerr << dec << " is not a positive integer." << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << "The binary form of " << dec << " is ";
        binary(dec);
        cout << endl;
        return EXIT_SUCCESS;
    }
}