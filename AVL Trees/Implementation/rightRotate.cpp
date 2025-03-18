template<typename T>
BinaryNode<T>* AVLTree<T>::rightRotate(BinaryNode<T>* currentRoot)
{
    BinaryNode<T>* newRoot = currentRoot->getLeftChild();

    currentRoot->setLeftChild(newRoot->getRightChild());
    newRoot->setRightChild(currentRoot);

    // Update heights
    currentRoot->setHeight(getHeightHelper(root));
    newRoot->setHeight(getHeightHelper(newRoot));

    if (currentRoot == rootPtr)
        rootPtr = newRoot;

    return newRoot;
}