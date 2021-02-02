#include <iostream>
using namespace std;
typedef struct Node node;

struct Node{
    int data;
    Node *right;
    Node *left;
    int height;
};

//createnode
Node* createNode(int data){
    Node* temp=new Node();
    temp->data = data;
    temp->left =nullptr;
    temp->right=nullptr;
    temp->height=1;
    return temp;
}

//delete
Node* DELETE(int value,Node* root){
    if (root==nullptr)
    {
        std::cout << "root is null" << std::endl;
        return root;
    }
    if (value>root->data){   
        if (root->data==value)  
        {
            root->data=0;
            return root;
        }
        root->right=DELETE(value,root->right);
    }
    if (value<root->data){   
        if (root->data==value)  
        {
            root->data=0;
            return root;
        }
        root->left=DELETE(value,root->left);
    }
    return root;
}

//traverse
void traverse(Node* root){
    if(root == nullptr){ 
        return;}
    else
    {
        traverse(root->left);
        std::cout << root->data << std::endl;
        traverse(root->right); 
    }
}