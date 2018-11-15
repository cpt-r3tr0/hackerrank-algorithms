#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main()
{
    //    Get input
    int n; cin >> n;
    vector<int> in(n, 0);
    for(int i = 0; i < n; i ++)
        cin >> in[i];

    //
    int maxbit = floor(log(*std::max_element(in.begin(), in.end()))/log(2));
    int k = -1;
    for (int bitcnt = maxbit - 1; bitcnt >= 0; bitcnt --)
    {
        bool bValid = true;
        unordered_map<int, unsigned> rec;
        for(auto v : in)
        {
            int vs = v >> bitcnt;
            rec[vs] ++;
            if(rec[vs] > (n/2))
            {
                bValid = false;
                break;
            }
        }
        if(!bValid)
        {
            continue;
        }
        k = bitcnt;
        break;
    }
    cout << k << endl;
    return 0;
}
