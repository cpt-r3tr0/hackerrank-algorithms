#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const long long MAX = 1e7;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long n,temp;
    cin>>n;
    vector<long long> a;
    for(long long i=0;i<n;i++){
        cin>>temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    long long diff=MAX;
    long long count=0;
    for(long long i=0;i<n-1;i++){
        if(a[i+1]-a[i]<diff){
            diff=a[i+1]-a[i];
            count=i;
        }
    }
    for(long long i=0;i<n-1;i++)
    	if(a[i+1]-a[i]==diff)cout<<a[i]<<" "<<a[i+1]<<" ";
    cout<<endl;
    return 0;
}
