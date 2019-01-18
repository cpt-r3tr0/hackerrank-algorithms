#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,i,e=0;
    cin>>n;
    long long int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=n-1;i>=0;i--){
        e=e+arr[i];
        if(e%2==0){
            e=e/2;
        }else{
            e=(e+1)/2;
        }
    }
    cout<<e;
    return 0;
}
