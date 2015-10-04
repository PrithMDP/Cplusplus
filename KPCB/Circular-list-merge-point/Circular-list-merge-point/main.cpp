//
//  main.cpp
//  Circular-list-merge-point
//
//  Created by Lionel Messi on 6/15/15.
//  Copyright (c) 2015 Lionel Messi. All rights reserved.
//

#include <iostream>
using namespace std;
/*
 Finding where cycle in linked list starts
 Start one pointer at speed one, other at speed 2. they will meet k nodes from start of the cycle. then reset slow to head and increment both at speed 1 they will meet at start of cycle
 
 A->B->C->D->E->F->G->H->I
             ^           |
             |
             N<-M-<L<-K<-J
 */


struct node
{
    int data;
    node* next;
};

int main(int argc, const char * argv[])
{

    node a,b,c,d,e,f,g,h,i,j,k,l,m,n;
    a.next=&b;
    b.next=&c;
    c.next=&d;
    d.next=&e;
    e.next=&f;
    f.next=&g;
    g.next=&h;
    h.next=&i;
    i.next=&j;
    j.next=&k;
    k.next=&l;
    l.next=&m;
    m.next=&n;
    n.next=&e;
    
    a.data=1;b.data=2;c.data=3;d.data=4;e.data=5;f.data=6;g.data=7;h.data=8;g.data=9;h.data=10;i.data=11;j.data=12;k.data=13;
    l.data=14;
    m.data=15;n.data=16;
    
    node *head1=&a;
    node *head2=&a;
    while(1)
    {
        head1=head1->next;
        head2=head2->next->next;

        if(head1==head2)
        {
            break;
        }
    }
    //head1 and head2 are at the same place
    //now increment head1 and head2 after resetting, they will meet at start of cycle
    
    head1=&a; //resetting to head
    
    while (1)
    {
        if (head1==head2)
        {
            cout<<"found the start of cycle\n";
            cout<<head1->data<<endl;
            //cout<<head1<<endl;
            break;
        }
        else
        {
            head1=head1->next;
            head2=head2->next;
        }
    }
    
    return 0;
}

