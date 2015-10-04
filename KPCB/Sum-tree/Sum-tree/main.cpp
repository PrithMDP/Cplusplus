//
//  main.cpp
//  Sum-tree
//
//  Created by Lionel Messi on 6/22/15.
//  Copyright (c) 2015 Lionel Messi. All rights reserved.
//

#include <iostream>
using namespace std;
struct node
{
    int data;
    node * right=NULL;;
    node * left=NULL;
};
/*
            A
        B       C
    D               E
 
 
 */

int sum(node *head);

int main(int argc, const char * argv[])
{

    node a,b,c,d,e;
    a.right=&b;
    a.left=&c;
    b.left=&d;
    c.right=&e;
    
    a.data=1;
    b.data=2;
    c.data=3;
    d.data=4;
    e.data=5;
    
    node* head=&a;
    
    cout<<sum(head)<<endl;
    return 0;
}

int sum(node *head)
{
    if(head==NULL)
    {
        return 0;
    }
    else
        return (sum(head->left) +head->data+ sum(head->right));
    
}