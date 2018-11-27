#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        //cout << t << "\n";
        int n,k;
        cin >> n >> k;
        //cout << n << k << "\n";

        if (n/2 < k) {
            cout << "-1\n";
            continue;
        }

        int c[n+1] = {0};
        int d[n+1];
        for (int i=1;i<=n;i++) {
            int a = i+k;
            int b = i-k;

            if (a > 0 && b > 0) {
                if (b <= n && c[b] == 1) {
                    if (a > n) {
                        cout << "-1\n";
                        goto hell;
                    }
                    d[i] = a;
                    c[a] = 1;
                }
                else {
                    d[i] = b;
                    c[b] = 1;
                }
            }
            else if (a > 0) {
                d[i] = a;
                c[a] = 1;
            }
            else {
                d[i] = b;
                c[b] = 1;
            }
        }

        for (int i=1;i<=n;i++) {
            cout << d[i] << " ";
        }
        cout << "\n";
        hell:;
    }
    return 0;
}
