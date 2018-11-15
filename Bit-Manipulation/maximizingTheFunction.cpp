#include <bits/stdc++.h>

using namespace std;

#define foreach(i,x) for(type(x)i=x.begin();i!=x.end();i++)
#define FOR(ii,aa,bb) for(int ii=aa;ii<=bb;ii++)
#define ROF(ii,aa,bb) for(int ii=aa;ii>=bb;ii--)

#define type(x) __typeof(x.begin())

#define orta (bas + son >> 1)
#define sag (k + k + 1)
#define sol (k + k)

#define pb push_back
#define mp make_pair

#define nd second
#define st first

#define endl '\n'

typedef pair < int ,int > pii;

typedef long long ll;

const long long linf = 1e18+5;
int mod = (int) 1e9 + 7;
const int logN = 18;
const int inf = 1e9 + 9;
const int N = 1e6 + 5;

int n, q, x, t, pre[N], l, r, k;

int main() {

    scanf("%d %d", &n, &q);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        pre[i + 1] = pre[i] + (t ^= x);
    }

    for(int i = 0; i < q; i++) {
        scanf("%d %d %d", &l, &r, &k);
        if(k != 0) {
            int t = r - l + 2;
            printf("%lld\n", (t / 2) * (ll) (t - t / 2));
        }
        else {
            int t = r - l + 2, s = pre[r + 1] - pre[max(l - 1, 0)];
            printf("%lld\n", s * (ll)(t - s));
        }
    }

    return 0;
}
