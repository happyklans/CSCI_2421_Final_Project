//To be used in conjunction with BSTree.h and Node.h
//When you modify this, please add your name and list any changes that you made
//A few member functions have been left blank so you, the student can implemement

/*Template Directions: #include "BSTREEInt.hpp"
but do NOT compile it (or add it to the project)*/
#include "BSTree.h"

// Constructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::BSTree() 
{
	items = 0;

	root = nullptr;
}

// Destructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::~BSTree() 
{
	if (root != nullptr)
		freeNode(root);
}

// Free the node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::freeNode(Node<DATATYPE, KEYTYPE> * leaf)
{
	if (leaf == nullptr)
	{
		return;
	}
	else if (leaf->Right() == nullptr && leaf->Left() == nullptr)
	{
		delete leaf;
		
		return;
	}
	
	freeNode(leaf->Right());
	
	freeNode(leaf->Left());
	
	delete leaf;

	return;
 
}

// Add a node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, DATATYPE &data)
{
	if (Root() == nullptr)
	{
		Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
		newNodePtr->setKey(key);
		newNodePtr->setData(data);
		root = newNodePtr;
		root->setParent(root);
		items++;

	}
	else
	{
		addNode(key, root, data);
		items++;
	}
}

// Add a node (private)
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data)
{
	if (leaf == nullptr)
	{
		Node<DATATYPE, KEYTYPE> * node_to_add = new Node<DATATYPE, KEYTYPE>;

		node_to_add->setData(data);

		node_to_add->setKey(key);

		node_to_add->setParent(nullptr);

		node_to_add->setLeft(nullptr);

		node_to_add->setRight(nullptr);

		leaf = node_to_add;

		return;
	}
	if (leaf->Key() >= key)
	{
		if (leaf->Left() == nullptr)
		{
			Node<DATATYPE, KEYTYPE> * node_to_add = new Node<DATATYPE, KEYTYPE>;

			node_to_add->setData(data);

			node_to_add->setKey(key);

			node_to_add->setParent(leaf);

			node_to_add->setLeft(nullptr);

			node_to_add->setRight(nullptr);

			leaf->setLeft(node_to_add);

			return;
		}
		else addNode(key, leaf->Left(), data);
	}
	if (leaf->Key() < key)
	{
		if (leaf->Right() == nullptr)
		{
			Node<DATATYPE, KEYTYPE> * node_to_add = new Node<DATATYPE, KEYTYPE>;

			node_to_add->setData(data);

			node_to_add->setKey(key);

			node_to_add->setParent(leaf);

			node_to_add->setLeft(nullptr);

			node_to_add->setRight(nullptr);

			leaf->setRight(node_to_add);

			return;
		}
		else addNode(key, leaf->Right(), data);
	}
}

template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key)
{
	return findNode(key, root);
}

// Find a node
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node)
{
	if (node == nullptr)
	{
		return node;
	}

	else if (node->Key() == key)
	{
		return node;
	}
	else if (node->Key() < key)
	{
		findNode(key, node->Right());
	}
	else if (node->Key() >= key)
	{
		findNode(key, node->Left());
	}
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder(ostream & out)
{
	printInorder(out, root);
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder(ostream & out,  Node<DATATYPE, KEYTYPE> * node)
{
	if (node == nullptr)
	{
		return;
	}
	if (node->Left() != nullptr)
	{
		printInorder(out, node->Left());
	}
	
	out << node->Data() << endl;
	
	if (node->Right() != nullptr)
	{
		printInorder(out, node->Right());
	}

	return;

}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printToFileInorder(ofstream & out)
{
	printToFileInorder(out, root);
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printToFileInorder(ofstream & out, Node<DATATYPE, KEYTYPE> * node)
{
	if (node == nullptr)
	{
		return;
	}
	if (node->Left() != nullptr)
	{
		printToFileInorder(out, node->Left());
	}

	out << node->Data();

	if (node->Right() != nullptr)
	{
		printToFileInorder(out, node->Right());
	}

	return;

}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::print(ostream & out, const DATATYPE & data)
{
	out << data << endl;
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::deleteNode(KEYTYPE key)
{
	setRoot(deleteNode(Root(), key));

	items--;
}

//deleteNode (Private)
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::deleteNode(Node<DATATYPE, KEYTYPE> * aRoot,KEYTYPE value)
{
   
	/* Given a binary search tree and a key, this function deletes the key
	and returns the new root */
	
	// base case
	if (aRoot == nullptr) return aRoot;

	// If the key to be deleted is smaller than the aRoot's key,
	// then it lies in left subtree
	if (value < aRoot->Key())
		aRoot->setLeft(deleteNode(aRoot->Left(), value));

	// If the key to be deleted is greater than the root's key,
	// then it lies in right subtree
	else if (value > aRoot->Key())
		aRoot->setRight(deleteNode(aRoot->Right(), value));

	// if key is same as root's key, then This is the node
	// to be deleted
	else
	{
		// node with only one child or no child
		if (aRoot->Left() == nullptr)
		{
			Node<DATATYPE, KEYTYPE> *temp = aRoot->Right();
			delete aRoot;	
			return temp;
		}
		else if (aRoot->Right() == nullptr)
		{
			Node<DATATYPE, KEYTYPE> *temp = aRoot->Left();
			delete aRoot;
			return temp;
		}

		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
		Node<DATATYPE, KEYTYPE> * temp = min(aRoot->Right());

		// Copy the inorder successor's content to this node
		aRoot->setKey(temp->Key());
		aRoot->setData(temp->Data());

		// Delete the inorder successor
		aRoot->setRight(deleteNode(aRoot->Right(), temp->Key()));
	}
	return aRoot;
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::reorder(KEYTYPE key)
{
	BSTree<DATATYPE, KEYTYPE> newTree;

	reorder(key, newTree, root);

	freeNode(root);

	root = newTree.Root();

	return;
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::reorder(KEYTYPE key, BSTree<DATATYPE, KEYTYPE> & newTree, 
	Node<DATATYPE, KEYTYPE> * node)
{
	DATATYPE data;

	if (node == nullptr)
	{
		return;
	}
	if (node->Left() != nullptr)
	{
		reorder(key, newTree, node->Left());
	}

	data = node->Data();

	newTree.addNode(key, data);

	if (node->Right() != nullptr)
	{
		reorder(key, newTree, node->Right());
	}

	return;
}


// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::min(Node<DATATYPE, KEYTYPE> * node)
{
	Node<DATATYPE, KEYTYPE> * current = node;

	/* loop down to find the leftmost leaf */
	while (current->Left() != nullptr)
		current = current->Left();

	return current;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::max(Node<DATATYPE, KEYTYPE> * node)
{
	Node<DATATYPE, KEYTYPE> * tempNode = node;
	if (node == nullptr)
		tempNode = nullptr;
	else if (node->Right())
		tempNode = max(node->Right());
	else
		tempNode = node;

	return tempNode;
}