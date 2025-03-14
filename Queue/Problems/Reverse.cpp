void Reverse1(LinkedQueue<int>& input)
{
	ArrayStack<int> S;
	int x;
	while (!input.isEmpty())
	{
		input.dequeue(x);
		S.push(x);
	}
	while (!S.isEmpty())
	{
		S.pop(x);
		input.enqueue(x);
	}
}


void Reverse2(LinkedQueue<int>& input)
{
	ArrayStack<int> S;
	int x;
	while (input.dequeue(x))
		S.push(x);

	while (S.pop(x))
		input.enqueue(x);
}