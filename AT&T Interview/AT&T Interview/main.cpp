//
//  main.cpp
//  AT&T Interview
//
//  Created by Lionel Messi on 6/30/15.
//  Copyright (c) 2015 Lionel Messi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void oddprinter();
int fib(int n);
void pingpong();
void palindromechecker( char arr[], int size);

int main(int argc, const char * argv[])
{
   
    
    char arr[]="racecar";
    
    palindromechecker(arr, 6);
    
    char arr2[]="abccba";
    palindromechecker(arr2, 5);

    char arr3[]="herty";
    palindromechecker(arr3, 4);
    
    cout<<sizeof(arr3)/sizeof(char);
    
    return 0;
}
//fn to print out all odd now from 1 to 99
//including 1 and 99
void oddprinter()
{
    int i=1;
    while (i<100)
    {
        cout<<i<<endl;
        i+=2;
    }
}
/*
 fibonacci sequence
 1,1,2,3,5 f(0)=f(1)=1;
 
 */

//fibonacci number
int fib(int n)
{
    if (n==0 || n==1) {
        return 1;
    }
    return (fib(n-1)+fib(n-2));
}

/*iterative fibonacci
//number was 1000
int fibiter(int n)
{
    
}
*/

//2 ARRAYS OF NUMBERS   -> return the intersection -> arrays not sorted
//extra memory
//find intersection
void intersection(vector<int>a,vector<int>b)
{
    for (unsigned i=0; i<a.size(); i++) {
        for (unsigned j=0; j<b.size(); j++) {
            if (a[i]==b[j])
            {
                cout<<a[i]<<endl;
            }
        }
    }
    
}
//one sorted one wasnt

//create a function with a for loop iterates 100 ping =3 pong at 5 ping pong at multiples of 3 and 5
//0 to 100 inclusive
void pingpong()
{
    for (int i=0; i<=100; i++)
    {
        if(i%3 ==0 && i%5 == 0) //i%15==0
        {
            cout<<"PingPong\n";
        }
        else if (i%3 == 0)
        {
            cout<<"Ping\n";
        }
        else if(i%5 == 0)
        {
            cout<<"Pong\n";
        }
        else
        {
            cout<<i<<endl;
        }
    }
}
//
//given a char arr check if palindrome;
void palindromechecker( char arr[], int size)
{
    char *start=arr;
    char *end=arr;
    //cout<<*start<<" "<<*end<<endl;
    //return;
    end+=size;
    while (start<end)
    {
        if (*start!=*end)
        {
            cout<<"not a palindorme\n";
            return;
        }
        start++;
        end--;
    }
    cout<<"it is a palindrome\n";
}


