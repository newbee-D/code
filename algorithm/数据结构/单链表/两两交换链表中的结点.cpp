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
        ListNode* first=new ListNode();
        ListNode* last=first;
        for(int i=0; i<n; i++)
        {
            ListNode* cur=new ListNode(a[i]);
            last->next=cur;
            last=cur;
        }
        return first->next;
    }
    ListNode*swapPairs(ListNode*head)      //两两交换链表中的结点
    {
        ListNode*first=new ListNode();     //附加头结点
        first->next=head;
        head=first;
        if(head== NULL  &&  head->next==NULL)
        {
            return head;
        }
        while(head->next!=NULL  &&  head->next->next!=NULL)
        {
            ListNode*p=head->next;
            ListNode*p1=head->next->next;
            head->next=p1;
            p->next=p1->next;
            p1->next=p;
            head=p;
        }
        return first->next;
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
    int a[]= {2,3,5,7,9,10};
    int n=sizeof(a)/sizeof(int);
    ListNode*head=obj.bulidList(a,n);
    obj.printList(head);
    obj.swapPairs(head);
    obj.printList(head);
    return 0;
}
