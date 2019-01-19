#include <bits/stdc++.h>

using namespace std;
typedef std::pair<int, int> cpair;
#define inf std::numeric_limits<int>::max()

vector<string> split_string(string);

// Complete the shortestReach function below.
vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
vector<int> d(n, inf);
    vector<cpair> adj[n];
    bool visited[n];
    fill(visited,  visited+n, false);
    for(int i=0; i<edges.size(); i++){
        adj[edges[i][0]-1].push_back(make_pair(edges[i][2], edges[i][1]-1));
        adj[edges[i][1]-1].push_back(make_pair(edges[i][2], edges[i][0]-1));
    }
    priority_queue<cpair, vector<cpair>, greater<cpair> > pq;

    // Insert S
    s--;
    d[s] = 0;
    pq.push(make_pair(d[s], s)); // Lexicographic comparision

    // Process all vertices
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(visited[u])
            continue;
        else
            visited[u] = true;

        for(auto vpair: adj[u]){
            int v = vpair.second;
            int w = vpair.first;
            if(d[u] + w < d[v]){
                d[v] = d[u] + w;
                pq.push(make_pair(d[v], v));
            }
        }
    }

    vector<int> result(n-1);
    int tmp;
    for(int i=0; i<n; i++){
        if(i == s) continue;
        if(i>s) tmp = i-1;
        else tmp = i;
        if(d[i] == inf) result[tmp] = -1;
        else result[tmp] = d[i];
    }
    return result;

}

int main(){
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(3);

            for (int j = 0; j < 3; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = shortestReach(n, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
