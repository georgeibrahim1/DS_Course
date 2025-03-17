template<typename T>
inline BinaryNode<T*> BinarySearchTree<T>::search(BinaryNode<T>* subtreePtr, const T& target)
{
	if (!subtreePtr)
		return nullptr;

	if (subtreePtr->getItem() == target)
		return subtreePtr;
	if (subtreePtr->getItem() < target)
		return search(subtreePtr->getRightChildPtr(), target);
	else
		return search(subtreePtr->getLeftChildPtr(), target);
}