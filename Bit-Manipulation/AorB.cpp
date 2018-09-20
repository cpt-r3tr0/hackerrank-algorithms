#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the aOrB function below.
 */
void rehex(char& c) {
    if ('0' <= c && c <= '9') c = (char)(c - '0');
    else c = (char)(c - 'A' + 10);
}

string trim0(string& s) {
    for(auto& x:s){
        if (0 <= x && x < 10) x = (char)('0' + x);
        else x = (char)('A' + (x - 10));
    }
    for(int i = 0; i < (int)s.size(); ++i) {
        if (s[i] != '0') return s.substr(i);
    }
    return "0";
}
bool aOrB(int K, string a, string b, string c) {
    /*
     * Write your code here.
     */
    int N;
    N = max(max((int)a.size(), (int)b.size()), (int)c.size());
    a = string(N-(int)a.size(), '0') + a;
    b = string(N-(int)b.size(), '0') + b;
    c = string(N-(int)c.size(), '0') + c;

    for(auto& x:a)
        rehex(x);
    for(auto& x:b)
        rehex(x);
    for(auto& x:c)
        rehex(x);

    int bits[4] = {8,4,2,1};
    for(int i = 0; i < N; ++i){
        for(auto& bi : bits) {
            if (!(c[i]&bi)) {
                if (a[i]&bi) {
                    a[i] &= ~bi;
                    --K;
                }
            if (b[i]&bi) {
                b[i] &= ~bi;
                --K;
            }
        }
        else {
            if (!((a[i]&bi) || (b[i]&bi))) {
                b[i] |= bi;
                --K;
            }
        }
    }
    }
    if (K < 0) return false;

    for(int i = 0; i < N; ++i){
        for(auto& bi : bits) {
            if (c[i]&bi) {
                if ((a[i]&bi) && (b[i]&bi) && K >= 1) {
                    a[i] &= ~bi;
                    K--;
                }
                else if ((a[i]&bi) && K >= 2) {
                a[i] &= ~bi;
                b[i] |= bi;
                K -= 2;
            }
        }
        }
    }
    cout << trim0(a) << endl;
    cout << trim0(b) << endl;
    return true;

}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int k;
        cin >> k;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string c;
        getline(cin, c);

        if (!aOrB(k, a, b, c))
            cout << -1 << endl;
    }

    return 0;
}
