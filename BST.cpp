/*
	BST.cpp
	Written By: Lauren Shirley
	Date: 05/03/16
	Description: This is the implementation file for the
	BinarySearchTree class.  This class utilizes the Node Struct
	to insert and delete items into a Binary Search Tree 
	to arrange data in infix order.  

*/

#include "BST.h"
#include <iostream>

using namespace std;

//recursive function to traverse the Tree in order
void BinarySearchTree::traverse(Node<int>* &bst, Node<int>* &bst_next ){
    //Recursive Step
	//if right child of next is not null
    if(bst_next->right != NULL){
		//traverse the right side then to find min value
    	traverse(bst, bst_next->right);
    }//end if
	//Base Case
	//otherwise bst = next 
	//and next = left child of next
    else{
	bst->data = bst_next->data;
	bst = bst_next;
	bst_next = bst_next->left;	
    }//end else
}//end traverse

//function to call the recursive function to insert a new item
void BinarySearchTree::Insert(int item){
    insert(BST, item); //call recursive function to insert
}//end Insert

//recursive function to insert a new item
void BinarySearchTree::insert(Node<int>* &bst, int item){
    //Base Case 1
	//If current node is null insert there
    if(bst == NULL){
	cout << "\nInserting: " << item;
	bst  = new Node<int>(item);	
	size++;	//increment size
    }//end if
    //Base Case 2
    else if(bst->data == item){
	return; //if duplicate return
    }//end  else if
    //Recursive steps
    else if(item > bst->data){
	insert(bst->right, item); //if item greater than current go right
    }//end else if
    else{
	insert(bst->left, item); //else go left
    }//end else
}//end insert

//function to call the recursive function to delete an item
void BinarySearchTree::Delete(int item){
    deleteitem(BST, item);//call recursive function to delete
}//end Delete

//function to call the recursive function to display the tree
void BinarySearchTree::deleteitem(Node<int>* &bst, int item){
    //Base Case 1
	//if null then element not in tree and return
    if(bst == NULL){
	cout << "\nElement not in tree!";
	return;
    }//end if
	//Base Case 2
	//Search for item
    else if(bst->data == item){ //if found assign to variable
	Node<int>* temp = bst;
	if(bst->left == NULL){
	   bst = bst->right; //rebuild tree
	} //end else if
	else if(bst->right == NULL){
	    bst = bst->left; //rebuild tree
	} //end else if
	else{
	    traverse(temp,temp->left); //call recursive function to find min
	}//end else
	size--;//decrement size
	delete temp; //delete item
	return; 
    }//end else if
	//Recursive steps
	//if item greater than current go right
    else if(item > bst->data){
   	deleteitem(bst->right, item);
    }//end else if
	//else go left
    else{
	deleteitem(bst->left, item);
    }//end else
}//end deleteitem

//function to call the recursive function to display the tree
void BinarySearchTree::DisplayTree(){
    cout << "\nBinary Tree Has Elements: ";    
	Display(BST); //call recursive display function
}//end DisplayTree

//recursive function to display the tree
void BinarySearchTree::Display(Node<int>* bst){
    //Base Case
	//If current null then return
    if(bst==NULL){
	return;
    }//end if
	//Recursive  Steps
	//else first go left then middle then right
    else{
	Display(bst->left);
	cout << bst->data << " ";
	Display(bst->right);
    }//end else
}//end Display
