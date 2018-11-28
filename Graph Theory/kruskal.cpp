#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


struct Edge {
    Edge(int u, int v, int w) : from(u), to(v), w(w) {};
  int from;
  int to;
  int w;
};

long mst(int n, vector<Edge> e) {

  map<int, map<int, vector<Edge>>> sorted;
  for(auto &c : e) {
    sorted[c.w][c.from + c.to + c.w].push_back(c);
  }

  long w = 0;
  unordered_map<int, unordered_set<int>*> v;
  for(int i = 0; i < n; i++) {
      v[i] = new unordered_set<int>{i};
  }
  for(auto &same_w : sorted) {
    for(auto &edges : same_w.second) {
      for(auto &c : edges.second) {
        if(v[c.from] != v[c.to]) {
          w += c.w;
          int copyFrom = c.from;
          int copyTo = c.to;
          if(v[c.from]->size() > v[c.to]->size()) {
            copyFrom = c.to;
            copyTo = c.from;
          }
          for(auto i : *v[copyFrom]) {
            v[copyTo]->insert(i);
            v[i] = v[copyTo];
          }
        //   delete v[copyFrom];
          v[copyFrom] = v[copyTo];
        }
      }
    }
  }
  delete v[0];
  return w;
}
/*
 * Complete the 'kruskals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    vector<Edge> e;
    for(int i = 0; i < g_from.size(); i++) {
        e.push_back(Edge(g_from[i]-1, g_to[i]-1, g_weight[i]));
    }
    return mst(g_nodes, move(e));
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    int res = kruskals(g_nodes, g_from, g_to, g_weight);

    // Write your code here.
    fout << res << endl;

    fout.close();

    return 0;
}
string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
