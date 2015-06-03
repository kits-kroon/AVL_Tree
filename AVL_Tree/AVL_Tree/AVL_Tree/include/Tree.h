#ifndef Tree_H
#define Tree_H

#include <cstddef>
#include <iostream>

using namespace std;

        /**
         * @class Tree
         * @brief A binary search tree data structure
         *
         * Allows the use of a binary tree, contains appropriate methods
         * for binary tree traversal as well as other functions.
         *
         * @author Jake Kroon
         * @version 01
         * @date 18/05/2015
         *
         * @bug No bugs to my knowledge
         */

template <class T>
class Tree
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
        Tree();

            /**
             * @brief Copy Constructor
             *
             * Deep copies the object passed in, into a new Tree object
             *
             * @param rhs - a constant reference to a Tree object
             * @return void
             */
        Tree(const Tree & rhs);

            /**
             * @brief Destructor
             *
             * Clears memory by destroying all objects on the heap
             *
             * @return void
             */
        ~Tree();

            /**
             * @brief Insert data into the tree
             *
             * Insert new data into the tree and will automatically
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
             * Traverses the binary tree in order, performs
             * an operation on the data at each leaf
             *
             * @param travFunc - A pointer to a function that will act on the data of each node
             * @return void
             */
        void InOrder(void(*travFunc)(const T & data));

            /**
             * @brief Processes the data in a pre order way
             *
             * Traverses the binary tree pre order, performs
             * an operation on the data at each leaf
             *
             * @param travFunc - A pointer to a function that will act on the data of each node
             * @return void
             */
        void PreOrder(void(*travFunc)(const T & data));

            /**
             * @brief Processes the data in a post order way
             *
             * Traverses the binary tree post order, performs
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
             * @brief Makes a deep copied version of the Tree being assigned
             *
             * Makes a new Tree object that is a deep copy of the object
             * on the right hand side of the  = operator. This new Tree
             * object is then returned.
             *
             * @param rhs - A constant reference to a Tree object
             * @return Tree - A deep copy of the binary tree assigned
             */
        Tree operator = (const Tree & rhs);

    private:

            /**
             * @struct node
             * @brief A node struct containing a left and right pointer as well as data
             *
             * This is the node that is used by the program, there is a left and right
             * pointer as well as data of the templated data type defined by the user.
             *
             */
        struct node
        {
            unsigned char height;
            node* left;
            node* right;
            T data;
            node(T d)
            {
                data = d;
                left = NULL;
                right = NULL;
                height = 1;
            }
        };

        node *root; /** The root node of the tree */

            /**
             * @brief Inserts new data into
             *
             * Allows the insertion of new data into the tree, automatically
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
             * Creates a deep copy of the tree passed in from the node
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

        unsigned char Height(node * parent);

        int BalanceFactor(node * parent);

        void FixHeight(node * parent);

        node * RotateRight(node * parent);

        node * RotateLeft(node * parent);

        node * Balance(node * parent);
};

template <class T>
Tree<T>::Tree()
{
    root = NULL;
}

//****************************************************************************
//                   DESTRUCTOR AND HELPER                                   *
//****************************************************************************

template <class T>
Tree<T>::~Tree()
{
    Clear(root);
}

template <class T>
void Tree<T>::Clear(node * parent)
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
Tree<T>::Tree(const Tree & rhs)
{
    root = Copy(rhs.root);
}

template <class T>
typename Tree<T>::node * Tree<T>::Copy(const node * parent)
{
    if(parent == NULL)
    {
        return NULL;
    }

    node *newNode = new node();
    newNode -> right = NULL;
    newNode -> left  = NULL;

    newNode -> data  = parent -> data;
    newNode -> right = Copy(parent -> left);
    newNode -> left  = Copy(parent -> right);

    return newNode;
}

template <class T>
Tree<T> Tree<T>::operator = (const Tree & rhs)
{
    Tree newBT(rhs);
    return newBT;
}

//****************************************************************************
//                  INSERTING INTO THE TREE                                  *
//****************************************************************************

template <class T>
void Tree<T>::Insert(T newData)
{
    root = Insert(newData, root);
}

template <class T>
typename Tree<T>::node * Tree<T>::Insert(T newData, node * parent)
{
    if(parent == NULL)
        return new node(newData);

    if(newData < parent -> data)
        parent -> left = Insert(newData, parent -> left);
    else
        parent -> right = Insert(newData, parent -> right);

    return Balance(parent);
}

//****************************************************************************
//                        ROTATING THE TREE                                  *
//****************************************************************************

template <class T>
typename Tree<T>::node * Tree<T>::Balance(node * parent)
{
    FixHeight(parent);

    if(BalanceFactor(parent) == 2)
    {
        if(BalanceFactor(parent -> right) < 0)
            parent -> right = RotateRight( parent -> right );
        return RotateLeft(parent);
    }

    if(BalanceFactor(parent) == -2)
    {
        if(BalanceFactor(parent -> left) > 0)
            parent -> left = RotateLeft( parent -> left );
        return RotateRight(parent);
    }

    return parent;
}

template <class T>
typename Tree<T>::node * Tree<T>::RotateRight(node * parent) // rotate the right portion
{
	node * y = parent -> left;
	parent -> left = y -> right;
	y -> right = parent;

	FixHeight(parent);
	FixHeight(y);

	return y;
}

template <class T>
typename Tree<T>::node * Tree<T>::RotateLeft(node * parent) // rotate the left portion
{
	node * x = parent -> right;
	parent -> right = x -> left;
	x -> left = parent;

	FixHeight(parent);
	FixHeight(x);

	return x;
}

// Can operate on empty (empty trees)
template <class T>
unsigned char Tree<T>::Height(node * parent)
{
	return parent ? parent -> height:0;
}

// Calculates balance factor, works with non zero only
template <class T>
int Tree<T>::BalanceFactor(node * parent)
{
	return Height(parent -> right) - Height(parent -> left);
}

// Retrieves the correct value for the height field
template <class T>
void Tree<T>::FixHeight(node * parent)
{
	unsigned char hl = Height(parent -> left);
	unsigned char hr = Height(parent -> right);
	parent -> height = (hl > hr ? hl : hr) + 1;
}
//****************************************************************************
//                  IN ORDER PROCESSING                                      *
//****************************************************************************

template <class T>
void Tree<T>::InOrder(void(*travFunc)(const T & data))
{
    InOrderHelper(root, travFunc);
}

template <class T>
void Tree<T>::InOrderHelper(node *& parent, void(*travFunc)(const T & data))
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
void Tree<T>::PreOrder(void(*travFunc)(const T & data))
{
    PreOrderHelper(root, travFunc);
}

template <class T>
void Tree<T>::PreOrderHelper(node *& parent, void(*travFunc)(const T & data))
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
void Tree<T>::PostOrder(void(*travFunc)(const T & data))
{
    PostOrderHelper(root, travFunc);
}

template <class T>
void Tree<T>::PostOrderHelper(node *& parent, void(*travFunc)(const T & data))
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
bool Tree<T>::Search(T key ,void(*searchFunc)(const T & data))
{
    bool found;
    found = SearchHelper(key, root, searchFunc);

    return found;
}

template<class T>
bool Tree<T>::SearchHelper(T key, node *& parent, void(*searchFunc)(const T & data))
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

#endif // Tree_H
