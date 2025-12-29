#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
ll N;
void recursion(ll n)
{
    if (n == 1)
    {
        int diff = N - 1;
        for (int i = 0; i < diff; i++)
        {
            cout << " ";
        }
        cout << "*" << endl;
        return;
    }
    recursion(n - 1);
    int time = n + n - 1;
    int diff = N - n;
    for (int i = 0; i < diff; i++)
    {
        cout << " ";
    }
    for (int i = 0; i < time; i++)
    {
        cout << "*";
    }
    cout << endl;
    return;
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
