#include <bits/stdc++.h>

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    int count = 0;
    vector<vector<int>> std{ {4,2,6,8},{9,7,1,3} };
    vector<vector<int>> std2{ {8,6,2,4},{1,7,9,3} };
    if (s[1][1] != 5) {
        count += abs(s[1][1] - 5);
    }
    vector <int> even;
    even.push_back(s[0][0]);
    even.push_back(s[0][2]);
    even.push_back(s[2][2]);
    even.push_back(s[2][0]);

    vector <int> odd;
    odd.push_back(s[0][1]);
    odd.push_back(s[1][2]);
    odd.push_back(s[2][1]);
    odd.push_back(s[1][0]);
    int min = 100;
    int temp;
    for (int n = 0; n < 4; n++) {
        temp = 0;
        for (int i = 0; i < 4; i++) {
            temp += abs(even[i] - std[0][i]);
            temp += abs(odd[i] - std[1][i]);
        }
        rotate(std[0].begin(), std[0].begin() + 1, std[0].end());
        rotate(std[1].begin(), std[1].begin() + 1, std[1].end());
        if (min > temp) {
            min = temp;
        }
    }

    for (int n = 0; n < 4; n++) {
        temp = 0;
        for (int i = 0; i < 4; i++) {
            temp += abs(even[i] - std2[0][i]);
            temp += abs(odd[i] - std2[1][i]);
        }
        rotate(std2[0].begin(), std2[0].begin() + 1, std2[0].end());
        rotate(std2[1].begin(), std2[1].begin() + 1, std2[1].end());
        if (min > temp)
            min = temp;
    }
    count = count + min;
    return count;
}

int main(){
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++)
            cin >> s[i][j];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
