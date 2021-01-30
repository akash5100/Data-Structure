#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue queue;

struct Queue { 
    int front, rear;
    unsigned int size; 
    unsigned capacity; 
    int* array; 
};

//function to create a queue
queue* create_queue(unsigned capacity)
{
    queue *ptr = malloc(sizeof(queue));
    ptr->capacity = capacity;
    ptr->front= ptr->size = 0;
    ptr->rear = 0;
    
    ptr->array = malloc(capacity * sizeof(int));

    return ptr;
}

//function to check queue is full
bool isFull(queue *ptr)
{   
    if (ptr->size == ptr->capacity-1)
    {
        return true;
    }
    return false;
}

// Function to check queue is empty 
bool isEmpty(queue* ptr)
{
    if (ptr->size == 0)
    {
        printf("queue is empty :( \n");
        return true;
    }
    return false;
}

// Function to get front of queue
int Front(queue* ptr)
{
    if(isEmpty(ptr)){
        printf("queue is empty\n");
        return 0;}
    int data = ptr->front;
    return data; 
}

//function to add element to queue
void enqueue(queue* ptr,int data)
{   
    if (isFull(ptr))
    {
        printf("queue is full :)\n");
        return;
    }

    *(ptr->array + ptr->front) = data;
    
    if (ptr->front < ptr->capacity)
    {
        ptr->front = ptr->front+1;
    }
    else
    {
        if (ptr->front >= ptr->capacity)
        {
            ptr->front = 0;
        }
    }
    
    
    ptr->size = ptr->size +1;
    printf("%d is added to queue\n",data);
}

//function to remove element from queue
void dequeue(queue *ptr)
{   
    if (isEmpty(ptr))
    {
        printf("queue is already empty :)\n");
        return;
    }
    
    int data =  *(ptr->array + ptr->rear);
    *(ptr->array + ptr->rear) = 0;
    if (ptr->rear < ptr->capacity)
    {
        ptr->rear = ptr->rear+1;
    }
    else
    {
        if (ptr->rear >= ptr->capacity)
        {
            ptr->rear = 0;
        }
    }

    ptr->size = ptr->size -1;
    printf("%d is removed queue\n",data);
}

// function to print the queue
void print_queue(queue* ptr)
{
    printf("Queue: \n");
    for (int i = 0; i < (ptr->capacity-1); i++)
    {
        printf("\t%d\n",*(ptr->array + i));
    }
    
}

int main(void)
{   
    queue *ptr = create_queue(8);
    enqueue(ptr,1);
    enqueue(ptr,2);
    enqueue(ptr,3);
    enqueue(ptr,4);
    enqueue(ptr,5);
    enqueue(ptr,6);
    enqueue(ptr,7);

    print_queue(ptr);
    return 0;
}