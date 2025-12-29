#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so here what we do is that first we find the right ones and then with the help of already found right ones we process the left

    unfilled nodes one by one to get the value at those indexes

    HOW DO WE FIND THE RIGHT ONES FIRST ?

        keep sending the indexes until you getting something other than zero , when you get fill that index with the value

        that you got and remove that index from the vector
*/
int find(vector<int> &q)
{
    cout << "? ";
    cout << q.size() << " ";
    for (auto a : q)
        cout << a << " ";
    cout << endl;
    int res;
    cin >> res;
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(2 * n, -1);
        vector<int> q;
        q.push_back(1);
        for (int i = 2; i <= 2 * n; i++)
        {
            // now we will push and check whether we get anything or not
            q.push_back(i);
            auto number = find(q);
            if (number)
            {
                // that means we got element at the last index in the q
                arr[q.back() - 1] = number;
                q.pop_back();
            }
        }
        // now we have  all the right elements
        q.clear();
        vector<int> already;is_reference
        for (int i = 0; i < 2 * n; i++)
        {
            if (arr[i] != -1)
            {
                already.push_back(i + 1);
            }
            else
                q.push_back(i + 1);
        }
        for (auto a : q)
        {
            // now we will process each one of these alone
            already.push_back(a);
            int number = find(already);
            arr[a - 1] = number;
            already.pop_back();
        }
        cout << "! ";
        for (auto a : arr)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
