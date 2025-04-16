template<typename T>
inline BinaryNode<T>* BinarySearchTree<T>::removeValue(BinaryNode<T>* rootPtr, const T& target, bool& success)
{
    if (rootPtr == nullptr)
        return nullptr;
    else if (target < rootPtr->getItem())
        rootPtr->setLeft(removeValue(rootPtr->getLeftChild(), target, success));
    else if (target > rootPtr->getItem())
        rootPtr->setRight(removeValue(rootPtr->getRightChild(), target, success));

    else // target is found 
    {
        if (rootPtr->getLeftChild() == nullptr) //leaf
        {
            BinaryNode<T>* temp = rootPtr->getRightChild();
            delete rootPtr;
            return temp;
        }

        else if (rootPtr->getRightChild() == nullptr) //leaf
        {
            BinaryNode<T>* temp = rootPtr->getLeftChild();
            delete rootPtr;
            return temp;
        }

        //not leaf
		//You can choose to find the max in the left subtree or the min in the right subtree
        //else
   //     {
			//// find max in the left subtree (in right subtree of it)
			//BinaryNode<T>* current = rootPtr->getLeftChild();
			//T newItem = current->getItem();

			//while (current->getRightChild())
			//	current = current->getRightChild();

			//rootPtr->setItem(newItem);
			//rootPtr->setLeft(removeValue(rootPtr->getLeftChild(), newItem, success));
   //     }
        else // find min in the right subtree (in left subtree of it)
        {
            success = true;

            BinaryNode<T>* current = rootPtr->getRightChild();
            T newItem = current->getItem();

            while (current->getLeftChild())
                current = current->getLeftChild();

            rootPtr->setItem(newItem);
            rootPtr->setRight(removeValue(rootPtr->getRightChild(), newItem, success));
        }
    }
    return rootPtr;
}