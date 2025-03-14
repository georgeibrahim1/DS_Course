

void delNegative(ArrayStack<int> & S)
{
	ArrayStack<int> temp;	//First create a temp stack 
	int item;
	while (S.pop(item))	//pop from S
		if(item>=0)
			temp.push(item); //push into temp
	
	//Now temp contains non-negative items only but S is empty
	while (temp.pop(item))	//pop from temp
		S.push(item); //push into S
}


