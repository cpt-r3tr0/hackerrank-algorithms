#include <cstdlib>
#include <cstring>
#include <climits>
#include <cstdio>
#include <cmath>
#include <ctime>

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define int64 long long

int64 countOnes(int64 X)
{
    if(X <= 0) return 0;
    else if(X == 1) return X;
    else
    {
        int cnt = 0;
        int64 i;
        for(i=31;i>=0;i--)
            if(X >= (1LL << i))
                break;
        return countOnes(X - (1LL << i)) + ((1LL << i) * i / 2LL) + (X - (1LL << i) + 1LL);
    }
}

void solve()
{
    int64 A, B;
    cin >> A >> B;
    if(0 <= A && 0 <= B)
        cout << countOnes(B) - countOnes(A-1) << endl;
    else if(A < 0 && B < 0)
    {
        B ++;
        cout << ((32LL * (- A)) - countOnes(- A - 1)) - ((32LL * (- B)) - countOnes(- B - 1)) << endl;
    }
    else
        cout << countOnes(B) + ((32LL * -A) - countOnes(-A - 1)) << endl;
}

int main()
{
    int test;
    cin >> test;
    while(test--)
        solve();

    return 0;
}
