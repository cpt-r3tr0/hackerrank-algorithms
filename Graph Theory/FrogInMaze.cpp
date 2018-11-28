#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define S2(x,y) scanf("%d%d",&x,&y)

typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n,m;
string s[20];
bool vis[20][20][2];
pii tunnel[20][20];
int M[20][20];

double G[400][400];
double X[400];

void dfs(int x, int y, int f) {
  // printf("%d %d\n",x,y);
  if(x < 0 || x >= n || y < 0 || y >= m) {
    return;
  }
  if(s[x][y] == '#' || s[x][y] == '*' || vis[x][y][f]) {
    return;
  }
  if(f && tunnel[x][y] != make_pair(x,y)) {
    dfs(tunnel[x][y].first, tunnel[x][y].second, 0);
    return;
  }
  vis[x][y][f] = true;
  if(s[x][y] == '%') {
    return;
  }
  for(int i = 0; i <4; i++){
    dfs(x + dx[i], y + dy[i], 1);
  }
}

int main() {
  int k;
  scanf("%d%d%d",&n,&m,&k);
  pii st;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
    for(int j = 0; j < m; j++){
      if(s[i][j] == 'A')
        st = make_pair(i,j);
      }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      tunnel[i][j] = make_pair(i,j);
    }
  }
  for(int i =0; i < k; i++) {
    int x1,y1;
    scanf("%d%d",&x1,&y1);
    x1--; y1--;
    int x2,y2;
    scanf("%d%d",&x2,&y2);
    x2--; y2--;
    tunnel[x1][y1] = make_pair(x2,y2);
    tunnel[x2][y2] = make_pair(x1,y1);
  }
  dfs(st.first, st.second, 0);
  int cnt = 0;
  memset(M, -1, sizeof(M));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(vis[i][j][0] || vis[i][j][1])
        M[i][j] = cnt++;
    }
  }

  int eq = 0;
  bool ok = false;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(vis[i][j][0] || vis[i][j][1]) {
        if(s[i][j] == '%') {
          ok = true;
          G[eq][M[i][j]] = 1.0;
          X[eq] = 1.0;
          eq++;
          continue;
        }
        vi v;
        int good = 0;
        for (int k =0; k<4; k++){
          int a = i + dx[k];
          int b = j + dy[k];
          if(a < 0 || a >= n || b < 0 || b >= m) continue;
          if(s[a][b] == '#') continue;
          if(tunnel[a][b] != make_pair(a,b)) {
            int aa = tunnel[a][b].first;
            int bb = tunnel[a][b].second;
            a = aa; b = bb;
          }
          good++;
          if(vis[a][b][0] || vis[a][b][1]) {
            v.push_back(M[a][b]);
          }
        }
        G[eq][M[i][j]] = -1.0;
        for(int k= 0; k < v.size(); k++) {
          G[eq][v[k]] = 1.0 / (double)good;
        }
        eq++;
      }
    }
  }

  if(!ok) {
    printf("%d\n",0);
    return 0;
  }

  assert(eq == cnt);

  for(int i = 0; i < eq; i++) {
    if(G[i][i] == 0.0) {
      int id = -1;
      for(int j = i+1; j < eq; j++){
        if(G[j][i]) {
          id = j;
          break;
        }
      }
      if(id == -1) continue;
      for(int j=0; j < eq; j++){
        swap(G[i][j], G[id][j]);
        swap(X[i], X[id]);
      }
    }

    X[i] /= G[i][i];
    for(int j =i+1; j< eq; j++){
      G[i][j] /= G[i][i];
    }
    G[i][i] = 1.0;
    for(int j =i+1; j< eq; j++){
      if(G[j][i]) {
        for (int k=i+1; k<cnt; k++) {
          G[j][k] -= G[i][k] * G[j][i];
        }
        X[j] -= X[i] * G[j][i];
        G[j][i] = 0.0;
      }
    }
  }

  for(int i = eq - 1; i >= 0; i--) {
    for(int j = i - 1; j >= 0; j--) {
      for(int k = j - 1; k >= 0; k--) {
        G[j][k] -= G[j][i] * G[i][k];
      }
      X[j] -= X[i] * G[j][i];
      G[j][i] = 0;
    }
  }
  printf("%lf\n",X[M[st.first][st.second]]);
  return 0;
}
