#include <bits/stdc++.h>



const long double PI = 3.1415926535897932384626433832795;

using namespace std;

long long aabs(long long a){
	if (a<0) return -a;
	return a;
}

long long gcd(long long a, long long b){
	a=aabs(a);
	b=aabs(b);
	while (a>0 && b>0) {
		if (a>b) {
			a%=b;
		}
		else {
			b%=a;
		}
	}
	return a+b;
}

long long pow(long long a, int n, long long mm){
	if (n==0) return 1%mm;
	long long t=pow(a,n/2,mm);
	t=(t*t)%mm;
	if (n&1){
		t=(t*a)%mm;
	}
	return t;
}

multiset<long long> a;
vector<long long> nm;
int n, k;

void sb(int st, long long sm, int cnt){
	if (cnt == k){
		a.erase(a.find(sm));
		return;
	}
	for (int i = 0; i <= st; i++){
		sb(i, sm + nm[i], cnt + 1);
	}
}

void solve(){
	a.clear();
	nm.clear();
	cin >> n >> k;
	if (k == 1){
		for (int i = 0; i < n; i++){
			long long t;
			cin >> t;
			cout << t << ' ';
		}
		cout << '\n';
		return;
	}
	string s;
	getline(cin, s);
	getline(cin, s);
	stringstream ss;
	ss << s;
	long long t;
	while (ss >> t){
		a.insert(t);
	}
	long long fs = (*(a.begin())) / k;
	cout << fs << ' ';
	nm.push_back(fs);
	sb(0,0,0);
	for (int i = 1; i < n; i++){
		long long cr = *(a.begin()) - (k-1)*fs;
		cout << cr << ' ';
		nm.push_back(cr);
		sb(nm.size() - 1, cr, 1);
	}
	cout << '\n';
}

int main(){
	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		solve();
	}
	return 0;
}
