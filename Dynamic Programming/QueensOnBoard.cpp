#include <bits/stdc++.h>

using namespace std;

const int N = 50;
const int M = 1000000007;

int arr[N];
int dp[N][8*8*8*8*8][2];
int rows, cols, all;

bool validHoriz(int queenMask, int blockedMask) {
    assert((queenMask & blockedMask) == 0);
    bool hasPrev = false;
    for (int i = 0, m = 1; i < cols; i++, m <<= 1) {
        if (blockedMask & m)
            hasPrev = false;
        else if (queenMask & m) {
            if (hasPrev) return false;
            hasPrev = true;
        }
    }
    return true;
}

int getRayMask(int rayState) {
    int res = 0;
    for (int i = 0, m = 1; i < cols; i++, m <<= 1) {
        if (rayState & 7)
            res |= m;
        rayState >>= 3;
    }
    return res;
}

int getNextRayState(int rayState, int queenMask) {
    int res = 0;
    for (int i = 0, m = 1; i < cols; i++, m <<= 1) {
        if (((rayState & 1) || (queenMask & 1)) && (i > 0)) res |= (1 << (3 * (i-1)));
        if ((rayState & 2) || (queenMask & 1)) res |= (2 << (3 * i));
        if (((rayState & 4) || (queenMask & 1)) && (i+1 < cols)) res |= (4 << (3 * (i+1)));
        rayState >>= 3;
        queenMask >>= 1;
    }
    return res;
}

void updateRay(int& rayState, int blockedMask) {
    int blockMask = 7;
    for (int i = 0; i < cols; i++, blockMask <<= 3) {
        if (blockedMask & 1) rayState &= ~blockMask;
        blockedMask >>= 1;
    }
}

int go(int row, int rayState, int placed) {
    if (row == rows) return placed;
    int& res = dp[row][rayState][placed];
    if (res >= 0) return res;
    res = 0;
    int forbiddenMask = arr[row] | getRayMask(rayState);
    for (int m = 0; m < all; m++) {
        if (m & forbiddenMask) continue;
        if (!validHoriz(m, arr[row])) continue;
        int nextPlaced = (placed || m != 0) ? 1 : 0;
        int nextRayState = getNextRayState(rayState, m);
        if (row+1 < rows) updateRay(nextRayState, arr[row+1]);
        res += go(row+1, nextRayState, nextPlaced);
        if (res >= M) res -= M;
    }
    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int t; cin >> t;
    while (t--) {
        cin >> rows >> cols;
        all = 1 << cols;
        for (int i = 0; i < rows; i++) {
            string s; cin >> s;
            arr[i] = 0;
            for (int j = 0, m = 1; j < cols; j++, m <<= 1) if (s[j] == '#') arr[i] |= m;
        }
        memset(dp, 0xff, sizeof(dp));
        cout << go(0, 0, 0) << endl;
    }

    return 0;
}
