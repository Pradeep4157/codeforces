#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    we need to construct a permutation where for 2 nodes..

    u,v if there is an edge from u --- v and u < v then u appears

    before v in the permuation..


    3 4 1 2 5

    3 4 1 5 2

    3 - 5

    4  - 5

    1 - 5

    1 - 2

    2 4 5 1 3


    so the permutation goes inc,inc,inc.... drop , inc,inc,inc..

    drop, inc,inc...inc..

    these inc have made their own undirected graphs..

    now we need to make edges among these ..


    if we can connect all of them then it's a yes else its a no..

    so we will keep these subarrays now we will move from

    left to right..

    and keep the lowest now for a subarray if the highest is <

    lowest then we add its lowest to the array ..

    and move ahead..

    for a subarray if its heighest > lowest of the arrays then we

    keep removing them

    then after removal least = min( least , top.second)



    if 1 is at 0..

    everything is sorted..




*/
auto cmp = [](const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first > b.first;
    return a.second < b.second;
};

priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<pair<int, int>> segments;
        int left = 0;
        while (left < n)
        {
            int right = left + 1;
            while (right < n && arr[right] >= arr[right - 1])
                right++;
            right--;
            segments.push_back({left, right});
            left = right + 1;
        }
        if (segments.size() == 1)
        {

            cout << "Yes" << endl;
            continue;
        }
        
        // now we need to merge these.
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        pq.push({arr[segments[0].second], arr[segments[0].first]});
        int size = (int)segments.size();
        for (int i = 1; i < size; i++)
        {
            int currhighest = arr[segments[i].second];
            int currlowest = arr[segments[i].first];
            while (!pq.empty())
            {
                pair<int, int> top = pq.top();
                int highest = pq.top().first;
                int lowest = pq.top().second;
                if (lowest <= currhighest)
                {
                    pq.pop();
                    currlowest = min(currlowest, lowest);
                    currhighest = max(highest, currhighest);
                }
                else
                    break;
            }
            pq.push({currhighest, currlowest});
        }
        if (pq.size() <= 1)
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
    return 0;
}
