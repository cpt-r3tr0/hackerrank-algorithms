#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<string> ar[100];

	int N;
	cin >> N;

	for(int i = 0; i < N; ++ i){
		int j;
        string s;
		cin >> j >> s;
        (i< N/2) ? ar[j].push_back("-") : ar[j].push_back(s) ;
	}

    for(int i = 0; i < 100; ++ i)
        for(int j = 0; j < ar[i].size(); ++ j)
            cout << ar[i][j] << " ";

	cout << endl;
	return 0;
}
