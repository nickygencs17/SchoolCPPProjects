#include<iostream>
#include"p2string.h"
#include"string.h"

using namespace stringclass;



int main()
{

	// Testing the constructors to make sure they function the way they're suppose too
	p2string p1 = p2string("Hello World");
    p2string hello = p2string("World");
	p2string p2 = p2string(p1);
    const char o = 'o';
    size_t number = 0;
    

	//p2string p3 = p2string('c');

	//Testing member functions

        p2.insert(p1, 3);
    
        std::cout<< "\n" <<p2.findChar(o);
    
        std::cout<<std::endl;
        std::cout<<p2<<std::endl;
        p2.char_swap(o, 5);
        std::cout<<p2<<std::endl;
        std::cout<<p2.find(hello)<<std::endl;
        std::cout<<p2;
    
    
        std::cout << "\n"<< p2 ;
        number = p2.numofChar(o);
        std::cout<<number;
    
    


	return 0;
}