 #include<iostream>
 using namespace std;
 int add(int a[],int len)
 {
     if(len==1)
        return a[0];
     else
     {
         return a[0]+add(a+1,len-1);
     }
 }
 int main()
 {
     int a[]={1,2,3,4,5,6};
     add(a,sizeof(a)/sizeof(int));
     cout<<add(a,sizeof(a)/sizeof(int));
     return 0;
 }
