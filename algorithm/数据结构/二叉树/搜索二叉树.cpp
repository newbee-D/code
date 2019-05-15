#include<iostream>
#include<vector>
using namespace std;

struct BinTreeNode
{
    int date;
    BinTreeNode* left;
    BinTreeNode*right;
    BinTreeNode(int date):date(date),left(NULL),right(NULL) {};
};

class Solution
{
public:
    void insert(BinTreeNode* &root,int x)//搜索二叉树插入算法
    {
        if(root==NULL)
        {
            root=new BinTreeNode(x);
            return;
        }
        if(x==root->date)return;        //不允许有重复元素
        else if(x<root->date)
            insert(root->left,x);
        else
            insert(root->right,x);
    }
    BinTreeNode*bulidTree(int a[],int n)
    {
        BinTreeNode*root=NULL;
        for(int i=0; i<n; i++)
        {
            insert(root,a[i]);
        }
        return root;
    }
    vector<int>Inorder(BinTreeNode*root)        //中序遍历二叉树输出从小到大
    {
        vector<int>result;
        Inorder(root,result);
        return result;
    }
    void Inorder(BinTreeNode*root,vector<int>&result)
    {
        if(root==NULL)
            return;
        Inorder(root->left,result);
        result.push_back(root->date);
        Inorder(root->right,result);
    }
    vector<int>InorderMirror(BinTreeNode*root)   //  镜像  中序遍历二叉树输出从大到小
    {
        vector<int>result1;
        InorderMirror(root,result1);
        return result1;
    }
    void InorderMirror(BinTreeNode*root,vector<int>&result1)
    {
        if(root==NULL)
            return;
        InorderMirror(root->right,result1);
        result1.push_back(root->date);
        InorderMirror(root->left,result1);
    }
};
int main()
{
    int a[]= {4, 5,8,3,5,3,6,2,1,7};
    int b[]= {4, 5,8,3,5,3,6,2,1,9};
    int n=sizeof(a)/sizeof(int);
    Solution obj;
    BinTreeNode* root=obj.bulidTree(a,n);

    vector<int>result=obj.Inorder(root);
    vector<int>result1=obj.InorderMirror(root);
    for(int i=0; i<result.size(); i++)
    {
        cout<<result[i];
        if(i<result.size())
            cout<<" ";
    }
    cout<<endl;

    for(int i=0; i<result1.size(); i++)
    {
        cout<<result1[i];
        if(i<result1.size())
            cout<<" ";
    }
    cout<<endl;

    vector<int>v1(a,a+n);
    vector<int>v2(b,b+n);    //比较两个二叉树是否相等
    if(v1==v2)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}
