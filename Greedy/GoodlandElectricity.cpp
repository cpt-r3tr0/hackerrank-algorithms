#include<bits/stdc++.h>
using namespace std;
int main()
{
    int flag=0;
    int n,k;
    cin>>n>>k;
    bool ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    int a,next,count=0;
    a=0;
    next=k;    int ranger=0;
    int flager=0;
    if(ar[0]==1)
    {
        for(int i=1;i<k;i++)
        {
            if(ar[i]==1){
            flager=1;break;}
        }
    }
   if(ar[0]==1&&flager==0)
   count+=1;
    while(ranger<n-1)
    {
        if(next>=n)
        next=n-1;
        while(ar[next]!=1&&next>a)
            next--;

    if(a==next)
    {
        cout<<"-1";
        flag=1;
        break;
    }
    else{
    count++;}
    a=next;
    next=next+2*k-1;
    ranger=a+k-1;

    }

    if(flag==0)
    cout<<count<<endl;

}
