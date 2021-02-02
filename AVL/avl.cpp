#include "avl.h"

//Height
int Height(node* root)
{
    if (root == nullptr)
        return root->height;
    return 0;       
}

//rightrotation
node* rotateright(node* root)
{

}

//leftrotation
node* rotateleft(node* root)
{

}

//BalanceFactor = height(left-sutree) − height(right-sutree)
int balance(node* root)
{

}

//insert
node* insert(int value,node* root)
{
    
}

int main(void)
{
    node* root = nullptr;
    insert(100,root);
    insert(50,root);
    insert(25,root);
    insert(60,root);
    insert(10,root);
    return 0;
}



/*
            100
           /  \
          25  50
         /     \
        10     60


*/