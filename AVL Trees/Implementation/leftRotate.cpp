template<typename T>
inline BinaryNode<T>* AVLTree<T>::leftRotate(BinaryNode<T>* currentRoot)
{
    BinaryNode<T>* newRoot = currentRoot->getRightChild();

    currentRoot->setRightChild(newRoot->getLeftChild());
    newRoot->setLeftChild(root);

    // Update heights
    currentRoot->setHeight(getHeightHelper(root));
    newRoot->setHeight(getHeightHelper(newRoot));

    if (currentRoot = rootPtr)
        rootPtr = newRoot;

    return newRoot;
}