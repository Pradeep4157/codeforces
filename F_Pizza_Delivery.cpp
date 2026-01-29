#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we cannot go left side in these operations..

    so we will collect all the left first and then move for the right ones..

    in a line the distance is def ..

    we will go in the shorter direction first and then in the longer one maybe ..

    since we cant go left ..

        we will sort on the basis of x axis..

        and then for each node i move to the top most or bottom most part of the next line or in short i end at top or bottom

        of the next line and then we store both the res in dp and move to the next line..

        for every line we just need to find the dist of top and bottom..

        that should do..

        how do we store we store in a map all the poss x axis and in vector all the  possible y axis..

        that should be enough..


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, first_x, first_y, end_x, end_y;
        cin >> n >> first_x >> first_y >> end_x >> end_y;
        vector<pair<int, int>> temp(n);
        for (int i = 0; i < n; i++)
            cin >> temp[i].first;
        for (int i = 0; i < n; i++)
            cin >> temp[i].second;
        int prev_x = first_x;
        int prev_first_y = first_y;
        int prev_second_y = first_y;
        sort(temp.begin(), temp.end());
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[temp[i].first].push_back(temp[i].second);
        }
        int SIZE = mp.size();
        vector<pair<int, int>> dp(SIZE);
        int index = 0;
        for (auto a : mp)
        {
            vector<int> all_y = a.second;
            int size = all_y.size();
            int curr_first_y = all_y[0];
            int curr_last_y = all_y[size - 1];
            int curr_x = a.first;
            // this is def dist..
            int curr = all_y[size - 1] - all_y[0];
            // now if we choose to  end at first point then we first move till last point and then move to this first point..
            // now here we either come from last point or first point..
            int curr1 = curr;
            int curr2 = curr;
            {
                // here we are minimizing dist to reach top of this..
                // if we come from prev top ..
                int temp1 = curr_x - prev_x;
                int temp2 = curr_x - prev_x;
                // in temp1  we are coming from prev top..
                temp1 += abs(curr_first_y - prev_first_y);
                // also if prev dp is there we add top dp as well..
                if (index > 0)
                    temp1 += dp[index - 1].first; // because we end there..

                // in temp2 we are coming fromm prev bottom..
                temp2 += abs(curr_first_y - prev_second_y);
                if (index > 0)
                    temp2 += dp[index - 1].second;

                // we are now at top of this .. and if we add curr we reach bottom of  this so we update dp[i].second..
                temp1 += curr;
                temp2 += curr;
                dp[index].second = min(temp1, temp2);
            }

            {
                // now here first we reach bottom and then we go top..
                int temp1 = curr_x - prev_x;
                int temp2 = curr_x - prev_x;
                // either we come from top..
                temp1 += abs(curr_last_y - prev_first_y);
                if (index > 0)
                    temp1 += dp[index - 1].first;

                // or we come from bottom of last..
                temp2 += abs(curr_last_y - prev_second_y);
                if (index > 0)
                    temp2 += dp[index - 1].second;

                // now we go to the top..
                temp1 += curr;
                temp2 += curr;

                dp[index].first = min(temp1, temp2);
            }
            index++;
            // also we udpate prev y's
            prev_first_y = curr_first_y;
            prev_second_y = curr_last_y;
            prev_x = curr_x;
        }

        // now we go from last dp to final point using first or second..
        int needed = (end_x - prev_x);
        int first = needed;
        int second = needed;

        first += abs(prev_first_y - end_y);
        if (SIZE)
            first += dp[SIZE - 1].first;
        second += abs(prev_second_y - end_y);
        if (SIZE)
            second += dp[SIZE - 1].second;
        int res = min(first, second);
        cout << res << endl;
    }
    return 0;
}
