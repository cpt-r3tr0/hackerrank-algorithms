#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define clr() clear()
#define ff first
#define ss second
#define umap unordered_map
#define fr(i,n) for(int i=0;i<n;++i)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, ll> cp;
typedef pair<int, int> pii;
typedef pair<long, int> pli;
typedef pair<int, long> pil;
typedef pair<long, long> pll;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<bool> vb;

int n, m;

vi cash;
vll masks;
vector<umap<ll, cp> > memo;

void init()
{
    cash.resize(n);
    masks.resize(n, 0);
    memo.resize(n);
}

bool isset(ll x, int pos)
{
    if(((1<<pos)&x)!=0) return 1;
    return 0;
}


cp maxpos(int idx, ll mask)
{
    if(idx==n){
        return mp(0, 1);
    }
    if(memo[idx].find(mask)!=memo[idx].end()) return memo[idx][mask];
    cp ans=maxpos(idx+1, mask);
    if(!isset(mask, idx)){
        cp tmp=maxpos(idx+1, (mask|masks[idx]));
        tmp.ff+=cash[idx];
        if(tmp.ff>ans.ff) ans=tmp;
        else if(tmp.ff==ans.ff)ans.ss+=tmp.ss;
    }
    memo[idx][mask]=ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    init();
    for(int i=0; i<n; ++i){
        cin>>cash[i];
    }
    int a, b;
    for(int i=0; i<m; ++i){
        cin>>a>>b;
        --a; --b;
        if(a>b)swap(a, b);
        masks[a]|=(1<<b);
    }
    //for(auto j:masks) cout<<j<<" ";
    //cout<<"\n";
    cp ans=maxpos(0, 0);
    cout<<ans.ff<<" "<<ans.ss;
    return 0;
}
