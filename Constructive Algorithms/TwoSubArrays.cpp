#include <bits/stdc++.h>

using namespace std;

const int maxn = 200005;

int s[maxn],f[55],n,ans,co,len;

int main()
{
    scanf("%d", &n);
    for(int i = 1;i <= n;i ++) scanf("%d", &s[i]),s[i] += s[i - 1];
    co = n;
    for(int r = n,mx = -(1 << 30);r;r --)
    {
        mx = max(mx,s[r]);
        if (mx - s[r] > 850) continue;
        memset(f,0,sizeof f);
        int inc = 0;
        for(int l = r;l;l --)
        {
            if (l != r && s[l] >= s[r]) break;
            if (s[l] - s[l - 1] > 0)
            {
                int v = s[l] - s[l - 1];
                for(int p = v + 1;p <= 41;p ++)
                    f[v] = max(f[v],f[p] + v);
                inc = max(inc,f[v]);
            }
            int g = s[r] - s[l - 1] - inc;
            if (g > ans) ans = g,len = r - l + 1,co = 1; else
                if (g == ans)
                {
                    if (r - l + 1 < len) len = r - l + 1,co = 1; else
                        if (r - l + 1 == len) ++ co;
                }
        }
    }
    cout << ans << " " << co << endl;
    return 0;
}
