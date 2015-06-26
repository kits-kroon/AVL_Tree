#ifndef BinaryTree_H
#define BinaryTree_H

#include <cstddef>
#include <iostream>

using namespace std;

        /**
         * @class BinaryTree
         * @brief An AVL Binary Search Tree
         *
         * Allows the use of an AVL Binary Search tree, as this tree is an AVL
         * search tree it is self balancing.
         *
         * @author Jake Kroon
         * @version 01
         * @date 18/05/2015
         *
         * @bug No bugs to my knowledge
         */

template <class T>
class BinaryTree
{
    public:

            /**
             * @brief Default Constructor
             *
             * Initialises the object and sets the pointer of the root object
             * node to NULL
             *
             * @return void
             */
        BinaryTree();

            /**
             * @brief Copy Constructor
             *
             * Deep copies the object passed in, into a new BinaryTree object
             *
             * @param rhs - a constant reference to a BinaryTree object
             * @return void
             */
        BinaryTree(const BinaryTree & rhs);

            /**
             * @brief Destructor
             *
             * Clears memory by destroying all objects on the heap
             *
             * @return void
             */
        ~BinaryTree();

            /**
             * @brief Insert data into the BinaryTree
             *
             * Insert new data into the BinaryTree and will automatically
             * sort the data. This requires the opertor < to be
             * overloaded for the chosen data type.
             *
             * @param newData - new data to be entered of the templated data type
             * @return void
             */
        void Insert(T newData);

            /**
             * @brief Processes the data in an in order way
             *
             * Traverses the binary BinaryTree in order, performs
             * an operation on the data at each leaf
             *
             * @param travFunc - A pointer to a function that will act on the data of each node
             * @return void
             */
        void InOrder(void(*travFunc)(const T & data));

            /**
             * @brief Processes the data in a pre order way
             *
             * Traverses the binary BinaryTree pre order, performs
             * an operation on the data at each leaf
             *
             * @param travFunc - A pointer to a function that will act on the data of each node
             * @return void
             */
        void PreOrder(void(*travFunc)(const T & data));

            /**
             * @brief Processes the data in a post order way
             *
             * Traverses the binary BinaryTree post order, performs
             * an operation on the data at each leaf
             *
             * @param travFunc - A pointer to a function that will act on the data of each node
             * @return void
             */
        void PostOrder(void(*travFunc)(const T & data));

            /**
             * @brief Searches for an object matching type T
             *
             * This is intended to be used with operator overloading
             * for non primitive types. Searches for an object and returns
             * it where a match is found. Returns NULL if object isn't found.
             *
             * @param searchFunc - A pointer to a function that will act on the data at the node.
             * @param key - An object of type T to search for
             * @return Object - An object of of type T that matches the key
             */
        bool Search(T key, void(*searchFunc)(const T & data));

            /**
             * @brief Makes a deep copied version of the BinaryTree being assigned
             *
             * Makes a new BinaryTree object that is a deep copy of the object
             * on the right hand side of the  = operator. This new BinaryTree
             * object is then returned.
             *
             * @param rhs - A constant reference to a BinaryTree object
             * @return BinaryTree - A deep copy of the binary BinaryTree assigned
             */
        BinaryTree operator = (const BinaryTree & rhs);

    private:

            /**
             * @struct node
             * @brief A node struct containing a left and right pointer as well as data
             *
             * This is the node that is used by the program, there is a left and right
             * pointer as well as data of the templated data type defined by the user.
             * The height of the node is also stored in this struct
             * Contains a constructor.
             */
        struct node;

        node *root; /** The root node of the BinaryTree */
//****************************************************************************
//                  IN ORDER PROCESSING                                      *
//****************************************************************************

            /**
             * @brief Inserts new data into
             *
             * Allows the insertion of new data into the BinaryTree, automatically
             * orders the data. If inserting with a class object, overload the
             * comparison operator '<' so that comparisons between objects
             * can be made.
             *
             * @param data - data of the templated data type
             * @param parent - a pointer reference to the node passed in
             * @return void
             */
        node * Insert(T data, node * parent);

            /**
             * @brief A recursive function for In Order traversal
             *
             * Traverses in order, performs a function on the data at each node.
             *
             * @param parent - a pointer reference to a node to traverse
             * @return void
             */
        void InOrderHelper(node *& parent, void(*travFunc)(const T & data));

            /**
             * @brief A recursive function for Pre Order traversal
             *
             * Traverse pre order, performs a function on the data at each node.
             *
             * @param parent - a pointer reference to a node to traverse
             * @return void
             */
        void PreOrderHelper(node *& parent, void(*travFunc)(const T & data));

