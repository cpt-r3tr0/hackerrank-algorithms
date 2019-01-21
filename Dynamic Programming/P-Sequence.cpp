#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

void add(int& a, int b){
    a += b;
    if(a >= mod) a -= mod;
}

int main(){
    int n, p; cin >> n >> p;

    vector<int> a, b;
    int sz = 0;
    for(int cur = 1, nxt; cur <= p; cur = nxt + 1, ++sz)
        a.push_back(cur), b.push_back(nxt = p / (p / cur));

    vector<int> val(sz, 1), nxt(sz);
    for(; n-- > 1; val = nxt)
        for(int pos = 0, cur = 0, sum = 0, i = sz-1; i >= 0; --i)
    {
        int end = p / a[i];
        if(b[pos] >= end)
            add(sum, (end - cur + 0LL) * val[pos] % mod);
        else{
            add(sum, (b[pos] - cur + 0LL) * val[pos] % mod);
            ++pos;
            add(sum, (end - a[pos] + 1LL) * val[pos] % mod);
        }
        nxt[i] = sum, cur = end;
    }

    int ret = 0;
    for(int i = 0; i < sz; ++i) add(ret, (b[i] - a[i] + 1LL) * val[i] % mod);
    cout << ret << "\n";
    return 0;
}
