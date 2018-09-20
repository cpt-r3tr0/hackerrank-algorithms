#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define MAXn 100001

int N;
int arr[MAXn];

ll mergesort(int low, int high){

    if(low >= high)
		return 0;

	int mid = (low+high)/2;

	ll r_ans = 0;
	r_ans = mergesort(low, mid) + mergesort(mid+1, high);

    vector<int> v;

    int i, j, k;

    i = low; j = mid + 1;
	while(i <= mid && j <= high){
		if(arr[i] > arr[j]){
			v.push_back(arr[j]);
			r_ans+=(ll)(mid-i+1);
			j++;
		}else{
			v.push_back(arr[i]);
			i++;
		}
	}
	while(i <= mid){
		v.push_back(arr[i]);
		i++;
	}
	while(j <= high){
		v.push_back(arr[j]);
		j++;
	}
	for(i = 0; i < v.size(); i++)
		arr[i + low] = v[i];
	return r_ans;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int test;
    scanf("%d", &test);
    while(test--){
        int i;
        scanf("%d", &N);
        for(i=0; i<N; i++)
            scanf("%d", &arr[i]);
        ll ans = mergesort(0, N-1);
        printf("%lld\n", ans);
    }
    return 0;
}
