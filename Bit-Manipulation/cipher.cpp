#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the cipher function below.
string cipher(int n, int k, string s) {
    string b="";
    b+=s[0];
    if(n<=k){
        for(int i=1;i<n;i++){
            int a=s[i-1]%48^s[i]%48;
            b+=(a+48);
        }
    }else{
        int i;
        for(i=1;i<k;i++){
            int a=s[i-1]%48^s[i]%48;
            b+=(a+48);
        }
        for(int p=0;b.size()<n;i++,p++){
            int a=s[i-1]%48^s[i]%48^b[p]%48;
            b+=(a+48);
        }
    }
    cout<<b;
    return b;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string s;
    getline(cin, s);

    string result = cipher(n, k, s);

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
