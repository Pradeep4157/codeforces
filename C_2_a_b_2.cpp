#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll N;
    cin >> N;

    ll count = 0;

    vector<bool> visited((N + 1) / 2, false);

    for (ll b = 1; b * b <= N; ++b)
    {
        ll b2 = b * b;
        ll val = b2 * 2;
        while (val <= N)
        {
            if (val > N / 2)
                break;
            if (!visited[val])
            {
                visited[val] = true;
                count++;
            }

            val *= 2;
        }
    }
    ll power = 2;
    while (power <= N)
    {
        if (power > N / 2)
            count++;
        power *= 2;
    }

    cout << count << '\n';
    return 0;
}
