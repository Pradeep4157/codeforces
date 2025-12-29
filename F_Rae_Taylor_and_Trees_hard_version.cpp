#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    now in this prob.. we need to return the edges as well...

    one thing is for sure that when a segment is made all of them have edges with prev one..

    now it is like dsu where we keep connnecting the nodes to their parent and parent..

    till the node which is its own parent..

    we just need some modification in our base method to solve this..

    one thing is that this is also a perm..

    so indexes are unq..

    now when we merge two things in pq..

    we can store the child of the current node..

    or childs of the current node..

    the method remains same i.e., at the end if pq.size() > 1 then there are 2 sgmts that cant be merged..

    so return no

    else for in the array ..

    for every ele in res..

    if res[i] is -1 maybe it is the leader or something so continue..

    else it will have some node...

    so just return the index of these 2..

    apart from this we need index map ..

    and res which is vector of vector..

    getting wa because edge is not right..

    maybe direct edge cant be made but they def can be connect but we need to connect some other part of the segment



    





*/

auto cmp = [](const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
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
        map<int, int> index;
        for (int i = 0; i < n; i++)
        {

            cin >> arr[i];
            index[arr[i]] = i;
        }
        vector<pair<int, int>> segments;
        vector<vector<int>> res(n);
        int left = 0;
        while (left < n)
        {
            int right = left + 1;
            while (right < n && arr[right] >= arr[right - 1])
            {
                res[right - 1].push_back(arr[right]);
                right++;
            }
            right--;
            segments.push_back({left, right});
            left = right + 1;
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

                    // here merging has happened..

                    // so we will store the child in the parent..

                    // here from lowest to currhighest.. edge is formed so we will store currhighes in lowest index..

                    res[index[lowest]].push_back(currhighest); // this should work..

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
            for (int i = 0; i < res.size(); i++)
            {

                for (auto b : res[i])
                    cout << arr[i] << " " << b << endl;
            }
            // now we need to output..
        }
        else
            cout << "No" << endl;
    }
    return 0;
}
