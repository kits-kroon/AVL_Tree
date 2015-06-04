#include <iostream>
#include "include\tree.h"
#include "unit.h"
#include <fstream>
#include <cstdlib>

using namespace std;

void PrintData(const int & i);
void UnitTreeTest();
void IntTreeTest();
void PrintUnit(const Unit & unit);

int main()
{
    IntTreeTest();
    //UnitTreeTest();
    return 0;
}

void IntTreeTest()
{
    Tree<int> tree;

    for(int i = 10; i >= 0; i--)
    {
        tree.Insert(i);
    }

    void (*print)(const int & i);
    print = &PrintData;

    cout << endl << "Pre Order" << endl;
    tree.PreOrder(print);
    cout << endl << "In Order" << endl;
    tree.InOrder(print);
}

void UnitTreeTest()
{
    Tree<Unit> tree;

    ifstream inFile("unitInput.csv");

    string unitId;
    string unitName;
    string credits;

    while(getline(inFile, unitId, ','))
    {
        Unit newUnit;

        getline(inFile, unitName, ',');
        getline(inFile, credits);

        newUnit.SetId(unitId);
        newUnit.SetName(unitName);
        newUnit.SetCredits(atol(credits.c_str()));

        tree.Insert(newUnit);
    }

    void (*print)(const Unit & unit);
    print = *PrintUnit;

    cout << "Pre Order" << endl << endl;
    tree.PreOrder(print);
    cout << endl <<"In Order" << endl << endl;
    tree.InOrder(print);
}

void PrintData(const int & i)
{
    cout << i << endl;
}

void PrintUnit(const Unit & unit)
{
    cout << unit << endl;
}

bool operator < (const Unit & lhs, const Unit & rhs)
{
    int compareInt; // Integer produced by compare
    compareInt = (lhs.GetId()).compare(rhs.GetId());

    if(compareInt <= 0)
    {
        return false; // lhs is greater than or equal to rhs
    }

    return true; // ID is less than rhs
}

bool operator == (const Unit & lhs, const Unit & rhs)
{
    if(lhs.GetId().compare(rhs.GetId()) == 0)
    {
        return true;
    }

    return false;
}

ostream & operator << (ostream & os, const Unit & aUnit)
{
    os << aUnit.GetId();

    return os;
}
