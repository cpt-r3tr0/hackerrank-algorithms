#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 12;

int T;
int N;

string tops, bots;
bool top[MAX_N];
bool bot[MAX_N];

bool cover(int pos, int lastDown){
    if(pos == N){
        if((N-lastDown-1)%2 == 0) return true;
        else return false;
    }else{
        if(!top[pos] && !bot[pos]){
            if((pos-lastDown-1)%2 == 0)
                if(cover(pos+1, pos)) return true;
        }

        if(pos > lastDown+1 && !top[pos] && !bot[pos-1]){
            if((pos-1-lastDown-1)%2 == 0){
                if(bot[pos]){
                    if(cover(pos+1, pos)) return true;
                }else if(cover(pos+1, pos-1)) return true;
            }
        }

        if(pos < N-1 && !top[pos] && !top[pos+1]){
            if(bot[pos]){
                if((pos-lastDown-1)%2 == 0){
                    if(bot[pos+1]){
                        if(cover(pos+2, pos+1)) return true;
                    }else if(cover(pos+2, pos)) return true;
                }
            }else if(bot[pos+1]){
                if((pos+1-lastDown-1)%2 == 0)
                    if(cover(pos+2, pos+1)) return true;
            }else{
                if(cover(pos+2, lastDown)) return true;
            }
        }

        if(top[pos]){
            if(bot[pos]){
                if((pos-lastDown-1)%2 == 0)
                    if(cover(pos+1, pos)) return true;
            }else if(cover(pos+1, lastDown)) return true;
        }

        return false;
    }
}

int main(){


    cin >> T;

    for(int t = 0; t < T; t++){
        cin >> N >> tops >> bots;

        for(int i = 0; i < N; i++)
            top[i] = (tops[i] == '1');

        for(int i = 0; i < N; i++)
            bot[i] = (bots[i] == '1');

        (cover(0,-1))? cout << "YES\n": cout << "NO\n" ;

    }

    return 0;
}
