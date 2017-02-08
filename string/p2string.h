// FILE: p2string.h
// AUTHOR: nickgenco
//
// CLASS PROVIDED: p2string (a sequence of characters)
//
// CONSTRUCTOR for the string class:
//     p2string();
//     Precondition: none
//     Postcondition: default sets string to NULL
//
//     p2string(const char * input)
//     Precondition: none
//     Postcondition: The string contains the sequence of chars from str.
//
//     p2string(const string& str)
//     Precondition: str is a p2string object.
//     Postcondition: The string contains the sequence of chars from str.
//
//     p2string(char c);
//     Precondition: c is a char object
//     Postcondition: Initializes the dynamic character array with the character 
//
// DESTRUCTOR for the p2string:
//      ~p2string();
//     Precondition: none
//     Postcondition: default sets string to NULL and deletes
//
// CONSTANT MEMBER FUNCTIONS for the p2tring class:
//      none
//
// MODIFICATION MEMBER FUNCTIONS for the p2tring class:
//  size_t numofChar(const char c)
//      Pre: needs to be passed a char
//      Post Finds the number of occurances a character is in a string
//
//  bool char_swap(const char c, size_t index);
//       Pre: needs a char and a index
//       Post: Replaces a single character in the string
//
//   size_t findChar(const char c);
//      Pre: Needs to be passed a char
//      Post: Finds the first occurance of a character and returns its position
//
//   bool insert(const p2string s, size_t index);
//      Pre: needs to be passed a index and a p2string object
//      Post: Inserts a string into a p2tring object at a specified position
//
//  bool insert(const char * s, size_t index);
//      Pre: needs to be passed an dynamic char array
//      Post: Inserts an array into a p2string object at a specified position
//
//  const size_t find(const char * word);
//      Pre:: needs be passed dyanamic char array
//      Pos:  Finds the first occurance a dynamic character array in the string
//
//  const size_t find(const p2string& word);
//      Pre:: needs to be passed p2string object
//      Post: Finds the first occurance of a substring in the p2string
//
// NON-MEMBER FUNCTIONS for the p2string class:
//      none
//
//  VALUE SEMANTICS for the p2string class:
//      Assignments and the copy constructor may be used with p2string objects.
//
//  TOTAL ORDER SEMANTICS (COMPARISONS) for the string class:
//      none
// 
// DYNAMIC MEMORY usage by the p2string class:
//      see string.h


#ifndef P2STRING_H
#define P2STRING_H

#include<cstdlib>
#include<iostream>
#include"string.h"

using namespace stringclass;


	class p2string : public string
	{
	
	public:
		p2string();//default sets string to NULL
		p2string(char c);//1. Initializes the dynamic character array with the character
		p2string(const char * input);//Takes in a dynamic charater array and resize the this->sequence
		p2string(const p2string& string);//Copy constructor
		~p2string();//Destructor deletes the string at the end
		size_t numofChar(const char c);//2. Finds the number of occurances a character shows up in a string
		bool char_swap(const char c, size_t index); //3. Replaces a single character in the string
		size_t findChar(const char c);//4. Finds the first occurance of a character and returns its position
		bool insert(const p2string s, size_t index);//5. Inserts a string into a astring object at a specified position
		bool insert(const char * s, size_t index);
		const size_t find(const char * word);//Finds the first occurance a dynamic character array in the string
		const size_t find(const p2string& word);//Finds the first occurance of a substring in the string

	};

#endif