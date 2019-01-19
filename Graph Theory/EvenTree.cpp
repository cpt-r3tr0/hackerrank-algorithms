#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
int count=0;
int dfs(list<int> *adj,int v,bool visited[]){
    visited[v]=true;
    int count_till=0;
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();++i){
        if(!visited[*i]){
            int k=dfs(adj,*i,visited);
            if(k%2==0){
                ::count+=1;
            }
            else{
                count_till+=k;
            }
    }
    }
    return count_till+1;
}
// Complete the evenForest function below.
int evenForest(int t_nodes, int t_edges, vector<int> t_from, vector<int> t_to) {

        list<int> *adj=new list<int>[t_nodes];

        for(int i=0;i<t_edges;i++){
            adj[t_from[i]-1].push_back(t_to[i]-1);
            adj[t_to[i]-1].push_back(t_from[i]-1);
        }

        bool *visited=new bool[t_nodes];

        for(int i=0;i<t_nodes;i++){
            visited[i]=false;
        }
       /* for(int i=0;i<t_nodes;i++){
            list<int> a=adj[i];
            list<int>::iterator p;
            for(p=adj[i].begin();p!=adj[i].end();++p){
                cout<<i+1<<" "<<((*p)+1)<<"M";
            }
            cout<<endl;
        }*/
        for(int i=0;i<t_nodes;i++){
            if(!visited[i])
                dfs(adj,i,visited);
        }
        return ::count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_nodes_edges_temp;
    getline(cin, t_nodes_edges_temp);

    vector<string> t_nodes_edges = split(rtrim(t_nodes_edges_temp));

    int t_nodes = stoi(t_nodes_edges[0]);
    int t_edges = stoi(t_nodes_edges[1]);

    vector<int> t_from(t_edges);
    vector<int> t_to(t_edges);

    for (int i = 0; i < t_edges; i++) {
        string t_from_to_temp;
        getline(cin, t_from_to_temp);

        vector<string> t_from_to = split(rtrim(t_from_to_temp));

        int t_from_temp = stoi(t_from_to[0]);
        int t_to_temp = stoi(t_from_to[1]);

        t_from[i] = t_from_temp;
        t_to[i] = t_to_temp;
    }

    int res = evenForest(t_nodes, t_edges, t_from, t_to);

    fout << res << "\n";

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
