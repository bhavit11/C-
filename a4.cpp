/*Assignment 4 - 301131169  bsharma   Bhavit Sharma
 
 **  a4.cpp
 **  Assignment 4, CMPT-225, Spring 2015
 **
 **  Reads a sequence of integers (in the range of int's) from standard in;
 **  It is interpreted as two lists, separated by a single 0
 **/
#include <iostream>
#include "Assign4.cpp"
#include "queue.cpp"
using namespace std;

int main(){
    
    cout<<"301131169 bsharma BhavitSharma"<<endl;
    bst list1;
    Queue list2;
    int x ;
    bool change = false;
    
    while (cin >> x){
        
        if(x == 0) change = true;
        
  //---------------------------------for List1---------------------------
        else if (change != true){
            list1.insert(x);	//insert into first list untill you see a 0
        }
  //---------------------------------for List2---------------------------
        else if (x!=0 && change == true)
        {
            list2.enqueue(x);	//insert after 0 occurs
        }
    }
  //-------------------To find the Largest non similar element in List 1-------------------------
    
    
    while(!list2.empty()){                  // While emptying the list2 delete all the similar elements in list 1
        int data=list2.front();
        if(list1.size()>0){
            while(list1.remove(data)!=0);
        }
        list2.dequeue();
    }
    
    if(list1.size() > 0) cout<< list1.rightmost()<<endl;        //Find the largest key in list if there are any keys
    else cout<< "None"<<endl;
    
    return 0;
}
