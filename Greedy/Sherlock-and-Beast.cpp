#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    int n,test,k;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        string ks;
        for(int j=n;j>=0;j--)
        {
            if(j%3==0 && (n-j)%5==0)
            {
                ks="";
                for(int k=0;k<j;k++)
                    ks+='5';
                for(int k=0;k<n-j;k++)
                    ks+='3';
                break;
            }
        }
        if(ks=="")
            cout<<"-1\n";
        else
            cout<<ks<<endl;
    }
    return 0;
}
