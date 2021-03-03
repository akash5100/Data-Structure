#include "ll.h"

int main(void)
{
    Node* head = createNode(45);
    insert(30,head);
    insert(35,head);
    Traverse(head);
    return 0;
}