//
//  main.cpp
//  lab 2
//
//  Created by Nicholas Genco on 3/6/15.
//  Copyright (c) 2015 ___NickGencoDEV___. All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;

bool contradictory(bool);
bool logicalSum(bool,bool);
bool logicalProduct(bool,bool);
bool implies(bool, bool);

int main(int argc, const char * argv[])
{
    bool a,b,c;
    bool statement=true; ;
    
    cout<< " A | B | C | (𝑐 → 𝑏)∙(~𝑐 → 𝑎) " <<endl;
    cout<< "______________________________"<<endl;
    
    for (a = 1; ; a =!a)
    {
        for (b = 1; ; b=! b)
        {
                 for (c = 1; ; c=! c)
                 {
                cout <<" "<< a << setw(4) << b <<setw(4)<< c << "  |  "<< setw(6)<<(implies(c, b)&(implies(!c,a)))<<endl;
                     
                     if((implies(c, b)&(implies(!c,a)))==true)
                     {
                        if (a==true)
                            {
                               if (c == false && b== false)
                                   statement = true;
                            }
                 }
                 if (c == 0) break;
                 
          }
          if(b==0) break;
    }
        
    if ( a == 0)break;
    }
    
    if (statement==true)
    {
        cout<<endl<< "Statement is true."<<endl;
    }
    else
    {
        cout<<endl<<"Statement is false."<<endl;
    }
    
    statement=false;
    
    cout<<endl<<endl;
    cout<< " P | Q | R | ((𝑝 ∙ 𝑞)∨(𝑟 ⋅~(~𝑝 ⋅~𝑞)) " <<endl;
    cout<< "_____________________________________"<<endl;
    
    for (a = 1; ; a =!a)
    {
        for (b = 1; ; b=! b)
        {
            for (c = 1; ; c=! c)
            {
                cout <<" "<< a << setw(4) << b <<setw(4)<< c << "  |   "<< setw(6)<<((a&b)||(c&!(!a&!b)))<<endl;
                if(((a&b)||(c&!(!a&!b)))==true)
                {
                   if (a==true)
                   {
                       if (c == false && b== false)
                           statement = true;
                   }
                }
              if (c == 0) break;
                
            }
        if(b==0) break;
        }
        
    if ( a == 0)break;
    }
    
    if (statement==true)
    {
        cout<<endl<< "Statement is true."<<endl;
    }
    else
    {
        cout<<endl<<"Statement is false."<<endl;
    }
    
    cout<<endl<<endl;

    system("pause");
    return 0;
    
}
bool contradictory(bool b)
{
    return !b;
}
bool implies(bool p, bool q)
{
    bool result = true;
    if (p == true && q == false)
    {
        result = false;
        
    }
    return result;
}
bool logicalSum(bool p, bool q)
{
    if ( p == 0 && q ==0)
        return 0;
    else
        return 1;
    
}
bool logicalProduct(bool p ,bool q)
{
    return p&q;
}