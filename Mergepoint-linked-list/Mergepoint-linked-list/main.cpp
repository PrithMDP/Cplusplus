//
//  main.cpp
//  Mergepoint-linked-list
//
//  Created by Lionel Messi on 6/13/15.
//  Copyright (c) 2015 Lionel Messi. All rights reserved.
//

#include <iostream>
using namespace std;

//linked list node
struct Node
{
    int data;   //data in linked list
    Node* next; //pointer to next node
};

// LINKED LIST
/*
 
 A->B->C->D->E->F->NULL
             ^
             |
       G->H->I
 
start of L1 is A of L2 is G
//ALGO
 
Calculate length of both, start at begining of small and begining of larger + length difference and compare all elements till end
*/
//function to calc length
int calclen(Node *head);

int main(int argc, const char * argv[])
{
    Node a,b,c,d,e,f,g,h,i;
    
    //L1
    a.next=&b;
    b.next=&c;
    c.next=&d;
    d.next=&e;
    e.next=&f;
    e.data=22;
    f.next=NULL;
    
    //L2
    g.next=&h;
    h.next=&i;
    i.next=&e;
    
    Node* head1=&a;
    Node* head2=&g;
    
    int len1=calclen(head1);
    int len2=calclen(head2);
    
    int diff=len1-len2;
    
    while (diff!=0) {
        if(diff>0)
        {
        head1=head1->next;
        }
        else
        {
            head2=head2->next;
        }
        diff--;
    }//head now points to correct position
    
    while (head1!=NULL&&head2!=NULL) {
        if (head1==head2) {
            cout<<"Found merge address is"<<head1<<" data is "<<head1->data<<endl;
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

int calclen(Node *head)
{
    int counter=0;
    while (head!=NULL) {
        counter++;
        head=head->next;
    }
    return counter;
    
}