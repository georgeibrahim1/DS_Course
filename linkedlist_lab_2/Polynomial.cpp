#include<iostream>
using namespace std;

template<typename T> 
class Node
{
public:
	T item;
	T* next;
};

class Term
{
public:
	double coffecient;
	int power;
};

class Polynomial
{
	Node<Term>* head;
	int degree;

public:
	polynomial()
	{
		head = nullptr;
		degree = 0;
	}

	void AddTerm(const& Term T)
	{
		if (head == nullptr)
		{
			head = new Node<Term>;
			head->item = T;
			head->next = nullptr;
			degree = T.power;
		}
		
		if(head->next == nullptr)
		{
			if(degree > T.power)
			{
				head->next = new Node<Term>;
				head->next->item = T;
				head->next->next = nullptr;
			}
			else if (degree == T.power)
			{
				head->item.coffecient += T.coffecient;
			}
			else
			{
				Node<Term>* temp = new Node<Term>;
				temp->item = T;
				temp->next = head;
				head = temp;
			}
		}

		//It is like InsertSorted but with descending order
		Node<Term>* prev = head;
		Node<Term>* curr = head->next;

		while ()
		{
			if(prev && curr->nex )
			{

			}

		}

	}

	void PrintPoly()
	{
		Node<Term>* temp = head;
		while (temp != nullptr)
		{
			cout << temp->item.coffecient << "x^" << temp->item.power << " + ";
			temp = temp->next;
		}
		cout << endl;
	}




};