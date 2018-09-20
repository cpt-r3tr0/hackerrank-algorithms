#include <bits/stdc++.h>

using namespace std;

// Complete the theGreatXor function below.

long theGreatXor(long x) {
    int cnt = 0;
    long sum = 0;
    while(x != 0) {
        int id = 1 - (x % 2);
        sum += id * (1LL << cnt);
        ++cnt;
        x /= 2;
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long x;
        cin >> x;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long result = theGreatXor(x);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
