// FILE: string-304.h
// AUTHOR: Prof. Sciabbarrasi
//
// CLASS PROVIDED: string (a sequence of characters)
//
// CONSTRUCTOR for the string class:
//   string(const char str[ ] = "") -- default argument is the empty string.
//     Precondition: str is an ordinary null-terminated string.
//     Postcondition: The string contains the sequence of chars from str.
//
//   string(const string& str) 
//     Precondition: str is a string object.
//     Postcondition: The string contains the sequence of chars from str.
//
// CONSTANT MEMBER FUNCTIONS for the string class:
//   size_t length( ) const
//     Postcondition: The return value is the number of characters in the
//     String.
//
//   char& operator [ ](size_t position) const
//     Precondition: position < length( ).
//     Postcondition: The value returned is the character at the specified
//     position of the string. A string's positions start from 0 at the start
//     of the sequence and go up to length( )-1 at the right end.
//
// MODIFICATION MEMBER FUNCTIONS for the String class:
//   void operator +=(const string& addend)
//     Postcondition: addend has been catenated to the end of the String.
//
//   void operator +=(const char addend[ ])
//     Precondition: addend is an ordinary null-terminated string.
//     Postcondition: addend has been catenated to the end of the String.
//
//   void operator +=(char addend)
//     Postcondition: The single character addend has been catenated to the
//     end of the String.
//
//   void reserve(size_t n)
//     Postcondition: All functions will now work efficiently (without
//     allocating new memory) until n characters are in the String.
//
// NON-MEMBER FUNCTIONS for the string class:
//   string operator +(const String& s1, const String& s2)
//     Postcondition: The string returned is the catenation of s1 and s2.
//
//   istream& operator >>(istream& ins, string& target)
//     Postcondition: A string has been read from the istream ins, and the
//     istream ins is then returned by the function. The reading operation
//     skips white space (i.e., blanks, newlines, tabs) at the start of ins.
//     Then the string is read up to the next white space or the end of the
//     file. The white space character that terminates the String has not
//     been read.
//
//   ostream& operator <<(ostream& outs, const string& source)
//     Postcondition: The sequence of characters in source has been written
//     to outs. The return value is the ostream outs.
//
//   istream& getline(istream& ins, string& target, char delimiter = '\n')
//     Postcondition: A string has been read from the istream ins. The reading
//     operation reads all characters (including white space) until the
//     delimiter is read and discarded (but not added to the end of string).
//     The return value is the istream ins.
//
//  VALUE SEMANTICS for the string class:
//    Assignments and the copy constructor may be used with string objects.
//
//  TOTAL ORDER SEMANTICS (COMPARISONS) for the string class:
//    The six comparison operators (==, !=, >=, <=, >, and <) are implemented
//    for the string class, forming a total order semantics, using the usual
//    lexicographic order on Strings.
// 
// DYNAMIC MEMORY usage by the string class: 
//   If there is insufficient dynamic memory then the following functions call
//   new_handler: The constructors, resize, operator +=, operator +, and the
//   assignment operator.

#ifndef STRING_CLASS_H
#define STRING_CLASS_H

#include <algorithm> // Provides copy
#include <iostream>  // Provides ostream, istream, peek & ignore
#include <cstdlib>  // Provides size_t

namespace stringclass
{
    class string
    {
    public:
       
		// CONSTRUCTORS and DESTRUCTOR
        string(const char str[ ] = "");
        string(const string& source);
		string(const char c);
        ~string( );
       
		// MODIFICATION MEMBER FUNCTIONS
        string& operator +=(const string& addend);
        string& operator +=(const char addend[ ]);
        string& operator +=(char addend);
        void reserve(size_t n);
        string& operator =(const string& source);
       
		// CONSTANT MEMBER FUNCTIONS
        size_t length( ) const { return current_length; }
        char& operator [ ](size_t position) const;
        
		// FRIEND FUNCTIONS
        friend std::ostream& operator <<(std::ostream& outs, const string& source);
        friend bool operator ==(const string& s1, const string& s2);
        friend bool operator !=(const string& s1, const string& s2);
        friend bool operator >=(const string& s1, const string& s2);
        friend bool operator <=(const string& s1, const string& s2);
        friend bool operator > (const string& s1, const string& s2);
        friend bool operator < (const string& s1, const string& s2);
    
	protected:
        char *sequence;
        size_t allocated;
        size_t current_length;
    };

    // NON-MEMBER FUNCTIONS for the string class
    string& operator +(const string& s1, const string& s2);
    std::istream& operator >>(std::istream& ins, string& target);
    std::istream& getline(std::istream& ins, string& target, char delimiter='\n');
}
#endif
