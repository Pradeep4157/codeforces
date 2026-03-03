#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    if i have n - 1 ops then i will change

    from 2..n to 1..

    for every i if i want all the numbers to be equal to

    arr[i]..

    then it is = mp.size()

    i will change with groups..

    brute ans is mp.size()

    now we will only do for the first occurence of any element..

    because if i choose 2nd of that there

    might be some other arr[i] that is left to it but right

    of first ..

    so bf on first occurence of all the numbers..

    and then for these numbers..

    i want to know what all can i change..

    is it i will try to convert all the numbers to  first

    else nothing ?

    because if i dont do that and take some

    other right ele..

    then that will also have to do the same thing..

    mostly try to change all arr[i] to first number..



*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        map<int, int> mp;
        for (auto a : arr)
            mp[a]++;
        int first_ele = arr[0];
        int res = mp.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto a : mp)
        {
            if (a.first != first_ele)
            {
                pq.push(a.second);
            }
        }
        while (true)
        {
            if (pq.empty() || pq.top() > k)
                break;
            k -= pq.top();
            pq.pop();
            res--;
        }
        cout << res << endl;
    }
    return 0;
}
