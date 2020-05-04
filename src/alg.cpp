#include <iostream>
#include "tstack.h"
#include <string>
using namespace std;


int prior(char sign)
{
	switch (sign)
	{
	case '(': return 0;
	case ')': return 1;
	case '+': return 2;
	case '-': return 2;
	case '*': return 3;
	case '/': return 3;
	default: return -1;
	}
}

std::string infx2pstfx(std::string inf)
{
	int k;
	TStack<char> stack1;
	std::string expr = "";
	for (int i = 0; i < inf.size(); i++)
	{
		k = prior(inf[i]);
		if (k > -1)
		{
			if (k == 0 || k > prior(stack1.get()) || stack1.isEmpty())
				stack1.push(inf[i]);
			else if (k == 1)
			{
				while (stack1.get() != '(')
				{
					expr.append(string(1, stack1.get()));
					stack1.pop();
				}
				stack1.pop();
			}
			else if (k <= prior(stack1.get()))
			{
				expr.append(string(1, stack1.get()));
				stack1.pop();
				stack1.push(inf[i]);
			}
		}
		else
			expr.append(string(1, inf[i]));
	}
	while (stack1.isEmpty() == false)
	{
		expr.append(string(1, stack1.get()));
		stack1.pop();
	}

	return expr;
}


int calc(int k1, int k2, char pst)
{
	switch (pst)
	{
	case '+': return k1 + k2;
	case '-': return k1 - k2;
	case '*': return k1 * k2;
	case '/': return k1 / k2;
	default: return -1;
	}
}


int eval(string pst)
	{
		int oper1;
		int oper2;
		TStack<int> stack2;
		for (int i = 0; i < pst.size(); i++)
		{
			char sym = pst[i];
			int priority = prior(sym);

			if (priority == -1)
				stack2.push(sym - 48);
			else
			{
				oper1 = stack2.get();
				stack2.pop();

				oper2 = stack2.get();
				stack2.pop();


				int res = calc(oper2, oper1, pst[i]);
				stack2.push(res);
			}
		}
		return stack2.get();
	}
