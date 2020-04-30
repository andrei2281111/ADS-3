#include "tstack.h"
#include <string>
#include<iostream>
#include<stdio.h>

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
    int k = 0;
 for(int j=0;j<inf.size();j++)
    {
        int priority = pr(inf[j]);
        int counter = 0;
        if (priority == -1)
        {
            pstfx += inf[j];
        }
        else
        if (pr(stack.get()) < priority || priority == 0 || stack.isEmpty()==true)
        {
            stack.push(inf[j]);
        }
        else
        if (priority == 1)
        {
           char simv = stack.get();
           stack.pop();
            while (pr(simv)>priority)
            {
                pstfx += simv;
                simv = stack.get();
                stack.pop();
            }
            if (stack.isEmpty() == false && stack.get()=='(')
                {
                    simv = stack.get();
                    stack.pop();
                    pstfx += simv;
                }
        }
        else
        {
            char simv = stack.get();
            while (pr(simv) > priority)
            {
                pstfx += simv;
                stack.pop();
                simv = stack.get();
                stack.pop();
            }
            stack.push(inf[j]);
        }

    }
    while (stack.isEmpty()==false)
    {
        char simv = stack.get();
        stack.pop();
        pstfx += simv;
    }
    return pstfx;
}

int eval(std::string pst)
{
  int sum = 0;
    TStack<int> stack;
 for(int j=0;j<pstfx.size();j++)
    {
        if (pr(pstfx[j])==-1)
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
        j++;
    }
    return stack.get();
}
