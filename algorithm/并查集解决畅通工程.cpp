#include<iostream>
#include<algorithm>
using namespace std;

/*
畅通工程
*/

struct load{  //修路结构体
    int a; //a,b路两端的两个村庄
    int b;
    int price; //价格
    bool operator<(const load&A) const{  //重载<运算符，根据price从小到大排序
        return price<A.price;
    }
}loads[5000];  //村庄数<100,估算路最多为4950

int parent[100];  //记录节点父亲的数组

int findRoot(int n){
    if(parent[n]==-1){
        return n;
    }else{
        int par=findRoot(parent[n]);
        parent[n]=par;
        return par;
    }
}

int main(){
    int n,m;  //n-道路条数，m-村庄个数
    cin>>n>>m;
    for(int i=0;i<m;i++){ //开始时各个节点独立，所以初始化节点父亲为-1
        parent[i]=-1;
    }
    for(int i=0;i<n;i++){  //输入道路信息
        cin>>loads[i].a;
        cin>>loads[i].b;
        cin>>loads[i].price;
    }
    sort(loads,loads+n); //排序
    int prices=0;   //统计价格
    for(int i=0;i<n;i++){
        int x=findRoot(loads[i].a);
        int y=findRoot(loads[i].b);
        if(x!=y){  //不属于同一集合，合并
            parent[y]=x;
            prices+=loads[i].price;
        }
    }
    cout<<prices<<endl;
}

