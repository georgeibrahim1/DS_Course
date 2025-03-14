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