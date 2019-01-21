#include <bits/stdc++.h>

const static int maxn = 16;
const static double eps = 1e-10;
const static int maxstep = maxn/2;
const static int modulo = 1000000007;

struct st_point{
    double x, y;
};

st_point points[maxn];

std::vector<int> remove_set[maxn];
std::vector<int> remove_sub_set[maxn][maxn][maxstep/2];
std::vector<int> prev_states;

bool prev_state_set[1<<maxn];

long long totaldivide[(1<<maxn)];

int minstep[1<<maxn];

int n;

bool collinear(st_point &p1, st_point &p2, st_point &p3){
    return ((p3.x-p1.x)*(p2.y-p1.y) == (p3.y-p1.y)*(p2.x-p1.x));
}

void read_data(){
    std::cin>>n;
    for (int i=0; i<n; ++i)
        std::cin>>points[i].x>>points[i].y;
}

void solve(){

    if (n == 1){
        std::cout<<"1 1"<<std::endl;
        return;
    }

    int final_state = (1<<n)-1;

    for (int i=0; i<n; ++i){
        remove_set[i].clear();

        bool include[maxn];
        memset(include, 0, sizeof(include));
        include[i] = true;

        for (int j=0; j<n; ++j){
            if (include[j]) continue;
            int set = 0;
            for (int k=0; k<n; ++k)
                if (collinear(points[i], points[j], points[k])){
                set |= (1<<k);
                include[k] = true;
            }

            remove_set[i].push_back(final_state^set);
            std::vector<int> *sub_set = remove_sub_set[i][remove_set[i].size()-1];

            for (int step = 0; step < maxstep/2; ++step)
                sub_set[step].clear();

            sub_set[0].push_back(set^final_state);
            for (int p1 = 0; p1 < n; ++p1)
                if (p1 != i && ((1<<p1) & set)){
                sub_set[1].push_back(set^(1<<p1)^final_state);
                for (int p2 = p1+1; p2 < n; ++p2)
                    if (p2 != i && ((1<<p2) & set)){
                    sub_set[2].push_back(set^(1<<p1)^(1<<p2)^final_state);
                    for (int p3 = p2+1; p3 < n; ++p3)
                        if (p3 != i && ((1<<p3) & set))
                        sub_set[3].push_back(set^(1<<p1)^(1<<p2)^(1<<p3)^final_state);
                }
            }
        }
    }

    memset(minstep, 0, sizeof(minstep));
    for (int state = 1; state <= final_state; ++state){
        int last;
        for (int i = 0; i < n; ++i)
            if (state & (1<<i))
            last = i;
            for (int set = 0; set < remove_set[last].size(); ++set)
            if (minstep[state] == 0 || minstep[state] > minstep[state & remove_set[last][set]]+1)
            minstep[state] = minstep[state & remove_set[last][set]]+1;
            }

    memset(prev_state_set, 0, sizeof(prev_state_set));
    memset(totaldivide, 0, sizeof(totaldivide));
    totaldivide[0] = 1;

    long long answer = 0;
    for (int step = 1; step <= (minstep[final_state]+1)/2; ++step){
        for (int state = 0; state <= final_state; ++state)
            if (minstep[state] == step && minstep[state^final_state]+minstep[state] == minstep[final_state]){
            prev_states.clear();
            int last;
            for (int i = 0; i < n; ++i)
                if (state & (1<<i))
                last = i;

                for (int set = 0; set < remove_set[last].size(); ++set)
                if (minstep[state & remove_set[last][set]] == step-1){
                for (int not_include = 0; not_include<step; ++not_include){
                    for (int sub_set = 0; sub_set < remove_sub_set[last][set][not_include].size(); ++sub_set){
                        int prev = state & remove_sub_set[last][set][not_include][sub_set];
                        if (minstep[prev] == step-1 && !prev_state_set[prev]){
                            prev_state_set[prev] = true;
                            prev_states.push_back(prev);
                        }
                    }
                }
            }

            for (int prev = 0; prev < prev_states.size(); ++prev){
                prev_state_set[prev_states[prev]] = false;
                totaldivide[state] = (totaldivide[state]+totaldivide[prev_states[prev]]) % modulo;
            }
        }
        for (int state = 0; state <= final_state; ++state)
            if (minstep[state] == step && minstep[state^final_state] <= step)
            answer = (answer + totaldivide[state]*totaldivide[state^final_state]) % modulo;
    }
    for (long long i = 1; i <= minstep[final_state]/2; ++i)
        answer = answer * i % modulo;

    for (long long i = 1; i <= minstep[final_state]-minstep[final_state]/2; ++i)
        answer = answer * i % modulo;

    std::cout<<minstep[final_state]<<" "<<answer<<std::endl;
}

int main(){
    int T;
    std::cin>>T;
    while (T>0){
        T--;
        read_data();
        solve();
    }
    return 0;
}
