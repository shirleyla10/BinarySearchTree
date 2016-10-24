/*
	main.cpp
	Written By: Lauren Shirley
	Date: 05/03/16
	Description:  This is the driver file to test	
	the BinarySearchTree data structure.
*/

#include "BST.h"
#include <cstdlib> //for use of rand()
#include <iostream>

using namespace std;

int main(){
	BinarySearchTree B; //initialize a null BST
	srand (time(NULL)); //to use rand()
	int numbers[15]; //create an array to hold random numbers to insert
	for(int i =0; i < 15;i++){
		//while i <size of numbers insert a new random number between 1 and 30
		int temp = (rand()%30)+1;
		numbers[i] = temp;
	}//end for
	for(int j=0; j<15; j++){
		//insert random numbers from array into tree
		B.Insert(numbers[j]);
	}//end for
	B.DisplayTree(); //display new tree
	int toRemove =  (rand()%14)+1; //randomly choose an index to remove from random array
	cout << "\nGoing to remove : " << numbers[toRemove]; //print out which number to remove
	B.Delete(numbers[toRemove]); //delete number corresponding to random index
	B.DisplayTree(); //display new tree
	toRemove = (rand()%14)+1; //randomly choose an index to remove from random array
	cout << "\nGoing to remove : " << numbers[toRemove]; //print out which number to remove
	B.Delete(numbers[toRemove]); //delete number corresponding to random index
	B.DisplayTree(); //display new tree
	cout << endl;
}//end main
