#include <bits/stdc++.h>

using namespace std;

long cost(long L, long A, long N, long D){
    long c = 0, mc = -1, R, C, F, B;
    if(D == 1)
        return A*L;
    if(L < N + 1 && D <= A){ // One row + one column
        c += A*(A+1)/2 - (A-D)*(A-D+1)/2; // First row
        c += (N-D)*A;
        return c;
    }

    R = (N - 1)/(D - 1); // Full rows in first part
    F = (N - 1)%(D - 1);

    for(long r = 1; r <= R; r++){
        F = N - 1 - r*(D - 1);
        C = (L - F)/r;
        B = (L - F)%r;
        if(C + (B>0) <= A){
            c = (A*(A+1)/2 - (A-C)*(A-C+1)/2)*r + A*F + (A - C)*B;
            mc = max(mc, c);
        }
    }
    return mc;
}


int main(){

    long T, L, A, N, D;
    long c;
    cin >> T;
    for(long t = 0; t < T; t++){
        cin >> L >> A >> N >> D;
        c = cost(L, A, N, D);
        if(c == -1)
            cout << "SAD" << endl;
        else
            cout << c << endl;
    }
    return 0;
}
