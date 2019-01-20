#include<bits/stdc++.h>
using namespace std;
int arr[100009];
bool isk[100009];
int jitu=1e9;

vector< pair<int,int> > dist[100009];

pair< int,int> dfs(int v,int p,vector< vector< pair<int,int> > > &graph)
{
    pair< int,int > temp;
    int mx=0,ans(0);
    bool isktemp=false;

    for(int i=0;i<graph[v].size();i++)
    if(graph[v][i].first!=p)
    {
        temp=dfs(graph[v][i].first,v,graph);

        if(isk[graph[v][i].first])
        {
            isktemp=true;
            temp.first+=graph[v][i].second;
            temp.second+=graph[v][i].second;
            ans+=temp.first+temp.second;
            mx=max(mx,temp.second);
            dist[v].push_back(temp);
        }
    }

    isk[v]=isktemp || arr[v];

    return make_pair(ans-mx,mx);
}

void dfs2(int v,int p,vector< vector< pair<int,int> > > &graph,pair<int,int> temp)
{
    //cout<<v<<" "<<temp.first<<" "<<temp.second<<" j\n";
    dist[v].push_back(temp);

    int ans(0),cnt(0),mx(0),mx2(0);
    int n=dist[v].size();

    for(int i=0;i<n;i++)
    {
        ans+=dist[v][i].first+dist[v][i].second;
      //  cout<<dist[v][i].first<<" "<<dist[v][i].second<<" || ";
        if(dist[v][i].second>mx)
        {
            mx2=mx;
            mx=dist[v][i].second;
        }
        else if(dist[v][i].second>mx2)
            mx2=dist[v][i].second;
    }
    //cout<<"\n";
    //cout<<v<<" "<<ans<<" "<<mx<<"\n";
    if(arr[v])
        jitu=min(jitu,ans-mx);

    for(int i=0;i<graph[v].size();i++)
    if(graph[v][i].first!=p && isk[graph[v][i].first])
    {
        ans-=dist[v][cnt].first+dist[v][cnt].second;
        int as;
        if(dist[v][cnt].second==mx)
            as=mx2;
        else
            as=mx;

        ans-=as;
        if(arr[v] || ans>0 || as>0)
        dfs2(graph[v][i].first,v,graph,make_pair(ans+graph[v][i].second,as+graph[v][i].second));
        else
        dfs2(graph[v][i].first,v,graph,make_pair(0,0));
        ans+=as;
        ans+=dist[v][cnt].first+dist[v][cnt].second;
        cnt++;
    }
}

int main()
{
    int n,k;
    cin>>n>>k;

    vector< vector< pair<int,int> > > graph(n+1);

    for(int i=0;i<k;i++)
    {
        int a;
        cin>>a;
        arr[a]=1;
    }

    for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    dfs(1,0,graph);
    dfs2(1,0,graph,make_pair(0,0));

    cout<<jitu<<"\n";
    return 0;
}