            /**
             * @brief A recursive function for Post Order traversal
             *
             * Traverse post order, performs a fucntion on the data at each node.
             *
             * @param parent - a pointer reference to a node to traverse
             * @return void
             */
        void PostOrderHelper(node *& parent, void(*travFunc)(const T & data));

            /**
             * @brief A helper method for the destructor
             *
             * Recursively deletes the objects at each node and sets the pointer
             * to NULL
             *
             * @param parent - a pointer to a node, this is for recursion
             * @return void
             */
        void Clear(node * parent);

            /**
             * @brief A method for deep copying
             *
             * Creates a deep copy of the BinaryTree passed in from the node
             * entered as a parameter
             *
             * @param parent - a pointer to a node, this is for recursion
             * @return node - A pointer to a node
             */
        node * Copy(const node * parent);

            /**
             * @brief A recursive function for searching for searching
             *
             * Searches for an item that matches the key recursively,
             * returns the matching key or NULL.
             *
             * @param key - The object to be found
             * @param parent - The node of the parent of the leaves being looked at.
             * @return object - An object of type T or a primitive, if not found returns NULL
             */
        bool SearchHelper(T key, node *& parent, void(*searchFunc)(const T & data));

            /**
             * @brief Gets the height of a node
             *
             * Checks that a node has been set, if it has it returns the height
             * if the node has not been set zero is returned.
             *
             * @param parent - The node to get the height of
             * @return height - An unsigned called that represents the height of the tree
             */
        unsigned Height(node * parent);

            /**
             * @brief Gets the height difference between two nodes
             *
             * Finds the difference in height between the left and right subtrees
             * of a node.
             *
             * @param parent - The node to compare subtree heights of
             * @return height - The height difference as an integer
             */
        int BalanceDifference(node * parent);

            /**
             * @brief Fixes the height of a node
             *
             * Recalculates the position of a node (i.e. height)
             * by finding the heights of the nodes in the subtree.
             *
             * @param parent - The node to set the height of
             * @return void
             */
        void FixHeight(node * parent);

            /**
             * @brief Rotates a node to the right
             *
             * Rotates nodes to the right to balance the tree
             *
             * @param parent - The node to perform rotation on
             * @return rotatedNode - The new node that replaces the one passed in
             */
        node * RotateRight(node * parent);

            /**
             * @brief Rotates a node to the left
             *
             * Rotates nodes to the left to balance the tree
             *
             * @param parent - The node to perform rotation on
             * @return rotatedNode - The new node that replaces the one passed in
             */
        node * RotateLeft(node * parent);

            /**
             * @brief Balances the tree
             *
             * Peforms rotations on the parent node where required
             * checks the balance and balances the tree where appropriate.
             *
             * @param parent - The node to check and perform balancing on
             * @return balancedNode - A balanced version of the tree passed in
             */
        node * Balance(node * parent);
};

