#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, *arr;
    cin>>n;
    arr = new int[n];
    for (int i = 0 ; i < n ; i++) cin>>arr[i];
    sort(arr,arr+n);

    (n%2 == 1 ) ? cout<<arr[(n-1)/2]<<endl : cout<<(arr[n/2 - 1]+arr[n/2])/2<<endl;

    return 0;
}
