#include<iostream>
using namespace std;

void InsertEnd(T data)
{
	Node<T>* newPtr = new Node<T>(data);


	if (!Head)
	{
		Head = newPtr;
		return;
	}

	Node<T>* Ptr = Head;
	while (Ptr->getNext())
	{
		Ptr = Ptr->getNext();
	}
	Ptr->setNext(newPtr);


}