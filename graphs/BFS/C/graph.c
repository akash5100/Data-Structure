#include "ll.h"
#include "queue.h"

void bfs(graph* g, int i)
{
        queue* q = create_queue();
        enqueue(q,i);
        int index = front(q), temp_index;
        dequeue(&q);
        graph* t = g;

        t->list[index].visited = true;
        Node* temp = g->list[index].head;
        while (temp->next != NULL)
        {
            temp_index = temp->data;
            t->list[temp_index].visited = true;
            enqueue(q,temp->data);
            temp = temp->next;
        }
        
        for(int j=0; j < g->V; j++)
        {
                index = front(q);
                if (t->list[index].visited == false)
                {
                        t->list[index].visited = true;        
                }
                Node* temp = g->list[index].head;
                while (temp->next != NULL)
                {
                        temp_index = temp->data;
                        if (t->list[temp_index].visited == false)
                        {
                                t->list[temp_index].visited = true;
                                enqueue(q,temp->data);    
                        }
                        temp = temp->next;
                }
                dequeue(&q);

        }
}

int main(void)
{
    int v = 5;

    graph* Graph = createGraph(v);
    
    insert(Graph, 0, 1);
    insert(Graph, 0, 2);
    insert(Graph, 1, 0);
    insert(Graph, 1, 2);
    insert(Graph, 1, 3);
    insert(Graph, 2, 0);
    insert(Graph, 2, 1);
    insert(Graph, 2, 4);
    insert(Graph, 3, 1);
    insert(Graph, 3, 4);
    insert(Graph, 4, 2);
    insert(Graph, 4, 3);

    //Traverse(Graph);
    printf("\n\n");
    bfs(Graph, 0);
    return 0;
}

/*
output :-

        At vertex 0 :
                ->1->2
        At vertex 1 :
                ->0->2->3
        At vertex 2 :
                ->0->1->4
        At vertex 3 :
                ->1->4
        At vertex 4 :
                ->2->3

*/