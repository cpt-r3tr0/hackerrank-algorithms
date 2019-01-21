#include <bits/stdc++.h>

using namespace std;
#define ll long long int
vector<string> vs , distr;
map<string , int > mp;

void f( string s , int &N   ) {
	if( mp[s] ) return;
	mp[s] = 1;
	char ch = s[s.size()-1];
	for( int i = 0; i < N; i++ ) {
		if( vs[i][0] > ch ) f( s+vs[i] , N );
	}
	distr.push_back(s);
}

long long int dp[200][12];
int DISTR;

long long int MOD = 1000000007;

long long int f1( int len , int lastchar ) {

	if( len <= 0 ) return 1;
	long long int &ret = dp[len][lastchar];
	if( ret == -1ll ) {
		ret = 0ll;
		for( int i = 0; i < DISTR; i++ ) {
			int tsz = distr[i].size();
			int fs = distr[i][0]-'a' , ls = distr[i][tsz-1]-'a';
			if( (tsz <= len) &&  (fs) <= lastchar ) ret += f1( len-tsz , ls );
			ret %= MOD;
		}
	}
	return ret;
}
int main () {
	int N , L;mp.clear();
	scanf("%d %d" , &N , &L );
	for( int i = 0; i < N; i++ ) {
		string s; cin >> s;
		vs.push_back(s);
	}

	f( "" , N );
	int sz = distr.size()-1;
	distr.resize(sz);DISTR = sz;

	sort( distr.begin()  , distr.end() );
	memset( dp , -1  , sizeof(dp) );
	ll ans = 0;
	for( int i = 0; i <= L; i++ ) {
		ans += f1( i , 11 );
		ans %= MOD;
	}
	cout << ans << "\n";

	return 0;
}
