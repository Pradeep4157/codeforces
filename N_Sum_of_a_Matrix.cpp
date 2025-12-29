#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
ll N, M;
void recursion(ll i, ll j, vector<vector<ll>> &arr1, vector<vector<ll>> &arr2)
{
    if (i == N - 1 && j == M - 1)
    {
        cout << arr1[i][j] + arr2[i][j] << endl;
        return;
    }
    if (j == M - 1)
    {
        cout << arr1[i][j] + arr2[i][j] << endl;
        recursion(i + 1, 0, arr1, arr2);
    }
    else
    {
        cout << arr1[i][j] + arr2[i][j] << " ";
        recursion(i, j + 1, arr1, arr2);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    N = n;
    M = m;
    vector<vector<ll>> arr1(n, vector<ll>(m));
    vector<vector<ll>> arr2(n, vector<ll>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
            cin >> arr1[i][j];
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
            cin >> arr2[i][j];
    }

    recursion(0, 0, arr1, arr2);
    return 0;
}
