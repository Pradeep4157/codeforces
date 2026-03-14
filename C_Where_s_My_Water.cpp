#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    n,h is given..

    swampy needs water..

    i need to give it to him..

    h * n grid above my house..

    each col has some bottom tiles dirt and above

    them there is water..

    i can place drain on some water tiles..

    i place a drain somewhere

    all the tiles above it , left && right to it that

    can come here will come in this drain..

    maybe can be done using dp

    by left traversal and right traversal..

    and then res is max at any point ..

    we will always place drain lowest of all columns..


    prob is that all the left dirt that is smaller than this we

    cant take its full  of that only >= this height..

    so left closest greater..

    so we will take dp of that + the dist betweeen these two * n - height..



    oh you can place 2 drains..


    there might be blocks in between so we need to think of that as well..

    how will we find the middle contri of left and right..

    





*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<pair<int, int>> dp(n);
        stack<int> st;
        vector<int> left_greater(n, -1), right_greater(n, -1);
        vector<pair<int, int>> DP(n);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && (arr[st.top()] < arr[i]))
                st.pop();
            if (!st.empty())
                left_greater[i] = st.top();
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && (arr[st.top()] < arr[i]))
                st.pop();
            if (!st.empty())
                right_greater[i] = st.top();
            st.push(i);
        }
        for (int i = 0; i < n; i++)
        {
            // merging with left side..
            // first thing is that we will get atleast height of this
            int curr = m - arr[i];
            // now we have left greater..
            // we will add dp of that..
            int left_cont = 0;
            if (left_greater[i] != -1)
            {
                int dist = i - left_greater[i] - 1;
                left_cont = (dist * curr);
                // but that tower might not be equally big so remove the contri of that and add sep..
                int left_height = arr[left_greater[i]];
                left_cont += m - left_height;
                DP[i].first = left_cont;
                left_cont += dp[left_greater[i]].first;
            }
            else
            {
                // if there's no left bigger than 1..this is all contri..
                int dist = i;
                left_cont = (dist * curr);
                DP[i].first = left_cont;
            }
            dp[i].first = left_cont;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            int curr = m - arr[i];
            int right_cont = 0;
            if (right_greater[i] != -1)
            {
                int dist = right_greater[i] - i - 1;
                right_cont = (dist * curr);
                int right_height = arr[right_greater[i]];
                right_cont += m - right_height;
                DP[i].second = right_cont;
                right_cont += dp[right_greater[i]].second;
            }
            else
            {
                int dist = n - 1 - i;
                right_cont = dist * curr;
                DP[i].second = right_cont;
            }
            dp[i].second = right_cont;
        }
        // now everything is stored just add this height contri add check with max..
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int left_index = left_greater[i];
            int right_index = right_greater[i];
            if (right_index == -1)
                right_index = n - 1;
            int curr = 0;
            curr += m - arr[i];
            curr += dp[i].first;
            curr += dp[i].second;
            int first = curr;
            res = max(res, curr);
            {
                int contri = 0;
                int max_height = i;
                for (int j = right_index + 1; j < n; j++)
                {
                    // now we can take right of j and left of i without any worries..
                    int curr = 0;
                    curr += dp[i].first;
                    curr += dp[j].second;
                    // now for mid.. if left_index of j is before right_index of i then move that to right_index + 1
                    int left_for_j = left_greater[j];
                    left_for_j = max(left_for_j,right_index + 1);
                    
                    // now add gap contri.. 
                    int left_size = right_index - i;
                    int left = left_size*(m - arr[i]);
                    // adding right height as well.. 
                    left += (m - arr[right_index])
                    
                    int right_size = j - left_for_j ;
                    int right = right_size*(m - arr[j]);
                    // adding left for j's height as well.. 
                    right += (m - arr[left_for_j]);
                    left = max
                    curr += left;
                    curr += right;
                    res = max(res,curr);
                }
            }
            {
                // this is for trying to merge with sonme left..
                for(int j = left_index - 1;j>=0;j--){
                    int curr = 0;
                    curr += dp[i].second;
                    curr += dp[j].first;
                    // right for j should be < left for i.. 
                    int right_for_j = right_greater[j];
                    right_for_j = min(right_for_j,left_index - 1);
                }
            }
            // cout << curr << ":" << dp[i].first << ":" << dp[i].second << endl;
        }
        // cout << endl;

        cout << res << endl;
    }
    return 0;
}
