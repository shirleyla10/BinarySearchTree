/*
	BST.h
	Written By: Lauren Shirley
	Date: 05/03/16
	Description: This is the header file for the
	BinarySearchTree class.  This class utilizes the Node Struct
	to insert and delete items into a Binary Search Tree 
	to arrange data in infix order. 
*/

#include <iostream>
#include <stdlib.h> //for use of NULL

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <typename Item_Type>

//node struct which holds data of any type and has pointers to parent and children
struct Node{
    Item_Type data; //the current data item
    Node* parent; //pointer to the parent data item
    Node* left; //pointer to the left child 
    Node* right; //pointer to the right chlid
    Node(const Item_Type& data_item, Node* parent_item = NULL, Node* left_child = NULL, Node* right_child = NULL):
		data(data_item), parent(parent_item), left(left_child), right(right_child){}

};//end struct Node

class BinarySearchTree{

private:
    Node<int>* BST; //pointer to the beginning of the tree
    int size; //variable to keep track of the size of tree

public:
    BinarySearchTree(){BST=NULL; size=0;}//constructor to initialie tree as empty
    void traverse(Node<int>* &old, Node<int>* &old_next); //recursive function to traverse the Tree in order
    void Insert(int item);//function to call the recursive function to insert a new item
    void insert(Node<int>* &bst, int item); //recursive function to insert a new item
    void Delete(int item); //function to call the recursive function to delete an item
    void deleteitem(Node<int>* &bst, int item); //recursive function to delete an item 
    void DisplayTree(); //function to ccall the recursive function to display the tree
    void Display(Node<int>* bst); //recursive function to display the tree
    int getsize(){return size;} //getter function to return the size -> used to debug
    int getdata(){return BST->data;} //getter function to return the data of a node ->used to debug
};//end class BST

#endif
