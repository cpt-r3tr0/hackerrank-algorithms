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

void insertionSort(vector <int>  ar) {
     int n = ar.size();
    if(n==0)
        return;
    if(n==1)
        cout<<ar[n-1]<<endl;
    int curr = ar[n-1];
    int i=n-2;
    while(i>=0){
        if(ar[i]>=curr){
            ar[i+1]=ar[i];
        }
        else{
            ar[i+1]=curr;
            i=-1;
        }
        for(int j=0;j<n;j++)
            cout<<ar[j] << " ";
        cout<<endl;
        if(i==0){
            ar[i]=curr;
            for(int j=0;j<n;j++)
                cout<<ar[j] << " ";
            cout<<endl;
        }
        i--;
    }
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

insertionSort(_ar);

   return 0;
}
