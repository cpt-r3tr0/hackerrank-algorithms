#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#include<stack>
#include<map>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii > vii;

int cost[100005],arr[100005],par[100005];
vector<int> adj[100005];
vector<int> edge[100005];

int dfs(int u){
	int sz=adj[u].size(),i;
	cost[u]=arr[u];
	for(i=0;i<sz;i++){
		if(adj[u][i]!=par[u])
		{
			par[adj[u][i]]=u;
			cost[u]+=dfs(adj[u][i]);
			edge[u].push_back(adj[u][i]);
		}
	}
	return cost[u];
}

int abs(int a){
    return a>0?a:-a;
}

int main(){
	int n;
	scanf("%d",&n);
	int i,sum=0;
	for(i=1;i<=n;i++){
		scanf("%d",arr+i);
		sum+=arr[i];
	}
	for(i=0;i<n-1;i++){
		int a,b;
        scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	par[1]=-1;
    dfs(1);
	int mn=1000000000,ans,j;
	for(i=1;i<=n;i++){
    	int sz=edge[i].size();
		for(j=0;j<sz;j++){
			ans=abs((sum-cost[edge[i][j]])-cost[edge[i][j]]);
			if(mn>ans)
				mn=ans;
		}
	}
	cout << mn << endl;
	return 0;
}
