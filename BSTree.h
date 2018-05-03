//To be used in conjunction with Node.h and BSTree<DATATYPE, KEYTYPE>.cpp
//If you modify this, please add your name and list any changes that you made
#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#include <fstream>
using namespace std;
#include "Node.h"

// Binary Search Tree class
template <typename DATATYPE, typename KEYTYPE>
class BSTree 
{
private:
	int items; //added by Benjamin Stanton 4/26/2

    Node<DATATYPE, KEYTYPE> * root;
   
	void addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data);
    
	Node<DATATYPE, KEYTYPE> * deleteNode(Node<DATATYPE, KEYTYPE> * node, KEYTYPE key);
    
	void freeNode(Node<DATATYPE, KEYTYPE> * leaf);
	
	void printInorder(ostream & out,  Node<DATATYPE, KEYTYPE> * node);
	
	void printToFileInorder(ofstream & out, Node<DATATYPE, KEYTYPE> * node);//added by Benjamin Stanton
	
	Node<DATATYPE, KEYTYPE> * findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node);
	
	void reorder(KEYTYPE key, BSTree<DATATYPE, KEYTYPE> & newTree, //added by Benjamin Stanton
		Node<DATATYPE, KEYTYPE> * node);

public:
    BSTree<DATATYPE, KEYTYPE>();
    
	~BSTree<DATATYPE, KEYTYPE>();
   
	Node<DATATYPE, KEYTYPE> * Root() { return root; }
   
	void setRoot(Node<DATATYPE, KEYTYPE> * _root) {root = _root;}
   
	void addNode(KEYTYPE key, DATATYPE &data);
	
	Node<DATATYPE, KEYTYPE> * findNode(KEYTYPE key);
	
	void printInorder(ostream & out);
	
	void printToFileInorder(ofstream & out);//added by Benjamin Stanton
	
	void print(ostream & out, const DATATYPE & data);
   
	void deleteNode(KEYTYPE key);

	void reorder(KEYTYPE key); //added by Benjamin Stanton
	
	Node<DATATYPE, KEYTYPE> * min(Node<DATATYPE, KEYTYPE> * node);
	
	Node<DATATYPE, KEYTYPE> * max(Node<DATATYPE, KEYTYPE> * node);
};
#endif  //BST
