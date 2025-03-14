#include <iostream>
#include <stack>
using namespace std;

void decimalToBinary(stack<int> &S, int n)
{
    if (n == 0)
    {
        return;
    }
    S.push(n % 2);
    decimalToBinary(S, n / 2);
}

int main()
{
    stack<int>S ;
    decimalToBinary(S, 10);
    while (!S.empty())
    {
        cout << S.top();
        S.pop();
    }

    return 0;
}