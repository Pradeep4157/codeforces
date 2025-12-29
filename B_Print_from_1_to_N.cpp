    #include <bits/stdc++.h>
    #define ll int64_t
    using namespace std;
    void recursion(int n)
    {
        if (n == 1)
        {
            cout << << endl;
            return;
        }
        recursion(n - 1);
        cout << n << endl;
        return;
    }
    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        ll n;
        cin >> n;
        recursion(n);
        return 0;
    }
