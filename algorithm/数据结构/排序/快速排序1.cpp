 #include<iostream>
 #include<algorithm>
 using namespace std;

 void quick_sort(int a[],int p,int r)
 {
            int key=a[(p+r)/2];              //选择中间的数做划界元素
            int i=p;int j=r;
            while(i<=j){
                      while(a[i]<key&&i<r) i++;
                      while(a[j]>key)j--;
                      if(i<=j)
                      {
                                 swap(a[i],a[j]);
                                 i++;
                                 j--;
                      }
            }
            if(j>p)quick_sort(a,p,j);
            if(i<r)quick_sort(a,i,r);
 }
 int main()
 {
            int a[]={2,4,6,7,8,9,3,2,1};
            int n=sizeof(a)/sizeof(int);
            quick_sort(a,0,n-1);
            for(int i=0;i<n;i++)
                    {
                               cout<<a[i];
                               if(i<n-1)
                                 cout<<" ";
                    }
                    return 0;

 }
