void Concat(LinkedQueue<int> Q1, LinkedQueue<int> Q2, LinkedQueue<int>& Q3)
{
	int x;
	while (Q1.dequeue(x))
		Q3.enqueue(x);
	while (Q2.dequeue(x))
		Q3.enqueue(x);
}