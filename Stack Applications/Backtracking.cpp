#include <iostream>
using namespace std;

/*
Firstly , we will define the map , thre map contain nodes , each node must have a value , top pointer , bottom pointer , and a branching flag
*/

template <class T>
class Node
{
public:
    T value;
    Node *top;
    Node *bottom;
    bool branch;
    Node(T value)
    {
        this->value = value;
        this->top = NULL;
        this->bottom = NULL;
        this->branch = false;
    }
};

/*
We will define the map of the nodes with some functions
*/

template <class T>
class Map
{
public:
    Node<T> *root;
    Map()
    {
        root = NULL;
    }

    void add(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            Node<T> *temp = root;
            while (temp->bottom != NULL)
            {
                temp = temp->bottom;
            }
            temp->bottom = newNode;
            newNode->top = temp;
        }
    }

    void addBranch(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            Node<T> *temp = root;
            while (temp->bottom != NULL)
            {
                temp = temp->bottom;
            }
            temp->bottom = newNode;
            newNode->top = temp;
            newNode->branch = true;
        }
    }

    void remove()
    {
        if (root == NULL)
        {
            cout << "Map is empty" << endl;
        }
        else
        {
            Node<T> *temp = root;
            while (temp->bottom != NULL)
            {
                temp = temp->bottom;
            }
            if (temp->top != NULL)
            {
                temp->top->bottom = NULL;
            }
            else
            {
                root = NULL;
            }
            delete temp;
        }
    }

    void removeBranch()
    {
        if (root == NULL)
        {
            cout << "Map is empty" << endl;
        }
        else
        {
            Node<T> *temp = root;
            while (temp->bottom != NULL)
            {
                temp = temp->bottom;
            }
            if (temp->top != NULL)
            {
                temp->top->bottom = NULL;
            }
            else
            {
                root = NULL;
            }
            delete temp;
        }
    }

    void print()
    {
        printHelper(root, 0);
    }

private:
    void printHelper(Node<T> *node, int depth)
    {
        if (node == NULL)
            return;

        for (int i = 0; i < depth; ++i)
        {
            cout << "  ";
        }
        cout << node->value << (node->branch ? " (branch)" : "") << endl;

        printHelper(node->bottom, depth + 1);
    }
};


int main()
{
    Map<int> map;
    map.add(1);
    map.add(2);
    map.addBranch(3);
    map.add(4);
    map.addBranch(5);
    map.add(6);

    map.print();


    return 0;
}