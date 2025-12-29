#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so it will def be some prime number ..

    now how do i find the least prime number ..

    so we brute force all the prime numbers from 2... 200..

*/
vector<int> findPrimesUpTo300()
{
    const int limit = 300;
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int num = 2; num * num <= limit; ++num)
    {
        if (isPrime[num])
        {
            for (int multiple = num * num; multiple <= limit; multiple += num)
            {
                isPrime[multiple] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= limit; ++i)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }

    return primes;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> primes = findPrimesUpTo300();
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int res = 1e18;
        for (auto a : primes)
        {
            bool found = false;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] % a != 0)
                {
                    res = a;
                    found = 1;
                    break;
                }
            }
            if (found)
                break;
        }
        cout << res << endl;
    }
    return 0;
}
