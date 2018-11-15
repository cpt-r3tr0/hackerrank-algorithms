#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using ull = unsigned long long;

constexpr int MAXN = 100000;
ull a[MAXN];
ull b[MAXN];

int main() {
    int n; ull m; cin >> n >> m;
    m -= 1;
    for (int i = 0; i != n; ++i) cin >> a[i];

    auto cr = a;
    auto nx = b;
    while (m) {
        int b = __builtin_ctzll(m);
        ull d = 1ULL << b;
        m ^= d;
        for (int i = 0; i != n; ++i) {
            nx[i] = cr[i] ^ cr[(i+d)%n];
        }
        swap(nx, cr);
    }
    for (int i = 0; i != n; ++i) {
        if (i) cout << ' ';
        cout << cr[i];
    }
    cout << '\n';
    return 0;
}
