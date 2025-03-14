void removeFirstZeros(LinkedQueue<int>& Q) //pass by ref
{
	int x;
	while (Q.peek(x))	//Have a look first before dequeuing it
		if (x != 0)	//if item is not zero, don't dequeue and end the function
			return;
		else
			Q.dequeue(x);	//it is a zero ==> dequeue it
}