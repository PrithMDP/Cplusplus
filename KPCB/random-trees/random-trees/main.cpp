//
//  main.cpp
//  random-trees
//
//  Created by Lionel Messi on 6/23/15.
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
// COUNT NUMBER OF LEAF NODES
/*
          A
     B          C
 D      E           F
                  G
 
 leaf nodes are D,E,G
 
 */
int leafnodecounter(node *head);


int main(int argc, const char * argv[])
{
    
    node a,b,c,d,e,f,g;
    a.left=&b;
    a.right=&c;
    b.left=&d;
    b.right=&e;
    c.right=&f;
    f.left=&g;
    
    node *head=&a;
    
    cout<<leafnodecounter(head)<<endl;
    
    
    return 0;
}

int leafnodecounter(node *head)
{
    if (head==NULL) {
        return 0;
    }
    else if(head->left==NULL && head->right==NULL)   //leaf
    {
        return 1;
    }
    else
    {
        return (leafnodecounter(head->left)+leafnodecounter(head->right));
    }
    
}