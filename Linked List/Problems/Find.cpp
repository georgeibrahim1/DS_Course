

bool find(T value)
{
	Node<T>* temp = head;
	while (temp != NULL)
	{
		if (temp->data == value)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}
