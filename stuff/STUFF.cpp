//
//  L#c#Main.cpp
//  stuff
//
//  Created by Nicholas Genco on 9/8/14.
//  Copyright (c) 2014 ___NickGencoDEV___. All rights reserved.
//

#include "STUFF.h"
#include <assert.h> // for assert()

Stuff::Stuff()
    {
        sLength = 0;
        sData = 0;
    }
    
   Stuff:: Stuff(int nLength)
    {
        sData = new int[nLength];
        sLength = nLength;
    }
    
    Stuff::~Stuff()
    {
        delete[] sData;
    }
    
    void Stuff:: Erase()
    {
        delete[] sData;
        // We need to make sure we set sData to 0 here or it will be left pointing at deallocated memory
        sData = 0;
        sLength = 0;
    }
    
    int& Stuff::operator[](int nIndex)
    {
        assert(nIndex >= 0 && nIndex < sLength);
        return sData[nIndex];
    }
    
    // Reallocate resizes the array
    void Stuff::Reallocate(int nNewLength)
    {
        // First we delete any existing elements
        Erase();
        
        // If our array is going to be empty now, return here
        if (nNewLength<= 0)
            return;
        
        // Then we have to allocate new elements
        sData = new int[nNewLength];
        sLength = nNewLength;
    }
    
    // Resize resizes the array
    void Stuff::Resize(int nNewLength)
    {
    
        if (nNewLength <= 0)
        {
            Erase();
            return;
        }
        
       
        
        // allocate a new array
        int *pnData = new int[nNewLength];
        

        if (sLength > 0)
        {
            int nElementsToCopy = (nNewLength > sLength) ? sLength : nNewLength;
            
            // Now copy the elements one by one
            for (int nIndex=0; nIndex < nElementsToCopy; nIndex++)
                pnData[nIndex] = sData[nIndex];
        }
        
        // Now we can delete the old array because we don't need it any more
        delete[] sData;
        
   
        sData = pnData;
        sLength = nNewLength;
    }
    
    void Stuff::InsertBefore(int nValue, int nIndex)
    {
        // Sanity check our nIndex value
        assert(nIndex >= 0 && nIndex <= sLength);
        
        // First create a new array one element larger than the old array
        int *pnData = new int[sLength+1];
        
        // Copy all of the elements up to the index
        for (int nBefore=0; nBefore < nIndex; nBefore++)
            pnData[nBefore] = sData[nBefore];
        
        // insert our new element into the new array
        pnData[nIndex] = nValue;
        
        // Copy all of the values after the inserted element
        for (int nAfter=nIndex; nAfter < sLength; nAfter++)
            pnData[nAfter+1] = sData[nAfter];
        
        // Finally, delete the old array, and use the new array instead
        delete[] sData;
        sData = pnData;
        sLength += 1;
    }
    
    void Stuff::Remove(int nIndex)
    {
        // Sanity check our nIndex value
        assert(nIndex >= 0 && nIndex < sLength);
        
        // First create a new array one element smaller than the old array
        int *pnData = new int[sLength-1];
        
        // Copy all of the elements up to the index
        for (int nBefore=0; nBefore < nIndex; nBefore++)
            pnData[nBefore] = sData[nBefore];
        
        // Copy all of the values after the inserted element
        for (int nAfter=nIndex+1; nAfter < sLength; nAfter++)
            pnData[nAfter-1] = sData[nAfter];
        
        // Finally, delete the old array, and use the new array instead
        delete[] sData;
        sData = pnData;
        sLength -= 1;
    }
    
    // A couple of additional functions just for convenience
    void Stuff::InsertAtBeginning(int nValue)
    {
        InsertBefore(nValue, 0);
    }
    void Stuff::InsertAtEnd(int nValue)
    {
        InsertBefore(nValue, sLength);
    }
    
    int Stuff::GetLength()
    {
        return sLength;
    }
