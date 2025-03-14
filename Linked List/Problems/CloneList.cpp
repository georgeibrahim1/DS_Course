Linkedlist CloneList(const Linkedlist& L1)
{
	Linkedlist L2;
	L2.head = nullptr;

	if(L1.head == nullptr) //if l1 is empty
	{
		return L2;
	}

	//clone the first node to make the head of L2
	L2.head = new Node<T>;
	L2.head->data = L1.head->data;
	L2.head->next = nullptr;

	Node<T>* temp1 = L1.head->next;
	Node<T>* temp2 = L2.head;

	while (temp1)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = temp1->data;
		newNode->next = nullptr;
		temp2->next = newNode;
		temp2 = temp2->next;
		temp1 = temp1->next;
	}

	return L2;
}