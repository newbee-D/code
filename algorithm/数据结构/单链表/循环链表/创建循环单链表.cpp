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
    ListNode* creatList(int a[],int n)
    {
        ListNode*first=new ListNode();
        ListNode*last=first;
        for(int i=0; i<n; i++)
        {
            ListNode*p=new ListNode(a[i]);
            last->next=p;
            last=p;
        }
        last->next=first;      //Ê×Î²ÏàÁ¬
        return first;
    }
    ListNode* deleteList(ListNode*head,int x)//删除x元素
    {
        ListNode*first=new ListNode();
        first->next=head;
        ListNode*pre=head;
        ListNode*p=head;
        while(p->next!=head)
        {
            if(p->val!=x)
            {
                pre=p;
                p=p->next;
            }
            else
            {
                ListNode*p1=p->next;
                pre->next=p1;
                delete p;
                return head;
            }
        }
    }
    void printList(ListNode* head)
    {
        if(head==NULL )
        {
            cout<<" NULL\n";
            return;
        }
        ListNode* cur=head;
        while(cur->next!=head)
        {
            if(cur==head)
                cout<<cur->val;
            else
                cout<<" "<<cur->val;
            cur=cur->next;
        }
        cout<<" "<<cur->val;              //
        cout<<endl;
    }
};
int main()
{
    int a[]={1,2,3,4,5,6};
    int n=sizeof(a)/sizeof(int);
    Solution obj;
    ListNode* head=obj.creatList(a,n);
    obj.printList(head);

    ListNode*l1=obj.deleteList(head,3);
    obj.printList(l1);
    cout<<endl;
    return 0;

}
