#include<iostream>
#include<vector>
#include<queue>
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
BinTreeNode* getPreorder(int post[],int in[],int n)
{
    int i,ll,lr;
    int *postleft;
    int *postright;
    int *inleft;
    int *inright;
    BinTreeNode*root;
    for(i=0; i<n; i++)
    {
        if(post[n-1]==in[i])
        {
            ll=i;
            lr=n-1-ll;
            root=new BinTreeNode(post[n-1]);
            if(ll)
            {
                postleft=new int[ll];
                inleft=new int[ll];
                for(int j=0; j<ll; j++)
                {
                    postleft[j]=post[j];
                    inleft[j]=in[j];
                }
                root->left=getPreorder(postleft,inleft,ll);
            }
            if(lr)
            {
                postright=new int[lr];
                inright=new int[lr];
                for(int j=0; j<lr; j++)
                {
                    postright[j]=post[j+ll];
                    inright[j]=in[j+1+ll];
                }
                root->right=getPreorder(postright,inright,lr);
            }
            break;
        }
    }
    return root;
}
vector<int>Levelorder(BinTreeNode*root)
{
    vector<int>v1;
    if(root==NULL)return v1;
    queue<BinTreeNode*>que;
    BinTreeNode*p=root;
    que.push(p);
    while(!que.empty())
    {
        p=que.front();
        que.pop();
        v1.push_back(p->date);
        if(p->left)que.push(p->left);
        if(p->right)que.push(p->right);
    }
    return v1;
}
int main(int argc,char const* argv[])
{
    int n;
    cin>>n;
    int *a=new int[n];
    int *b=new int[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int j=0; j<n; j++)
    {
        cin>>b[j];
    }
    BinTreeNode*root=getPreorder(a,b,n);
    vector<int>v=Levelorder(root);
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i];
        if(i<v.size()-1)
            cout<<" ";
    }
    cout<<endl;
    return 0;
}
