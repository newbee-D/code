#include<iostream>
#include<algorithm>
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

ListNode *deleteDuplicates(ListNode *head)
    {
        if (NULL == head)
        {
            return head;
        }
        ListNode* p = head;
        ListNode* temp = head;

        while (p->next != NULL && temp->next != NULL)
        {
            while (p->val == temp->val && temp->next != NULL)
            {
                temp = temp->next;
            }
            if (temp->next == NULL)              //分情况处理最后一个元素
            {
                if (p->val == temp->val)                //最后一个元素重复
                {
                    p->next = NULL;
                }
                else          //不重复
                {
                    p->next = temp;
                }
                break;
            }
            p->next = temp;
            p = p->next;
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
    int a[]= {2,3,3,5,7,9,10,10,1,1,2};
    int n=sizeof(a)/sizeof(int);
    sort(a,a+n);
    ListNode*head=obj.bulidList(a,n);
    obj.deleteDuplicates(head);
    obj.printList(head);
    return 0;
}
