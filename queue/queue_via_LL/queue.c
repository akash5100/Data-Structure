#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue queue;

struct Queue
{
    int data;
    queue* next;
};

typedef struct Counter counter;
struct Counter
{
       queue *rear , *front;
}ctrl;

queue* create_queue()
{
    queue* root = malloc(sizeof(queue));
    root->data = 0;
    root->next=NULL;
    ctrl.rear = root;
    return root;
}

//isEmpty - tells if the queue is empty
bool isEmpty(queue* root)
{
    if (root->next == NULL)
    {   
        if (root->data == 0)
        {
            return true;
        }
    }
    return false;
}

//enqueue - function to add node at end 
void enqueue(queue* root, int data)
{   
    if (isEmpty(root))
    {
        root->data = data;
        root->next = NULL;
        printf("%d is added to queue\n", root->data);
    }
    else
    {
        queue* temp = malloc(sizeof(queue));
        temp->data = data;
        //--------------------------------------------//
            while (ctrl.rear->next != NULL)
            {
                ctrl.rear = ctrl.rear->next;
            }
        ctrl.rear->next = temp;
        temp->next = NULL;

        printf("%d is added to queue\n", temp->data);
    }
    
    return;
}
//dequeue - function to remove node 
void dequeue(queue* root)
{
    queue* remove = root;
    root = remove->next;
    printf("%d is removed from queue\n",remove->data);
    free(remove);
    return;
}

//front - return the front node



int main(void)
{
    queue* root = create_queue();
    enqueue(root,1);
    enqueue(root,2);
    enqueue(root,3);
    enqueue(root,4);
    enqueue(root,5);
    enqueue(root,6);
    enqueue(root,8);
    enqueue(root,9);
    dequeue(root);


    //outputs:-
    queue* temp= root;
    printf("\nqueue:-\n");
    while (temp != NULL)
    {
        printf("\t%d\n",temp->data);
        temp = temp->next;
    }
    

    return 0;
}