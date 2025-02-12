#include <iostream>
#include "matrix.h"

using namespace std;


// Class Template Specialization --> Would be useless , we don't need to change all the functions of the class matrix
// Inheritance --> why we need to inherit date from matrix? no relaion
// Operator oveloading --> I think it is the best one , we will make the operators = , < , ...

// I would make a mix between inheritance & Operators Overloading
class Date
{
public:
    int day;
    int month;
    int year;

    Date(int d = 0, int m = 0, int year = 0) : day(d), month(m), year(year)
    {

    }

    bool operator>(Date& o)
    {
        if (year > o.year) {
            return true;
        }
        else if (year == o.year)
        {
            if (month > o.month)
            {
                return true;
            }
            else if (month = o.month)
            {
                if (day > o.day)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    Date& operator=(const Date& other)
    {
        if (this != &other)
        {
            day = other.day;
            month = other.month;
            year = other.year;
        }

        return *this;
    }

    bool operator==(const Date& other) const {
        return (day == other.day) && (month == other.month) && (year == other.year);
    }

};

ostream& operator<<(ostream& os, const Date& date) {
    os << date.day << "/" << date.month << "/" << date.year;
    return os;
}


int main()
{
    matrix<int> IntMatrix;

    for(int i = 0 ; i < 2 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            IntMatrix.AddValue(i,j,2);
        }
    }

    matrix<double> DoubleMatrix;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            DoubleMatrix.AddValue(i, j, 3.3);
        }
    }

    matrix<string> StringMatrix;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            StringMatrix.AddValue(i, j, "-");
        }
    }

    int rowI = 0;
    IntMatrix.PrintRow(rowI);
    cout << endl;
    DoubleMatrix.PrintRow(rowI);
    cout << endl;
    StringMatrix.PrintRow(rowI);
    cout << endl;

    IntMatrix.Print();
    DoubleMatrix.Print();
    StringMatrix.Print();

    IntMatrix.AddValue(1,2,2);
    DoubleMatrix.AddValue(1,2,5);
    StringMatrix.AddValue(1,2,"a");

    cout << endl;

    cout << IntMatrix.BelongTo(2) << endl ;
    cout << DoubleMatrix.BelongTo(4.44) << endl;
    cout << StringMatrix.BelongTo("a") << endl;

    cout << endl;

    cout << IntMatrix.MaxValue() << endl;
    cout << DoubleMatrix.MaxValue() << endl;
    cout << StringMatrix.MaxValue() << endl;

    cout << "-------------------------------------------------------------" << endl;

    matrix<Date> dateMatrix;

    // Adding values
    dateMatrix.AddValue(0, 0, Date(10, 2, 2025));
    dateMatrix.AddValue(0, 1, Date(15, 5, 2023));
    dateMatrix.AddValue(0, 2, Date(7, 8, 2024));
    dateMatrix.AddValue(1, 0, Date(21, 11, 2022));
    dateMatrix.AddValue(1, 1, Date(5, 6, 2026));
    dateMatrix.AddValue(1, 2, Date(30, 1, 2021));

    // Print the matrix
    cout << "Date Matrix:\n";
    dateMatrix.Print();

    // Check if a date belongs to the matrix
    if (dateMatrix.BelongTo(Date(7, 8, 2024))) {
        cout << "Date 7/8/2024 exists in the matrix.\n";
    }

    // Find max date
    Date maxDate = dateMatrix.MaxValue();
    cout << "Max Date: " << maxDate << endl;

    return 0;
}