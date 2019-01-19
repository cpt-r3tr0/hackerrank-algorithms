#include<bits/stdc++.h>
using namespace std;

class edge
{
public:
    int src;
    int dest;
    int val;
};

bool compare(edge&i1,edge&i2)
{
    return(i1.val<i2.val);
}

int find_parent(int v,int*parent)
{
    if(parent[v]==v)return v;
    return find_parent(parent[v],parent);
}

void mst(edge*arr,int n,int src)
{
    edge*output=new edge[n-1];
    int cnt=0;
    int*parent=new int[n];
    for(int i=0;i<n;i++)parent[i]=i;
    int j=0;

    while(cnt!=n-1)
    {
        int p1=find_parent(arr[j].src,parent);
        int p2=find_parent(arr[j].dest,parent);
        if(p1!=p2)
        {
            parent[p1]=p2;
            output[cnt]=arr[j];
            cnt++;
        }
        j++;
    }
    int out=0;
    for(int i=0;i<n-1;i++)out+=output[i].val;
    cout<<out;
}

int main()
{
    int n,m;
    cin>>n>>m;
    edge*arr=new edge[m];

    for(int i=0;i<m;i++)
    {
        cin>>arr[i].src;
        cin>>arr[i].dest;
        cin>>arr[i].val;
    }
    int st;
    cin>>st;
    sort(arr,arr+m,compare);

    mst(arr,n,st);
}
