#include <iostream>
#include "tstack.h"

using namespace std;


int priority(char input)
{
switch (input)
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
//преобразование
string infx2pstfx(string inf)
{
TStack<char> stack1;
string tmp = "";
for (int i = 0; i < inf.size(); i++)
{
char ch = inf[i];
int k = priority(ch);

if (k == -1)
tmp.append(string(1, ch));
else
if (stack1.isEmpty() || k == 0 || k > priority(stack1.get()))
stack1.push(ch);
else
{
if (ch == ')')
while (true)
{
char sym = stack1.get();
stack1.pop();
if (sym != '(')
tmp.append(string(1, sym));
else
break;
}
else
{
while (!stack1.isEmpty())
{
char lastStackEl = stack1.get();
stack1.pop();
if (prioriy(lastStackEl) >= k)
tmp.append(string(1, lastStackEl));
}
stack1.push(ch);
}
}
}
while (!stack1.isEmpty())
{
char lastStackEl = stack1.get();
stack1.pop();
tmp.append(string(1, lastStackEl));
}
return tmp;
}


int excute_calc(int k1, int k2, char post)
{
switch (post)
{
case '+': return k1 + k2;
case '-': return k1 - k2;
case '*': return k1 * k2;
case '/': return k1 / k2;
default: return -1;
}
}
//вычисление

int eval(string post)
{
TStack<int> stack2;
for (int i = 0; i < post.size(); i++)
{
char ch = post[i];
int pr = priority(ch);

if (pr == -1)
stack2.push(ch - 48);
else
{
int k1 = stack2.get();
stack2.pop();

int k2 = stack2.get();
stack2.pop();


int res = excute_calc(k2, k1, ch);
stack2.push(res);
}

}
return stack2.get();
}
