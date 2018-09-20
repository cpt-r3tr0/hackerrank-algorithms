#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long n;
        cin >> n;
        long a[n+2];
        for(long i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        long answer = 0;
        for(long i = 0 ; i < n ; i=i+2){
            answer = answer ^ a[i];
        }
        if(n%2 == 0)
            answer = 0;
        cout << answer << "\n";
    }
    return 0;
}
