# C-plus-plus
C++ programs with different data structures implementation

#Bhavit Sharma

#Report the largest different element from a list when compared to a different list


#=====================================================================
What the program does:


Store all the elements read before 0 appears into a BST(list1) and the ones after 0 into a dynamic queue (list 2) 

Compare by dequeuing elements from queue(list 2) and if it exists in the BST,remove all instances of the same element from the BST. Continue this until the queue is empty.

Once the Queue is empty, either the BST will also be empty
or there will be some elements left.

Report the largest element from the BST using rightmost function if there is one, otherwise report "None"

#======================================================================
