#include "ll.h"



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

    Traverse(Graph);
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