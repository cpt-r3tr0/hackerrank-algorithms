#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n;
int cnt[1 << 10];


void readInp() {
  string x;
  cin >> n;
  for(int i = 1; i <= n; ++i) {
      cin >> x;
    int mask = 0;
      for(int j = 0; j < x.size(); ++j) mask |= (1 << (x[j] - '0'));
      ++cnt[mask];
  }
}

long long solve() {
   long long ans = 0;
   for(int m1 = 0; m1 <= 1023; ++m1)
       for(int m2 = 0; m2 <= 1023; ++m2)
        if((m1 | m2) == 1023)
            ans += m1 == m2 ? 1LL * cnt[m1] * (cnt[m1] - 1) : 1LL * cnt[m1] * cnt[m2];
    return ans / 2LL;
}

void out(long long x) {
    cout << x << endl;
}

int main() {
    readInp();
    out(solve());
    return 0;
}
