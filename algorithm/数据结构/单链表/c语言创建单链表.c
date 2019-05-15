#include<stdio.h>
#include<malloc.h>              //内存分配函数
#include<stdlib.h>

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
    head=(struct node*)malloc(sizeof(struct node));   //分配内存空间
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
int main()
{
  /*  int a[]= {3,2,5,7};
    struct node* head;
    head=create(a,4);
    printList(head);*/
    struct node* pre;
     struct node* p;
     struct node* head;
     head=(struct node*)malloc(sizeof(struct node));
     pre=head;
     head->date=-1;
     printf("%d\n",head->date);
     p=(struct node*)malloc(sizeof(struct node));;
     p->date=20;
     p->next=NULL;
     pre->next=p;
     pre=p;
     printf("%d\n",p->date);
     pre=head;
     while(pre!=NULL)
     {
         printf("%d\n",pre->date);
         pre=pre->next;
     }

    return 0;

}

