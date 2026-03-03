#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we can inc any element by k..

    all ele should be made dist with min opertions..

    so we keep decreasing some ele..

    so on what ele are we going to apply this op.

    sames eles..

    4,4,4,4

    so for first we will keep same for other first we do k,2k,3k also these positions should be open..

    also since k can be pos or neg..

    yaa traversing from a direction is better..


    because we will know the positions that are opened in that dir..

    if k is > 0 then start from biggest because we cant go left..

    so something of sort 0..k -1 is left..then

    so on the basis of remainder we can do ..

    so any number can go only to remainders..

    so it will go the nearest remainder there is ..

    so for every ele if there are duplicates then we will keep removing from the set the remainder that is available and using that remainder

    and then after we are done processing this ele there would be gap between this ele and next new number

    so we will use those gap numbers to  add but we

    it is of that form only we need open positions with remainders..

    can i make same code for k > 0 && k < 0

    maybe i will have to group the same remainder numbers in a single group because the affect each other..

    1,4 and k == -3 then 4 will  have to jump twice..

    so for each group we need those many positions in that right ?

    so we iterate in these groups..

    and check if that pos is opened or not..

    if not then we find the next pos..

    i will have to keep doing -k which is same as bf..

    so at max what do we need

    we need only n positions..

    so we just need to find them ?

    so for every pos if there are some req we will find them in advance and store it in some rem map..

    for every remainder keep the necessary postions..

    that shouldnt be more than O(n)

    and then iterate and if there are open pos then add them as well..





*/
int n, k;
int front(int a, int b, int k)
{
    if (a >= b)
        return 0;
    return (b - a + k - 1) / k;
}

int back(int a, int b, int k)
{
    if (b <= a)
        return 0;
    int step = -k;
    return (b - a + step - 1) / step;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int res = 0;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        map<int, int> rem;
        map<int, int> same;
        for (auto a : arr)
        {
            rem[a]++;
            same[a]++;
        }
        map<int, deque<int>> mp;
        // now we find all the pos that are necessary..
        set<int> st;
        if (k > 0)
        {
            sort(arr.rbegin(), arr.rend());
            // now in this case we need to store the right free indexes on the right of biggest element..
            // we will store all the mod sames just in case..
            int maxi = arr[0];

            for (auto a : rem)
            {
                int min_req = a.second;
                // we will find the next available to the biggest..
                int next = a.first + ceil((maxi - a.first) / k) * k;

                // now we are at a free pos..
                // now from here we find enough ele to satisfy..
                while (min_req--)
                {
                    mp[a.first].push_back(next);
                    next += k;
                }
            }
            // now we have enough open positions for each group ..
            // for each adj element if we see a gap we will push in front of the deque because this open pos is better than far ones..
            // for (auto a : mp)
            // {
            //     cout << a.first << ":";
            //     for (auto b : a.second)
            //         cout << b << " ";
            //     cout << endl;
            // }
            for (int i = 0; i < n; i++)
            {
                int rem = arr[i];
                deque<int> &curr_available = mp[rem];
                int first = curr_available.front();
                if (!st.count(arr[i]))
                {

                    st.insert(arr[i]);

                    if (first == arr[i])
                        curr_available.pop_front();
                }
                // we will use the front position in the dequee.

                // that is going to be >= arr[i]..
                else
                {
                    int temp = front(arr[i], first, k);

                    res += temp;
                    curr_available.pop_front();
                }

                // now we add the positions that are available between curr ele and next ele..
                if (i < n - 1)
                {
                    int start = arr[i + 1] + 1;
                    int end = arr[i] - 1;
                    for (int i = end; i >= start; i--)
                    {
                        int curr_rem = i % k;

                        mp[curr_rem].push_front(i);
                    }
                }
                // this should work..
            }
        }
        else
        {
            sort(arr.begin(), arr.end());
            int mini = arr[0];
            // we keep going left in this case..
            for (auto a : rem)
            {
                int min_req = a.second;
                int next = mini - ceil((mini - a.first) / k) * k;
                if (a.first < mini)
                {
                    next = a.first;
                }
                while (min_req--)
                {
                    mp[a.first].push_back(next);
                    next += k;
                }
            }
            // for (auto a : mp)
            // {
            //     cout << a.first << ":";
            //     for (auto b : a.second)
            //         cout << b << " ";
            //     cout << endl;
            // }
            for (int i = 0; i < n; i++)
            {
                int rem = arr[i];
                deque<int> &curr_available = mp[rem];
                int first = curr_available.front();
                if ((!st.count(arr[i])))
                {
                    st.insert(arr[i]);
                    if (first == arr[i])
                        curr_available.pop_front();
                }
                // we will use the front position in the dequee.

                // that is going to be >= arr[i]..
                else
                {
                    int temp = back(first, arr[i], k);

                    res += temp;

                    curr_available.pop_front();
                }

                if (i < n - 1)
                {
                    int start = arr[i] + 1;
                    int end = arr[i + 1] - 1;
                    for (int i = start; i <= end; i++)
                    {
                        int curr_rem = i % k;
                        mp[curr_rem].push_front(i);
                    }
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
