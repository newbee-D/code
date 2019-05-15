#include<iostream>
#include<vector>
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
void getPostorder(int pre[],int in[],int n)
{
    int i,ll,lr;
    int *preleft;
    int *preright;
    int *inleft;
    int *inright;
    for(i=0; i<n; i++)
    {
        if(pre[0]==in[i])
        {
            ll=i;
            lr=n-1-ll;
            if(ll)
            {
                preleft=new int[ll];
                inleft=new int[ll];
                for(int j=0; j<ll; j++)
                {
                    preleft[j]=pre[j+1];
                    inleft[j]=in[j];
                }
                getPostorder(preleft,inleft,ll);
            }
            if(lr)
            {
                preright=new int[lr];
                inright=new int[lr];
                for(int j=0; j<lr; j++)
                {
                    preright[j]=pre[j+1+ll];
                    inright[j]=in[j+1+ll];
                }
                getPostorder(preright,inright,lr);
            }
            cout<<" "<<pre[0];
            break;
        }
    }
}
BinTreeNode* getPostorderTree(int pre[],int in[],int n)
{
    int i,ll,lr;
    int *preleft;
    int *preright;
    int *inleft;
    int *inright;
    BinTreeNode* root;
    for(i=0; i<n; i++)
    {
        if(pre[0]==in[i])
        {
            root=new BinTreeNode(pre[0]);
            ll=i;
            lr=n-1-ll;
            if(ll)
            {
                preleft=new int[ll];
                inleft=new int[ll];
                for(int j=0; j<ll; j++)
                {
                    preleft[j]=pre[j+1];
                    inleft[j]=in[j];
                }
                root->left=getPostorderTree(preleft,inleft,ll);
            }
            if(lr)
            {
                preright=new int[lr];
                inright=new int[lr];
                for(int j=0; j<lr; j++)
                {
                    preright[j]=pre[j+1+ll];
                    inright[j]=in[j+1+ll];
                }
                root->right=getPostorderTree(preright,inright,lr);
            }
            cout<<" "<<pre[0];
            break;
        }
    }
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
    getPostorder(a,b,n);
    cout<<endl;
    BinTreeNode* root=getPostorderTree(a,b,n);
    return 0;
}
