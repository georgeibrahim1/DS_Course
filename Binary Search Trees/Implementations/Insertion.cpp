template<typename T>
BinaryNode<T>* BinarySearchTree<T>::insertInorder(BinaryNode<T>* subTreePtr, T target)
{
    if (subTreePtr == nullptr)
        subTreePtr = new BinaryNode<T>(target);
    else if (target < subTreePtr->getItem())
        subTreePtr->setLeft(insertInorder(subTreePtr->getLeftChild(), target));
    else
        subTreePtr->setRight(insertInorder(subTreePtr->getRightChild(), target));

    return subTreePtr;
}

