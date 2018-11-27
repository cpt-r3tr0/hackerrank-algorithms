#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k; cin>>n>>k;
    int rq,cq; cin>>rq>>cq;

    int cnt[8] = {0};
    cnt[0] = min(abs(rq-1),abs(cq-1));
    cnt[1] = abs(rq-1);
    cnt[2] = min(abs(rq-1),abs(n-cq));
    cnt[3] = abs(n-cq);
    cnt[4] = min(abs(n-cq),abs(n-rq));
    cnt[5] = abs(n-rq);
    cnt[6] = min(abs(n-rq),abs(cq-1));
    cnt[7] = abs(cq-1);

    for(int i=0; i<k; i++){
        int r,c; cin>>r>>c;
        if(r<rq && c<cq && abs(c-cq)==abs(r-rq)){
            cnt[0] = min(cnt[0],rq-r-1);
        }else if(c==cq && r<rq){
            cnt[1] = min(cnt[1],rq-r-1);
        }else if(r<rq && c>cq && abs(c-cq)==abs(r-rq)){
            cnt[2] = min(cnt[2],c-cq-1);
        }else if(r==rq && c>cq){
            cnt[3] = min(cnt[3],c-cq-1);
        }else if(r>rq && c>cq && abs(c-cq)==abs(r-rq)){
            cnt[4]= min(cnt[4],r-rq-1);
        }else if(c==cq && r>rq){
            cnt[5] = min(cnt[5],r-rq-1);
        }else if(r>rq && c<cq && abs(c-cq)==abs(r-rq)){
            cnt[6] = min(cnt[6],r-rq-1);
        }else if(r==rq && c<cq){
            cnt[7] = min(cnt[7],cq-c-1);
        }
    }

    long int count =0;
    for(int i=0; i<8; i++){
        count+=cnt[i];
    }cout<<count;

    return 0;

}
