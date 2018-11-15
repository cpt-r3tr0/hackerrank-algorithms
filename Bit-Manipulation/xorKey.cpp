#include <bits/stdc++.h>

using namespace std;
typedef long double ldb;
typedef long long lld;
typedef unsigned long long ulld;

const int N = 1e5 + 5;
struct node;
typedef node* pnode;
lld arr[N];
struct node {
    vector<lld> data;
    pnode nxt[2];
    node() {
        nxt[0] = nxt[1] = 0;
    }
};
pnode root;

void insert(lld val, lld pos) {
    pnode v = root;
    v->data.push_back(pos);
    for(int i=15;i>=0;i--){
        lld bit = (val>>i) & 1;
        if(v->nxt[bit] != 0) {
            v = v->nxt[bit];
        }
        else {
            v->nxt[bit] = new node();
            v = v->nxt[bit];
        }
        v->data.push_back(pos);
    }
}

bool check(pnode v, lld l, lld r) {
    if(v == 0) return false;
    return upper_bound(v->data.begin(),v->data.end(), r) - lower_bound(v->data.begin(),v->data.end(), l);
}

lld query(lld val, lld l, lld r) {
    pnode v = root;
    lld ans = 0;
    for(int i=15;i>=0;i--){
        lld bit = (val>>i) & 1;
        if(check(v->nxt[1^bit], l, r)) {
            ans |= (1 << i);
            v = v->nxt[1^bit];
        }
        else v = v->nxt[bit];
    }
    return ans;
}

int main() {
    lld n, Q, a, p, q;
    int t;
    cin>>t;
    while(t--){
        root = new node();
        cin >> n >> Q;
        for(int i=0;i<n;i++){
            cin >> arr[i];
            insert(arr[i], i + 1);
        }
        while(Q--) {
            cin >> a >> p >> q;
            cout << query(a, p, q) << endl;
        }
    }
}
