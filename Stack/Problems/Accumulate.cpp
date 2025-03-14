

void Accumulate(LinkedQueue<int>& input)
{
	ArrayStack<int> s;
	int x;
	int n = 0;
	while (input.dequeue(x))
	{
		if (x >= 0)
		{
			s.push(x + n);
			s.peek(n);
		}
		else
		{

			int c = -x;
			int a = 0;
			ArrayStack<int> l;
			for (int i = 0; i < c; i++)
			{
				if (!s.isEmpty())
				{
					int o;
					s.peek(o);
					l.push(o);
					s.pop(x);
					s.peek(n);
					a++;
				}
				else
				{
					break;
				}
			}

			if (a != c)
			{
				while (l.pop(x))
				{
					s.push(x);
					s.peek(n);
				}
			}
		}
	}
	ArrayStack<int> temp;
	while (s.pop(x))
	{
		temp.push(x);
	}

	while (temp.pop(x))
	{
		input.enqueue(x);
	}
}