#include <bits/stdc++.h>
#define int long long
using namespace std;
#include <iostream>
#include <vector>
using namespace std;

vector<int> generatePrimes(int n)
{
    int limit = 2 * n * 20; // Rough overestimate (safe side)
    vector<bool> is_prime(limit, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i < limit; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < limit; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i < limit && primes.size() < n; ++i)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }
    return primes;
}

int_fast32_t main()
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
        int sum = accumulate(arr.begin(), arr.end(), 0LL);
        vector<int> primes = generatePrimes(n);

        int minsum = accumulate(primes.begin(), primes.end(), 0LL);
        if (minsum <= sum)
        {
            cout << 0 << endl;
            continue;
        }
        sort(arr.rbegin(), arr.rend());

        int i = n - 1;
        while (true)
        {

            sum -= arr[i];
            minsum -= primes[i];
            if (minsum <= sum)
            {

                break;
            }
            i--;
        }

        cout << n - i << endl;
    }
    return 0;
}
