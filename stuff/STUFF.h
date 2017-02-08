//
//  L#c#Main.h
//  stuff
//
//  Created by Nicholas Genco on 9/8/14.
//  Copyright (c) 2014 ___NickGencoDEV___. All rights reserved.
//

#ifndef STUFF_H
#define STUFF_H

#include <iostream>
#include <vector>
#include <assert.h>

class Stuff
{
private:
    int sLength;
    int *sData;
    
public:
    Stuff();
    Stuff(int nLength);
    ~Stuff();
    void Erase();
    int& operator[](int nIndex);
    int GetLength();
    void Reallocate(int nNewLength);
    void Resize(int nNewLength);
    void InsertBefore(int nValue, int nIndex);
    void Remove(int nIndex);
    void InsertAtEnd(int nValue);
    void InsertAtBeginning(int nValue);
    
};
#endif