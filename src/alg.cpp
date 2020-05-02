#include <iostream>
#include "tstack.h"
#include <string>
std::string infx2pstfx(std::string inf)
{
TStack<char> stack1;    
    std::string res;
    int len = inf.length();
    for (int i = 0; i < len; i++) {
        if ('0' <= inf[i] && inf[i] <= '9') { res += inf[i]; }
        else if (inf[i] == '(')
            stack1.push(inf[i]);
 else if ((inf[i] == '+' || inf[i] == '-') && (stack1.get() != '*') && (stack1.get() != '/') && (stack1.get() != '+') && (stack1.get() != '-'))
            stack1.push(inf[i]);
        else if ((inf[i] == '*') || (inf[i] == '/') && ((stack1.get() != '*') || (stack1.get() != '/')))
            stack1.push(inf[i]);
        else if (inf[i] == ')')
        {
            while (stack1.get() != '(') {
                res += stack1.get();
                stack1.pop();
            }
            stack1.pop();
        }
        else
        {
            if (inf[i] == '+' || inf[i] == '-')
            {
                while ( (stack1.get() != '(') && (!stack1.isEmpty())) {
                    res += stack1.get();
                    stack1.pop();
                }
                stack1.push(inf[i]);
          }
            if (inf[i] == '*' || inf[i] == '/') {
                while( (stack1.get() == '*' || stack1.get() == '/') && (!stack1.isEmpty()) ) {
                    res += stack1.get();
                    stack1.pop();
               }
                stack1.push(inf[i]);
         }         
        }     
    }
    while (!stack1.isEmpty()) {
        res += stack1.get();
        stack1.pop();
    }
    inf = res;
    return inf;
}
int eval(std::string pst)
{
TStack<int> stack2;
    int len = pst.length();
    for (int i = 0; i < len; i++) {
        if ('0' <= pst[i] && pst[i] <= '9') {    
          int x = pst[i] - '0';
            stack2.push(x);
        }
        if (pst[i] == '+') {
            int a = stack2.get();  stack2.pop();
            int b = stack2.get();  stack2.pop();
            int c = b + a;  stack2.push(c);       
        }
        if (pst[i] == '-') {
            int a = stack2.get();  stack2.pop();
            int b = stack2.get();  stack2.pop();
            int c = b - a;  stack2.push(c);
        }
        if (pst[i] == '*') {
            int a = stack2.get();  stack2.pop();
            int b = stack2.get();  stack2.pop();
            int c = b * a;  stack2.push(c);
        }
        if (pst[i] == '/') {
            int a = stack2.get();  stack2.pop();
            int b = stack2.get();  stack2.pop();
            int c = b / a;  stack2.push(c);
        }
    }
    int res = stack2.get();  stack2.pop();
    return res;
}
