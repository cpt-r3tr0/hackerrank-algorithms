#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define li long long
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin>>T;
    while(T--)
    {
        li N;
        cin>>N;
        bool buzz=true;
        int i,j,k;
        string s1,s2;
        vector<string> a(N);
        for(i=0;i<N;i++)
        {
            cin>>a[i];
        sort(a[i].begin(),a[i].end());
        }
        for(j=0;j<N;j++)
        {
            for(i=1;i<N;i++)
            {
                if(a[i][j] < a[i-1][j])
                    buzz=false;
            }
        }
        if(buzz)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
