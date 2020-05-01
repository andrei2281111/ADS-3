#include <iostream>
#include "tstack.h"
using namespace std;

int getPriority(char x)
{
    switch (x)
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

string infx2pstfx(string inf)
{
    TStack<char> stack;
    string out = "";
    for (int i = 0; i < inf.size(); i++)
    {
        char x = inf[i];
        int priority = getPriority(x);

        if ( priority == -1)
            out.append(string(1,x));
        else
            if( stack.isEmpty() || priority == 0 || priority > getPriority(stack.get()) )
                stack.push(x);
            else
            {
                if ( x == ')')
                    while(true)
                    {
                        char lastStackEl = stack.get();
                        stack.pop();
                        if (lastStackEl != '(')
                            out.append(string(1,lastStackEl));
                        else
                            break;
                    }
                else
                {
                    while(!stack.isEmpty())
                    {
                        char lastStackEl = stack.get();
                        stack.pop();
                        if (getPriority(lastStackEl) >= priority)
                            out.append(string(1,lastStackEl));
                    }
                    stack.push(x);
                }
            }
    }
    while(!stack.isEmpty())
    {
        char lastStackEl = stack.get();
        stack.pop();
        out.append(string(1,lastStackEl));
    }
    return out;
}

int calculate(int n1, int n2, char operation)
{
    switch (operation)
    {
    case '+': return n1 + n2;
    case '-': return n1 - n2;
    case '*': return n1 * n2;
    case '/': return n1 / n2;    
    default: return -1;
    }
}

int eval(string pst)
{
    TStack<int> stack;
    for (int i = 0; i < pst.size(); i++)
    {
        char x = pst[i];
        int priority = getPriority(x);

        if ( priority == -1)
            stack.push(x - 48);
        else
        {
            int  n1=stack.get(); 
            stack.pop();

            int n2 = stack.get();
            stack.pop();

            int result = calculate(n2, n1, x);
            stack.push(result);
        }

    }
    return stack.get();
}
