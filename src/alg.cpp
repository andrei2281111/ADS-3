#include "tstack.h"
#include <string>
#include<iostream>
#include<stdio.h>

int pr(char s)
{
    prior arr[6];
    int prior=-1;
    arr[0].operac = '('; arr[0].priority = 0;
    arr[1].operac = ')'; arr[1].priority = 1;
    arr[2].operac = '+'; arr[2].priority = 2;
    arr[3].operac = '-'; arr[3].priority = 2;
    arr[4].operac = '*'; arr[4].priority = 3;
    arr[5].operac = '/'; arr[5].priority = 3;
    for(int i=0;i<6;i++)
        if (s == arr[i].operac)
        {
            prior = arr[i].priority;
            break;
        }
    return prior;
}

std::string infx2pstfx(std::string inf)
{
   std::string pstfx;
    TStack<char> stack;
    int j = 0;
    int k = 0;
    while (inf[j] != '\0')
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

        j++;
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
    int j = 0;
    while (pstfx[j] != '\0')
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
