#include <iostream>
#include "include\tree.h"
using namespace std;

void PrintData(const int & i);

int main()
{
    Tree<int> tree;

    for(int i = 1; i <= 10; i++)
    {
        tree.Insert(i);
    }

    void (*print)(const int & i);
    print = &PrintData;

    cout << "In Order" << endl;
    tree.InOrder(print);
    cout << endl << "Post Order" << endl;
    tree.PostOrder(print);
    cout << endl << "Pre Order" << endl;
    tree.PreOrder(print);

    return 0;
}

void PrintData(const int & i)
{
    cout << i << endl;
}
