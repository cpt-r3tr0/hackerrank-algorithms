#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
int nonZeroBits(long long n){
    int count = 0;
    long long base = 1;
    for (int i = 0; i < 64; ++i)
    {
        if (n & base << i)
        {
            ++count;
        }
    }

    return count;
}

// Complete the findConnectedComponents function below.
int findConnectedComponents(vector<long> d) {
    vector<vector<pair<int,long long>>> result;
    for (int i = 0; i < d.size(); ++i)
    {
        int currentSize = result.size();
        pair<int, long long> t1(nonZeroBits(d[i]), d[i]);

        result.emplace_back(vector<pair<int, long long>>{ t1 });

        for (int j = 0; j < currentSize; ++j)
        {
            vector<pair<int, long long>> tmp (result[j]);
            bool merged = false;
            for (int k = 0; k < tmp.size(); ++k)
            {
                if (tmp[k].second & d[i])
                {
                    tmp[k].second |= d[i];
                    tmp[k].first = nonZeroBits(tmp[k].second);
                    merged = true;
                }

            }

            if (!merged)
            {
                tmp.emplace_back(t1);
            }

            result.emplace_back(tmp);
        }
    }

    int total = 0;

    for (int i = 0; i < result.size(); ++i)
    {
        int nonZerocount = 0;
        for (int j = 0; j < result[i].size(); ++j)
        {
            nonZerocount += result[i][j].first;
        }

        total = total + result[i].size() + 64 - nonZerocount;
    }

    total += 64;

    return total;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int d_count;
    cin >> d_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string d_temp_temp;
    getline(cin, d_temp_temp);

    vector<string> d_temp = split_string(d_temp_temp);

    vector<long> d(d_count);

    for (int i = 0; i < d_count; i++) {
        long d_item = stol(d_temp[i]);

        d[i] = d_item;
    }

    int components = findConnectedComponents(d);

    fout << components << "\n";

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
