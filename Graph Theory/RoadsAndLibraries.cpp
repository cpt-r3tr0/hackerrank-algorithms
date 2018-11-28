#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
map<int, int> dfs(map<int, shared_ptr<set<int>>> graph) {
    map<int, int> parents;
    map<int, int> lengths;

    stack<int> open_set;
    for (auto entry: graph) {
        auto parent = entry.first;
        if (parents.find(parent) == parents.end()) {
            lengths[parent] = 0;
            parents[parent] = 0;
            auto ancestor = parent;
            open_set.push(parent);
            while(open_set.size() > 0) {
                auto parent = open_set.top();
                open_set.pop();
                auto it = graph.find(parent);
                if (it == graph.end()) continue;
                auto children = *it->second;
                for (auto child : children) {
                    if (parents.find(child) == parents.end()) {
                        lengths[ancestor] = lengths[ancestor] + 1;
                        parents[child] = parent;
                        open_set.push(child);
                    }
                }
            }
        }
    }

    return lengths;
}
// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    set<int> unique_cities;
    map<int, shared_ptr<set<int>>> graph;
    for_each(cities.cbegin(), cities.cend(), [&graph, &unique_cities](auto v) {
        auto from = v[0];
        auto to = v[1];
        auto it = graph.find(from);
        auto s = it != graph.end() ? it->second : (graph[from] = make_shared<set<int>>());
        s->insert(to);
        it = graph.find(to);
        unique_cities.insert(to);
        s = it != graph.end() ? it->second : (graph[to] = make_shared<set<int>>());
        s->insert(from);
        unique_cities.insert(from);
    });

    auto lengths = dfs(graph);
    long answer;
    if (c_road >= c_lib) {
        answer = accumulate(lengths.begin(), lengths.end(), 0L, [c_lib, c_road](auto l1, auto l2) {
            return l1 + c_lib*(l2.second + 1);
        });
    } else {
        answer = accumulate(lengths.begin(), lengths.end(), 0L, [c_lib, c_road](auto l1, auto l2) {
            return l1 + (c_road*l2.second + c_lib);
        });
    }
    auto left_out = n - unique_cities.size();
    answer += left_out*c_lib;

    return answer;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
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
