#include "avl.h"
//maximum
int maximum(int a, int b)
{
    int max= 0;
    if (a > b)
        max = a;
    else if (b > a)
        max = b;
    return max;
}

//Height
int Height(node* root)
{       
    if (root == nullptr)
    {
        return 0;
    }
    return root->height;  
}

//leftrotation
node* leftleft(node* root)
{
    std::cout << "\nperforming leftleft\n" << std::endl;
    node* temp = root->left;
    node* temp2 = temp->right;

    root->left = temp2;
    temp->right = root;

        root->height = 1 + maximum(Height(root->left),Height(root->right));
        temp2 = temp->right;
        temp2->height = 1 + maximum(Height(temp2->left),Height(temp2->right));

    return temp; 
}

//rightrotation
node* rightright(node* root)
{
    node* temp = root->right;
    node* t2 = temp->left;
    root->right = t2;
    temp->left = root;

    root->height = maximum(Height(root->left),Height(root->right))+1;
    t2 = temp->right;
    t2->height = maximum(Height(t2->left),Height(t2->right))+1;

    std::cout << "performing rightright\n" << std::endl;
    return temp;
}

node* leftright(node* root)
{
    std::cout << "performing leftright\n" << std::endl;
    rightright(root->left);
    return leftleft(root);
}

node* rightleft(node* root)
{
    std::cout << "performing rightleft\n" << std::endl;
    leftleft(root->right);
    return rightright(root);
}

//BalanceFactor = height(left-sutree) − height(right-sutree)
int BFactor(node* root)
{
    return (Height(root->left) - Height(root->right));
}

void balance(node* root)
{
    int Bf = BFactor(root);

    if (Bf != 0 && Bf!= 1 &&Bf != -1)
    {
        switch (Bf)
        {
        case +2:
            if(BFactor(root->left) == 1)
                leftleft(root);
            if(BFactor(root->left) == -1)
                leftright(root);
            break;
        
        case -2:
            if(BFactor(root->right) == -1)
                rightright(root);
            if(BFactor(root->right) == 1)
                rightleft(root);
            break;

        default:
            std::cout << "performing nothing\n" << std::endl;
            break;
        }
    }
    return;

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
node* insert(int value, node* root)
{
    if (root == nullptr){
        return createNode(value);
    }

    if(value < root->data)
        root->left = insert(value,root->left);
    else if (value > root->data)
        root->right = insert(value,root->right);
    else 
        return root;   

    root->height = maximum(Height(root->left),Height(root->right))+1;

    balance(root);

    return root;
}

int main(void)
{
    Node* root=insert(10,root);
    insert(11,root);
    insert(5,root);
    insert(4,root);
    insert(7,root);
    insert(6,root);
    insert(8,root);
    

    //DELETE(50,root);

    std::cout << "\nTree:-\n" << std::endl;
    traverse(root);

    return 0;
}



/*
                -   50
                 /      \
            -30           70
           /             /  \
        20            60     80
       /
      40 
*/