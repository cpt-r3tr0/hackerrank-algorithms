#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll val = 4294967295L;
int main() {
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        ll cur;
        cin >> cur;
        cout << (val-cur) << endl;
    }
    return 0;
}
