#include <iostream>
using namespace std;
 
class Node
{
public:
   Node(int d) { data = d; next = NULL; }
   Node(int d, Node *n) { data = d; next = n; }
   int data;
   Node *next;
};

void insertBefore(Node **head, int n)
{
   Node* newNode = new Node(n, *head);
   (*head) = newNode;
}

void insertAfter(Node **head, int n)
{
    Node *newNode = new Node(n);
    Node *lastNode = *head;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while (lastNode->next != NULL)
        lastNode = lastNode->next;
    lastNode->next = newNode;
}

void displayList(Node *node)
{
   while (node != NULL)
   {
      cout << node->data <<"-->";
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
