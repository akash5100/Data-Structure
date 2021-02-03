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

//returns a pointer to the inorder successor of the node
Node* minimuM(Node* root)
{   
    Node* temp=nullptr;
    if (root->left != nullptr)
    {
        temp = minimuM(root->left);
    }
    else if(root->right != nullptr)
    {
        temp = root->right;
    }
    
    return temp;
}

//deleting only leaves
Node* DELETE(int value,Node* root){
    if (root==nullptr)
    {
        std::cout << "root is null" << std::endl;
        return root;
    }

    //if value lies on left of the root node then, go left 
    if(root->data > value)
    {
        root->left = DELETE(value,root->left);
    }
    //else if value lies on right of the root node then, go right
    else if(root->data > value)
    {
        root->right = DELETE(value,root->right);
    }
    //if the node has 1 or no child
    if (root->left == nullptr)
    {   
        Node* temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == nullptr)
    {
        Node* temp = root->left;
        free(root);
        return temp;
    }
    //if the node has 2 child 
    Node* temp=minimuM(root->right);
    temp->left = root->left;
    temp->right = root->right;
    free(root);
    return temp;
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
    insert(30,root);
    insert(70,root);
    insert(20,root);
    insert(40,root);
    insert(60,root);
    insert(80,root);


    DELETE(20,root);
    traverse(root);
    return 0;
}