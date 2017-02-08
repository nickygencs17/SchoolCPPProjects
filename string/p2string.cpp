//
// CLASS IMPLEMENTED: string (see p2sting.h for documentation)
// INVARIANT for the p2string ADT:
//   1. The number of items in the string is in the member variable
//      current_length;
//   2. The actual items of the string are stored in a partially filled array.
//      The array is a dynamic array, pointed to by the member variable
//      sequence;
//   3. The size of the dynamic array is in the member variable allocated.


#include"p2string.h"
#include<cassert>

using namespace stringclass;

p2string::p2string()//default sets string to NULL

{
    current_length = 1;
    
    sequence = new char[current_length];
    
    sequence[0] = '\0';
}


p2string::p2string(const char c)//1. Initializes the dynamic character array with the character
: string(c)
{
    current_length = 2;
    
    sequence = new char[current_length];
    
    sequence[0] = c;
    
    sequence[1] = '\0';
}

p2string::p2string(const p2string& input)//Takes in a dynamic charater array and resize the sequence
: string(input)
{
    current_length = input.current_length;
    
    sequence = new char[current_length];
    
    //strcpy_s(sequence, current_length, input.sequence);
    
    for (size_t i = 0; i < current_length; i++)
        sequence[i] = input[i];
    
}

p2string::p2string(const char * input)//Copy constructor
: string(input)
{
    
    current_length = strlen(input) + 1;
    
    sequence = new char[current_length];
    
    for (size_t i = 0; i < current_length; i++)
        sequence[i] = input[i];
    
}

p2string::~p2string()////Destructor deletes the string at the end
{
    
    if (sequence != NULL)
    {
        
        delete[] sequence;
        
        sequence = NULL;
    }
    
}

bool p2string::char_swap(const char c, const size_t index)//3. Replaces a single character in the string
{
    
    if (index >= current_length - 1)
        return false;
    
    sequence[index] = c;
    
    return true;
}

// Overloaded the find so it can take a dynamic array as well as a p2string object

const size_t p2string::find(const char * word)//2. Finds the number of occurances a character shows up in a string
{
    if (strlen(word) > current_length)
        return -1; // if the substring is greater then or equal to the this object then return -1
    
    int i = 0, j = 0;
    
    for (i = 0; i < current_length; i++)
    {
        
        for (j = 0; j < strlen(word); j++)
            if (((i + j) >= current_length) || (sequence[i + j] != word[j])) // if they don't match, break
                break;
        
        if (j == strlen(word)) // We went through the entire substring, didn't hit break
            return i; // return index
        
    }
    
    return -1; // if we never return anything means, we didn't find it, so return -1
}

const size_t p2string::find(const p2string& word)//2. Finds the number of occurances a character shows up in a string
{
    if (word.current_length > current_length)
        return -1;
    
    size_t i = 0, j = 0;
    
    for (i = 0; i < current_length; i++)
    {
        
        for (j = 0; j < word.current_length; j++)
            if (((i + j) >= current_length) || (sequence[i + j] != word.sequence[j]))
                break;
        
        if (j == word.current_length)
            return i;
        
    }
    
    return -1;
}

size_t p2string::numofChar(const char c)//2. Finds the number of occurances a character shows up in a string
{
    
    size_t i = 0;
    size_t j = 0;
    
    while (sequence[i] != '\0')
    {
        if (c == sequence[i])
        {
        
         ++j;
        }
        ++i;
    }
    
    return j;
    
}

size_t p2string::findChar(const char c)//4. Finds the first occurance of a character and returns its position
{
    
    size_t i = 0;
    
    while (c != sequence[i])
        ++i;
    
    return i;
    
}

bool p2string::insert(const p2string s, size_t index)// Inserts an array into a p2string object at a specified position
{
    
    if (s.current_length != 1)
        if (index < current_length)
        {
            
            size_t size = ((s.current_length - 1) + (current_length - 1)) + 1;
            
            char * temp = new char[size];
            
            if (index == 0)
            {
                
                for (size_t i = 0; i < (s.current_length - 1); i++)
                    temp[i] = s.sequence[i];
                
                size_t j = 0;
                
                for (size_t k = s.current_length - 1, j = 0; k < (size - 1); k++, j++)
                    temp[k] = sequence[j];
                
                
                if (temp[size - 1] != '\0')
                    temp[size - 1] = '\0';
                
                current_length = size;
                
                delete[] sequence;
                
                sequence = temp;
                
                return true;
                
            }
            
            else
            {
                --index;
                
                size_t j = 0;
                
                for (size_t i = 0; i < index; ++i)
                    temp[i] = sequence[i];
                
                for (size_t k = index, j = 0; k < (size - 1); k++, j++)
                    temp[k] = s.sequence[j];
                
                for (size_t l = ((size)-(s.current_length - index)), j = index; l < size; ++l, ++j)
                    temp[l] = s.sequence[j];
                
                temp[size - 1] = '\0';
                
                current_length = size;
                
                delete[] sequence;
                
                sequence = temp;
                
                return true;
                
            }
        }
    
    return false;
    
}

bool p2string::insert(const char * s, size_t index)// Inserts an array into a p2string object at a specified position
{
    
    if (strlen(s) != 1)
        if (index < current_length)
        {
            
            size_t size = ((strlen(s) - 1) + (current_length - 1)) + 1;
            
            char * temp = new char[size];
            
            if (index == 0)
            {
                
                for (size_t i = 0; i < (strlen(s) - 1); i++)
                    temp[i] = s[i];
                
                size_t j = 0;
                
                for (size_t k = strlen(s) - 1, j = 0; k < (size - 1); k++, j++)
                    temp[k] = sequence[j];
                
                
                if (temp[size - 1] != '\0')
                    temp[size - 1] = '\0';
                
                current_length = size;
                
                delete[] sequence;
                
                sequence = temp;
                
                return true;
                
            }
            
            else
            {
                --index;
                
                size_t j = 0;
                
                for (size_t i = 0; i < index; ++i)
                    temp[i] = sequence[i];
                
                for (size_t k = index, j = 0; k < (size - 1); k++, j++)
                    temp[k] = s[j];
                
                for (size_t l = ((size)-((strlen(s)+1) - index)), j = index; l < size; ++l, ++j)
                    temp[l] = s[j];
                
                temp[size - 1] = '\0';
                
                current_length = size;
                
                delete[] sequence;
                
                sequence = temp;
                
                return true;
                
            }
        }
    
    return false;
    
}