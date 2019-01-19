#include <bits/stdc++.h>

using namespace std;

// Complete the quickestWayUp function below.
int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
        int moves[101];
    vector<int>link[101];

    for(int i=0;i<=100;i++)
    {
        moves[i]=-1;
    }

    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=6 && j+i<101;j++)
        link[i].push_back(j+i);
    }

    for(int i=0;i<ladders.size();i++)
    {
        int j=ladders[i][0]-6;
        if(j<1)
            j=1;
        for(;j<=ladders[i][0];j++)
        {
            for(int k=0;k<link[j].size();k++)
            {
                if(link[j][k]==ladders[i][0])
                {
                    link[j][k]=ladders[i][1];
                    break;
                }
            }
        }
    }

    for(int i=0;i<snakes.size();i++)
    {
        int j=snakes[i][0]-6;
        if(j<1)
            j=1;
        for(;j<=snakes[i][0];j++)
        {
            for(int k=0;k<link[j].size();k++)
            {
                if(link[j][k]==snakes[i][0])
                {
                    link[j][k]=snakes[i][1];
                    break;
                }
            }
        }
    }

    moves[1]=0;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int i=q.front();
        q.pop();
        for(int j=0;j<link[i].size();j++)
        {
            if(moves[link[i][j]]==-1)
            {
                moves[link[i][j]]=moves[i]+1;
                q.push(link[i][j]);
            }
            else{
                if(moves[link[i][j]]>moves[i]+1)
                {
                    moves[link[i][j]]=moves[i]+1;
                    q.push(link[i][j]);
                }
            }
        }

    }

    return moves[100];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> ladders(n);
        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> ladders[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> snakes(m);
        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> snakes[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = quickestWayUp(ladders, snakes);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
