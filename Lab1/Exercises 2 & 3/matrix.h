#include<iostream>
using namespace std;



template<typename T>
class matrix
{
private:
	T Matrix[2][3];
public:
	void AddValue(int rowI, int colI, T value)
	{
		Matrix[rowI][colI] = value;
	}

	bool BelongTo(T value)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (Matrix[i][j] == value)
				{
					return true;
				}
			}
		}

		return false;
	}

	void PrintRow(int rowI)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << Matrix[rowI][i] << " ";
		}
	}

	void Print()
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << Matrix[i][j] << " ";
			}

			cout << endl;
		}
	}


	T MaxValue()
	{
		T max = Matrix[0][0];

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (Matrix[i][j] > max)
				{
					max = Matrix[i][j];
				}
			}
		}
		return max;
	}

	

};




