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
    ListNode* bulidList(int a[],int n)     //创建链表
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
    int getLengthList(ListNode* head)     //计算链表长度
    {
        int cnt=0;
        while(head!=NULL)
        {
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    ListNode* reverse(ListNode* head)    // 逆置链表
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
    bool isPalindrome(ListNode* head)  //对比逆置链表是否与链表相同
    {
        if(head==NULL || head->next==NULL)
            return true;
        int n=getLengthList(head);
        int *a=new int[n];     //分配动态数组内存
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
    bool isPalindrome2(ListNode* head)                  //快慢指针
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
        if(fast!=NULL)                  //结点个数为奇
        {
            slow->next=reverse(slow->next);  //翻转后一半
            slow=slow->next;
        }
        else                                  //结点个数为偶数
            slow=reverse(slow);
        while(slow)
        {
            if(head->val!=slow->val)        //与前一半进行对比
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
