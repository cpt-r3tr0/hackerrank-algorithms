#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    long long cur = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (cur + v[i] > K) {
            cout << i << endl;
            return 0;
        } else
            cur+= v[i];
    }
    cout << N << endl;
    return 0;
}
