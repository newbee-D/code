#include<stdio.h>
#include<stdlib.h>
#include<string >
const int MAXSIZE=1000;  // ջ�������Ԫ��
int t;    //ջ��ָ��
int s[MAXSIZE];     //���ջ��Ԫ��
void push(int x)      //��ջ
{
    s[++t]=x;
}
int top()                //ȡջ��Ԫ��
{
    return s[t];
}
void pop()              //ɾ��ջ��Ԫ��
{
    t--;
}
int isEmpty()               //�ж��Ƿ�Ϊ��ջ
{
    return t==0;
}
int isFull()                  //�ж�ջ�Ƿ�����
{
    return t>MAXSIZE-1;
}
int size()              //ջ��Ԫ�ظ���
{
    return t;
}

int main()                 //����1+2*(5-4)-6/3     1 2 5 4 - * + 6 3 / -
{                           //��׺���ʽ  ��������ɨ�裬��������ջ�����������������δ�ջ���˳�����������
    int a,b;
    t=0;
    char post[100];      //��ź�׺���ʽ
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
    printf("%d\n",top());     //ջ��Ϊ������
    return 0;
}
