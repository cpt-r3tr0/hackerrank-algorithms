#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int mostSignificantBit(const int& x) {
    int i = 1;
    while (i <= x)
        i <<= 1;
    return i >> 1;
}

// Complete the anotherMinimaxProblem function below.
int anotherMinimaxProblem(vector<int> a) {
    int inf = 1 << 30;
    int res = inf;
    while (res == inf) {
        int mx = *max_element(a.begin(), a.end());
        int k = mostSignificantBit(mx);
        if (k == 0)
            break;
        for (const int& x : a) {
            if (x >= k) {
                for (const int& y : a) {
                    if (y < k)
                        res = min(res, x ^ y);
                }
            }
        }
        for (int& x : a)
            x -= k;
    }
    return res == inf ? 0 : res;
}

int main(){
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = anotherMinimaxProblem(a);

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
