#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int q;cin>>q;
    while(q--)
    {
        ll n;cin>>n;
        ll a[n][n];
        vector<ll>v1(n),v2(n);
        for(ll i=0;i<n;i++)
            for(ll j=0;j<n;j++){
                cin>>a[i][j];
                v2[j]+=a[i][j];
                v1[i]+=a[i][j];
            }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        bool flag=1;
        for(ll i=0;i<n;i++)
            if(v1[i]!=v2[i])
                flag=0;
        if(flag)cout<<"Possible"<<"\n";
        else cout<<"Impossible"<<"\n";
    }
    return 0;
}
