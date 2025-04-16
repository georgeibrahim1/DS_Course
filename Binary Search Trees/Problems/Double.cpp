void rec_double(Node* subRoot)
{
	if (!subRoot)
	{
		return;
	}

	rec_double(subRoot->getleft());
	subRoot->setdata(subRoot->getdata() * 2);
	rec_double(subRoot->getright());
}