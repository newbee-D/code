#include<iostream>
#include<algorithm>
using namespace std;

//�����Ŀ�ṹ��
struct show{
    int sTime;  //��Ŀ��ʼʱ��
    int eTime;  //��Ŀ����ʱ��
    //����<�������������ʱ����������
    bool operator <(const show &A) const{
        return eTime<A.eTime;
    }
}shows[100];


int main(){
    int n;
    while(cin>>n){
        int res=1;  //ͳ�ƿɿ���Ŀ����
        if(n==0){  //nΪ0ʱ����
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
