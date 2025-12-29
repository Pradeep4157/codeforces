#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
ll findmex(unordered_set<ll> &friends)
{
    if (!friends.count(0))
    {
        return 0;
    }
    else if (!friends.count(1))
        return 1;
    else
        return 2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x, y;
        cin >> n >> x >> y;
        vector<ll> arr(n, 0);
        x--;
        y--;
        arr[y] = 1;
        if ((y - x - 1) % 2 == 0)
        {

            for (ll i = x + 1; i < y; i++)
            {
                if (arr[i - 1] == 0)
                    arr[i] = 1;
            }
        }
        else
        {
            for (ll i = x + 1; i < y - 1; i++)
            {
                if (arr[i - 1] == 0)
                    arr[i] = 1;
            }
            arr[y - 1] = 2;
        }
        if ((n - (y - x + 1)) % 2 == 0)
        {

            for (ll i = y + 1; i < n; i++)
            {
                if (arr[i - 1] == 0)
                    arr[i] = 1;
            }
            if (arr[n - 1] == 0)
                arr[0] = 1;
            for (int i = 1; i < x; i++)
            {
                if (arr[i - 1] == 0)
                    arr[i] = 1;
            }
        }
        else
        {

            for (ll i = y + 1; i < n; i++)
            {
                if (arr[i - 1] == 0)
                    arr[i] = 1;
            }

            if (x == 0)
            {
                arr[n - 1] = 2;
            }
            else
            {
                arr[x - 1] = 2;
            }
            if (arr[n - 1] == 0)
                arr[0] = 1;
            for (ll i = 1; i < x - 1; i++)
            {
                if (arr[i - 1] == 0)
                    arr[i] = 1;
            }
        }
        for (auto a : arr)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}