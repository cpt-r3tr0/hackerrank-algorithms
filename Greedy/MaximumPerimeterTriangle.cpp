#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maximumPerimeterTriangle function below.
vector<int> maximumPerimeterTriangle(vector<int> sticks) {
    vector<int> v;
    int n=sticks.size();
    sort(sticks.begin(),sticks.end(),greater<long long>());
    bool ans=false;
    long long a=-1,b=-1,c=-1,d;
    for(int i=0;i<n-2;i++)
    {
        a=sticks[i];
        b=sticks[i+1];
        d=a-b;
        //cout<<"d "<<d<<endl;
        if(sticks[i+2]>d)
        {
            c=sticks[i+2];
            ans=true;
            break;
        }
    }
    if(ans)
    {
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
    }
    else
        v.push_back(-1);
    sort(v.begin(),v.end());
    return v;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string sticks_temp_temp;
    getline(cin, sticks_temp_temp);

    vector<string> sticks_temp = split_string(sticks_temp_temp);

    vector<int> sticks(n);

    for (int i = 0; i < n; i++) {
        int sticks_item = stoi(sticks_temp[i]);

        sticks[i] = sticks_item;
    }

    vector<int> result = maximumPerimeterTriangle(sticks);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
M
