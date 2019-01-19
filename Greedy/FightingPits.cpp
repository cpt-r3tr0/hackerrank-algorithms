#include <bits/stdc++.h>

using namespace std;
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int binary(vector<int> &l, int val) {
    int lo = 0;
    int hi = l.size();
    int mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (l[mid] == val)
            return mid;
        if (l[mid] > val)
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

int find_winner(int x, int y, vector<vector<int>> &l, unsigned long long x_sum, unsigned long long y_sum) {
    vector<int> &X = l[x];
    vector<int> &Y = l[y];
    int x_count = X.size() - 1;
    int y_count = Y.size() - 1;
    bool chance = true;
    while (true) {
        if (chance) {
            if (x_sum >= y_sum)
                return x;
            y_count -= X[x_count];
            if (y_count < 0)
                return x;
            for(int i = y_count + 1; i <= y_count + X[x_count]; i++) {
                y_sum -= Y[i];
            }
        } else {
            if (y_sum >= x_sum)
                return y;
            x_count -= Y[y_count];
            if (x_count < 0)
                return y;
            for (int i = x_count + 1; i <= x_count + Y[y_count]; i++) {
                x_sum -= X[i];
            }
        }

        chance = !chance;
    }
}

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<vector<int>> l;
    for (int i = 0; i <= k; i++) {
        vector<int> cur;
        l.push_back(cur);
    }

    vector<unsigned long long> sums;
    for (int i = 0; i <= k; i++) {
        sums.push_back(0);
    }

    int s, t;
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        l[t].push_back(s);
        sums[t] += s;
    }

    for (int i = 1; i <= k; i++) {
        sort(l[i].begin(), l[i].end());
    }

    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            l[y].insert(l[y].begin() + binary(l[y], x), x);
            sums[y] += x;
        } else {
            cout << find_winner(x, y, l, sums[x], sums[y]) << endl;
        }
    }
    return 0;
}
