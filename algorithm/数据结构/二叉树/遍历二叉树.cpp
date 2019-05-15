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
BinTreeNode* bulidTree(int a[],int n,int start)          //创建二叉树
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

//递归遍历二叉树
//前序遍历二叉树
void PreorderTraversal(BinTreeNode *root)
{
    if(root==NULL)return ;
    cout<<" "<<root->date;                    //1》根 2》左 3》右
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}
//前序遍历  利用动态数组控制空格
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
//中序遍历二叉树
void InorderTraversal(BinTreeNode *root)
{
    if(root==NULL)return ;
    InorderTraversal(root->left);     //   1》左 2》根 3》右
    cout<<" "<<root->date;
    InorderTraversal(root->right);
}
//后序遍历二叉树
void PostorderTraversal(BinTreeNode *root)
{

    if(root==NULL)return ;                                    //二叉树非空
    PostorderTraversal(root->left);                    //  1》左 2》由 3》根
    PostorderTraversal(root->right);
    cout<<" "<<root->date;

}

//非递归遍历二叉树（用栈）
void preOrderUnRecursive(BinTreeNode* root)   //前序
{
    if(!root)return;
    stack<BinTreeNode*>s;             //入栈的是地址
    BinTreeNode* p=root;
    s.push(p);
    while(!s.empty())
    {
        p=s.top();      //取栈顶元素
        s.pop();          // 删除栈顶元素
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
    BinTreeNode* p;     //当前结点
    BinTreeNode* q;    //刚刚访问过的结点
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
            if(p->right==q)         //无右子树，或刚刚已经访问过
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
//层次遍历    用队列
void levelOrderUnRecursive(BinTreeNode* root)
{
    if(!root)return;
    queue<BinTreeNode*>que;
    BinTreeNode* p=root;
    que.push(p);
    while(!que.empty())
    {
        p=que.front();    //取队列首元素
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

void LevelorderTraversal(BinTree BT)    //层次遍历二叉树
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

    cout<<"递归遍历二叉树：\n";

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

    cout<<"非递归遍历二叉树：\n";

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
