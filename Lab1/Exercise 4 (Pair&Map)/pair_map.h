#pragma once

#include<iostream>
using namespace std;

template<class T , class U>
class mypair
{
private:
	T key;
	U value;

public:
	mypair()
	{

	}
	mypair(T k , U v) : key(k) , value(v)
	{

	}

	void setPair(T key , U value)
	{
		this->key = key;
		this->value = value;
	}

	T getKey()
	{
		return key;
	}

	U getValue()
	{
		return value;
	}

	bool operator==(const mypair& other)
	{
		return ((this->key == key) && (this->value == value));
	}

};


template<class T , class U>
class myMap
{
private:
	mypair<T, U> Set_of_Pairs[100];
	int Count;

public:
	myMap()
	{
		Count = 0;
	}

	bool addPair(T key , U value)
	{
		if(Count == 100)
		{
			return false;
		}
		else
		{
			Set_of_Pairs[Count++] = mypair<T, U>(key,value);
			return true;
		}
	}

	U getValue(T key)
	{
		for(int i = 0 ; i < Count ;i++)
		{
			if (key == Set_of_Pairs[i].getKey())
			{
				return Set_of_Pairs[i].getValue();
			}
		}
	}

	bool updateValue(T key ,U value)
	{
		for (int i = 0; i < Count; i++)
		{
			if (key == Set_of_Pairs[i].getKey())
			{
				Set_of_Pairs[i].setPair(key , value);
				return true;
			}
		}
		return false;
	}

	void displayMap()
	{
		for(int i = 0 ; i < Count ; i++)
		{
			cout << "(" << Set_of_Pairs[i].getKey() << "," << Set_of_Pairs[i].getValue() << ")" << endl;
		}
	}

	bool deletePair(T key)
	{
		for (int i = 0; i < Count; i++)
		{
			if (key == Set_of_Pairs[i].getKey())
			{
				for(int j = i ; j < Count - 1 ; j++) //Shifting to left
				{
					Set_of_Pairs[j] = Set_of_Pairs[j + 1];
				}
				//Set_of_Pairs[Count - 1] = null; //Last element
				Count--;
				return true;
			}
		}
		return false;
	}


};