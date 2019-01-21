/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include<iostream>
#include<set>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MOD 1000000007;
int n,k,t;
char C[101];
bool E[101][101][3];
bool V[101][101][3];
bool Can(int i , int j , int w){
	if(i == j)
		return C[i]-'a' == w;
	int a, b;
	if(E[i][j][w])return V[i][j][w];
	if(w == 0){a=1;b=2;}
	if(w == 1){a=0;b=2;}
	if(w == 2){a=0;b=1;}
	V[i][j][w] = E[i][j][w] = 1;
	for(int m = i ; m < j ; m++)
		if(Can(i,m,a) && Can(m+1,j,b))
			return 1;
	for(int m = i ; m < j ; m++)
		if(Can(i,m,b) && Can(m+1,j,a))
			return 1;
	V[i][j][w] = 0;
    return 0;
}
int DP[3][101];
int main()
{
  scanf("%d",&t);
  while(t--){
	  memset(E,0,sizeof(E));
	  memset(V,0,sizeof(V));
      scanf("%s",C);
      n = strlen(C);
      DP[0][0] = DP[1][0] = DP[2][0] = 0;
      for(int i = 1 ; i <= n ; i++)
      {
    	  DP[0][i] = DP[1][i] = DP[2][i] = 300;
    	 for(int j = 0 ; j < i ; j++)
    	 {
    		 if(Can(j,i-1,0))
    			 DP[0][i] = min(DP[0][i],DP[0][j]+1);
    		 if(Can(j,i-1,1))
    			 DP[1][i] = min(DP[1][i],DP[1][j]+1);
    		 if(Can(j,i-1,2))
    			 DP[2][i] = min(DP[2][i],DP[2][j]+1);
    	 }
      }

      int x = min(DP[1][n],min(DP[0][n],DP[2][n]));
      printf("%d\n",x);
  }
  return 0;
}
