#include<iostream>
using namespace std;

typedef struct Anode Node;
struct Anode
{
    int data;
    Node *next;
};

typedef struct Vertex vertex;
struct Vertex
{
    Node *head;
    bool visited;
};

typedef struct gph graph;
struct gph
{
    int V;
    struct Vertex *list;
};

//signature
    graph* createGraph(int v); 
    void Traverse(graph *head);
    graph* insert(graph* Graph, int index, int value);
    Node* createNode(int data);

graph* createGraph(int V)
{
    graph* temp= new graph;

    temp->V = V;
    temp->list = new vertex[V];

    for (int i = 0; i < V ; i++)
    {   
        temp->list[i].head = NULL;
        temp->list[i].visited = false;
    }
    return temp;
} 

graph* insert(graph* Graph, int index, int value)
{

    if (Graph->list[index].head == NULL){
        Graph->list[index].head = createNode(value);
        return Graph; }
/*
*    //auto-sorting insertion
*    //only problem 
*    //in case of using autosorting, largest node must be inserted first
*    
*    Node* temp = Graph->list[index].head;
*        //make temp pointer point on a smaller node than data is available
*        while(temp->data < value)
*        {
*            temp = temp ->next;
*        }
*        if (temp->data > value)
*        {   
*            Node* temp2 = createNode(value);
*            temp2->next = temp->next;
*            temp->next = temp2;
*            int A = temp->data;
*            temp->data = temp2->data;
*            temp2->data = A;
*       }
*      if (temp->data < value)
*      {
*         Node* temp2 = createNode(value);
*            temp2->next = temp->next;
*            temp->next = temp2;
*      } 
*/

    Node* temp = Graph->list[index].head;
        //let the temp pointer point at last of the list
        while(temp->next != NULL)
        {
            temp = temp ->next;
        }
        Node* temp2 = createNode(value);
        temp2->next = temp->next;
        temp->next = temp2;

    //for undirected graph
    //temp = Graph->list[value].head;
    //   while(temp->next != NULL)
    //   {
    //       temp = temp ->next;
    //   }
    //temp2 = createNode(index);
    //temp2->next = temp->next;
    //temp->next = temp2;
    return Graph;
}

void Traverse(graph *head)
{
    int V= head->V;
    for (int i = 0; i < V; i++)
    {
        printf("\tAt vertex %d :\n\t\t",i);
            Node *temp = head->list[i].head;
            if(temp != NULL)    
            {   while(temp->next!=NULL)
                {
                    printf("->%d",temp->data);
                    temp=temp->next;
                }
                printf("->%d\n",temp->data); //printing the last node 
            }
            else
                printf("No Edges\n");
    }  
}


Node* createNode(int data)
{
    Node *temp= new Node;
    //check if pointer is null
    if (temp == NULL)
    {
      fprintf(stderr,"Error: memory allocation failed.\n");
      exit(1);
    }

    temp->data=data;
    temp->next=NULL;
    return temp; //returns a pointer to a node with data and NUll pointer
}