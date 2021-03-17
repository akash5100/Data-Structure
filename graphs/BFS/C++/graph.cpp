#include "ll.h"
#include <queue>

void bfs(graph* g, int i)
{
        queue<int> q;
        q.push(i);
        int index = q.front(), temp_index;
        graph* t = g;
        t->list[index].visited = true;
        printf("%d\n",index); //1st vertex
        q.pop();
        Node* temp = g->list[index].head;
        while (temp->next != NULL)
        {
            temp_index = temp->data;
            t->list[temp_index].visited = true;
            q.push(temp->data);
            temp = temp->next;
        }
        
        for(int j=0; j < g->V; j++)
        {
                index = q.front();
                if (t->list[index].visited == false)
                {
                        t->list[index].visited = true;
                        printf("%d\n",index); //rest vertex        
                }
                Node* temp = g->list[index].head;
                while (temp->next != NULL)
                {
                        temp_index = temp->data;
                        if (t->list[temp_index].visited == false)
                        {
                                t->list[temp_index].visited = true;
                                q.push(temp->data);    
                        }
                        temp = temp->next;
                }
                q.pop();

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