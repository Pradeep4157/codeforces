#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    n,k is given..

    array is given..

    1<=ai<=k..

    bi of size m

    every pos multiple of bi should <=k

    should be there in arr..

    every divisor of arr[i] should be there

    in b[i]..

    i think this will automatically satisfy

    once b cond are satisfied..

    all multiples of all b[i] should be

    there in arr[i]..

    all bi is going to be some of the

    values of arr[i]..

    now for all the values of arr[i]

    either it is not present in b[i]..

    else it should have all the

    multiples till k

    else it is impossible..

    these are going to be mostly

    all the prime numbers ..

    because they wont be multiple of

    some smaller numbers..

    maybe 1 is an edge case..

    for arr containing 1 the ans is

    either {1} else it is -1

    {1} is when arr is 1...k

    else - 1

    for other cases..

    first we will find all the prime numbers..




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
        multiset<int> st1, st2;

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        for (int i = 0; i < n; i++)
            st1.insert(arr[i]);

        for (auto a : arr)
        {
            st2.insert(a);
        }
        vector<int> res;
        while (!st1.empty())
        {
            int front = *st1.begin();
            res.push_back(front);
            for (int i = 1; i * front <= k; i++)
            {
                st1.erase(i * front);
            }
        }
        bool ok = 1;
        for (auto a : res)
        {
            int curr = a;
            for (int i = 1; i * curr <= k; i++)
            {
                if (!st2.count(i * curr))
                {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << res.size() << "\n";
            for (auto a : res)
                cout << a << " ";
            cout << endl;
        }
    }

    return 0;
}