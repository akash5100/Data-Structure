#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"


//dequeue - function to remove node 
void dequeue(queue* root)
{   
    if (root == NULL) 
        return;
    
    queue *ptr = root; 
    root = root->next;
    //printf("%d is removed from queue\n",temp->data);
    //traverse(root);

    return;
}

int main(void)
{
    queue* root = create_queue();
    enqueue(root,1);
    enqueue(root,2);
    enqueue(root,3);
    enqueue(root,4);
    enqueue(root,5);
    enqueue(root,6);
    enqueue(root,7);
    enqueue(root,8);
    enqueue(root,9);
    dequeue(root);


    traverse(root);
    

    return 0;
}



