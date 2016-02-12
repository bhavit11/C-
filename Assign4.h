//
//  Assign4.h
//  
//
//  Created by Bhavit Sharma on 2015-04-15.
//
//

#include <iostream>
using namespace std;

class bstnode// node type for the linked list
{
public:
    bstnode(int value){
        key = value;
        parent = NULL;
        left = NULL;
        right = NULL;
    }
    int key;         //key stored at node
    bstnode* parent; //parent of the node
    bstnode* right;   //  right child
    bstnode* left;  //  left child
    
};

//*******-------------------*********//

class bst
{
public:
    
    //Constructors and Destructor
    bst();
    bst(int value);
    ~bst(); //Destructor
    
    //Modifiers
    void insert(int x);
    bool remove(int x);
    
    //Accessors
    bstnode* search(int x);
    int size(){return tsize;};
    int Root(){return root->key;};
    int rightmost();
    
private:
    
    
    
    
    bstnode* root;
    int tsize;
    
    
    //----FUNCTIONS----//
    void inserth(bstnode* v, int x); //
    bstnode* searchh(bstnode* v, int x); //
    bstnode* pred(bstnode* v);
    void destr(bstnode* p);
};
