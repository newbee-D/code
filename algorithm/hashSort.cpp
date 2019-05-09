#include<iostream>
using namespace std;

int so[1000];

int main(){
    int n;
    while(cin>>n){
        if(n==0){
            break;
        }
        for(int i=0;i<1000;i++){
            so[i]=0;
        }
        for(int i=0;i<n;i++){
            int s;cin>>s;
            so[s]++;
        }
        for(int i=0;i<1000;i++){
            if(so[i]>0){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
}
