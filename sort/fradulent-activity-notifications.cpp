#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
bool is_greater_than_median ( vector<int> &v, int expenditure_today )
{
    size_t sz = v.size();
    size_t mid = sz / 2;
    double median = v[mid];
    if (( sz % 2 ) == 0)
        median = ((v[mid-1] + v[mid]) / 2.0);
    return (expenditure_today >= (median*2)) ;
}

// Function to sort the array
void customSort(std::vector<int> &v, int pos)
{
    if ( pos == 0 && v[pos] <= v[pos+1])
        return;
    if ( pos+1 == v.size() && v[pos-1] <= v[pos])
        return;

    bool bForward = true;
    if ( pos+1 == v.size())
        bForward = false;
    if ( v[pos] < v[pos-1] && pos > 1)
        bForward = false;

    if ( bForward )
    {
        for ( size_t j = pos; j < v.size(); j++ )
        {
            if ( j+1 < v.size() && v[pos] > v[j+1])
            {
                swap( v[pos], v[j+1]);
                pos = j+1;
            }
            else break;
        }
    }
    else
    {
        for ( size_t j = pos; j != 0; j-- )
        {
            int t_idx = j - 1;
            if ( t_idx >= 0 && v[pos] < v[j-1])
            {
                swap( v[pos], v[j-1]);
                pos = j-1;
            }
            else break;
        }
    }


}

// Complete the activityNotifications function below.
int activityNotifications( const std::vector< int > & expenditures, int days_back )
{
    // Return value
    int notifications = 0;

    // Create a subset of expeditures needed for median
    std::vector< int > window( expenditures.begin(), expenditures.begin() + days_back );

    // Sort expenditures
    std::sort( window.begin(), window.end() );

    // Is the vector odd or even, used in median calulation
    bool is_odd = days_back % 2 == 1;

    // We will need the number of expenditures less the days back plus one iterations...
    for ( int index = 0; index < expenditures.size() - days_back + 1; ++index )
    {
         // Protect agains out-of_bounds for last iteration
        if ( index + days_back < expenditures.size() )
        {
            // Calculate the current median
            double current_median = is_odd ? (double)window[ days_back / 2 ] : ( static_cast< double >( window[ days_back / 2 - 1 ] ) + (double)window[ days_back / 2 ] ) / 2;

            // Lookup the current days expediture
            int current_expenditure = expenditures[ days_back + index ];

            // If the current expediture is twice the medain, send notification...
            if ( current_expenditure >= ( current_median * 2 ) )
            {
                // Increment notifications
                ++notifications;
            }

            // Find where the current expediture will be inserted to keep the vector sorted
            auto iter = std::lower_bound( window.begin(), window.end(), current_expenditure );

            // Insert at location to keep vector sorted
            window.insert( iter, current_expenditure );

            // Find where the aged out expediture now is
            iter = std::lower_bound( window.begin(), window.end(), expenditures[ index ] );

            // Remove aged out expedicture
            window.erase( iter );
        }
    }

    // Return the notifications sent
    return notifications;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
