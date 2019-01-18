#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n,lloc=0,bpair=0;
    cin>>n;
    int a[n],b[n];


    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);

    for(int i=0;i<n;i++)
    {
        for(int j=lloc;j<n;j++)
        {

                if(a[i]==b[j])
                {
                    bpair++;
                    lloc=j+1;
                    break;

                }


        }

    }

    if(bpair<n)cout<<bpair+1;
    else cout<<bpair-1;
}
