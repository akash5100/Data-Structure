#include "ll.h"

int main(void)
{
    Node* head = createNode(50);
    insert(30,head);
    insert(35,head);
    insert(40,head);
    DELETE(35,head);
    insert(10,head);
    insert(35,head);
    insert(45,head);

    Traverse(head);
    return 0;
}