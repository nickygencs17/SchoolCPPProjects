// FILE: string-304.cpp
// AUTHOR: Prof. Sciabbarrasi
//
// CLASS IMPLEMENTED: string (see mystring.h for documentation)
// INVARIANT for the string ADT:
//   1. The number of items in the string is in the member variable
//      current_length;
//   2. The actual items of the string are stored in a partially filled array.
//      The array is a dynamic array, pointed to by the member variable
//      sequence;
//   3. The size of the dynamic array is in the member variable allocated.


#include "string.h"


namespace stringclass
{

string::string(const char str[ ])
// Library facilities used: string.h
{
	current_length = strlen(str);
	allocated = current_length + 1;
	sequence = new char[allocated];
	std::copy(str, str + allocated, sequence);
}

string::string(const string& source)
// Library facilities used: string.h
{
	current_length = source.length();
	allocated = current_length + 1;
	sequence = new char[allocated];
	std::copy(&source[0], &source[0] + allocated, sequence);
}

string::string(const char c)
{
	current_length = 2;

	this->sequence = new char[current_length];

	this->sequence[0] = c;

	this->sequence[1] = '\0';
}

string::~string( )
{
	 delete [ ] sequence;
}

string& string::operator +=(const string& addend)
// Library facilities used: assert.h, stdlib.h
{
	 size_t other_string_size = addend.length() + 1;

	 if (current_length + other_string_size > allocated)
		  reserve(current_length + other_string_size);
   std::copy(&addend[0], &addend[0] + other_string_size, sequence + current_length);
   current_length = allocated - 1;
   return *this;
}

string& string::operator +=(const char addend[ ])
// Library facilities used: assert.h, stdlib.h
{
	 size_t other_string_size = strlen(addend);

	 if (current_length + other_string_size > allocated)
		  reserve(current_length + other_string_size);
   std::copy(addend, addend + other_string_size, sequence + current_length);
   current_length = allocated - 1;
   return *this;
}

string& string::operator +=(char addend)
{
	 if (current_length + 1 >= allocated)
		  reserve(current_length + 1);
	 sequence[current_length] = addend;
	 sequence[current_length+1] = NULL;
	 current_length++;
   return *this;
}

void string::reserve(size_t n)
// Library facilities used: stdlib.h
{
	 if (n == allocated)
		  return; // The allocated memory is already the right size

	 char *larger_array;

	 if (n <= current_length)
		  n = current_length; // Can't allocate less than we are using

	 larger_array = new char[n];
	 std::copy(sequence, sequence + allocated, larger_array);
	 delete [ ] sequence;
	 sequence = larger_array;
	 allocated = n;
}

string& string::operator =(const string& source)
// Library facilities used: stdlib.h
{
	if (&source != this)
	{
		size_t i;
		char *new_sequence;

		if (allocated != source.allocated)
		{
			new_sequence = new char[source.allocated];
			delete[] sequence;
			sequence = new_sequence;
			allocated = source.allocated;
		}
		current_length = source.current_length;
		for (i = 0; i < current_length; i++)
			sequence[i] = source.sequence[i];
	}
  return *this;
}

char& string::operator [ ](size_t position) const
{
	return sequence[position];
}

std::ostream& operator <<(std::ostream& outs, const string& source)
{
	outs << &source[0];
	return outs;
}

bool operator ==(const string& s1, const string& s2)
// Library facilities used: string.h
{
	return (strcmp(&s1[0], &s2[0]) == 0);
}

bool operator !=(const string& s1, const string& s2)
// Library facilities used: string.h
{
	return (strcmp(&s1[0], &s2[0]) != 0);
}

bool operator >=(const string& s1, const string& s2)
// Library facilities used: string.h
{
	return (strcmp(&s1[0], &s2[0]) >= 0);
}

bool operator <=(const string& s1, const string& s2)
// Library facilities used: string.h
{
	return (strcmp(&s1[0], &s2[0]) <= 0);
}

bool operator > (const string& s1, const string& s2)
// Library facilities used: string.h
{
	return (strcmp(&s1[0], &s2[0]) > 0);
}

bool operator < (const string& s1, const string& s2)
// Library facilities used: string.h
{
	return (strcmp(&s1[0], &s2[0]) < 0);
}

string& operator +(const string& s1, const string& s2)
{
	string answer(s1);

	answer += s2;

	return answer;
}

std::istream& operator >>(std::istream& ins, string& target)
// Library facilities used: ctype.h
{
    getline(ins, target, ' ');
	return ins;
}

std::istream& getline(std::istream& ins, string& target, char delimiter)
// Library facilities used: ctype.h
{
	char c;

//	while (ins && ins.peek() == ' ')
//		ins.ignore();

	target = ""; //Set the target to an empty string.

	while (ins && ins.peek() != delimiter)
	{
		ins >> c;
		target += c;
	}

   return ins;
}

}