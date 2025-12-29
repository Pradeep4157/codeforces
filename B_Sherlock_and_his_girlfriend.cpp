#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    2,4,6,8 all should have different colors
    3,6,9,12,15
    max we need 2 colors:
        6->2,3,


*/
vector<vector<int>> find(int n)
{
    vector<vector<int>> isprime(n + 1);

    for (int i = 2; i <= n; i++)
    {
        if (isprime[i].size() == 0)
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                isprime[j].push_back(i);
            }
        }
    }
    return isprime;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if (n <= 2)
    {

        cout << 1 << endl;
        for (int i = 0; i < n; i++)
            cout << 1 << " ";
        cout << endl;
        return 0;
    }
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = (i + 1);
    }
    vector<vector<int>> primes = find(n + 1);
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        int number = i + 2;
        if (primes[number].size() == 0)
        {
            res[i] = 1;
        }
        else
            res[i] = 2;
    }
    cout << 2 << endl;
    for (auto a : res)
        cout << a << " ";
    cout << endl;

    return 0;
}
