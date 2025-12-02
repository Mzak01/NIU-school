/*
Milo Zak
Z1917365
CSCI340-3

I certify that this is my own work and where appropriate an extension
of the starter code provided for the assignment.
*/

#ifndef H_BTREE
#define H_BTREE

#include "node.h"

using namespace std;

template <typename T> class BinaryTree{

public:
    BinaryTree();                                      // default constructor
    unsigned     getSize() const;                      // returns size of tree
    unsigned     getHeight() const;                    // returns height of tree
    virtual void Insert(const T&);                     // inserts node in tree
    void         Inorder(void (*)(const T&));          // inorder traversal of tree

protected:
    Node<T> *root;                                      // root of tree

private:
    unsigned _getSize(Node<T> *) const;                 // private version of getSize()
    unsigned _getHeight(Node<T> *) const;               // private version of getHeight()
    void     _Insert(Node<T> *&, const T&);             // private version of Insert()
    void     _Inorder(Node<T> *, void (*)(const T&));   // private version of Inorder()
};

//added from the stuff yes
typedef enum {left_side, right_side } SIDE;

SIDE rnd(){
    return rand()%2 ? right_side : left_side;
}// End of rnd()


/*
Func: BinaryTree

Arg: sets root to null for blank slate

Ret:m none
*/
template <typename T>
BinaryTree<T>::BinaryTree()
{
    root = NULL;
}

/*
Func: unsigned BinaryTree<T>::getSize() const

Arg: returns size of tree

Ret: _getSize(root)
*/
template <typename T>
unsigned BinaryTree<T>::getSize() const
{
    return _getSize(root);
}

/*
Func: unsigned BinaryTree<T>::getHeight() const

Arg: returns height of the tree

Ret: _getHeight(root);
*/
template <typename T>
unsigned BinaryTree<T>::getHeight() const
{
    return _getHeight(root);
}

/*
Func: virtual void BinaryTree<T>::Insert(const T& x)

Arg: calls private insert to insert node

Ret: none
*/
template <typename T>
void BinaryTree<T>::Insert(const T& x)
{
    _Insert(root, x);
}

/*
Func: void BinaryTree<T>::Inorder(void (*) (const T& x))

Arg: calls priv version to inorder sort tree

Ret: none
*/
template <typename T>
void BinaryTree<T>::Inorder(void (*x) (const T&))
{
    _Inorder(root, x);
}

/*
Func: unsigned BinaryTree<T>::_getSize(Node<T> *x) const

Arg: counts the amount of nodes within the binary tree

Ret: the size of the tree
*/
template<typename T>
unsigned BinaryTree<T>::_getSize(Node<T> *x) const
{
    if(x != NULL)
    {
        return(_getSize(x->left) + 1 + _getSize(x->right));
    }
    else
    {
        return 0;
    }
}

/*
Func: unsigned BinaryTree<T>::_getHeight(Node<T> *x) const

Arg: goes down to the lowest left and right side and finds the max
     between the two sides

Ret: the height of the tree
*/
template<typename T>
unsigned BinaryTree<T>::_getHeight(Node<T> *x) const
{
    if(x == NULL)
    {
        return 0;
    }
    else
    {
        auto right_side = _getHeight(x->right);
        auto left_side = _getHeight(x->left);

        return max(right_side, left_side) + 1;
    }
}

/*
Func: void BinaryTree<T>::_Insert(Node<T> *&n, const T& x)

Arg: is the tree is not empty  use rnd() to place the next node within
     the tree.

Ret: none
*/
template<typename T>
void BinaryTree<T>::_Insert(Node<T> *& n_node, const T& x)
{
    if(n_node == NULL)
    {
        n_node = new Node<T>();

        n_node->data = x;
    }
    else
    {
        SIDE placement = rnd();

        if(placement == right_side)
        {
            _Insert(n_node->right, x);
        }
        else
        {
            _Insert(n_node->left, x);
        }
    }
}

/*
Func: void BinaryTree<T>::_Inorder(Node<T> *n, void (*x)(const T&))

Arg: sorts the nodes within the tree to an inorder sort.

Ret: none
*/
template<typename T>
void BinaryTree<T>::_Inorder(Node<T> *n_node, void (*x)(const T&))
{
    if(n_node != NULL)
    {
        _Inorder(n_node->left, x);
        x(n_node -> data);
        _Inorder(n_node->right, x);
    }
}

#endif // End of H_BTREE
