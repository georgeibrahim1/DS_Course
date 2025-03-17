template<typename T>
T BinarySearchTree<T>::findMinimumHelper(BinaryNode<T>* subtreePtr)
{
	if (!subtreePtr->getLeftChildPtr())
		return subtreePtr->getItem();
	T temp = findMinimum(subtreePtr->getLeftChildPtr());
}

template<typename T>
T BinarySearchTree<T>::findMaximumHelper(BinaryNode<T>* subtreePtr)
{
	if (!subtreePtr->getRightChildPtr())
		return subtreePtr->getItem();
	T temp = findMaximum(subtreePtr->getRightChildPtr());
}