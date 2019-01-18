#include<bits/stdc++.h>
using namespace std;

void swapPermutation(long long int arr[], int n, int k) {
  int pos[n + 1];
  for (int i = 0; i < n; ++i)
    pos[arr[i]] = i;
  for (int i = 0; i < n && k; ++i) {
    if (arr[i] == n - i)
      continue;
    int temp = pos[n - i];
    pos[arr[i]] = pos[n - i];
    pos[n - i] = i;
    swap(arr[temp], arr[i]);
    --k;
  }
  for(int i=0;i<n;++i)
    cout<<arr[i]<<" ";
}

int main(){
    int n,k;
    cin>>n>>k;
    long long int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    swapPermutation(a,n,k);



}
