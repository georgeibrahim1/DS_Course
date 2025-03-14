

bool general_palindrome(string shit)
{
	Arraystack<char> s;

	int sizeofstack = shit.length();

	for(int i = 0 ; i < shit.length() ; i++)
	{
		if (islower(shit[i]))
		{
			s.push(shit[i]);
		}
		else if (iscapital(shit[i]))
		{
			s.push(tolower(shit[i]));
		}
		else
		{
			sizeofstack--;
		}
	}

	Arraystack<char> s1;
	Arraystack<char> s2;

	int x1;
	for (int = 0 ; i < sizeofstack / 2 ;i++)
	{
		s.pop(x1);
		s1.push(x1);
	}

	if (sizeofstack % 2 != 0)
	{
		s.pop(x1);
	}

	int x2;
	for (int = 0; i < sizeofstack / 2; i++)
	{
		
		s.pop(x2);
		s1.push(x2);
	}

	int a, b;
	while (s1.pop(a) || s2.pop(b) ) // they must be in the same size here
	{
		if (a != b)
		{
			return false;
		}
	}

	return true;

}