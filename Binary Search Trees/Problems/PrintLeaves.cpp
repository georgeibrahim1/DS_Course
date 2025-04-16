
void rec_PrintLeaves(Node* subRoot)
{
	if(!subRoot)
	{
		return;
	}

	rec_PrintLeaves(subRoot->getleft());
	if(subRoot->getleft() == nullptr && subRoot->getright() == nullptr) // add ! to this -> Print Parents
	{
		cout << subRoot->getdata();
	}
	rec_PrintLeaves(subRoot->getright());
}