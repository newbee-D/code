#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct BinTreeNode
{
    int date;
    BinTreeNode* left;
    BinTreeNode* right;
    BinTreeNode(int date)
    {
        this->date=date;
        this->left=NULL;
        this->right=NULL;
    }
};

/*BinTree bulidTree(vector<char> list,int start)
{
    if(list[start]=='a')
        return NULL;
    BinTree root=(BinTree)malloc(sizeof(struct TNode));
    root->left=NULL;
    root->right=NULL;
    root->date=list[start];

    int lnode=2*start+1;
    int rnode=2*start+2;

    if(lnode>list.size()-1)
        root->left=NULL;
    else
        root->left=bulidTree(list,lnode);
    if(rnode>list.size()-1)
        root->right=NULL;
    else
        root->right=bulidTree(list,rnode);
    return root;
}*/
BinTreeNode* bulidTree(int a[],int n,int start)          //����������
{
    BinTreeNode* root=new BinTreeNode(a[start]);
    int lnode=2*start+1;
    int rnode=2*start+2;
    if(lnode>n-1)
        root->left=NULL;
    else
        root->left=bulidTree(a,n,lnode);
    if(rnode>n-1)
        root->right=NULL;
    else
        root->right=bulidTree(a,n,rnode);
    return root;
}
/*BinTree CreatBinTree()
{
    freopen("in.txt","r",stdin);
    char c;
    vector<char>v;
    while(cin>>c)
    {
        v.push_back(c);
    }
    int n=v.size();
    int i;
    for(i=0; i<n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return root;
}*/

//�ݹ����������
//ǰ�����������
void PreorderTraversal(BinTreeNode *root)
{
    if(root==NULL)return ;
    cout<<" "<<root->date;                    //1���� 2���� 3����
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}
//ǰ�����  ���ö�̬������ƿո�
void preOrder2(BinTreeNode*root,vector<int>&v)
{
    if(root==NULL)return ;
    v.push_back(root->date);
    preOrder2(root->left,v);
    preOrder2(root->right,v);
}
vector<int>preOrder(BinTreeNode*root)
{
    vector<int>result;
    if(root==NULL)return result;
    preOrder2(root,result);
    return result;
}
//�������������
void InorderTraversal(BinTreeNode *root)
{
    if(root==NULL)return ;
    InorderTraversal(root->left);     //   1���� 2���� 3����
    cout<<" "<<root->date;
    InorderTraversal(root->right);
}
//�������������
void PostorderTraversal(BinTreeNode *root)
{

    if(root==NULL)return ;                                    //�������ǿ�
    PostorderTraversal(root->left);                    //  1���� 2���� 3����
    PostorderTraversal(root->right);
    cout<<" "<<root->date;

}

//�ǵݹ��������������ջ��
void preOrderUnRecursive(BinTreeNode* root)   //ǰ��
{
    if(!root)return;
    stack<BinTreeNode*>s;             //��ջ���ǵ�ַ
    BinTreeNode* p=root;
    s.push(p);
    while(!s.empty())
    {
        p=s.top();      //ȡջ��Ԫ��
        s.pop();          // ɾ��ջ��Ԫ��
        cout<<" "<<p->date;
        if(p->right)s.push(p->right);
        if(p->left)s.push(p->left);
    }
}

void inOrderUnRecursive(BinTreeNode*root)
{
    if(!root)return ;
    stack<BinTreeNode*>s;
    BinTreeNode* p=root;
    while(!s.empty() || p!=NULL)
    {
        while(p!=NULL)
        {
            s.push(p);
            p=p->left;
        }
        if(!s.empty())
        {
            p=s.top();
            s.pop();
            cout<<" "<<p->date;
            p=p->right;
        }
    }
}
void postOrderUnRecursive(BinTreeNode* root)
{
    if(!root)return ;
    stack<BinTreeNode*>s;
    BinTreeNode* p;     //��ǰ���
    BinTreeNode* q;    //�ոշ��ʹ��Ľ��
    p=root;
    do
    {
        while(p!=NULL)
        {
            s.push(p);
            p=p->left;
        }
        q=NULL;
        while(!s.empty())
        {
            p=s.top();
            s.pop();
            if(p->right==q)         //������������ո��Ѿ����ʹ�
            {
                cout<<" "<<p->date;
                q=p;
            }
            else
            {
                s.push(p);
                p=p->right;
                break;
            }
        }
    }
    while(!s.empty());
}
//��α���    �ö���
void levelOrderUnRecursive(BinTreeNode* root)
{
    if(!root)return;
    queue<BinTreeNode*>que;
    BinTreeNode* p=root;
    que.push(p);
    while(!que.empty())
    {
        p=que.front();    //ȡ������Ԫ��
        que.pop();
        cout<<" "<<p->date;
        if(p->left)que.push(p->left);
        if(p->right)que.push(p->right);
    }
}

/*int print_at_level(BinTree BT,int level)
{
    if(!BT || level<0)
        return 0;
    if(0==level)
    {
        cout<<" "<<BT->date;
        return 1;
    }
    return print_at_level(BT->left, level-1) + print_at_level(BT->right,level-1);
}

void print_by_level_1(BinTree BT)
{
    int i=0;
    for(i=0; ; i++)
    {
        if(!print_at_level(BT,i))
            break;
    }
}

void LevelorderTraversal(BinTree BT)    //��α���������
{
    if(BT==NULL)
        return ;
    print_by_level_1(BT);
}*/
int main(int argc,char const *argv[])
{
    int a[]= {1,2,3,4,5,6,7,8,9};
    int n=sizeof(a)/sizeof(int);
    BinTreeNode* root=bulidTree(a,n,0);

    cout<<"�ݹ������������\n";

    cout<<"PreorderTraversal:";
    PreorderTraversal(root);
    cout<<endl;

    vector<int>v;
    cout<<"preOrder:";
    v=preOrder(root);
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i];
        if(i<v.size()-1)
            cout<<" ";
    }
    cout<<endl;

    cout<<"InorderTraversal:";
    InorderTraversal(root);
    cout<<endl;

    cout<<"PostorderTraversal:";
    PostorderTraversal(root);
    cout<<endl;

    cout<<"�ǵݹ������������\n";

    cout<<"preOrderUnRecursive:";
    preOrderUnRecursive(root);
    cout<<endl;

    cout<<"inOrderUnRecursive:";
    inOrderUnRecursive(root);
    cout<<endl;

    cout<<"postOrderUnRecursive:";
    postOrderUnRecursive(root);
    cout<<endl;

    cout<<"levelOrderUnRecursive:";
    levelOrderUnRecursive(root);
    cout<<endl;

    return 0;
}
