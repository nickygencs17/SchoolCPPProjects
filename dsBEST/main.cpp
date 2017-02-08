#include<iostream>
#include"p2string.h"
#include"string.h"

using namespace stringclass;


int main()
{

	// Testing the constructors to make sure they function the way they're suppose too
	p2string p1 = p2string("Hello World");

	p2string p2 = p2string(p1);

	//p2string p3 = p2string('c');

	//Testing member functions

	if(p2.insert(p1, 3));
		std::cout << p2;


	system("pause");

	return 0;
}