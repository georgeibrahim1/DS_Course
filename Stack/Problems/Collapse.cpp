void collapse(Arraystack<int>& s)
{
	int x1;
	int x2;
	Arraystack<int> temp;
	while(s.pop(x1))
	{
		if (!s.IsEmpty())
		{
			s.pop(x2);
			temp.push(x1+x2);
		}
		else
		{
			temp.push(x1);
		}
	}
	int x;
	while (temp.pop(x))
	{
		s.push(x);
	}
}