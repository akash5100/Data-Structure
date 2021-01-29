#include <iostream>
#include <queue>
using namespace std;


struct Node{
    int data;
    Node *right;
    Node *left;
};

Node* createNode(int data){
    Node* temp=new Node();
    temp->data = data;
    temp->left =nullptr;
    temp->right=nullptr;

    return temp;
}

Node* insert(int value,Node* root){
    if(root == nullptr)
        return createNode(value);

    if(value < root->data)
        root->left = insert(value,root->left);
    if(value > root->data)
        root->right = insert(value,root->right);
    
    return root;
}
//deleting only leaves
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

Node* search(int data,Node* root){
    if (root == nullptr)
        return nullptr;

    Node* out=nullptr;
    queue <Node*>q;
    q.push(root);
    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if (temp->data == data) { 
            out = temp; }

        if (temp->left != nullptr) {
            q.push(temp->left); }
            
        if (temp->right != nullptr) {
            q.push(temp->right); }
    }
    return out;
}



int main(){
    Node* root=insert(50,root);
    insert(20,root);
    insert(30,root);
    insert(60,root);
    
    DELETE(60,root);
    traverse(root);
    return 0;
}