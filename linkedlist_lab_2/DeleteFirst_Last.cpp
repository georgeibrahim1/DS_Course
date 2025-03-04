void DeleteFirst()
{
	if (head == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		Node* temp = head;
		head = head->next;
		temp = NULL;
	}

}

void DeleteLast()
{
	if(head == nullptr)
	{
		return;
	}

	while (head->next == nullptr) //if one node
	{
		delete head;
		head = nullptr;
		return;
	}

	Node<T>* setToNull = head;
	while (setToNull->next->next != nullptr) //It stops on the node that is before the last node
	{
		setToNull = setToNull->next;
	}

	Node<T>* nodetobedeleted = setToNull->next ;
	delete nodetobedeleted;
	setToNull->next = nullptr;
}