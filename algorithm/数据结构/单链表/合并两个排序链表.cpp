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
    ListNode* mergeTwoLists(ListNode* head1,ListNode* head2)//合并排序链表
    {
        if(head1==NULL)return head2;
        if(head2==NULL)return head1;
        if(head1==NULL && head2==NULL)return NULL;
        ListNode* first=new ListNode();    //附加头结点
        ListNode* head=first;
        while(head1 && head2)
        {
            if(head1->val <= head2->val)
            {

                head->next=head1;
                head1=head1->next;
                head=head->next;
            }
            else
            {
                head->next=head2;
                head2=head2->next;
                head=head->next;
            }
        }
        if(head1!=NULL)
            head->next=head1;
        if(head2!=NULL)
            head->next=head2;

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
    int a[]= {2,3,5,7};
    int b[]= {1,4,6,8,9,10};
    int n=sizeof(a)/sizeof(int);
    int m=sizeof(b)/sizeof(int);
    ListNode* head1=obj.bulidList(a,n);
    ListNode* head2=obj.bulidList(b,m);
    ListNode* head=obj.mergeTwoLists(head1,head2);
    obj.printList(head);

    return 0;
}
