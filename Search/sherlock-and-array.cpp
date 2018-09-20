#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define MAX 100010
int x[MAX],y[MAX];
char ans[2][4]={"NO","YES"};
int main()
{
	int tc; scanf("%d",&tc);
	REP(t,0,tc)
	{
		int n,s=0,f=0; scanf("%d",&n);
		REP(i,0,n)
		{
			scanf("%d",&x[i]);
			s+=x[i];
		}
		y[0]=0;
		REP(i,1,n) y[i]=x[i-1]+y[i-1];
		REP(i,0,n) if(s-x[i]==2*y[i]) f=1;
		printf("%s\n",ans[f]);
	}
	return 0;
}
