#include <iostream>

using namespace std;

class btree_node
{

    int *data;
    int t;
    btree_node **ptr;
public:

    //constructor
    btree_node(int T)
    {
        data = new int[T-1];
        ptr = new btree_node *[T]; 
    }
friend class Btree;
};

class BTree
{

    int t;
    btree_node *root;
public:
    //constructor
    BTree(int T)
    {
        root = nullptr;
        t = T;
    }
};



int main(void)
{
    BTree t(3);
}
