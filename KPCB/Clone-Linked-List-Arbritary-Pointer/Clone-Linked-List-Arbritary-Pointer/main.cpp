//
//  main.cpp
//  Clone-Linked-List-Arbritary-Pointer
//
//  Created by Lionel Messi on 6/21/15.
//  Copyright (c) 2015 Lionel Messi. All rights reserved.
//

#include <iostream>
using namespace std;

//struct for linked list node
struct node
{
    int data;
    node* next;
    node* random;
};
/*
 Clone a linked list with an arbritary pointer such that the arb pointer can point anywhere
 
 Sample list is
 
 
 A->B->C->D->NULL
 
 A rand = C
 B rand = A
 C rand = A
 D rand = B
 
 copy linked list and then connect 
 
 
 */

void listcopier(node *head);    //takes in head pointer and then copies the list

int main(int argc, const char * argv[])
{

    node a,b,c,d;
    a.data=1;b.data=2,c.data=3,d.data=4;
    a.next=&b;b.next=&c;c.next=&d;d.next=NULL;
    a.random=&c;b.random=&a;c.random=&a;d.random=&b;
    
    node * head=&a;
    
    while (head!=NULL) {
        node *a = new node;
        a->data=head->data;
        a->next=head->next;
        head->next=a;
        head=head->next->next;
    }
    
    head=&a;
    
    while (head!=NULL) {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
    
    node *h1=&a;
    
    while (h1!=NULL)    //setting the random pointers here
    {
        h1->next->random=h1->random->next;
        h1=h1->next->next;
    }
    
   
    
    
    
    //now to correctly break and link the linked list into 2 pieces
    
    head=&a;    //resetting
    node *head2=&a;
    head2=head2->next;
    
    node * head2nd=&a;
    head2nd=head2nd->next;
    
    while (head->next!=NULL && head2->next!=NULL)
    {
        head->next=head->next->next;
        head2->next=head2->next->next;
        head=head->next;
        head2=head2->next;
    }
//reset the last pointers to point to null
    
    
    return 0;
}

//take in head node and make copy
