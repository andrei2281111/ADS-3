#include "tstack.h"
#include <iostream>
#include <string>
#include "main.h"
TStack<char>stack1;
TStack<int>stack2;
int prior(char a)
{
	int mas[] = { 0,1,2,2,3,3};
	char str[] = "()+-*/";
	int tmp=strchr(str, a)-str;
	return mas[tmp];
}
// преобразование выражение в постфиксную форму
std::string infx2pstfx(std::string inf)
{
	int k = 0, k1 = 0;
	std:: string tmp;
	for (int i = 0; i < inf.size(); i++)
	{
		if (!(inf[i] >= '0' && inf[i] <= '9'))
		{
			k = prior(inf[i]);
			if (stack1.isEmpty() == true || k == 0)
				stack1.push(inf[i]);
			k1 = prior(stack1.get());
			if (k > k1)
				stack1.push(inf[i]);
			else if (k < k1)
			{
				tmp += stack1.get();
				stack1.pop();
				while (stack1.get() == '(' || stack1.get() == ')')
					stack1.pop();
			}
		}
		else
			tmp+= inf[i];
	}
	tmp += stack1.get();
	return tmp;
}

int ex(int k1, int k2, char pst)
{
	switch (pst)
	{
	case '+':
		return k1 + k2;
	case '-':
		return k1 - k2;
	case '*':
		return k1 * k2;
	case '/':
		return k1 / k2;
	}
}
int eval(std::string pst)
{
	std::string tmp;
	int res;
	for (int i = 0; i < pst.size(); i++)
	{
		
		if(pst[i]>='0' && pst[i]<='9')
			stack2.push(pst[i] - '0');
		else
		{
			int k1 = stack2.get();
			stack2.pop();
			int k2 = stack2.get();
			stack2.pop();
			res = ex(k1, k2, pst[i]);
			stack2.push(res);
		}
	}
	return stack2.get();
}
