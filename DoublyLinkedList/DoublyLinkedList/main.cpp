#include <iostream>
using namespace std;
 
struct Node
{
   int data;
   struct Node *next;
   Node *prev;
};

void insertBefore(Node **head, int n)
{
   struct Node* newNode = new Node;
   newNode->data = n;
   newNode->next = (*head);
   newNode->prev = NULL;
   (*head) = newNode;
}

void insertAfter(Node **head, int n)
{
    struct Node *newNode = new Node;
    struct Node *lastNode = *head;
    newNode->data = n;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while (lastNode->next != NULL)
        lastNode = lastNode->next;
    lastNode->next = newNode;
}

void displayList(struct Node *node)
{
   while (node != NULL)
   {
      cout<<node->data<<"-->";
      node = node->next;
   }
   printf("NULL\n");
}

int main()
{
    Node *head = NULL;
    insertAfter(&head, 10);
    insertBefore(&head, 20);
    insertBefore(&head, 30);
    insertAfter(&head, 50);
    displayList(head);
    return 0;
}
