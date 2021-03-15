#include "ll.h"



int main(void)
{
    int v = 4;

    graph* Graph = createGraph(v);
    //only problem 
    //  in case of using autosorting, largest node must be inserted first
    insert(Graph, 0, 4);
    insert(Graph, 0, 1);
    insert(Graph, 1, 4);
    insert(Graph, 1, 3);
    insert(Graph, 1, 2);
    insert(Graph, 2, 4);
    insert(Graph, 3, 3);

    Traverse(Graph);
    return 0;
}

/*
output 

    At vertex 0 :
            ->1->4
    At vertex 1 :
            ->2->3->4
    At vertex 2 :
            ->4
    At vertex 3 :
            ->3

*/