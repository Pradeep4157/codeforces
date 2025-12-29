#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so the constraint is that we cant add 2 or more sides to make one side of the polygon longer ,

    therefore all the sides form a side of the polygon , now the next condition

    that is they need to be symmetrical  for that this is where a lot of things are going to be discarded

    here they are not even taking some subset they are literally taking subsequence

    now the conditions that needs to be fullfilled are

    i will map all of them and for every value i will take if the value is >=2 i will all the even values from it

    after all these things if the sides that i get == 2 , then i can only add 1 extra side that forms a traingle

    else i can choose two sides:

    for this i can store all the single values in an array and the sum of remaining sides that are present

    for every i, i either will add this only side for that if sum of sides > arr[i] then yes else no
    else if i choose to add two  sides then i will choose arr[i-1] if arr[i-1] + sides > arr[i] then yes else no

    i think what happens is that when i  am adding the last side lets say for 3,3,5,5 last side just needs to be < 16

    but dont you think some values of last side will make 3,5 join as one side and other side 3,5 which shouldnt happen

    ever



*/
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
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> singles;
        for (auto a : arr)
            mp[a]++;
        int remsides = 0;
        int res = 0;
        int evensides = 0;
        for (auto a : mp)
        {

            int sides = a.second;

            if (sides & 1)
            {
                sides--;
                singles.push_back(a.first);
            }
            remsides += ((a.first) * (sides));
            if (sides)
            {
                evensides += sides;
            }
        }
        if (evensides > 2)
            res = remsides;
        sort(singles.begin(), singles.end());
        int size = singles.size();
        for (int i = size - 1; i >= 0; i--)
        {
            // either i choose this as my single side

            // then this is possible

            if (singles[i] < remsides)
                res = max(res, singles[i] + remsides);
            // now i will also try to take 2 rems
            auto it = lower_bound(singles.begin(), singles.end(), singles[i] + remsides);
            if (it != singles.begin())
            {
                it--;
                int biggestvalue = *it;
                if (biggestvalue > singles[i] && singles[i] + remsides > biggestvalue)
                {
                    res = max(res, singles[i] + remsides + biggestvalue);
                }
            }
        }

        cout << res << endl;
    }
    return 0;
}
