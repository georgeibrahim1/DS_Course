/*bool DeleteNode(T data)
		{
			Node<T>* Ptr = nullptr;
			Node<T>* Prev = nullptr;
			bool flag = false;

			if (!Head)
			{
				return false;
			}

			while ( Head && Head->getItem() == data)
			{
				Head = Head->getNext();
				flag = true;
			}

			if (Head)
			{
				Ptr = Head;
				Prev = Head;
			}

			while(Ptr && Prev)
			{
				if (Ptr->getItem() == data)
				{
					Node<T>* nodeTobedeleted = Ptr;
					Prev->setNext(Ptr->getNext());
					Ptr = Ptr->getNext();
					delete nodeTobedeleted;
					flag = true;
				}
				else
				{
					Prev = Ptr;
					Ptr = Ptr->getNext();
				}
			}

			return flag;
		}*/
}