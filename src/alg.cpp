#include "tstack.h"
#include <string>
#include <utility>

int un_num(const char& sim)
{
    std::pair<char, int> priority[6];
    priority[0].first = '('; priority[0].second = 0;
    priority[1].first = ')'; priority[1].second = 1;
    priority[2].first = '+'; priority[2].second = 2;
    priority[3].first = '-'; priority[3].second = 2;
    priority[4].first = '*'; priority[4].second = 3;
    priority[5].first = '/'; priority[5].second = 3;
    int prior = -1;
    for (int j = 0; j < 6; ++j)
        if (sim == priority[j].first)
        {
            prior = priority[j].second;
            break;
        }
    return prior;
}
// преобразование выражения в постфиксную форму
std::string infx2pstfx(std::string inf)
{
    std::string work;
    TStack<char> stack;
    for (auto &sim : inf)
    {
        int prior = un_num(sim);
        if (prior == -1)
            work += sim;
        else
            if (stack.get() < prior || prior == 0 || stack.isEmpty())
                stack.push(sim);
            else if (sim == ')')
            {
                char sm = stack.get();
                while (un_num(sm) >= prior)
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
                while (un_num(sm) >= prior)
                {
                    work += sm;
                    stack.pop();
                    sm = stack.get();
                }
                stack.push(sim);
            }

    }
    while (!stack.isEmpty())
    {
        work += stack.get();
        stack.pop();
    }
    return work;
}

int eval(std::string pst)
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

} 
// вычисление выражения, записанного в постфиксной форме
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
