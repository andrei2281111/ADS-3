#include "tstack.h"
#include <string>

int op_precedence(char c)
{
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

std::string infx2pstfx(std::string inf)
{
    TStack<char> stack;
    std::string ns;
    for(char i : inf)
    {
        if((i >= '1' && i <= '9'))
            ns+=i;
        else if(i == '(')
            stack.push('(');
        else if(i == ')')
        {
            while(!stack.isEmpty() && stack.get() != '(')
            {
                char c = stack.get();
                stack.pop();
                ns += c;
            }
            if(stack.get() == '(')
            {
                stack.pop();
            }
        }
        else{
            while(!stack.isEmpty() && op_precedence(i) <= op_precedence(stack.get()))
            {
                char c = stack.get();
                stack.pop();
                ns += c;
            }
            stack.push(i);
        }

    }
    while(!stack.isEmpty())
    {
        char c = stack.get();
        stack.pop();
        ns += c;
    }

    return ns;
}

int eval(std::string pst)
{
    TStack<int> stack;

    for (int i = 0; pst[i]; ++i)
    {
        if (isdigit(pst[i]))
            stack.push(pst[i] - '0');
        else
        {
            int val1 = stack.get();
            stack.pop();
            int val2 = stack.get();
            stack.pop();
            switch (pst[i])
            {
                case '+':
                    stack.push(val2 + val1);
                    break;
                case '-':
                    stack.push(val2 - val1);
                    break;
                case '*':
                    stack.push(val2 * val1);
                    break;
                case '/':
                    stack.push(val2 / val1);
                    break;
            }
        }
    }
    return stack.get();
}
