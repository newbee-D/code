#include<iostream>
#include<string.h>
using namespace std;

void strZIP(char* str,int strLen){
    char* strOut=new char[1024];
    int k=0,sum=1;
    for(int i=0;i<strLen;i++){
        if(str[i]==str[i+1]){
            sum++;
        }else{
            strOut[k]=sum+'0';
            strOut[k+1]=str[i];
            sum=1;
            k=k+2;
        }
    }
    for(int i=0;i<k;i++){
        cout<<strOut[i];
    }
    cout<<endl;
}

int main(){
    char* str=new char[1024];
    while(cin>>str){
        int strLen=strlen(str);
        if(strLen==1){
            cout<<"1"<<str<<endl;
        }else{
            strZIP(str,strLen);

        }
    }
    return 0;
}
