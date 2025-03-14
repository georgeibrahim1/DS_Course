int CountOccurance(T value)
{
	Node* <T> temp = head;
	int count = 0;
	while (temp != NULL)
	{
		if (temp->data == value)
		{
			count++;
		}
		temp = temp->next;
	}
	return count;
}