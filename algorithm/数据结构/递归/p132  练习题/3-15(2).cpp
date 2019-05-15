#include<iostream>
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
    ListNode* bulidList(int a[],int n)
    {
        ListNode*first=new ListNode;
        ListNode* last=first;
        for(int i=0; i<n; i++)
        {
            ListNode* cur=new ListNode(a[i]);
            last->next=cur;
            last=cur;
        }
        return first->next;
    }
    int getLengthList(ListNode* head)
    {
        if(head==NULL)
            return 0;
        else
        {
            return 1+getLengthList(head->next);
        }
    }
};
int main()
{
    Solution obj;
    int a[]= {1,2,3,4,5,6};
    int n=sizeof(a)/sizeof(int);
    ListNode* head=obj.bulidList(a,n);
    obj.getLengthList(head);
    cout<<obj.getLengthList(head);
    return 0;
}
