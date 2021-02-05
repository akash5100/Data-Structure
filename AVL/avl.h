#include <iostream>
#include <cstdlib>

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
//minimum 
Node* minimuM(Node* root)
{   
    Node* temp=root;
    while (temp && temp->left != NULL){
        temp = temp->left;}
    return temp;
}

//delete
Node* DELETE(int value,Node* root){
    if (root==nullptr)
        return root;
    
    Node* temp;
    
    //if value lies on left of the root node then, go left 
    if(root->data > value)
    {
        root->left = DELETE(value,root->left);
    }
    //else if value lies on right of the root node then, go right
    else if(root->data < value)
    {
        root->right = DELETE(value,root->right);
    }
    //if the node has 1 or no child
        //check left
    if (root->left == nullptr && root->data == value)
    {   
        Node* temp = root->right;
        free(root);
        return temp;
    }
        //check right
    else if (root->right == nullptr && root->data == value)
    {
        Node* temp = root->left;
        free(root);
        return temp;
    }
    
    //if the node has 2 child 
    if(root->right != nullptr && root->left != nullptr)
    {
        Node* temp=minimuM(root->right); 
        root->data = temp->data;
        root->right = DELETE(temp->data,root->right); 
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