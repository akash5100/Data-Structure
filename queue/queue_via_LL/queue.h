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

//signature
void traverse(queue* root);
queue* create_queue();
bool isEmpty(queue* root);
void enqueue(queue* root, int data);
void dequeue(queue* root);

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
        if (root->data == 0)
            return true;

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
        /*
            queue *trav = root;
            while(trav->next!=NULL)
            {
                trav = trav->next;
            }
            trav->next = temp; */
        
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

void traverse(queue *root)
{   
    printf("\nTraverse:-\n");
    queue *temp = root;
    while (temp!=NULL)
    {
        printf("\t%d\n",temp->data);
        temp = temp->next;
    }
    return;
}