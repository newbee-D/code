#include<iostream>
using namespace std;

struct star{
    int a;
    int b;
}stars[100000];

int main(){
    int n;cin>>n;
    int x,y;
    for(int i=0;i<n;i++){
        cin>>stars[i].a>>stars[i].b;
    }
    int m;cin>>m;
    while(m--){
        int a1,b1,a2,b2;
        int res=0;
        cin>>a1>>b1>>a2>>b2;
        for(int i=0;i<n;i++){
            if(stars[i].a>=a1 && stars[i].a<=a2 && stars[i].b>=b1 && stars[i].b<=b2){
                res++;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
