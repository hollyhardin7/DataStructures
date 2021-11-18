#include <iostream>

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *parent;
    Node(int v);
};

Node::Node(int v)
{
public:
    val = v;
    left = NULL;
    right = NULL;
    parent = NULL;
}

class BinarySearchTree
{
public:
    Node *root;
    BinarySearchTree() { root = NULL; }
    void insert(Node *n);
    void inorder(Node *n);
    Node* search(Node *n, int v);
    Node* min(Node *n);
    Node* max(Node *n);
    Node* successor(Node *n);
    Node* predecessor(Node *n);
    void transplant(Node *t1, Node *t2);
    void deleteTree(Node *n);
};

void BinarySearchTree::insert(Node *newNode)
{
    Node *parent = NULL;
    Node *currentNode = root;
    while (currentNode != NULL)
    {
        parent = currentNode;
        if (newNode->val < currentNode->val)
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;
    }
    newNode->parent = parent;
    if (parent == NULL)
        root = newNode;
    else if (newNode->val < parent->val)
        parent->left = newNode;
    else
        parent->right = newNode;
}

void BinarySearchTree::inorder(Node *n)
{
    if (n != NULL)
    {
        inorder(n->left);
        printf("%d\n", n->val);
        inorder(n->right);
    }
}

Node* BinarySearchTree::search(Node *n, int v)
{
    while (n != NULL && v != n->val)
    {
        if (v < n->val)
            n = n->left;
        else
            n = n->right;
    }
    return n;
}

Node* BinarySearchTree::min(Node *n)
{
    while (n->left != NULL)
        n = n->left;
    return n;
}

Node* BinarySearchTree::max(Node *n)
{
    while (n->right != NULL)
        n = n->right;
    return n;
}

Node* BinarySearchTree::successor(Node *n)
{
    if (n->right != NULL)
        return min(n->right);
    
    Node *currentNode = n->parent;
    while (currentNode != NULL && currentNode->right == n)
    {
        n = currentNode;
        currentNode = currentNode->parent;
    }
    return currentNode;
}

Node* BinarySearchTree::predecessor(Node *n)
{
    if (n->left != NULL)
        return max(n->left);
    
    Node *currentNode = n->parent;
    while (currentNode != NULL && currentNode->left == n)
    {
        n = currentNode;
        currentNode = currentNode->parent;
    }
    return currentNode;
}

void BinarySearchTree::transplant(Node *firstSubtree, Node *secondSubtree)
{
    if (firstSubtree->parent == NULL)
        root = secondSubtree;
    else if (firstSubtree == firstSubtree->parent->left)
        firstSubtree->parent->left = secondSubtree;
    else
        firstSubtree->parent->right = secondSubtree;
    
    if (secondSubtree != NULL)
        secondSubtree->parent = firstSubtree->parent;
}

void BinarySearchTree::deleteTree(Node *n)
{
    if (n->left == NULL)
        transplant(n, n->right);
    else if (n->right == NULL)
        transplant(n, n->left);
    else
    {
        Node *successor = min(n->right);
        if (successor->parent != n)
        {
            transplant(successor, successor->right);
            successor->right = n->right;
            successor->right->parent = successor;
        }
        transplant(n, successor);
        successor->left = n->left;
        successor->left->parent = successor;
    }
}

int main(int argc, const char * argv[])
{
    BinarySearchTree bst;
    for (int i = 5; i < 11; i++)
    {
        Node *temp = new Node(i);
        bst.insert(temp);
    }
    for (int i = 0; i < 5; i++)
    {
        Node *temp = new Node(i);
        bst.insert(temp);
    }
    bst.inorder(bst.root);
    bst.deleteTree(bst.root->right);
    bst.inorder(bst.root);
    
    return 0;
}
