#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
void partition(vector <int>  ar) {
    if(ar.size() == 0)
		return;
	else if(ar.size() == 1){
		cout << ar[0] << endl;
		return;
	}

	int p = ar[0];
	vector<int> less;
	vector<int> more;

	for(vector<int>::iterator itr = ar.begin() + 1; itr != ar.end(); itr++){
		if(*itr < p)
			less.push_back(*itr);
		else
			more.push_back(*itr);
	}

	for(vector<int>::iterator itr = less.begin(); itr != less.end(); itr++)
		cout << *itr << " ";
	cout << p << " ";
	for(vector<int>::iterator itr = more.begin(); itr != more.end(); itr++)
		cout << *itr << " ";
	cout << endl;


}
int main(void) {
   vector <int>  _ar;
   int _ar_size;
cin >> _ar_size;
for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
   int _ar_tmp;
   cin >> _ar_tmp;
   _ar.push_back(_ar_tmp);
}

partition(_ar);

   return 0;
}
