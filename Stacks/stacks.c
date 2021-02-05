#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
    int data;
    Node* next;
};

//function signature
Node* push(Node* root, int data);
Node* pop(Node* root);

int main(void)
{  
    Node* root = NULL;
    root = push(root, 5);
    root = push(root, 10);
    root = push(root, 15);
    root = push(root, 20);
    root = pop(root);

    printf("%i is the last node\n",root->data);
    return 0;
}

Node* push(Node* root, int data)
{   
    if (root == NULL)
    {
        /*  what we do here :-
                root = new node
                new node -> data = data
                new node -> next = null
                return root
        */
        root = malloc(sizeof(Node));
        root->data = data;
        root->next = NULL;
        printf("%d pushed in the stack\n",data);
        return root;
            
    }
    if (root != NULL)
    {
        Node* temp = root;
        root = malloc(sizeof(Node));
        root->data = data;
        root->next = temp;
        printf("%d pushed in the stack\n",data);
        return root;

        /*  what we do here :-
            temp_ptr = root
            root -> new node(malloc)
            new node->data = data 
            new node->next = temp
            return root
        */
    }   
}

Node* pop(Node* root)
{
    /*  what we do here :-
        temp -> root 
        root = temp->next
        free(temp)
        return root
        now root is pointing to second node and top node is popped.
    */

    Node* temp = root;
    root = temp->next;
    int data = temp->data;
    //do whatever you want with last node, here we free the node 
    free(temp);
    printf("%d is popped from the stack\n",data);
    return root;
}


