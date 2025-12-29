#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;

const int mod = 1e9 + 7;

// ordered_set using PBDS
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int_fast32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> first(n);
    for (int i = 0; i < n; i++)
        cin >> first[i];

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ordered_set<int> st;
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        int leftmore = st.size() - st.order_of_key(arr[i]);

        int totalmore = n - arr[i];
        int rightmore = totalmore - leftmore;
        int totalright = n - 1 - i;
        int rightless = totalright - rightmore;

        res = (res + leftmore + rightless) % mod;

        st.insert(arr[i]);
    }

    cout << res << endl;
    return 0;
}
