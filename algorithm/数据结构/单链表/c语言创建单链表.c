#include<stdio.h>
#include<malloc.h>              //�ڴ���亯��
#include<stdlib.h>

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
    head=(struct node*)malloc(sizeof(struct node));   //�����ڴ�ռ�
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