template <class T>
struct BinaryTree<T>::node
{
    unsigned height; // Height of the subtree
    node* left;      // Left subtree root
    node* right;     // Right subtree root
    T data;          // Data contained in the node
    node(T d)        // Constructor got struct
    {
        data = d;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

template <class T>
BinaryTree<T>::BinaryTree()
{
    root = NULL;
}

//****************************************************************************
//                   DESTRUCTOR AND HELPER                                   *
//****************************************************************************

template <class T>
BinaryTree<T>::~BinaryTree()
{
    Clear(root);
}

template <class T>
void BinaryTree<T>::Clear(node * parent)
{
    if(parent != NULL)
    {
        Clear(parent -> left); // Clears all leaves left of a root
        Clear(parent -> right); // Clears all leaves right of a root
        delete parent; // delete parent node
        parent = NULL; // no dangling pointer
    }
}

//****************************************************************************
//                   COPY CONSTRUCTORS                                       *
//****************************************************************************

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree & rhs)
{
    root = Copy(rhs.root);
}

template <class T>
typename BinaryTree<T>::node * BinaryTree<T>::Copy(const node * parent)
{
    if(parent == NULL)
    {
        return NULL;
    }

    node *newNode;
    newNode = new node(parent -> data);

    newNode -> right = NULL;
    newNode -> left  = NULL;

    newNode -> right = Copy(parent -> right);
    newNode -> left  = Copy(parent -> left);

    return newNode;
}

template <class T>
BinaryTree<T> BinaryTree<T>::operator = (const BinaryTree & rhs)
{
    BinaryTree newBT(rhs);
    return newBT;
}

//****************************************************************************
//                  INSERTING INTO THE BINARY TREE                           *
//****************************************************************************

template <class T>
void BinaryTree<T>::Insert(T newData)
{
    root = Insert(newData, root);
}

template <class T>
typename BinaryTree<T>::node * BinaryTree<T>::Insert(T newData, node * parent)
{
    if(parent == NULL)
        return new node(newData);

    if(newData < parent -> data)
        parent -> left = Insert(newData, parent -> left);
    else if(parent -> data < newData)
        parent -> right = Insert(newData, parent -> right);

    return Balance(parent);
}

//****************************************************************************
//                        ROTATING THE BINARYTREE                            *
//****************************************************************************

template <class T>
typename BinaryTree<T>::node * BinaryTree<T>::Balance(node * parent)
{
    FixHeight(parent);

    if(BalanceDifference(parent) == 2)
    {
        if(BalanceDifference(parent -> right) < 0)
            parent -> right = RotateRight( parent -> right );
        return RotateLeft(parent);
    }

    if(BalanceDifference(parent) == -2)
    {
        if(BalanceDifference(parent -> left) > 0)
            parent -> left = RotateLeft( parent -> left );
        return RotateRight(parent);
    }

    return parent;
}

template <class T>
typename BinaryTree<T>::node * BinaryTree<T>::RotateRight(node * parent)
{
	node * y = parent -> left;
	parent -> left = y -> right;
	y -> right = parent;

	FixHeight(parent);
	FixHeight(y);

	return y;
}

template <class T>
typename BinaryTree<T>::node * BinaryTree<T>::RotateLeft(node * parent)
{
	node * x = parent -> right;
	parent -> right = x -> left;
	x -> left = parent;

	FixHeight(parent);
	FixHeight(x);

	return x;
}

//****************************************************************************
//                      HEIGHT FUNCTIONS                                     *
//****************************************************************************

// Can operate on empty (empty BinaryTrees)
template <class T>
unsigned BinaryTree<T>::Height(node * parent)
{
    // If parent == NULL, return zero else return height
	return parent ? parent -> height:0;
}

// Calculates balance factor, works with non zero only
template <class T>
int BinaryTree<T>::BalanceDifference(node * parent)
{
	return Height(parent -> right) - Height(parent -> left);
}

// Retrieves the correct value for the height field
template <class T>
void BinaryTree<T>::FixHeight(node * parent)
{
	unsigned hl = Height(parent -> left);
	unsigned hr = Height(parent -> right);

	if(hl > hr)
        parent -> height = hl + 1;
    else
        parent -> height = hr + 1;
}

//****************************************************************************
//                  IN ORDER PROCESSING                                      *
//****************************************************************************

template <class T>
void BinaryTree<T>::InOrder(void(*travFunc)(const T & data))
{
    InOrderHelper(root, travFunc);
}

template <class T>
void BinaryTree<T>::InOrderHelper(node *& parent, void(*travFunc)(const T & data))
{
    if(parent != NULL)
    {
        InOrderHelper(parent -> left, travFunc);
        travFunc(parent -> data);
        InOrderHelper(parent -> right, travFunc);
    }
}

//****************************************************************************
//                  PRE ORDER PROCESSING                                     *
//****************************************************************************

template <class T>
void BinaryTree<T>::PreOrder(void(*travFunc)(const T & data))
{
    PreOrderHelper(root, travFunc);
}

template <class T>
void BinaryTree<T>::PreOrderHelper(node *& parent, void(*travFunc)(const T & data))
{
    if(parent != NULL)
    {
        travFunc(parent -> data);
        PreOrderHelper(parent -> left, travFunc);
        PreOrderHelper(parent -> right, travFunc);
    }
}

//****************************************************************************
//                  POST ORDER PROCESSING                                    *
//****************************************************************************

template <class T>
void BinaryTree<T>::PostOrder(void(*travFunc)(const T & data))
{
    PostOrderHelper(root, travFunc);
}

template <class T>
void BinaryTree<T>::PostOrderHelper(node *& parent, void(*travFunc)(const T & data))
{
    if(parent != NULL)
    {
        PostOrderHelper(parent -> left, travFunc);
        PostOrderHelper(parent -> right, travFunc);
        travFunc(parent -> data);
    }
}

//****************************************************************************
//                          SEARCH FUNCTION                                  *
//****************************************************************************

template <class T>
bool BinaryTree<T>::Search(T key ,void(*searchFunc)(const T & data))
{
    bool found;
    found = SearchHelper(key, root, searchFunc);

    return found;
}

template<class T>
bool BinaryTree<T>::SearchHelper(T key, node *& parent, void(*searchFunc)(const T & data))
{
    if(parent != NULL)
    {
        if(key == parent -> data)
        {
            searchFunc(parent -> data);
            return true;
        }

        if(key < parent -> data)
        {
            return SearchHelper(key, parent -> left, searchFunc);
        }
        else
        {
            return SearchHelper(key, parent -> right, searchFunc);
        }
    }

    return false;
}

#endif // BinaryTree_H
