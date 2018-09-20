#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;

int gInt () {
    int i;
    scanf("%d", &i);
    return i;
}

lli gLong () {
    lli i;
    scanf("%lld", &i);
    return i;
}

double gDouble () {
    double i;
    scanf("%lf", &i);
    return i;
}

void quit () {
    fflush(stdout);
    exit(0);
}

int pars[100005];
list <int> children[100005];
int n;
int t;
int bit[100005];
lli ans;

inline void chgNum (int num, int chg) {
    while (num <= n) {
        bit[num] += chg;
        num += (num & -num);
    }
}

inline int readNum (int num) {
    int read = 0;
    while (num > 0) {
        read += bit[num];
        num -= (num & -num);
    }
    return read;
}

void rec (int node) {
    int trueNum = node + 1;
    int upper = min(n, trueNum + t);
    int lower = max(0, trueNum - t - 1);
    int freq = readNum(upper) - readNum(lower);
    ans += freq;
    chgNum(trueNum, 1);
    for (auto it = children[node].begin(); it != children[node].end(); it ++)
        rec(*it);
    chgNum(trueNum, -1);
}

int main (int argc, char ** argv) {
    n = gInt();
    t = gInt();
    for (int i = 0; i < n; i ++) {
        pars[i] = -1;
    }
    for (int i = 0; i < n - 1; i ++) {
        int par = gInt() - 1, child = gInt() - 1;
        pars[child] = par;
        children[par].push_back(child);
    }
    for (int i = 0; i < n; i ++) {
        if (pars[i] == -1)
            rec(i);
    }
    printf("%lld\n", ans);
    quit();
}
