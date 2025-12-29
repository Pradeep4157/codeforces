#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
            IF GCG(ARR)>1 RETURN ARR
            FOR GCD>1 THERE SHOULD BE SOME COMMON FACTOR BETWEEN THE ELEMENTS
            WITH THE HELP OF K
            TO EACH ELEMENT IN ARRAY I CAN ADD EITHER 0,K,2*K,3*K,
            ... K*K
            WHAT SHOULD I ADD TO EACH ELEMENT?
            1)IF K IS ODD THEN I CAN MAKE ALL  THE ELEMENTS EVEN

            WHAT IF K IS EVEN
            2) FOR A[I] I CAN MAKE IT A FACTOR OF EITHER A[I]%K
             OR K+A[I]%K OR K-A[I]%K
            SO TRY THESE 3 VALUES
            7 10
            7+(x*10)
*/
int modInverse(int a, int m)
{
    int m0 = m, x0 = 0, x1 = 1;
    while (a > 1)
    {
        int q = a / m;
        int t = m;

        m = a % m;
        a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }
    return (x1 + m0) % m0;
}

int make(int val, int k)
{
    int mod = k + 1;
    int rem = val % mod;
    if (rem == 0)
        return val;

    int invK = modInverse(k, mod);
    int m = (1LL * (mod - rem) * invK) % mod;
    return val + m * k;
}

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
        int gcd = arr[0];
        for (int i = 1; i < n; i++)
        {
            gcd = __gcd(arr[i], gcd);
        }
        if (gcd > 1)
        {
            for (auto a : arr)
                cout << a << " ";
            cout << endl;
            continue;
        }
        if (k % 2)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] & 1)
                    arr[i] += k;
            }
            for (auto a : arr)
                cout << a << " ";
            cout << endl;
            continue;
        }
        else
        {
            bool ok = true;
            // EVERYTHING WILL BE A FACTOR OF K+1
            for (int i = 0; i < n; i++)
            {
                int rem = arr[i] % (k + 1);
                if (rem != 0)
                {
                    arr[i] = arr[i] + k * (arr[i] % (k + 1));
                }
            }

            for (auto a : arr)
                cout << a << " ";
            cout << endl;
        }
    }
    return 0;
}
