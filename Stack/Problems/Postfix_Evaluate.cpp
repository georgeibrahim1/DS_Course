#include <iostream>
#include <stack>
using namespace std;

stack<int> Postfix_Ev(string expression)
{
    stack<int> S;
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            S.push(expression[i] - '0'); // This is done to convert the character to integer like '2' to 2 -> ASCII value of '2' is 50 - 48 = 2 , since 0 is 48 in ASCII
        }
        else
        {
            int op2 = S.top();
            S.pop();
            int op1 = S.top();
            S.pop();
            switch (expression[i])
            {
            case '+':
                S.push(op1 + op2);
                break;
            case '-':
                S.push(op1 - op2);
                break;
            case '*':
                S.push(op1 * op2);
                break;
            case '/':
                S.push(op1 / op2);
                break;
            case '^':
                S.push(op1 ^ op2);
                break;
            }
        }
    }
    return S;
}

int main()
{
    string expression = "231*+9-";
    stack<int> S = Postfix_Ev(expression);
    cout << S.top();

    return 0;
}