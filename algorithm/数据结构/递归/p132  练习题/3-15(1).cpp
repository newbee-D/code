#include<stdio.h>
#include<malloc.h>              //�ڴ���亯��
#include<stdlib.h>
#include<algorithm>
#include<limits.h>

struct node                            //��������
{
    int date;
    struct node* next;
};
struct node* create(int a[],int n)
{
    int i;
    struct node* head;
    struct node* pre;                   //��������ָ�����
    struct node* p;
    head=(struct node*)malloc(sizeof(struct node));
    pre=head;                       //  ��head�ĵ�ַ�����ʼ��
    pre->date=a[0];                          //����ָ�루����ָ��������֮ǰ��Ҫ�Ƚ��г�ʼ��������ָ��һ���Ѿ��������Ķ���Ȼ����ʹ�ã�
    for(i=1; i<n; i++)
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->date=a[i];
        p->next=NULL;                      //����ָ����->
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
