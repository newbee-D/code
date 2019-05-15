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
    ListNode* bulidList(int a[],int n)             // β�巨
    {
        ListNode* first=new ListNode;               //  ����ͷ���
        ListNode* last=first;
        for(int i=0; i<n; i++)
        {
            ListNode* cur=new ListNode(a[i]);
            last->next=cur;
            last=cur;
        }
        return first;
        // return first->next;   û�и���ͷ�ļ�
    }
    void printList(ListNode* head)
    {
        //if(head==NULL)
        if(head==NULL || head->next==NULL)
        {
            cout<<" NULL\n";
            return;
        }
        ListNode* cur=head->next;
        // listNode* cur=head;

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

};
int main(int argc,char const*argv[])
{
    Solution obj;
    int a[]= {3,2,5,7};
    int n=sizeof(a)/sizeof(int);
    ListNode* head=obj.bulidList(a,n);
    obj.printList(head);
    return 0;


}
