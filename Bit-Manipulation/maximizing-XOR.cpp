#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/*
 * Complete the function below.
 */
int maxXor(int l, int r) {

    int i,j;
    int mx = -1000000000;
    for(i=l;i<=r;i++){
        for(j=i;j<=r;j++){
            mx = max(mx,i^j);
        }
    }
    return mx;
}

int main() {
    int res;
    int _l;
    cin >> _l;

    int _r;
    cin >> _r;

    res = maxXor(_l, _r);
    cout << res;

    return 0;
}
