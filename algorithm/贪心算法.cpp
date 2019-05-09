#include<iostream>
#include<algorithm>
using namespace std;

//定义节目结构体
struct show{
    int sTime;  //节目开始时间
    int eTime;  //节目结束时间
    //重载<运算符，按结束时间升序排列
    bool operator <(const show &A) const{
        return eTime<A.eTime;
    }
}shows[100];


int main(){
    int n;
    while(cin>>n){
        int res=1;  //统计可看节目个数
        if(n==0){  //n为0时结束
            break;
        }
        for(int i=0;i<n;i++){
        cin>>shows[i].sTime;
        cin>>shows[i].eTime;
        }
        sort(shows,shows+n);
        int t=0;
        for(int i=1;i<n;i++){
            if(shows[i].sTime>=shows[t].eTime){
                t=i;
                res++;
            }
        }
        cout<<res<<endl;
    }

}
