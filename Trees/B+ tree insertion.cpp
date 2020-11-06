// C++ program for implementing B+ Tree 
#include <climits> 
#include <fstream> 
#include <iostream> 
#include <sstream> 
using namespace std; 
int MAX = 3; 

// BP node 
class Node { 
	bool IS_LEAF; 
	int *key, size; 
	Node** ptr; 
	friend class BPTree; 

public: 
	Node(); 
}; 

// BP tree 
class BPTree { 
	Node* root; 
	void insertInternal(int, 
						Node*, 
						Node*); 
	Node* findParent(Node*, Node*); 

public: 
	BPTree(); 
	void search(int); 
	void insert(int); 
	void display(Node*); 
	Node* getRoot(); 
}; 

// Constructor of Node 
Node::Node() 
{ 
	key = new int[MAX]; 
	ptr = new Node*[MAX + 1]; 
} 

// Initialise the BPTree Node 
BPTree::BPTree() 
{ 
	root = NULL; 
} 

// Function to find any element 
// in B+ Tree 
void BPTree::search(int x) 
{ 

	// If tree is empty 
	if (root == NULL) { 
		cout << "Tree is empty\n"; 
	} 

	// Traverse to find the value 
	else { 

		Node* cursor = root; 

		// Till we reach leaf node 
		while (cursor->IS_LEAF == false) { 

			for (int i = 0; 
				i < cursor->size; i++) { 

				// If the element to be 
				// found is not present 
				if (x < cursor->key[i]) { 
					cursor = cursor->ptr[i]; 
					break; 
				} 

				// If reaches end of the 
				// cursor node 
				if (i == cursor->size - 1) { 
					cursor = cursor->ptr[i + 1]; 
					break; 
				} 
			} 
		} 

		// Traverse the cursor and find 
		// the node with value x 
		for (int i = 0; 
			i < cursor->size; i++) { 

			// If found then return 
			if (cursor->key[i] == x) { 
				cout << "Found\n"; 
				return; 
			} 
		} 

		// Else element is not present 
		cout << "Not found\n"; 
	} 
} 

// Function to implement the Insert 
// Operation in B+ Tree 
void BPTree::insert(int x) 
{ 

	// If root is null then return 
	// newly created node 
	if (root == NULL) { 
		root = new Node; 
		root->key[0] = x; 
		root->IS_LEAF = true; 
		root->size = 1; 
	} 

	// Traverse the B+ Tree 
	else { 
		Node* cursor = root; 
		Node* parent; 

		// Till cursor reaches the 
		// leaf node 
		while (cursor->IS_LEAF 
			== false) { 

			parent = cursor; 

			for (int i = 0; 
				i < cursor->size; 
				i++) { 

				// If found the position 
				// where we have to insert 
				// node 
				if (x < cursor->key[i]) { 
					cursor 
						= cursor->ptr[i]; 
					break; 
				} 

				// If reaches the end 
				if (i == cursor->size - 1) { 
					cursor 
						= cursor->ptr[i + 1]; 
					break; 
				} 
			} 
		} 

		if (cursor->size < MAX) { 
			int i = 0; 
			while (x > cursor->key[i] 
				&& i < cursor->size) { 
				i++; 
			} 

			for (int j = cursor->size; 
				j > i; j--) { 
				cursor->key[j] 
					= cursor->key[j - 1]; 
			} 

			cursor->key[i] = x; 
			cursor->size++; 

			cursor->ptr[cursor->size] 
				= cursor->ptr[cursor->size - 1]; 
			cursor->ptr[cursor->size - 1] = NULL; 
		} 

		else { 

			// Create a newLeaf node 
			Node* newLeaf = new Node; 

			int virtualNode[MAX + 1]; 

			// Update cursor to virtual 
			// node created 
			for (int i = 0; i < MAX; i++) { 
				virtualNode[i] 
					= cursor->key[i]; 
			} 
			int i = 0, j; 

			// Traverse to find where the new 
			// node is to be inserted 
			while (x > virtualNode[i] 
				&& i < MAX) { 
				i++; 
			} 

			// Update the current virtual 
			// Node to its previous 
			for (int j = MAX + 1; 
				j > i; j--) { 
				virtualNode[j] 
					= virtualNode[j - 1]; 
			} 

			virtualNode[i] = x; 
			newLeaf->IS_LEAF = true; 

			cursor->size = (MAX + 1) / 2; 
			newLeaf->size 
				= MAX + 1 - (MAX + 1) / 2; 

			cursor->ptr[cursor->size] 
				= newLeaf; 

			newLeaf->ptr[newLeaf->size] 
				= cursor->ptr[MAX]; 

			cursor->ptr[MAX] = NULL; 

			// Update the current virtual 
			// Node's key to its previous 
			for (i = 0; 
				i < cursor->size; i++) { 
				cursor->key[i] 
					= virtualNode[i]; 
			} 

			// Update the newLeaf key to 
			// virtual Node 
			for (i = 0, j = cursor->size; 
				i < newLeaf->size; 
				i++, j++) { 
				newLeaf->key[i] 
					= virtualNode[j]; 
			} 

			// If cursor is the root node 
			if (cursor == root) { 

				// Create a new Node 
				Node* newRoot = new Node; 

				// Update rest field of 
				// B+ Tree Node 
				newRoot->key[0] = newLeaf->key[0]; 
				newRoot->ptr[0] = cursor; 
				newRoot->ptr[1] = newLeaf; 
				newRoot->IS_LEAF = false; 
				newRoot->size = 1; 
				root = newRoot; 
			} 
			else { 

				// Recursive Call for 
				// insert in internal 
				insertInternal(newLeaf->key[0], 
							parent, 
							newLeaf); 
			} 
		} 
	} 
} 

