#include<iostream>
#include<queue>
using namespace std;

/*
给定一个模拟公园的二维数组,以及二维
其中：1-入口，-1-出口，0-障碍物，2-可通过的路出口只有一个，入口不止一个
问：给出由入口到出口的最短路径
输出：最短路径，没有则输出-1；
*/

int park[50][50]; //存储公园数据
int mark[50][50]; //标记数组，已搜索的点过为true
int ins[100];//记录每一个入口的最短路径
int util[4][2]={{0,1},{0,-1},{1,0},{-1,0}}; //转向数组，每一点走向只有上下左右
//结构体，记录到达每一点的最短路径，t为路径长度
struct T{
    int x;
    int y;
    int t;
};

int bfs(queue<T> &sea,int n,int m){
    while(!sea.empty()){
        T t2=sea.front();
        sea.pop();
        for(int i=0;i<4;i++){
            int px=t2.x+util[i][0];
            int py=t2.y+util[i][1];
            if(park[px][py]==-1){
                return t2.t+1;
            }
            if(px<0||px>=n||py<0||py>=m){
                continue;
            }
            if(mark[px][py]==true){
                continue;
            }
            T t3;
            t3.x=px;t3.y=py;t3.t=t2.t+1;
            sea.push(t3);
        }
    }
    return -1;

}

int main(){
    int n,m; //数组长宽
    cin>>n>>m;
    int aaaaa=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>park[i][j];
            if(park[i][j]==0){
                mark[i][j]=true;
            }
            mark[i][j]=false;
        }
    }
    queue<T> in; //记录所有入口
    queue<T> sea; //记录所有搜索点
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(park[i][j]==1){
                aaaaa++;
                mark[i][j]=true;
                T t1;
                t1.x=i;t1.y=j;t1.t=0;
                in.push(t1);
            }
        }
    }

    int bbbbb=0;
    while(!in.empty()){
        while(!sea.empty()){ //清空队列
            sea.pop();
        }
        sea.push(in.front());
        in.pop();
        ins[bbbbb]=bfs(sea,n,m);
        bbbbb++;
    }
    int res=ins[0];//记录最小结果
    for(int i=0;i<aaaaa;i++){
        if(aaaaa==1 && ins[i]==-1){
            res=-1;break;
        }
        res=ins[i]<res?ins[i]:res;
    }
    cout<<res<<endl;
    return 0;
}
