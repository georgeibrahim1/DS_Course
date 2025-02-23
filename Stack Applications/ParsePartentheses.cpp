#include <iostream>
#include <stack>
using namespace std;

bool ParseParentheses(string expression)
{
    stack<char> S;
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            S.push(expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
            if (S.empty())
            {
                return false;
            }
            else if (expression[i] == ')' && S.top() == '(')
            {
                S.pop();
            }
            else if (expression[i] == '}' && S.top() == '{')
            {
                S.pop();
            }
            else if (expression[i] == ']' && S.top() == '[')
            {
                S.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (S.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string expression = "({[]})";
    if (ParseParentheses(expression))
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Not Balanced";
    }
    cout << endl;
    string expression2 = "({[})";
    if (ParseParentheses(expression2))
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Not Balanced";
    }

    return 0;
}