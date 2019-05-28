#include<iostream>
#include<queue>
using namespace std;

/*
����һ��ģ�⹫԰�Ķ�ά����,�Լ���ά
���У�1-��ڣ�-1-���ڣ�0-�ϰ��2-��ͨ����·����ֻ��һ������ڲ�ֹһ��
�ʣ���������ڵ����ڵ����·��
��������·����û�������-1��
*/

int park[50][50]; //�洢��԰����
int mark[50][50]; //������飬�������ĵ��Ϊtrue
int ins[100];//��¼ÿһ����ڵ����·��
int util[4][2]={{0,1},{0,-1},{1,0},{-1,0}}; //ת�����飬ÿһ������ֻ����������
//�ṹ�壬��¼����ÿһ������·����tΪ·������
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
    int n,m; //���鳤��
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
    queue<T> in; //��¼�������
    queue<T> sea; //��¼����������
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
        while(!sea.empty()){ //��ն���
            sea.pop();
        }
        sea.push(in.front());
        in.pop();
        ins[bbbbb]=bfs(sea,n,m);
        bbbbb++;
    }
    int res=ins[0];//��¼��С���
    for(int i=0;i<aaaaa;i++){
        if(aaaaa==1 && ins[i]==-1){
            res=-1;break;
        }
        res=ins[i]<res?ins[i]:res;
    }
    cout<<res<<endl;
    return 0;
}
