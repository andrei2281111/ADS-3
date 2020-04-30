#include "tstack.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

int pr(char s)
{
    switch (s)
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
    std::string pstfx;
    TStack<char> stack;
    int j = 0;
    int k = 0;
    for (int i = 0; i < inf.size(); i++)
    {
        int priority = pr(inf[i]);
        int counter = 0;
        if (priority == -1)
        {
            pstfx += inf[i];
            k++;
        }
        else
            if (pr(stack.get()) < priority || priority == 0 || stack.isEmpty() == true)
            {
                stack.push(inf[i]);
                printf("stack:%c\n", inf[i]);
            }
            else
                if (priority == 1)
                {
                    char simv = stack.get();
                    stack.pop();
                    while (pr(simv) > priority)
                    {
                        pstfx += simv;
                        k++;
                        printf("1simv:%c\n", simv);
                        simv = stack.get();
                        stack.pop();
                    }
                    if (stack.isEmpty() == false)
                    {
                        simv = stack.get();
                        
                        if (pr(simv) > pr(pstfx[k]))
                        {
                            printf("2simv:%c\n", simv);
                            stack.pop();
                            pstfx += simv;
                        }
                        k++;
                    }
                }
                else
                {
                    char simv = stack.get();
                    while (pr(simv) > priority)
                    {
                        pstfx += simv;
                        printf("3simv:%c\n", simv);
                        stack.pop();
                        simv = stack.get();
                        stack.pop();
                    }
                    stack.push(inf[i]);
                }
    }
    while (stack.isEmpty() == false)
    {
        char simv = stack.get();
        printf("4simv:%c\n", simv);
        stack.pop();
        pstfx += simv;
    }
    return pstfx;
}

int eval(std::string pstfx)
{
    int sum = 0;
    TStack<int> stack;
    for (int j = 0; j < pstfx.size(); j++)
    {
        if (pr(pstfx[j]) == -1)
        {
            std::string S;
            S += pstfx[j];
            std::istringstream iss(S, std::istringstream::in);
            int val;
            iss >> val;
            stack.push(val);
        }
        else
        {
            int a = stack.get();
            stack.pop();
            int b = stack.get();
            stack.pop();
            if (pstfx[j] == '+') sum = a + b;
            if (pstfx[j] == '-') sum = b - a;
            if (pstfx[j] == '*') sum = a * b;
            if (pstfx[j] == '/') sum = b / a;
            stack.push(sum);
        }
        if (pstfx[j] == '\0') break;
    }
    return stack.get();
}
