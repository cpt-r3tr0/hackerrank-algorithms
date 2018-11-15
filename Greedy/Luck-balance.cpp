#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,ans,t,x;
    vector<int> v;
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x>>t;
        if(t==0) ans+=x;
        else v.push_back(x);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    x=min(k,(int)v.size());
    for(int i=0;i<x;i++)
        ans+=v[i];
    for(int i=x;i<v.size();i++)
        ans-=v[i];
    cout<<ans<<endl;
}
