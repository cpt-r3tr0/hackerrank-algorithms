#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
int find(int parent[], int x)
{
    if(parent[x]!=x)
        parent[x]= find(parent, parent[x]);
    return parent[x];
}

void union_(int parent[], int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);

    if(xset < yset)
        parent[yset]=xset;
    if(xset > yset)
        parent[xset]=yset;
}
// Complete the journeyToMoon function below.
long int journeyToMoon(int n, vector<vector<int>> astronaut) {
    int parent[n];
    for(int i=0; i<n; i++)
        parent[i]=i;

    for(int i=0; i< astronaut.size(); i++)
        union_(parent, astronaut[i][0], astronaut[i][1]);

    for(int i=n-1; i>=0; i--)
        parent[i]=find(parent, i);

    vector <int> ans(n,0);
    for(int i=0; i<n; i++)
        ans[parent[i]]++;

    long int sum =0, cnt=n;

    for(int i=0; i<n;i++)
    {
        if(ans[i]>0)
        {
            cnt -= ans[i];
            sum += ans[i]*cnt;
        }
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long int result = journeyToMoon(n, astronaut);

    fout << result << "\n";

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
