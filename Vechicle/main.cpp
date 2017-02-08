//
//  main.cpp
//  project1DS
//
//  Created by Nicholas Genco on 9/10/14.
//  Copyright (c) 2014 ___NickGencoDEV___. All rights reserved.
//

#include <iostream>
#include <vector>
#include "vechicleV.h"
using namespace vechicle;



int main()
{
   
    int hm;
    std::string garbage;
    std::vector<vechicleV> vvector;
    std::string n;
    char su;
    int s;
    do
    {
        std::cout<<"\nHow many vechicles?: ";//prompt and reading how many players
        std::cin>>hm;
        
        
	}while(hm < 0);
    
	for (int i=0; i<hm; ++i)
    {
        getline(std::cin, garbage);
        
		std::cout<<"\nVechicle"<<i+1;
        
		std::cout<<"\nWhat Make is the vechicle?: ";
        
		getline(std::cin, n);
        
		std::cout<<"\nWhat is the speed?: ";
        
		std::cin>>s;
        
		getline(std::cin, garbage);
        
		std::cout<<"\nWhat are the units on the speed(m for miles/k for km): ";
        
		std::cin >> su;
        
		getline(std::cin, garbage);

		vvector.push_back(vechicleV(su, s, n));
        

    }

	for (int i = 0; i < hm; i++)
	{
		std::cout << "\n Vechile #" << i + 1 << std::endl;
		std::cout << vvector[i].getName() << std::endl;
		std::cout << vvector[i].getSpeed() << std::endl;
		std::cout << vvector[i].getUnits() << std::endl << std::endl;

	}

	std::cin.ignore().get();

	return 0;

}


