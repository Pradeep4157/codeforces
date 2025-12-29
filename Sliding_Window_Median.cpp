#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<
    pair<int, int>, // (value, unique_id)
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_multiset;
/*
        OBSERVATIONS:

    we can use ordered set to keep all the k elements and then find

    then middle ele is k >> 1

    now if k is even do middle --

    first find for first k ele and then for the remaining do a for loop

    and add right value and remove left value and find the middle ele..


*/

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ordered_multiset oms;
    int u_index = 0;
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // middle index ..
    int middle = k / 2;
    if (k % 2 == 0)
    {
        middle--;
    }
    int i = 0;
    while (i < k)
    {
        oms.insert({arr[i], u_index++});
        i++;
    }

    vector<int> res;
    // now we have k ele in arr..
    res.push_back(oms.find_by_order(middle)->first);
    int left = 0;
    for (int right = k; right < n; right++)
    {
        // removing the left part..
        auto it = oms.lower_bound({arr[left], -1});
        oms.erase(it);
        // now adding the right ele..
        oms.insert({arr[right], u_index++});
        // now find the middle ..
        res.push_back(oms.find_by_order(middle)->first);
        left++;
    }
    for (auto a : res)
        cout << a << " ";
    cout << endl;

    return 0;
}
