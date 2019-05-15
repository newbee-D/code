#include<stdio.h>
#include<malloc.h>              //内存分配函数
#include<stdlib.h>
#include<algorithm>
#include<limits.h>

struct node                            //链表结点类
{
    int date;
    struct node* next;
};
struct node* create(int a[],int n)
{
    int i;
    struct node* head;
    struct node* pre;                   //声明对象指针变量
    struct node* p;
    head=(struct node*)malloc(sizeof(struct node));
    pre=head;                       //  用head的地址将其初始化
    pre->date=a[0];                          //对象指针（对象指针在试用之前，要先进行初始化，让它指向一个已经声名过的对象，然后再使用）
    for(i=1; i<n; i++)
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->date=a[i];
        p->next=NULL;                      //对象指针名->
        pre->next=p;
        pre=p;

    }
    return head;
};
void printList(struct node* head)
{
    struct node* p=head;
    while (p!=NULL)
    {
        printf("%d ",p->date);
        p=p->next;
    }
    printf("\n");
}
int Max(int a,int b)
{
    return a>b ? a: b;
}
int getMax(struct node*head)
{
    if(head==NULL)
        return INT_MIN;
    else
        return Max(head->date,getMax(head->next));
}
int main()
{
    int a[]= {3,2,5,7};
    struct node* head;
    head=create(a,4);
    printList(head);
    getMax(head);
    printf("%d",getMax(head));
}
