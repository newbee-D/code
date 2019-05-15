#include<iostream>
using namespace std;
void convert(int N,int B)
{
    if(N<B)
    {
        if(N>=10)
        {
            cout<<(char)('A'+N-10);
        }
        else{
            cout<<N;
        }
    }
    else
    {
        convert(N/B,B);
        int t=N%B;
        if(t>=10)
        {
            cout<<(char)('A'+t-10);
        }
        else
            cout<<t;
    }
}
int main()
{
    int B,N;
    while(cin>>N>>B)
    {
        convert(N,B);
    }
    return 0;
}
