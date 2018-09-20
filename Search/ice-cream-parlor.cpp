#include <cmath>
#include <cstdio>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int C, L;
        cin >> C >> L;
        vector<int> v(L);
        map<int, int> M;
        for (int j = 0; j < L; ++j)
            cin >> v[j];

        for (int j = 0; j < L; ++j) {
            int diff = C - v[j];
            if (M.count(diff)) {
                cout << 1 + M[diff] << " " << 1 + j << endl;
                break;
            }
            M[v[j]] = j;
        }
    }
    return 0;
}
