
int rec_Num_Less_than_a_node(Node* subRoot , int value)
{
	if (!subRoot)
	{
		return 0;
	}

	if(subRoot->getdata() >= value)
	{
		return rec_Num_Less_than_a_node(subRoot->getleft() , value);
	}
	else
	{
		return 1 + rec_Num_Less_than_a_node(subRoot->getright(), value) + rec_Num_Less_than_a_node(subRoot->getleft(), value);
	}
}