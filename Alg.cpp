#include "tstack.h"
#include <string>
#include <utility>

int un_num(const char& simb)
{
std::pair<char, int> priority[6];
priority[0].first = '('; priority[0].second = 0;
priority[1].first = ')'; priority[1].second = 1;
priority[2].first = '+'; priority[2].second = 2;
priority[3].first = '-'; priority[3].second = 2;
priority[4].first = '*'; priority[4].second = 3;
priority[5].first = '/'; priority[5].second = 3;
int pr = -1;
for (int j = 0; j < 6; ++j)
if (simb == priority[j].first)
{
pr = priority[j].second;
break;
}
return pr;
}

std::string infx2pstfx(std::string inf)
{
std::string work;
TStack<char> stack;
for (auto &simb : inf)
{
int pr = un_num(simb);
if (pr == -1)
work += simb;
else
if (stack.get() < pr || pr == 0 || stack.isEmpty())
stack.push(simb);
else if (simb == ')')
{
char sm = stack.get();
while (un_num(sm) >= pr)
{
work += sm;
stack.pop();
sm = stack.get();
}
stack.pop();
}
else
{
char sm = stack.get();
while (un_num(sm) >= pr)
{
work += sm;
stack.pop();
sm = stack.get();
}
stack.push(simb);
}

}
while (!stack.isEmpty())
{
work += stack.get();
stack.pop();
}
return work;
}

int counter(const int& a, const int& b , const char& el)
{
switch (el)
{
default:
break;
case '+':return a + b;
case '-':return a - b;
case '*':return a * b;
case '/':return a / b;
}
}

int eval(std::string pst)
{
int summ{ 0 };
TStack<int> stack;
for (auto& el : pst)
{
if (un_num(el) == -1)
{
char k[2];
k[0] = el;
k[1] = '\0';
int r = atoi(k);
stack.push(r);
}
else
{
int b = stack.get();
stack.pop();
int a = stack.get();
stack.pop();
stack.push(counter(a, b, el));
}
}
return stack.get();
}