// Function to implement the Insert 
// Internal Operation in B+ Tree 
void BPTree::insertInternal(int x, 
							Node* cursor, 
							Node* child) 
{ 

	// If we doesn't have overflow 
	if (cursor->size < MAX) { 
		int i = 0; 

		// Traverse the child node 
		// for current cursor node 
		while (x > cursor->key[i] 
			&& i < cursor->size) { 
			i++; 
		} 

		// Traverse the cursor node 
		// and update the current key 
		// to its previous node key 
		for (int j = cursor->size; 
			j > i; j--) { 

			cursor->key[j] 
				= cursor->key[j - 1]; 
		} 

		// Traverse the cursor node 
		// and update the current ptr 
		// to its previous node ptr 
		for (int j = cursor->size + 1; 
			j > i + 1; j--) { 
			cursor->ptr[j] 
				= cursor->ptr[j - 1]; 
		} 

		cursor->key[i] = x; 
		cursor->size++; 
		cursor->ptr[i + 1] = child; 
	} 

	// For overflow, break the node 
	else { 

		// For new Interval 
		Node* newInternal = new Node; 
		int virtualKey[MAX + 1]; 
		Node* virtualPtr[MAX + 2]; 

		// Insert the current list key 
		// of cursor node to virtualKey 
		for (int i = 0; i < MAX; i++) { 
			virtualKey[i] = cursor->key[i]; 
		} 

		// Insert the current list ptr 
		// of cursor node to virtualPtr 
		for (int i = 0; i < MAX + 1; i++) { 
			virtualPtr[i] = cursor->ptr[i]; 
		} 

		int i = 0, j; 

		// Traverse to find where the new 
		// node is to be inserted 
		while (x > virtualKey[i] 
			&& i < MAX) { 
			i++; 
		} 

		// Traverse the virtualKey node 
		// and update the current key 
		// to its previous node key 
		for (int j = MAX + 1; 
			j > i; j--) { 

			virtualKey[j] 
				= virtualKey[j - 1]; 
		} 

		virtualKey[i] = x; 

		// Traverse the virtualKey node 
		// and update the current ptr 
		// to its previous node ptr 
		for (int j = MAX + 2; 
			j > i + 1; j--) { 
			virtualPtr[j] 
				= virtualPtr[j - 1]; 
		} 

		virtualPtr[i + 1] = child; 
		newInternal->IS_LEAF = false; 

		cursor->size 
			= (MAX + 1) / 2; 

		newInternal->size 
			= MAX - (MAX + 1) / 2; 

		// Insert new node as an 
		// internal node 
		for (i = 0, j = cursor->size + 1; 
			i < newInternal->size; 
			i++, j++) { 

			newInternal->key[i] 
				= virtualKey[j]; 
		} 

		for (i = 0, j = cursor->size + 1; 
			i < newInternal->size + 1; 
			i++, j++) { 

			newInternal->ptr[i] 
				= virtualPtr[j]; 
		} 

		// If cursor is the root node 
		if (cursor == root) { 

			// Create a new root node 
			Node* newRoot = new Node; 

			// Update key value 
			newRoot->key[0] 
				= cursor->key[cursor->size]; 

			// Update rest field of 
			// B+ Tree Node 
			newRoot->ptr[0] = cursor; 
			newRoot->ptr[1] = newInternal; 
			newRoot->IS_LEAF = false; 
			newRoot->size = 1; 
			root = newRoot; 
		} 

		else { 

			// Recursive Call to insert 
			// the data 
			insertInternal(cursor->key[cursor->size], 
						findParent(root, 
									cursor), 
						newInternal); 
		} 
	} 
} 

// Function to find the parent node 
Node* BPTree::findParent(Node* cursor, 
						Node* child) 
{ 
	Node* parent; 

	// If cursor reaches the end of Tree 
	if (cursor->IS_LEAF 
		|| (cursor->ptr[0])->IS_LEAF) { 
		return NULL; 
	} 

	// Traverse the current node with 
	// all its child 
	for (int i = 0; 
		i < cursor->size + 1; i++) { 

		// Update the parent for the 
		// child Node 
		if (cursor->ptr[i] == child) { 
			parent = cursor; 
			return parent; 
		} 

		// Else recursively traverse to 
		// find child node 
		else { 
			parent 
				= findParent(cursor->ptr[i], 
							child); 

			// If parent is found, then 
			// return that parent node 
			if (parent != NULL) 
				return parent; 
		} 
	} 

	// Return parent node 
	return parent; 
} 

// Function to get the root Node 
Node* BPTree::getRoot() 
{ 
	return root; 
} 

// Driver Code 
int main() 
{ 
	BPTree node; 

	// Create B+ Tree 
	node.insert(6); 
	node.insert(16); 
	node.insert(26); 
	node.insert(36); 
	node.insert(46); 

	// Function Call to search node 
	// with value 16 
	node.search(16); 

	return 0; 
} 
