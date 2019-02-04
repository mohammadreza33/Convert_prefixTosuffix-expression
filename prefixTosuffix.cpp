/*
    convertion a prefix expression 
    to a suffix expression.
*/

#include <iostream>
#include <stdlib.h>
#include <stack>
#include <string>

using namespace std;

// check operators
bool isOperator(char x)
{
	switch (x)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return true;

	}
	return false;
}
//  a method that convert prefix expression 
//  to postfix using stack
string preTopost(string pre_exp)
{
	stack<string> s;

	int length = pre_exp.size();

	for (int i = length - 1; i >= 0; i--)
	{
		if (!(isOperator(pre_exp[i])))
		{
			s.push(string(1, pre_exp[i]));
		}
		else
		{
            string opd1 = s.top(); s.pop();
			string opd2 = s.top(); s.pop();
            //operand1 + operand2 + operator
			string temp = opd1 + opd2 + pre_exp[i];
			s.push(temp);
		}
	}
	return s.top();
}

int main()
{
	string t,test = "*+AB-CD";
	cout << "COnverted to postfix is:";
	t = preTopost(test);
	cout<<t;
    cin.get();
	return 0;
}
