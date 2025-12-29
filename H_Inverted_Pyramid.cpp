#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
ll N;
void recursion(ll n)
{
    if (n == 1)
    {
        int dist = N - n;
        for (int i = 0; i < dist; i++)
        {
            cout << " ";
        }
        cout << "*" << endl;
        return;
    }
    int dist = N - n;
    for (int i = 0; i < dist; i++)
    {
        cout << " ";
    }
    int total = n + n - 1;
    for (int i = 0; i < total; i++)
    {
        cout << "*";
    }
    cout << endl;
    recursion(n - 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    N = n;
    recursion(n);
    return 0;
}
