#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> A;
    int n;cin>>n;
    A.push_back(n);
    while(cin.get()!='\n'){
        cin>>n;
        A.push_back(n);
    }

    return 0;
}
