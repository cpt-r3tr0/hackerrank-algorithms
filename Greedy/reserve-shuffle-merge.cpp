#include <bits/stdc++.h>

using namespace std;


int main() {
    string s, r = "";
    string a = "";
    vector<vector<int> > cidx(26);
    int pos[26] = {0};
    int cnt[10000][26];
    int len;
    cin >> s;
    len = s.length();
    memset(cnt, 0, sizeof(cnt));
    for (int i = len-1; i >=0 ; i--) r+=s[i];
    for (int i = 0; i < len; i++) {
        cidx[r[i]-'a'].push_back(i);
        if (i > 0) {
            for (int j = 0; j < 26; j++) cnt[i][j] = cnt[i-1][j];
        }
        cnt[i][r[i]-'a']++;
    }
    int curpos = 0;
    int left[26];
    for (int i = 0; i < 26; i++) {
        left[i] = cnt[len-1][i]/2;
    }
    for (int i = 0; i < len/2; i++) {
        for (int j = 0; j < 26; j++) {
            if (left[j] == 0) continue;
            while (pos[j]<cidx[j].size() && cidx[j][pos[j]]<curpos) pos[j]++;
            bool poss = 1;
            left[j]--;
            for (int k = 0; k < 26; k++) {
                if (cnt[len-1][k] - cnt[cidx[j][pos[j]]][k] < left[k]) poss=0;
            }
            left[j]++;
            if (poss) {
                a += ('a' + j);
                left[j]--;
                curpos = cidx[j][pos[j]]+1;
                pos[j]++;
                break;
            }
        }
    }
    cout << a << endl;
    return 0;
}
