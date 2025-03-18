template<typename T>
inline BinaryNode<T>* AVLTree<T>::removeValue(BinaryNode<T>* subTreePtr, const T& target, bool& success)
{
    if (subTreePtr == nullptr)
        return nullptr;
    else if (target < subTreePtr->getItem())
        subTreePtr->setLeftChild(removeValue(subTreePtr->getLeftChild(), target, success));
    else if (target > rootPtr->getItem())
        subTreePtr->setRightChild(removeValue(subTreePtr->getRightChild(), target, success));

    else // target is found 
    {
        if (subTreePtr->getLeftChild() == nullptr)
        {
            BinaryNode<T>* temp = subTreePtr->getRightChild();
            delete subTreePtr;
            return temp;
        }

        else if (subTreePtr->getRightChild() == nullptr)
        {
            BinaryNode<T>* temp = subTreePtr->getLeftChild();
            delete subTreePtr;
            return temp;
        }

        else // find min in the right subtree (in left subtree of it)
        {
            success = true;

            BinaryNode<T>* current = subTreePtr->getRightChild();
            T newItem = current->getItem();

            while (current->getLeftChild())
                current = current->getLeftChild();
            subTreePtr->setItem(newItem);
            subTreePtr->setRightChild(removeValue(rootPtr->getRightChild(), newItem, success));
        }
    }
    return subTreePtr;

    // Update the height 
    subTreePtr->setHeight(getHeightHelper(subTreePtr));

    // Check the balance factor after insertion
    int balance = getBalanceFactor(subTreePtr);

    if (balance > 1) // Left heavy
    {
        int childBalance = getBalanceFactor(subTreePtr->getLeftChild());

        if (childBalance < 0)
            subTreePtr->setLeftChild(leftRotate(subTreePtr)); // right of left 
        return rightRotate(subTreePtr); // left of left 
    }

    if (balance < -1) // right heavy
    {
        int childBalance = getBalanceFactor(subTreePtr->getRightChild());

        if (childBalance > 0)
            subTreePtr->setRightChild(rightRotate(subTreePtr)); // left of right
        return leftRotate(subTreePtr); // right of right 
    }

    return subTreePtr;
}