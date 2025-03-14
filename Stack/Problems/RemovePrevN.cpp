
void RemovePrevN(LinkedQueue<int>& Q)
{
	ArrayStack<int> s;
	int x;
	while (Q.dequeue(x))
	{
		if (x >= 0)
		{
			s.push(x);
		}
		else
		{
			int n = -x;
			for(int i = 0 ; i < n; i++)
			{
				if(!s.isEmpty())
				{
					s.pop(x);
				}
				else
				{
					break;
				}
			}
		}
	}

	ArrayStack<int> temp;
	while (s.pop(x))
	{
		temp.push(x);
	}

	while(temp.pop(x))
	{
		Q.enqueue(x);
	}

}