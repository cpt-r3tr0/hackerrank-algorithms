#include <iostream>
#include <vector>

using namespace std;


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool isSorted(int * a, int n){
    for(int i=1; i<n; i++){
        if(a[i]<a[i-1]) return false;
    }
    return true;
}

bool swappable(int * a, int n, int * l, int * r){
    int dc = 0, dci1 = -1, dci2 = -1;
    for(int i=1; i<n; i++){
        if(a[i]<a[i-1]){
            if(dci1 == -1) dci1 = i-1;
            else dci2 = i;
            dc++;
        }
    }
    if(dc>2) return false;
    else if(dc == 2){
        swap(&a[dci1], &a[dci2]);
        *l = dci1; *r = dci2;
        if(isSorted(a, n)) return true;
        else{
            swap(&a[dci1], &a[dci2]);
            return false;
        }
    }
    else if(dc == 1){
        dci2 = dci1 +1;
        swap(&a[dci1], &a[dci2]);
        *l = dci1; *r = dci2;
        if(isSorted(a, n)) return true;
        else{
            swap(&a[dci1], &a[dci2]);
            return false;
        }
    }
    return false;
}


void reverse(int * a, int n, int ll, int rl){
    while(ll<rl){
        swap(&a[ll], &a[rl]);
        ll++; rl--;
    }
}

bool reversible(int * a, int n, int * l, int * r){
    int i = 0, c =0, rl = -1, ll = -1;
    while(i<n-1 && a[i]<a[i+1]) i++;
    ll = i;
    while(i<n-1 && a[i]>a[i+1]){
        i++;
    }
    rl = i;
    c++;
    reverse(a, n, ll, rl);
    *l = ll; *r = rl;
    if(isSorted(a, n)) return true;
    else return false;
}

int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    int l=0, r=0;
    if(isSorted(a, n)){
        cout<<"yes";
    }
    else if(swappable(a, n, &l, &r)){
        cout<<"yes\nswap "<<l+1<<" "<<r+1;
    }
    else if(reversible(a, n, &l, &r)){
        cout<<"yes\nreverse "<<l+1<<" "<<r+1;
    }
    else{
        cout<<"no";
    }
    return 0;
}
