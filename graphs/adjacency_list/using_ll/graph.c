#include "ll.h"



int main(void)
{
    int v = 4;

    graph* Graph = createGraph(v);
    //only problem 
    //  in case of using autosorting, largest node must be inserted first
    insert(Graph, 0, 50);
    insert(Graph, 0, 40);
    insert(Graph, 0, 45);
    insert(Graph, 0, 40);
    insert(Graph, 2, 30);
    insert(Graph, 2, 20);

    Traverse(Graph);
    return 0;
}

/*
output 

at index 0 :-  
    ->1->5

*/