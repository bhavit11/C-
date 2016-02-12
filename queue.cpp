//CMPT225 Assignment 4 - 301131169  bsharma   Bhavit Sharma
//Assignment 4
//*****Same as submitted for Assignment 2******//
//Instructor: David Mitchell
#include <cstring> // For declaration of NULL
#include "queue.h"
#include <string>
#include <iostream>

using namespace std;

Queue::Queue(){
    // the default constructor constructs a new empty queue
    front_p = NULL; // Front pointer points to NULL
    back_p = NULL; // Back pointer points to NULL
    current_size = 0;
}
void Queue::enqueue(int item){
    // enqueue item
    if(back_p == NULL){
        back_p = new node(item, back_p);//when element added is first element in queue
        front_p = back_p;
    }
    else{ //adding more elements to queue (not first)
        back_p->next = new node (item, NULL);
        back_p = back_p->next;
    }
    
    current_size++; // Increment size of queue after enqueuing
}
int Queue::front(){
    if(front_p !=0){ //Without dequeueing, returning value of front item
        return front_p->data;
    }
    else{
        return 0;
    }
}
bool Queue::empty(){ //Bool check if queue is empty
    return current_size == 0;
}
int Queue::size(){ // Return size of queue
    return current_size;
}
int Queue::dequeue(){
    if(front_p->next != 0){ //Remove node if a node exists (non-head node)
        node * old_front = front_p;
        int temp = old_front->data;
        front_p = old_front->next;
        delete old_front; // Delete old top node as it is no longer in use
        current_size--;
        return temp; // Return the value that was there at the top
    }
    else{ // If removing a node which is the head entry in the queue
        int temp = front_p -> data;
        node * old_front = front_p;
        front_p = NULL; // Re-initialize the front pointer to NULL
        back_p = NULL; // Re-initialize the back pointer to NULL
        delete old_front;
        current_size --;
        return temp;
    }
}
Queue::~Queue(){ //destructor
    node *ptr = front_p; //get front pointer
    while(ptr != NULL){ //keep removing front most node and iterating through queue, until empty
        front_p= front_p->next;
        delete ptr;
        ptr = front_p;
        current_size--;
    }
    front_p=NULL;
}
Queue::Queue( const Queue& q ){//copy constructor
    if(q.front_p==NULL){ //if copying empty queue
        front_p=NULL;
        back_p=NULL;
    }
    else{ //Otherwise copy queue node by node from front
        front_p= q.front_p;
        int num;
        node *temp;
        temp=q.front_p;

        while(temp!=NULL){
            num=temp->data;
            enqueue(num);
            temp=temp->next;
        }
        back_p=q.back_p;
    }
    
}

