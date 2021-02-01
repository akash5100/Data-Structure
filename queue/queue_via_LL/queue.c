#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"


//dequeue - function to remove node 
void dequeue(queue **root)
{   
    if (root == NULL) 
        return;
    
    queue *ptr = *root; 
    *root = ptr->next;
    printf("%d is removed from queue\n",ptr->data);

    return;
}

int main(void)
{
    queue* root = create_queue();
    enqueue(root,1);
    enqueue(root,2);
    enqueue(root,3);
    enqueue(root,4);
    dequeue(&root);
    enqueue(root,5);
    enqueue(root,6);
    dequeue(&root);
    enqueue(root,7);
    dequeue(&root);
    enqueue(root,8);
    enqueue(root,9);
    dequeue(&root);


    traverse(root);
    

    return 0;
}



