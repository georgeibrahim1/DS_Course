template<class T>
inline BinaryNode<T>* AVLTree<T>::insert(BinaryNode<T>* subTreePtr, T target)
{
    // First perform normal BST insertion
    if (subTreePtr == nullptr)
        subTreePtr = new BinaryNode<T>(target);
    else if (target < subTreePtr->getItem())
        subTreePtr->setLeftChild(insert(subTreePtr->getLeftChild(), target));
    else
        subTreePtr->setRightChild(insert(subTreePtr->getRightChild(), target));

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