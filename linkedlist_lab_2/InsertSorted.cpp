#include<iostream>
using namespace std;


//Assume it is a ascending order
//and The value of the new node doen't exist in the list
void InsertSorted(Node<T>* newNode)
{

	if (head == nullptr)
	{
		head = newNode;
		newNode->next = nullptr;
		return;
	}

	if(head->next == nullptr)
	{
		if (head->item < newNode->item)
		{
			newNode->next = head;
			head = newNode;
			return;
		}
		else if (head->item > newNode->item)
		{
			head->next = newNode;
			newNode->next = nullptr;
			return;
		}
		else
		{
			return;
		}
	}

	Node<T>* Prev = head;
	Node<T>* Curr = head->next;

	while (Curr != nullptr)
	{
		if(Prev->item < newNode->item && newNode->item < Curr->item)
		{
			Prev->next = newNode;
			newNode->next = Curr;
			return;
		}

		Prev = curr;
		curr = curr->next;
	}

	if (Curr == nullptr)
	{
		Prev->next = newNode;
		newNode->next = nullptr;
		return;
	}
}