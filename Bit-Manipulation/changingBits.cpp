#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
using namespace std;

int main(){
    set<int> s;
    int n,q;
    cin>>n>>q;
    string a,b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < a.size(); i++){
           if (a[i] == b[i])
            s.insert(i);
    }
    for(int i=0;i<q;i++){
        char ch;
        string si;
        cin >> si;
        if (si[4] == 'a'){
            int l;
            cin>>l>>ch;
            if (a[l] !=ch){
                if (a[l] == b[l])
                    s.erase(l);
                else
                    s.insert(l);
                a[l] =ch;
            }
        } else if (si[4]=='b'){
            int l;
            cin>>l;
            cin >>ch ;
            if (b[l] !=ch){
                if (a[l] == b[l])
                    s.erase(l);
                else
                    s.insert(l);
                b[l] = ch;
            }
        } else{
            int l,ans= 0;
            cin>>l;
            if (l > 0){
                set <int> ::iterator it = s.upper_bound(l-1);
                if (it != s.begin()){
                    --it;
                    if (a[*it] == '1')
                        ans =1;
                }
            }
            if (l >= a.size()){
                if(ans) cout << "1";
                else cout << "0";
            }else{
                int k=a[l]+b[l]-2*'0';
                int m=(k+ans)%2;
                cout<<m;
            }
        }
    }
    return 0;
}
