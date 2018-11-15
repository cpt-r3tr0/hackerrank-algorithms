#include <bits/stdc++.h>
#define abs(x) ((x) < 0?-(x):(x))
#define uint unsigned int
using namespace std;

int gcd(int x, int y) {
    if(x > y) swap(x,y);
    while(x > 0) {
        int z =x;
        x =y%x;
        y =z;
    }
    return y;
}

int main() {
    int N;
    cin >> N;
    vector<int> start(N);
    for(int i =0; i < N; i++) cin >> start[i];
    set<int> su;
    for(int i =0; i < N; i++) su.insert(start[i]);
    start.clear();
    for(auto x:su) start.push_back(x);
    N =start.size();
    int rep =0;
    while(N > 0) {
        if(start[0] == 1 && rep > 0) {
            rep +=start[N-1];
            break;
        }
        for(int i =1; i < N; i++) if(start[i]-start[i-1] == 1) {
            rep +=start[N-1]-start[0]+1;
            cout << rep << "\n";
            return 0;
        }
        if(N < 50) {
            vector<int> v;
            for(int i =0; i < N; i++) for(int j =0; j < i; j++) if(start[i] != start[j])
                v.push_back(start[i]-start[j]);
            sort(begin(v),end(v));
            start.clear();
            int g =0;
            for(int i =0; i < (int)v.size(); i++) g =gcd(g,v[i]);
            if(g > 0) for(int i =0; i < (int)v.size(); i++)
                if(i == 0 || v[i] != v[i-1]) start.push_back(v[i]/g);
            N =start.size();
            rep++;
            continue;
        }
        vector<int> occ(start[N-1]+1,0);
        for(int i =0; i < N; i++) for(int j =0; j < i; j++) if(start[i] != start[j])
            occ[start[i]-start[j]] =1;
        start.clear();
        int g =0;
        for(int i =1; i < (int)occ.size(); i++) if(occ[i]) g =gcd(g,i);
        if(g > 0) for(int i =g; i < (int)occ.size(); i +=g)
            if(occ[i]) start.push_back(i/g);
        N =start.size();
        rep++;
    }
    cout << rep << "\n";
    return 0;
}
