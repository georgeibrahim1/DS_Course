

void deletes_duplicates_from_sorted(LinkedQueue<int>& Q)
{
	int x;
	int y;

	if(!Q.dequeue(y)) return ;

	Arraystack<int> s;

	while (Q.dequeue(x))
	{
		if (y != x)
		{
			s.push(x);
			y = x;
		}
		
	}

	Arraystack<int> temp;

	while (s.pop(x))
	{
		temp.push(x);
	}

	while(temp.pop(x))
	{
		Q.enqueue(x);
	}

}