#include "tstack.h"
#include <iostream>
#include <string>
using namespace std;

int change(char a)
{
	if (a == '(')
		return 0;
	else if (a == ')')
		return 1;
	else if (a == '+')
		return 2;
	else if (a == '-')
		return 2;
	else if (a == '*')
		return 3;
	else if (a == '/')
		return 3;
}

bool compare_2(char b, char a) {
	int num1 = change(b);
	int num2 = change(a);
	if (num2 <= num1)
		return true;
	else
		return false;
}

bool compare(TStack<char>& stack,char a) {
	int num1 = change(stack.get());
	int num2 = change(a);
	if (num2 > num1)
		return true;
	else
		return false;
}

string infx2pstfx(string inf)
{
	TStack<char> stack;
	string pst;
	int i = 0;
	for (int i = 0; i < inf.length(); i++)
	{
		if (inf[i] == '0' || inf[i] == '1' || inf[i] == '2' || inf[i] == '3' || inf[i] == '4' || inf[i] == '5' || inf[i] == '6' || inf[i] == '7'
			|| inf[i] == '8' || inf[i] == '9')
		{
			pst+= inf[i];
		}
		else if (inf[i]=='(')
			stack.push(inf[i]);
		else if (stack.isEmpty())
		{
			stack.push(inf[i]);
		}
		else if (compare(stack,inf[i]))
		{
			stack.push(inf[i]);
		}
		else
		{
			while (compare_2(stack.get(), inf[i]))
			{
				if (stack.get() != ')' && stack.get() != '(')
				{
					pst += stack.get();
				}
				stack.pop();
			}
			if (inf[i] == ')')
			{
				stack.pop();
			}
			else
				stack.push(inf[i]);
		}
	}
	while (!stack.isEmpty())
	{
		if (stack.get() != ')' && stack.get() != '(')
		{
			pst+= stack.get();
		}
		stack.pop();
	}
	return pst;
}

int eval(string pst)
{
	int result=0;
	TStack<int> stack;
	for (int i = 0; i < pst.length(); i++)
	{
		if (pst[i] == '0' || pst[i] == '1' || pst[i] == '2' || pst[i] == '3' || pst[i] == '4' || pst[i] == '5' || pst[i] == '6' || pst[i] == '7'
			|| pst[i] == '8' || pst[i] == '9')
		{
			int num = pst[i]-'0';
			stack.push(num);
		}
		else if(pst[i]=='/' )
		{
			int num2 = stack.get();
			stack.pop();
			int num1 = stack.get();
			stack.pop();
			stack.push(num1 / num2);
		}
		else if (pst[i] == '*')
		{
			int num2 = stack.get();
			stack.pop();
			int num1 = stack.get();
			stack.pop();
			stack.push(num1 * num2);
		}
		else if (pst[i] == '+')
		{
			int num2 = stack.get();
			stack.pop();
			int num1 = stack.get();
			stack.pop();
			stack.push(num1 + num2);
		}
		else if (pst[i] == '-')
		{
			int num2 = stack.get();
			stack.pop();
			int num1 = stack.get();
			stack.pop();
			stack.push(num1 - num2);
		}
		else
		{
			return -1;
		}
	}
	return stack.get();
}
