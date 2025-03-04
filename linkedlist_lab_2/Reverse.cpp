void Reverse()
{
	if (head == nullptr)
	{
		return;
	}

	if (head->next == nullptr)
	{
		return;
	}

	Node<T>* prev , curr , next;

	prev = nullptr;
	curr = head;
	next = head;

	while(curr != nullptr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	head = prev;
}