//CMPT225 Assignment 4 - 301131169  bsharma   Bhavit Sharma
//  Assign4.cpp
//BST implementation
//
// Most of the ideas for BST implementation were directly taken from the Psuedo code given to students by Dr. David Mitchell in class. Also ideas on how to implement in C++ was taken from different Labs and Assignments from CMPT 225 class


#include "Assign4.h"

bst::bst(){
    root=NULL;
    tsize=0;
}
bst::bst(int value){ //bst with one node with key = value
    root = new bstnode(value);
    tsize=1;
}

bst::~bst(){//Destructor
   if(tsize>0) destr(root);
    
}

void bst::destr(bstnode* p){
    if(p!=NULL){
     
      destr(p->left);
   destr(p->right);
           delete p;
    }
}


//--------------------------********INSERT*********------------------------------------------------//
void bst::insert(int x){
    if(root==NULL){
        root= new bstnode(x);
        tsize++;
    }
    else{
        inserth(root, x);
        tsize++;
    }
}
void bst::inserth(bstnode* v, int x){
    if( x <= v->key){                       //if x<= the v key, then insert to left tree
        if(v->left !=NULL){// if left child exists
            inserth(v->left, x);
        }
        else{
            bstnode* newnode = new bstnode(x);
            v->left=newnode;
            newnode->parent=v;
        }
    }
    else{                                   //else insert into the right tree
        if(v->right!=NULL){// if right child exists
            inserth(v->right,x);
        }
        else{
            bstnode* newnode = new bstnode(x);
            v->right=newnode;
            newnode->parent=v;
        }
    }
}



//----------------------------********SEARCH********---------------------------------------------//
bstnode* bst::search(int x){
    
    return searchh(root, x);
}


bstnode* bst:: searchh(bstnode* v, int x){
    if(v->key ==  x)  return v;
    else if( x <= v->key){
        if( v->left!=NULL) return searchh(v->left, x);
        else return 0;
    }
    else{
        if(v->right != NULL) return searchh(v->right, x);
        else return 0;
    }
}

//**********REMOVE***********//
bool bst::remove(int x){
    
    bstnode* find = search(x);
    
    if(find == 0 || tsize== 0){
        return 0;
        
    };
    
    
    // *********------CASE 1--------- node containing x is a leaf-----------*********
    if(find->left==NULL && find->right==NULL){
        bstnode* findparent= find->parent;
        
        if(findparent!=NULL){//if find is not root
            
            if (x>findparent->key){
                findparent->right = NULL;
            }
            else{
                findparent->left=NULL;
            }
        }
        delete (find);
        tsize--;
        return 1;
        
        
    }
    
    
    // *******--------CASE 2:-------- node containing x has one child (replace find with subtree rooted at the child of x---********
    else if((find->left != NULL && find->right == NULL)||(find->right != NULL && find->left == NULL)){
        
        bstnode* findparent= find->parent;
        
        
        if(find->right!=nullptr){ //-----------------child is on the right-----------------------
            
            if(findparent!=NULL){                      //if find is not the root
                if(findparent->key < find->key){
                    findparent->right=find->right;
                    find->right->parent=findparent;
                }
                else{
                    findparent->left=find->right;
                    find->right->parent=findparent;
                }
            }
            
            else{                               //the remove node is a root, make right child the new root
                root=find->right;
                find->right->parent=NULL; //making the right node the new root
            }
        }
        else{                  //-----------------child is on the left-----------------------
            if(findparent!=NULL){                      //if find is not the root
                if(findparent->key < find->key){
                    findparent->right=find->left;
                    find->left->parent=findparent;
                }
                else{
                    findparent->left=find->left;
                    find->left->parent=findparent;
                }
            }
            
            else{                                       //the remove node is a root, make left child the new root
                root=find->left;
                find->left->parent=NULL; //making the right node the new root
            }
        }
        delete (find);
        tsize--;
        return 1;
        
    }
    
    
    // ********---------CASE 3----------node containing  has 2 children-------**********
    else{
        bstnode* predi= pred(find);
        
        if(predi->left == NULL && predi->right ==NULL){// CASE 3A- If predi is a leaf
            find->key=predi->key;
            if(predi->parent->key < predi->key) predi->parent->right = NULL;
            else predi->parent-> left = NULL;
            delete (predi);
            tsize--;
            return 1;
            
        }
        else{//CASE 3B
            find->key=predi->key;
            bstnode* findparent = predi->parent;
            if( findparent->key < predi->left->key){
                findparent->right = predi->left;
                predi->left->parent = findparent;
            }
            else{
                findparent->left = predi->left;
                predi->left->parent = findparent;
            }
            delete (predi);
            tsize--;
            return 1;
            
        }
    }
}

bstnode* bst::pred(bstnode* v){
    bstnode* u= v->left;
    while(u->right!=NULL){
        u=u->right;
    }
    return u;
}

int bst::rightmost(){
    bstnode* u=root;
    while(u->right!=NULL){
        u = u->right;
    }
    return u->key;
}







