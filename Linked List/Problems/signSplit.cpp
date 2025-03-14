void signSplit(Node<T>* L , Node<T>* L1 , Node<T>* L2 )
{
	//l1 is the list of negative numbers
	//l2 is the list of positive numbers

	L1 = nullptr;
	L2 = nullptr;

	if(L == nullptr)
	{
		return;
	}

	Node<T>* temp = L;

	//set the heads of l1 , l2
	while(temp && (!L1 || !L2) )
	{
		if (temp->data < 0 && !L1)
		{
			L1 = temp;
			temp = temp->next;
		}
		else if (temp->data > 0 && !L2)
		{
			L2 = temp;
			temp = temp->next;
		}
		else
		{
			temp = temp->next;
		}
	}

	while(temp)
	{
		if (temp->data < 0)
		{
			L1 = temp;
		}
		else if(temp->data > 0)
		{
			L2 = temp;
		}

		temp = temp->next;
	}

}