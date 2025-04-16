//Write a function PrintSmallerEq(int x) that outputs, in ascending order of keys,
//all elements in a BST whose keys are smaller than or equal to x and returns true.
//if there were no smaller keys than x then return false

bool PrintSmallerEq(int x)
{

}

bool rec_PrintSmallerEq(Node* subRoot, int x)
{
	if(!subRoot)
	{
		return false;
	}

	bool found = rec_PrintSmallerEq(subRoot->getleft(), x);

	if(subRoot->getdata() <= x)
	{
		cout << subRoot->getdata() << " ";
		found = true;

		found = rec_PrintSmallerEq(subRoot->getright(), x);
	}

	return found;
}