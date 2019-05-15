#include<stdio.h>
#include<stdlib.h>
#include<string >
const int MAXSIZE=1000;  // 栈最大容纳元素
int t;    //栈顶指针
int s[MAXSIZE];     //存放栈中元素
void push(int x)      //入栈
{
    s[++t]=x;
}
int top()                //取栈顶元素
{
    return s[t];
}
void pop()              //删除栈顶元素
{
    t--;
}
int isEmpty()               //判断是否为空栈
{
    return t==0;
}
int isFull()                  //判断栈是否已满
{
    return t>MAXSIZE-1;
}
int size()              //栈中元素个数
{
    return t;
}

int main()                 //计算1+2*(5-4)-6/3     1 2 5 4 - * + 6 3 / -
{                           //后缀表达式  从左向右扫描，操作数入栈，如遇操作符，依次从栈中退出两个操作数
    int a,b;
    t=0;
    char post[100];      //存放后缀表达式
    while(scanf("%s",post)!=EOF)
    {
        if(post[0]=='+')
        {
            a=top();
            pop();
            b=top();
            pop();
            push(a+b);
        }
        else if(post[0]=='-')
        {
            a=top();
            pop();
            b=top();
            pop();
            push(a-b);
        }
        else if(post[0]=='*')
        {
            a=top();
            pop();
            b=top();
            pop();
            push(a*b);
        }
        else if(post[0]=='/')
        {
            a=top();
            pop();
            b=top();
            pop();
            push(a/b);
        }
        else
        {
            push(atoi(post));
        }
    }
    printf("%d\n",top());     //栈顶为计算结果
    return 0;
}
