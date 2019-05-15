#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode (int val)
    {
        this->val=val;
        this->next=NULL;
    }
    ListNode()
    {
        this->val=-1;
        this->next=NULL;
    }
};
class Solution
{
public:
    ListNode* bulidList(int a[],int n)
    {
        ListNode* first=new ListNode;
        ListNode* last=first;
        for(int i=0; i<n; i++)
        {
            ListNode* cur=new ListNode(a[i]);
            last->next=cur;
            last=cur;
        }
        return first->next;
    }
    int getLengthList(ListNode* head)     //计算链表长度
    {
        int cnt=0;
        while(head!=NULL)
        {
            cnt++;
            head=head->next;
        }
        return cnt;
    }
     ListNode* removeNthFromEnd(ListNode*head,int n)   //找倒数第N个结点
    {
        if(head==NULL&&head->next==NULL)
        {
            return NULL;
        }
        int cnt=getLengthList(head);
        int tot=cnt-n+1;
        int k=1;
        ListNode*cur=head;
        while(k<tot-1)
        {
            k++;
            cur=cur->next;
        }
        if(cur==head)               //如果删除第一个元素，head指向下一个元素
        {
            head=head->next;
        }
        else
        {
            ListNode*tmp=cur->next;
            cur->next=tmp->next;
            cur=cur->next;
            delete tmp;                   //删除第n个元素
        }
        return head;
    }
    void printList(ListNode* head)
    {
        if(head==NULL)
        {
            cout<<" NULL\n";
            return;
        }
        ListNode* cur=head;
        while(cur!=NULL)
        {
            if(cur==head)
                cout<<cur->val;
            else
                cout<<" "<<cur->val;
            cur=cur->next;
        }
        cout<<endl;
    }
};
int main(int argc,char const*argv[])
{
    Solution obj;
    int a[]= {3,2,5,7};
    int n=sizeof(a)/sizeof(int);
    ListNode* head=obj.bulidList(a,n);
    obj.printList(head);
    obj.removeNthFromEnd(head,2);
    obj.printList(head);
    return 0;
}

