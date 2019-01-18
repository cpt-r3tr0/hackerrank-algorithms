#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int p,q;
    cin>>p>>q;
    sort(a,a+n);
    int b[q-p+1],max1=-1,temp,temp1=0;
    for(int i=p;i<=q;i++)
    {
        int min1=INT_MAX,c=0;
        for(int j=temp1;j<n;j++)
        {
            if(a[j]>i)
            {
                if(j==0)
                    min1=abs(a[j]-i);
                else
                {
                    long int r1,r2;
                    r1=abs(a[j]-i);
                    r2=abs(a[j-1]-i);
                    min1=min(r1,r2);
                }
                temp1=j;
                c=1;
                break;
            }
        }
        if(c==0)
        {
            min1=abs(a[n-1]-i);
        }

        if(min1>max1)
        {
            max1=min1;
            temp=i;
        }
    }
    cout<<temp;
    return 0;

}
