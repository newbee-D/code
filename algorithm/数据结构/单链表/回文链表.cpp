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
    ListNode* bulidList(int a[],int n)     //��������
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
    int getLengthList(ListNode* head)     //����������
    {
        int cnt=0;
        while(head!=NULL)
        {
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    ListNode* reverse(ListNode* head)    // ��������
    {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* cur=head;
        ListNode* pre=NULL;
        while(cur)
        {
            ListNode *next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head)  //�Ա����������Ƿ���������ͬ
    {
        if(head==NULL || head->next==NULL)
            return true;
        int n=getLengthList(head);
        int *a=new int[n];     //���䶯̬�����ڴ�
        ListNode* p=head;
        int i=0;
        while(p)
        {
            a[i++]=p->val;
            p=p->next;
        }
        ListNode* head2=bulidList(a,n);
        head2=reverse(head2);
        p=head;
        ListNode* p1=head2;
        while(p && p1)
        {
            if(p->val!=p1->val)return false;
            else
            {
                p=p->next;
                p1=p1->next;
            }
        }
        return true;
    }
    bool isPalindrome2(ListNode* head)                  //����ָ��
    {
        if(head==NULL || head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=NULL)                  //������Ϊ��
        {
            slow->next=reverse(slow->next);  //��ת��һ��
            slow=slow->next;
        }
        else                                  //������Ϊż��
            slow=reverse(slow);
        while(slow)
        {
            if(head->val!=slow->val)        //��ǰһ����жԱ�
                return false;
            else
            {
                head=head->next;
                slow=slow->next;
            }
        }
        return true;
    }
};
int main()
{
    Solution obj;
    int a[]= {1,2,3,3,2,1};
    int n=sizeof(a)/sizeof(int);
    ListNode* head=obj.bulidList(a,n);
    if(obj.isPalindrome(head))
        cout<<"yes\n";
    else
        cout<<"no\n";
    if(obj.isPalindrome2(head))
        cout<<"yes\n";
    else
        cout<<"no\n";
    return 0;
}
