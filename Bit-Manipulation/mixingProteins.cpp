#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the pmix function below.
 */
string pmix(string s, int k) {
    /*
     * Write your code here.
     */
    int n=s.size(),c=1,C=k,f=0;
    vector<int> N(n),T(n);
    for(int i=0;i<n;i++)
        N[i]=(int)s[i]-(int)'A';
    for(int i=0;i<n;i++)
        cout<<N[i]<<' ';
    while(C){
        if(C%2){
            if(f%2==0){
                for(int i=0;i<n;i++)
                    T[i]=N[i]^N[(i+c)%n];
            }else
                for(int i=0;i<n;i++)
                    N[i]=T[i]^T[(i+c)%n];
            f++;
        }
        c*=2;
        C/=2;
    }
    if(f%2)
        for(int i=0;i<n;i++)
            s[i]=char(int('A')+T[i]);
    else
        for(int i=0;i<n;i++)
            s[i]=char(int('A')+N[i]);
    return s;
}

int main(){
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string s;
    getline(cin, s);

    string result = pmix(s, k);

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
