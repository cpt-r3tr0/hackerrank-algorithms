#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>
#include <limits>
#include <fstream>

using namespace std;



void bfs(vector<set<int> > &V,int &S,stringstream &ss)
{
	vector<bool> A(V.size(),false);
	vector<int> D(V.size(),-1);
	D[S] = 0;
	queue<int> Q;
	Q.push(S);

	A[S] = true;
	while(!Q.empty())
	{
		int f = Q.front(); Q.pop();

		for(set<int>::iterator it = V[f].begin();
			it != V[f].end() ; ++it)
		{
			int p = *it;
			if(!A[p])
			{

				D[p] = D[f] + 1;

				A[p] = true;
				Q.push(p);
			}
		}

	}
	for(int i=0; i<D.size(); i++)
	{
		if(D[i] == -1)
			ss<<-1<<" ";
		else if(D[i] > 0)
			ss<<(D[i]*6)<<" ";
	}
	ss<<"\n";
}


int main()
{
	int t;
	cin>>t;
	stringstream ss;
	for(int i=0; i<t; ++i)
	{
		int n,m;
		cin>>n>>m;
		vector<set<int> > V(n,set<int>());
        for(int j=0; j<m; ++j)
		{
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			V[a].insert(b);
			V[b].insert(a);
		}
		int S;
		cin>>S;
		S--;
		bfs(V,S,ss);
	}
	cout<<ss.str();
	return 0;
}

