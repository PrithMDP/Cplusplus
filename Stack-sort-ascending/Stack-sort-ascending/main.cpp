//
//  main.cpp
//  Stack-sort-ascending
//
//  Created by Lionel Messi on 6/16/15.
//  Copyright (c) 2015 Lionel Messi. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
/*
 Sort stack in ascending order
 */

int main(int argc, const char * argv[])
{
    stack<int> holder;
    stack<int> temp;
    
    while (!holder.empty())
    {
        int top=holder.top();
        
        if (!temp.empty() && top<temp.top())
        {
            while (!temp.empty() && top<temp.top())
            {
                int big=holder.top();
                holder.push(big);
                temp.pop();
            }
        }
        temp.push(top);
        
    }
    
    return 0;
}

