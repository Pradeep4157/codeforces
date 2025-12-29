#include <bits/stdc++.h>
#define int long long
using namespace std;

int_fast32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        unordered_set<int> alice, bob;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'A')
                alice.insert(i + 1);
            else
                bob.insert(i + 1);
        }
        if (alice.count(1) && alice.count(n))
        {
            cout << "Alice" << endl;
            continue;
        }
        else if (bob.count(1) && bob.count(n))
        {
            cout << "Bob" << endl;
            continue;
        }
        else if (alice.count(1))
        {
            if (bob.size() == 1)
            {
                cout << "Alice" << endl;
                continue;
            }
            else
            {
                cout << "Bob" << endl;
                continue;
            }
        }
        else
        {
            if (alice.size() == 1)
            {
                cout << "Bob" << endl;
                continue;
            }
            else
            {
                if (alice.count(n - 1))
                    cout << "Alice" << endl;
                else
                    cout << "Bob" << endl;
            }
        }
    }
    return 0;
}
