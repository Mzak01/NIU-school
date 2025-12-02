/*
    Milo Zak
    Z1917365
    CSCI340-3

	I certify that this is my own work and where appropriate an extension
	of the starter code provided for the assignment.
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <bits/stdc++.h>

#include "node.h"
#include "btree.h"

using namespace std;

template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
public:
    void Insert(const T &x);       // inserts node with value x
    bool Search(const T &x) const; // searches leaf with value x
    bool Remove(const T &x);       // removes leaf with value x
private:
    void _Insert(Node<T> *&, const T &);      // private version of insert
    bool _Search(Node<T> *, const T &) const; // private version of search
    void _Remove(Node<T> *&, const T &);      // private version of remove
    bool _Leaf(Node<T> *node) const;          // checks if node is leaf
};


/*
Func: void Insert(const T &x);

Arg: calls private version to insert val

Ret: none
*/
template <typename T>
void BinarySearchTree<T>::Insert(const T &x)
{
    _Insert(this->root, x);
}

/*
Func: bool Search(const T &x) const

Arg: searches for a node in bst, only can be leaf
     calls on private version

Ret: true/false
*/
template <typename T>
bool BinarySearchTree<T>::Search(const T &x) const
{
   return _Search(this->root, x);
}

/*
Func: bool Remove(const T &x)

Arg: if it is a leaf then remove, else return false

Ret: true/false
*/
template <typename T>
bool BinarySearchTree<T>::Remove(const T &x)
{
    if(Search(x) == true)
    {
        _Remove(this->root, x);
        return true;
    }
    return false;
}

/*
Func: void _Insert(Node<T> *&, const T &)

Arg: private version which actually inserts a node

Ret: none
*/
template <typename T>
void BinarySearchTree<T>::_Insert(Node<T> *& node, const T & x)
{
    if(node == NULL)
    {
        node = new Node<T> (x);
    }

    if(x < node->data)
    {
        _Insert(node->left, x);
    }
    else if(x > node->data)
    {
        _Insert(node->right, x);
    }
    else
    {
        return;
    }
}

/*
Func: bool _Search(Node<T> *, const T &) const

Arg: Private version of search. Only returns if the val is a leaf

Ret:. true/false
*/
template <typename T>
bool BinarySearchTree<T>::_Search(Node<T> *node, const T & x) const
{
    if(node == NULL)
    {
        return false;
    }
    if( x == node->data)
    {
        if(_Leaf(node))
        {
            return true;
        }
        return false;
    }

    if( x > node->data)
    {
        return _Search(node->right, x);
    }
    else
    {
        return _Search(node->left, x);
    }
}

/*
Func: void _Remove(Node<T> *&, const T &)

Arg: removes a value in the BST if it is leaf

Ret: none
*/
template <typename T>
void BinarySearchTree<T>::_Remove(Node<T> *&node, const T & x)
{
    if(node == NULL)
    {
        return;
    }
    if(_Leaf(node) && x == node->data)
    {
        delete node;
        node = NULL;
        return;
    }
    if(x > node->data)
    {
        _Remove(node->right, x);
    }
    if(x < node ->data)
    {
        _Remove(node->left, x);
    }
}

/*
Func: bool _Leaf(Node<T> *node) const

Arg: figures out if the value is a leaf node or not

Ret: true/false
*/
template <typename T>
bool BinarySearchTree<T>::_Leaf(Node<T> *node) const
{
    if(node->left == NULL && node->right == NULL)
    {
        return true;
    }
        return false;
}

#endif //end of BINARYSEARCHTREE_H
