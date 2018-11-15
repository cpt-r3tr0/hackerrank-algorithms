#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef long long LL;
const int MOD = 1000000007;

int count(vector <int> cards, int k) {
    int res = 0;
    sort(cards.begin(), cards.end());

    LL t = 1;
    int n = cards.size();
    int tmp = cards[n-1];
    if (tmp == 0) return k == 0;
    while (tmp) {
      tmp >>= 1;
      t <<= 1;
    }
    if (k >= t) return 0;
    t >>= 1;

    // not set most sig bit
    LL cnt[102][2];
    memset(cnt, 0, sizeof(cnt));
    cnt[0][0] = 1;
    for (int i = 0 ; i < n-1 ; ++i) {
      for (int j = 0 ; j < 2 ; ++j) {
        cnt[i][j] %= MOD;
        if (cards[i] < t) {
          cnt[i+1][j] += (cnt[i][j] * (cards[i]+1)) % MOD;
        } else {
          cnt[i+1][j] += (cnt[i][j] * t) % MOD;
          cnt[i+1][j^1] += cnt[i][j] * (cards[i]-t+1) % MOD;
        }
      }
    }
    if (k < t) res += cnt[n-1][0];
    else res += cnt[n-1][1];
    res %= MOD;

    // set most sig bit
    vector<int> tc(cards);
    tc[n-1] -= t;
    res += count(tc, k^t);
    res %= MOD;

    return res;
}

int main() {
  int n;
  scanf("%d",&n);
  vector<int> c, c2;
  for (int i = 0 ; i < n ; i++) {
    int tmp;
    scanf("%d",&tmp);
    c.push_back(tmp);
    c2.push_back(tmp-1);
  }
  printf("%d\n", (count(c, 0) - count(c2, 0) + MOD) % MOD);
  return 0;
}
