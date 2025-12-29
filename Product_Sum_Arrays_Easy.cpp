#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we need to print min(r,3) ..

    n is given..

    array is good if

    ai is from 1..n

    array is sorted..

    sum of array == n ...

    multiple is also n ..

    so i need to find atleast 3 good arrays..

    one is def n itself..

    and then it is any 2 factor of n followed by

    1,1,1,1 till sum n is reached..

    for any n no of multiple will be n/2

    we can bf them..




*/
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

vector<pair<int, int>> getFactorPairs(int n)
{
    vector<pair<int, int>> res;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res.push_back({i, n / i});
            if (i != n / i)
                res.push_back({n / i, i});
        }
    }
    return res;
}

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
        vector<pair<int, int>> arr = getFactorPairs(n);

        set<pair<int, int>> st;
        st.insert({-1, n});
        bool found = false;
        for (auto a : arr)
        {
            if (st.size() >= 3)
                break;
            int first = a.first;
            int second = a.second;
            // multiple is already n..
            // now rem 1..
            int rem = n - first - second;
            if (rem < 0)
                continue;
            if (n - rem >= 0)
            {

                int mini = min(a.first, a.second);
                int maxi = max(a.first, a.second);
                if (found == false)
                {
                    bool first = isPrime(mini);
                    bool second = isPrime(maxi);
                    if (first == 0 || second == 0)
                    {
                        found = 1;
                    }
                    st.insert({mini, maxi});
                }
            }
        }
        int res = 0;
        res += (int)st.size();
        res += ((found) ? 1 : 0);
        cout << min(res, 3LL) << endl;
    }

    return 0;
}
