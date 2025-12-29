#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

ll power(ll base, ll exponent)
{
    ll res = 1;
    while (exponent)
    {
        if (exponent & 1)
        {
            res *= base;
        }
        base *= base;
        exponent >>= 1;
    }
    return res;
}

// Function to get the number at cell (x, y)
ll get_number(ll size, ll x, ll y)
{
    ll left = 1, right = size * size;
    while (true)
    {
        ll phase;
        ll phaseelements = (right - left + 1) / 4;
        if (phaseelements == 1)
        {
            if (x == 1 && y == 1)
            {
                return left;
            }
            else if (x == 1 && y == 2)
            {
                return right;
            }
            else if (x == 2 && y == 1)
            {
                return right - 1;
            }
            else
            {
                return left + 1;
            }
        }

        if (x > (size / 2))
        {
            if (y > (size / 2))
            {
                phase = 2;
            }
            else
                phase = 3;
        }
        else
        {
            if (y > (size / 2))
            {
                phase = 4;
            }
            else
                phase = 1;
        }
        if (phase == 1)
        {
            right -= (3 * phaseelements);
        }
        else if (phase == 2)
        {
            left += phaseelements;
            right -= (2 * phaseelements);
            x -= (size / 2);
            y -= (size / 2);
        }
        else if (phase == 3)
        {
            left += (2 * phaseelements);
            right -= phaseelements;
            x -= (size / 2);
        }
        else
        {
            left += (3 * phaseelements);
            y -= size / 2;
        }
        size /= 2;
    }
    return 0;
}

// Function to get coordinates of number d
pair<ll, ll> get_coordinates(ll size, ll d)
{
    ll number = size * size;
    ll xleft = 1, xright = size, yleft = 1, yright = size;
    ll x, y;
    while (true)
    {
        if (number == 4)
        {
            if (d == 1)
            {
                x = xleft;
                y = yleft;
                break;
            }
            else if (d == 2)
            {
                x = xright;
                y = yright;
                break;
            }
            else if (d == 3)
            {
                x = xright;
                y = yleft;
                break;
            }
            else
            {
                x = xleft;
                y = yright;
                break;
            }
        }

        ll phaseelements = number / 4;
        ll phase = (d + phaseelements - 1) / phaseelements;
        ll xmid = (xleft + xright) / 2;
        ll ymid = (yleft + yright) / 2;
        if (phase == 1)
        {
            xright = xmid;
            yright = ymid;
        }
        else if (phase == 2)
        {
            xleft = xmid + 1;
            yleft = ymid + 1;
        }
        else if (phase == 3)
        {
            xleft = xmid + 1;
            yright = ymid;
        }
        else
        {
            xright = xmid;
            yleft = ymid + 1;
        }
        number /= 4;
        d -= (phaseelements * (phase - 1));
    }
    return {x, y};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        ll grid_size = power(2, n);
        ll q;
        cin >> q;
        cin.ignore();

        for (ll i = 0; i < q; i++)
        {
            string line;
            getline(cin, line);
            stringstream ss(line);
            string type;
            ss >> type;

            if (type == "->")
            {
                ll x, y;
                ss >> x >> y;
                ll result = get_number(grid_size, x, y);
                cout << result << '\n';
            }
            else if (type == "<-")
            {
                ll d;
                ss >> d;
                pair<ll, ll> coord = get_coordinates(grid_size, d);
                cout << coord.first << " " << coord.second << '\n';
            }
        }
    }

    return 0;
}
