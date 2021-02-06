#include "avl.h"

//Height
int Height(node* root)
{
    int left_max = Height(root->left);
    int right_max = Height(root->right);
        if (left_max > right_max    )
        {
            return left_max + 1 ;
        }
        else if (right_max > left_max)
        {
            return right_max + 1;
        }
    return root->height;
}


//rightrotation
node* rotateright(node* root)
{
    //todo
    return root;
}

//leftrotation
node* rotateleft(node* root)
{
    //todo
    return root;
}

//BalanceFactor = height(left-sutree) − height(right-sutree)
int balance(node* root)
{
    return (Height(root->left) - Height(root->right));
}

//insert
    // points to remember :-
    //      All node should be balanced 
    //      if root is null return a new node with required value
    //      if balanceF equals -1 then left subtree of the node contains extra node.
    //      if balanceF equals 1 then right subtree of the node contains extra node.
    //      if balcnceF of node is +2 and that of node->left is +1 then we perform LL rotation
    //      if balcnceF of node is -2 and that of node->right is -1 then we perform RR rotation
    //      if balcnceF of node is -2 and that of node->right is +1 then we perform RL rotation
    //      if balcnceF of node is +2 and that of node->left is -1 then we perform LR rotation
node* insert(int value,node* root)
{
    if (root == nullptr)
        return createNode(value);
    
    if(value < root->data)
        root->left = insert(value,root->left);
    if (value > root->data)
        root->right = insert(value,root->right);    
    return root;
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