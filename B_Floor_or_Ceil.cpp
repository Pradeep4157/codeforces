#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
ll findhigh(ll x, ll n, ll m)
{
    while (x > 1 && n + m > 1)
    {
        if (x & 1)
        {
            if (n > 0)
            {
                x /= 2;
                n--;
            }
            else if (m > 0)
            {
                x = (x + 1) / 2;
                m--;
            }
            else
                break;
        }
        else
        {
            if (n > 0)
            {
                x /= 2;
                n--;
            }
            else if (m > 0)
            {
                x /= 2;
                m--;
            }
            else
                break;
        }
    }
    if (x == 0)
        return x;
    if (n > 0)
    {
        x /= 2;
    }
    else if (m > 0)
    {

        x = (x + 1) / 2;
    }
    return x;
}
ll findlow(ll x, ll n, ll m)
{
    while (x > 1 && n + m > 1)
    {
        if (x & 1)
        {
            if (m > 0)
            {
                x = (x + 1) / 2;
                m--;
            }
            else if (n > 0)
            {
                x /= 2;
                n--;
            }
            else
                break;
        }
        else
        {
            if (m > 0)
            {
                m--;
                x /= 2;
            }
            else if (n > 0)
            {
                n--;
                x /= 2;
            }
            else
                break;
        }
    }
    if (n > 0)
    {
        x /= 2;
    }
    else if (m > 0)
    {
        x = (x + 1) / 2;
    }
    return x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, n, m;
        cin >> x >> n >> m;
        ll high = findhigh(x, n, m);
        ll low = findlow(x, n, m);
        cout << low << " " << high << endl;
    }
    return 0;
}
