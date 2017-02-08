#include <iostream>
#include <cmath>

using namespace std;

int gcd(int, int);
int mod(int, int);
int gcf(int, int);


int main()
{
    int p,q,n,temp1, temp2;
   
    do
    {
        cout << "Enter the Numerator: ";
        cin >> p;
    } while (p <= 0);
    
    do
    {
        cout << "Enter the Denomentator: ";
        cin >> q;
    } while (q <= 0);
    
    cout << "The Egyptian Expansion of "<<p <<"/" <<q <<" is :"<<endl;
    
    if (p<q)
    {
        n = p / q;
        if(n!=0)
        {
            cout << n << " + ";
        }
        p = p % q;
    }
    while ( p != 1)
    {
        cout<< "1/" << ceil(1.0*q/p) << " + ";
        temp1 = mod(-q,p);
        temp2 = ceil(1.0*q/p)*q;
        n = gcf(temp1, temp2);
        p = temp1/n;
        q = temp2/n;
        
    }
    cout<<"1/" <<ceil(1.0*q/p)<<endl;
    
    
    system("pause");
    return 0;
}
int mod(int m, int n)
{
    return (m%n+n);
}
int gcf(int a,int b)
{
    if (a % b == 0)
        return b;
    else
        return gcf(b, a % b);
}


// Euclid's algorithm
int gcd(int m, int n)
{
    if (n == 0)
        return m;
    else return gcd(n, m % n);
}