/****************************************************************************
Title: bstree.h

Class: CSCI241 Assign11

Programmer: Milo Zak(z1917365)

Use: This assignment is an exercise in implementing the map ADT using a
     binary search tree. You will need to write a template structure to
     represent a tree node, and a template class to represent the tree.
****************************************************************************/

#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdlib>

using namespace std;

//constructing the node
template<class K, class V>
struct node
{
	K key;
	V value;

	node<K, V> *left;
	node<K, V> *right;

	node(const K& key = K(), const V& value = V(), node<K, V> *left = nullptr, node<K, V> *right = nullptr)
	{
		this->key = key;
		this->value = value;
		this->left = left;
		this->right = right;
	}
};

//template class definition used later on
template<class K, class V>
class bstree
{
	private:
		node<K, V> *root;
		size_t tree_size;
	public:
		bstree();
		~bstree();
		bstree(const bstree<K, V>& x);
		bstree<K, V>& operator=(const bstree<K, V>& x);
		void clear();
		size_t size() const;
		size_t height() const;
		bool empty() const;
		const K& min() const;
		const K& max() const;
		bool insert(const K&, const V&);
		bool remove(const K&);
		const node<K, V>* find(const K&) const;
		void preorder() const;
		void inorder() const;
		void postorder() const;
		void level_order() const;
		void Murder(const node<K, V>*);
		node<K, V> *clone(const node<K, V>*);
};

/***************************************************************************
Function: bstree()

Use: The class should have a default constructor that sets the root pointer
     data member of the tree to nullptr and the tree size to 0.

Return: n/a
***************************************************************************/
template <class K, class V>
bstree<K, V>::bstree()
{
	//sets things to 0 and nothing
	root = nullptr;
	tree_size = 0;
}

/***************************************************************************
Function: ~bstree()

Use: The class should have a destructor. The destructor can simply call the
     clear() method.

Return: n/a
***************************************************************************/
template <class K, class V>
bstree<K, V>::~bstree()
{
	clear();
}

/***************************************************************************
Function: bstree(const bstree<K, V>& x)

Use: The class should have a proper copy constructor. Making a copy of the
     tree nodes can be done by performing a modified preorder traversal as
     described in the course notes on binary search trees.

Return: n/a
***************************************************************************/
template <class K, class V>
bstree<K, V>::bstree(const bstree<K, V>& x)
{
	tree_size = x.tree_size;
	root = clone(x.root);
}

/***************************************************************************
Function: opertator=

Use: The assignment operator should be properly overloaded.

Return: n/a
***************************************************************************/
template <class K, class V>
bstree<K, V>& bstree<K, V>::operator=(const bstree<K, V>& x)
{
	//overloading
	if(this != &x)
	{
		clear();
		tree_size = x.tree_size;
		root = clone(x.root);
	}
	return *this;
}

/***************************************************************************
Function: clear()

Use: This member function should set the tree back to the empty state,
     deleting all of the nodes in the tree and setting the size back to 0.

Return: n/a
***************************************************************************/
template <class K, class V>
void bstree<K, V>::clear()
{
	//if it is not empty
	if(root != nullptr)
	{
		//kill everything until it is
		Murder(root->left);
		Murder(root->right);

		delete root;
	}
	root =  nullptr;
	tree_size = 0;
}

/***************************************************************************
Function: size

Use: Returns the tree size.

Return: tree_size
***************************************************************************/
template <class K, class V>
size_t bstree<K, V>::size() const
{
	return tree_size;
}

/***************************************************************************
Function: height()

Use: Returns the tree height. In this assignment, we will use a slightly
     modified definition for the height of a tree. An empty tree will have
     height 0, a tree with only a root node will have height 1. The height
     of any other node in the tree is the height of its parent node + 1.
     The height of the tree can then be defined as the maximum height of
     any of its nodes.

Return: tree_size
***************************************************************************/
template <class K, class V>
size_t bstree<K, V>::height() const
{
	//nothing return 0
	if(empty())
	{
		return 0;
	}

	//makes a queue for the tree
	queue<node<K, V>*> queue;

	queue.push(root);

	//height amount(can't reuse height because
	//it is already a function)
	size_t h = 0;

	//while h is one return h
	while(1)
	{
		int counting = queue.size();

		if(counting == 0)
		{
			return h;
		}

		h++;

		//if the amount of nodes counted is greater than 0
		while(counting > 0)
		{
			node<K, V> *point = queue.front();

			queue.pop();

			if(point->left != nullptr)
			{
				queue.push(point->right);
			}
			counting--;
		}
	}
}

