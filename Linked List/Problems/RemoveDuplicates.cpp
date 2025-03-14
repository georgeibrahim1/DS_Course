

void removedublicates(linkedlist* head)
{
	linkedlist* current = head;
	while (current->next != NULL)
	{
		if (current->data == current->next->data)
		{
			linkedlist* temp = current->next;
			current->next = current->next->next;
			delete temp;
		}
		else
		{
			current = current->next;
		}
	}
}