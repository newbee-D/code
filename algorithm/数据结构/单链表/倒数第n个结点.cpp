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
    int getLengthList(ListNode* head)     //求结点个数
    {
        int cnt=0;
        while(head!=NULL)
        {
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    ListNode* nthToLast(ListNode*head,int n)     //从末尾开始
    {
          if(head==NULL&&head->next==NULL)
        {
            return NULL;
        }
        int cnt=getLengthList(head);
        int tot=cnt-n+1;
        int k=1;
        while(k<tot)
        {
            k++;
            head=head->next;
        }
        cout<<head->val<<endl;
        return head;
    }
    ListNode* nthToLast2(ListNode*head,int n)       //双指针法
    {
          if(head==NULL&&head->next==NULL)
        {
            return NULL;
        }
        ListNode*f=head;
        ListNode*s=head;
        int k=0;
        while(k<n)
        {
            k++;
            f=f->next;
        }
        while(f!=NULL)
        {
            f=f->next;
            s=s->next;
        }
        cout<<s->val<<endl;
        return s;
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
    obj.nthToLast2(head,2);
    obj.nthToLast(head,2);
    return 0;
}
