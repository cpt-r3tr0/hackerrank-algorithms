#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class disjoint_set {
    vector<int> rep;
    vector<int> rank;
public:
    disjoint_set(int n) : rep(n), rank(n, 1) {
        for(int i = 0; i != n; ++i)
            rep[i] = i;
    }
    int find(int v);
    bool join(int v1, int v2);
    vector<int> make_array();
};

int disjoint_set::find(int v) {
    if(rep[v] != v)
        rep[v] = find(rep[v]);
    return rep[v];
}

bool disjoint_set::join(int v1, int v2) {
    v1 = find(v1);
    v2 = find(v2);
    if(v1 == v2)
        return false;
    if(rank[v1] > rank[v2]) {
        rep[v2] = v1;
        rank[v1] += rank[v2];
    }
    else {
        rep[v1] = v2;
        rank[v2] += rank[v1];
    }
    return true;
}

vector<int> disjoint_set::make_array() {
    vector<int> result;
    for(int i = 0; i != rep.size(); ++i) {
        if(rep[i] == i)
            result.push_back(rank[i]);
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    for(int i_t = 0; i_t < t; ++i_t) {
        int n, m, c = 0;
        cin >> n >> m;
        disjoint_set friends(n + 1);
        for(int i = 0; i != m; ++i) {
            int v1, v2;
            cin >> v1 >> v2;
            if(!friends.join(v1, v2))
                ++c;
        }
        long long total = 0, sum = 0;
        vector<int> sizes = friends.make_array();
        sort(sizes.begin(), sizes.end(), greater<int>());
        for(int i = 0; i != n; ++i) {
            long long n = sizes[i] - 1;
            if(n == 0)
                break;
            total += sum * n + n*(n + 1)*(n + 2)/3;
            sum += n*(n + 1);
        }
        total += sum*c;
        cout << total << endl;
    }
    return 0;
}
