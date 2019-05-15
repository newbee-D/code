#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int val):val(val),next(NULL){}
};
class Solution
{
public:
    void Josephus(ListNode* head,int n,int m)
    {
        ListNode* pre=head;
        ListNode* cur=head;
        int tot=0;
        while(tot<n)
        {
            for(int j=1;j<m;j++)
            {
                pre=cur;
                cur=cur->next;
            }
            cout<<cur->val<<" ";
            pre->next=cur->next;
            delete cur;
            tot++;
            cur=pre->next;
        }
    }
    ListNode*create(int a[],int n)
    {
        ListNode* first=new ListNode(-1);
        ListNode* last=first;
        for(int i=0;i<n;i++)
        {
            ListNode* p=new ListNode(a[i]);
            last->next=p;
            last=last->next;
        }
        last->next=first->next;
        return first->next;
    }
    void printList(ListNode* head)
    {
        if(head==NULL)
        {
            cout<<"\n";
            return;
        }
        ListNode* p=head;
        while(p->next != head)
        {
            if(p==head) cout<<p->val;
            else
                cout<<" "<<p->val;
            p=p->next;
        }
        cout<<" "<<p->val;
        cout<<"\n";
    }
};
int main()
{
    int n,p;
    while(cin>>n>>p)
    {
        int a[n];
        for(int i=0;i<n;i++)a[i]=i+1;
        Solution obj;
        ListNode* head=obj.create(a,n);
        //obj.printList(head);
        obj.Josephus(head,n,p);
        cout<<endl;
    }
    return 0;
}
