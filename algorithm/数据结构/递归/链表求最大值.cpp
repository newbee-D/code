#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode()
    {
        this->val=-1;
        this->next=NULL;
    }
    ListNode(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};
class Solution
{
public:
    ListNode* bulidList(int a[],int n)     //´´½¨Á´±í
    {
        ListNode*first=new ListNode;
        ListNode* last=first;
        for(int i=0; i<n; i++)
        {
            ListNode* cur=new ListNode(a[i]);
            last->next=cur;
            last=cur;
        }
        return first;
    }

    void printList(ListNode*head)
    {
        ListNode*cur=head->next;
        while(cur!=NULL)
        {
            if(cur==head->next)
                cout<<cur->val;
            else
                cout<<" "<<cur->val;
            cur=cur->next;
        }
        cout<<endl;
    }
    int getMax(ListNode*head)
    {
        if(head==NULL)
            return INT_MIN;
        else
            return max(head->val,getMax(head->next));
    }
};
int main()
{
    int a[]= {3,2,5,7};
    Solution obj;
    ListNode* head=obj.bulidList(a,4);
    obj.printList(head);
    obj.getMax(head);
    cout<<obj.getMax(head);
    return 0;
}

