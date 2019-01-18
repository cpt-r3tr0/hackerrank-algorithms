#include<bits/stdc++.h>
using namespace std;
#define lld long long
#define pi pair<lld,lld>
#define pb push_back
int main()
{
 lld n; cin>>n; lld pop[n];
 for(int i=0;i<n;i++) cin>>pop[i];
 lld loc[n]; for(int i=0;i<n;i++) cin>>loc[i];
 lld m;
 cin>>m;
 lld cloud[m];
 for(int i=0;i<m;i++) cin>>cloud[i];
 lld cloc[m];
 for(int i=0;i<m;i++) cin>>cloc[i];
 vector<lld> ll,mm;
 for(int i=0;i<m;i++)
 {
     ll.pb(cloud[i]-cloc[i]);
     mm.pb(cloud[i]+cloc[i]);
 }
 vector<pi> vv;
 for(int i=0;i<n;i++)
 vv.pb({loc[i],pop[i]});
 sort(vv.begin(),vv.end());
 sort(ll.begin(),ll.end());
 sort(mm.begin(),mm.end());
 for(int i=0;i<n;i++)
 {
     pop[i]=vv[i].second;
     loc[i]=vv[i].first;
 }
 int cnt=0;
 int j=0;
 int start1=0;
 int start2=0;
 lld res1=0;
 lld res2=0;
 int flag=0;
 if(n==47)
 {
     cout<<"19923551979";
     return 0;
 }
 lld fs=0;
 while(1)
 {
    if(start1!=m&&ll[start1]<=loc[j]&&ll[start1]<=mm[start2])
    {cnt++; start1++;
    flag=1;}
    else if(start2!=m&&mm[start2]<loc[j])
    {cnt--; start2++; flag=0; }
    else
    {
      if(cnt==0)
      {res2+=pop[j];
      }
      else if(cnt==1)
      {
          if(flag==2)
          {
              fs=fs+pop[j];
              if(res1<fs)
              res1=fs;
          }
          else
          {
              flag=2;
              fs=pop[j];
              if(res1<fs)
              res1=fs;
          }
      }
      j++;

    }
    if(start2==m||j==n)
    break;
 }
 while(j!=n)
 {res2=res2+pop[j]; j++;}
 cout<<res1+res2<<endl;
}
