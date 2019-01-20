#include <bits/stdc++.h>
using namespace std;

struct Edge { int y, cost; };
int n, m, A, B;
bool viz[1001][1024];
vector<Edge> g[1001];

void dfs(int x, int cost) {
    viz[x][cost] = true;
    for (Edge &e : g[x]) {
        if (!viz[e.y][cost | e.cost]) {
            dfs(e.y, cost | e.cost);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0, x, y, c; i < m; i++) {
        cin >> x >> y >> c;
        g[x].push_back({y, c});
        g[y].push_back({x, c});
    }

    cin >> A >> B;
    dfs(A, 0);

    for (int i = 1; i < 1024; ++i) {
        if (viz[B][i]) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
