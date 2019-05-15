#include<iostream>
using namespace std;
void depart(int*a,int n,int k)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int*first=a;
        int*last=a+n;
        while(i<n){
        if(*first>k && *last<k)
        {
            int b=*last;
            *last=*first;
            *first=b;
            first++;
            last--;
            i++;
            sum++;
        }
        else if(*first>k && *last>k){last--;i++;}
        else if(*first<k && *last>k){first++;sum++;i++;}
        else {
            first++;
            i++;
        }
    }
    }
    cout<<sum<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
int main()
{
    int n,k;
    while(cin>>n)
    {
       cin>>k;
       int a[n];
       for(int i=0;i<n;i++)
        cin>>a[i];
       depart(a,n,k);
       cout<<endl;
    }
    return 0;
}
