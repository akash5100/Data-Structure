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
    Node* root=insert(50,root);
    insert(30,root);
    insert(70,root);
    insert(20,root);
    insert(40,root);
    insert(60,root);
    insert(80,root);

    DELETE(50,root);

    std::cout << "\nTree:-\n" << std::endl;
    traverse(root);

    return 0;
}



/*
                    50
                 /      \
            30              70
           /   \           /  \
        20      40      60      80  
*/