/***************************************************************************
Function: empty()

Use: Returns true if the tree size is 0; otherwise, returns false.

Return: true if empty, false if not
***************************************************************************/
template <class K, class V>
bool bstree<K, V>::empty() const
{
	if(tree_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/***************************************************************************
Function: min()

Use: This member function should return the minimum key in the tree. You
     may assume that this function will not be called for an empty tree.

Return: point->key
***************************************************************************/
template <class K, class V>
const K& bstree<K, V>::min() const
{
	//point of the node currently on
	node<K, V> *point = root;

	//continues to the left until it is on the last node
	while(point->left != nullptr)
	{
		point = point->left;
	}

	return point->key;
}

/***************************************************************************
Function: max()

Use: This member function should return the maximum key in the tree. You
     may assume that this function will not be called for an empty tree.

Return: point->right
***************************************************************************/
template <class K, class V>
const K& bstree<K, V>::max() const
{
	//point node is currently on
	node<K, V> *point = root;

	//travels the furthest to the right to find max
	while(point->right != nullptr)
	{
		point = point->right;
	}
	return point->key;
}

/***************************************************************************
Function: insert(const K&, const V&)

Use: This member function should attempt to insert a key and value into the
     binary search tree. If the key already exists in the tree, the
     function should return false. Otherwise, a new tree node containing
     the key and value should be inserted in the correct spot to maintain
     the ordered property of the binary search tree, the size of the tree
     should be incremented, and the function should return true.

Return: true or false
***************************************************************************/
template <class K, class V>
bool bstree<K, V>::insert(const K& key, const V& value)
{
	//point is point being looked at of the node
	node<K, V> *point = root;

	//parent node of children
	node<K, V> *parent = nullptr;

	//if the point is there and has others coming off of it
	//then the point focused on is a perant
	while(point != nullptr && key != point->key)
	{
		parent = point;

		//moves left or right
		if(key < point->key)
		{
			point = point->left;
		}
		else
		{
			point = point->right;
		}
	}

	//point not 0 return false
	if(point != nullptr)
	{
		return false;
	}

	//creates a new temp place holder of the variables
	node<K, V> *new_node = nullptr;
	new_node = new node<K, V>(key, value, new_node, new_node);

	//if parent and null are equal than the root is new_node
	if(parent == nullptr)
	{
		root = new_node;
	}
	//if it is not the root move throughout the tree and
	//put the numbers in their respective places
	else
	{
		if(new_node->key < parent->key)
		{
			parent->left = new_node;
		}
		else
		{
			parent->right = new_node;
		}
	}

	//increase tree size, because a new node has now been inserted
	tree_size = tree_size + 1;

	return true;
}

/***************************************************************************
Function: remove(const K&)

Use: This member function should attempt to remove the specified key from
     the binary search tree. If the key is not in the tree, the function
     should return false. Otherwise, the node with a matching key should be
     removed, the size of the tree should be decremented, and the function
     should return true.

Return: true or false
***************************************************************************/
template <class K, class V>
bool bstree<K, V>::remove(const K& key)
{
	//point like the prev
	node<K ,V> *point = root;

	//parent is onek above point
	node <K, V> *parent = nullptr;

	//replacing the point
	node<K, V> *replace = nullptr;

	//replacing parremt
	node<K, V> *replace_parent = nullptr;

	//either going to the left or right
	while(point != nullptr && key != point->key)
	{
		parent = point;

		if(key < point->key)
		{
			point = point->left;
		}
		else
		{
			point = point->right;
		}
	}

	//empty return false (point)
	if(point == nullptr)
	{
		return false;
	}

	//replacing left with right or reverse
	//depending on which is nullptr
	if(point->left == nullptr)
	{
		replace = point->right;
	}
	else if(point->right == nullptr)
	{
		replace = point->left;
	}
	//replacing the parent based on what is happening
	else
	{
		replace_parent = point;
		replace = point->left;

		while(replace->right != nullptr)
		{
			replace_parent = replace;
			replace = replace->right;
		}

		if(replace_parent != point)
		{
			replace_parent->right = replace->left;
			replace->left = point->left;
		}

		replace->right = point->right;
	}
	//no parent then replace the root
	if(parent == nullptr)
	{
		root = replace;
	}
	else
	{
		//how to replace raoot
		if(point->key <parent->key)
		{
			parent->left = replace;
		}
		else
		{
			parent->right = replace;
		}
	}

	//deletes the point being removed
	delete point;
	tree_size = tree_size - 1;

	//returns true upon success
	return true;
}

/***************************************************************************
Function: find(const K&)

Use: This member function should attempt to find the specified key in the
     binary search tree. If the key is not in the tree, the function
     should return nullptr. Otherwise, it should return the address of the
     node that contains the specified key.

Return: point
***************************************************************************/
template <class K, class V>
const node<K, V>* bstree<K, V>::find(const K& key) const
{
	//sets the pointer to the root instead of null
	node<K, V> *point = root;

	//while point is not empty and doesnt reach inital
	//point being found search
	while(point != nullptr && key != point->key)
	{
		if(key < point->key)
		{
			point = point->left;
		}
		else
		{
			point = point->right;
		}
	}
	//once found return the point
	return point;
}

/***************************************************************************
Function: preorder()

Use: This member function should perform a preorder traversal of the tree
     from left to right. As each node is visited, it should have its key
     and value printed (see Output below for the required format).

Return: n/a
***************************************************************************/
template <class K, class V>
void bstree<K, V>::preorder() const
{
	//sets point to root
	node<K, V> *point = root;

	//OOOOooooOOooOoOo another stack
	stack<node<K, V>*> stacks;

	while(point != nullptr || !stacks.empty())
	{
		//finding the preorder because point is not null
		while(point != nullptr)
		{
			//output of the word
			cout << point->key<<": "<<point->value<<endl;

			//moves to the next point
			stacks.push(point);
			point = point->left;
		}

		//puts point on top and removes amouont by one
		point = stacks.top();
		stacks.pop();

		point = point->right;
	}
}

/***************************************************************************
Function: inorder()

Use: This member function should perform a inorder traversal of the tree
     from left to right. As each node is visited, it should have its key
     and value printed (see Output below for the required format).

Return: n/a
***************************************************************************/
template <class K, class V>
void bstree<K, V>::inorder() const
{
	node<K , V> *point = root;

	stack<node<K, V>*> stacks;

	while(point != nullptr || !stacks.empty())
	{
		//goes through the point being looked at
		//and goes through until null
		while(point != nullptr)
		{
			stacks.push(point);
			point = point->left;
		}
		//puts num on top and keeps going after removing the node
		point = stacks.top();
		stacks.pop();

		//printing the value
		cout<<point->key<<": "<<point->value<<endl;

		point = point->right;
	}
}

/***************************************************************************
Function: postorder()

Use: This member function should perform a prostorder traversal of the tree
     from left to right. As each node is visited, it should have its key and
     value printed (see Output below for the required format).

Return: n/a
***************************************************************************/
template <class K, class V>
void bstree<K, V>::postorder() const
{
	//creates new pointers
	node<K, V> *prev = nullptr;
	node<K, V> *point = root;

	//stack to move the numbers around easily
	//had to put some diversity from que cause learning :)
	stack<node<K, V>*> stk;

	while(point != nullptr && prev != root)
	{
		//pushing the pointer over to the left
		while(point != nullptr && point != prev)
		{
			stk.push(point);
			point = point->left;
		}

		//puts value in pointer to top of the list, then removes
		//it by one
		point = stk.top();
		stk.pop();

		//does the same for the right side of the binary tree
		if(point->right == nullptr || point->right == prev)
		{
			cout<<point->key<<": "<<point->value<<endl;
			prev = point;
		}
		else
		{
			stk.push(point);
			point = point->right;
		}
	}
}

/***************************************************************************
Function: level_order()

Use: This member function should perform a level order traversal of the tree
     from left to right. As each node is visited, it should have its key
     and value printed (see Output below for the required format).

Return: n/a
***************************************************************************/
template <class K, class V>
void bstree<K, V>::level_order() const
{
	queue<node<K, V>*> queue;
	node<K, V> *point = nullptr;

	//if the tree is empty
	if(root == nullptr)
	{
		return;
	}

	//makes a temp queue to move things
	queue.push(root);

	//while queue is not nullptr
	while(!queue.empty())
	{
		point = queue.front();
		queue.pop();

		//prints the key and value of the transveral
		cout<<point->key<<": "<<point->value<<endl;

		//pushing the order from left to right until its fit
		if(point->left !=nullptr)
		{
			queue.push(point->left);
		}
		if(point->right != nullptr)
		{
			queue.push(point->right);
		}
	}
}

/***************************************************************************
Function: clone(const node<K, V> *)

Use: clones the pointer to make changes to it in the future

Return: new_node if there is data to copy, else nullptr
***************************************************************************/
template<class K, class V>
node<K, V>* bstree<K, V>::clone(const node<K, V> *point)
{
	//if the node being cloned is not empter
	if(point != nullptr)
	{
		node<K, V> *new_node = nullptr;

		//new temp holder
		new_node = new node<K, V>(point->key, point->value, new_node, new_node);

		new_node->key = point->key;
		new_node->value = point->value;

		new_node->left = clone(point->left);
		new_node->right = clone(point->right);

		//cloned node
		return new_node;
	}
	else
	{
		//nothing return nothing
		return nullptr;
	}
}

/************************************************************************
Function: Murder(const node<K, V> *point)

Use: destroys a node on the binary search tree. (AKA the function commits
     murder OoOoOoOOooo). finds the last thing point points to :)

Return: nothing
************************************************************************/
template<class K, class V>
void bstree<K, V>::Murder(const node<K, V> *point)
{
	if (point != nullptr)
	{

		//recursive (I hope I spelled that right)
		Murder(point->left);
		Murder(point->right);

		//deletes point pointed to
		delete point;
	}

}
#endif
