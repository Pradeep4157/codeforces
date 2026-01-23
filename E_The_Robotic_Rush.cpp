#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    all the robots move the same directions..

    so i just need left distance of all robots

    when they die and right distance ..

    at some left distance x robot dies..

    and some right dist robot dies..

    we just prefix and suffix of all these

    and after every move if we are

    at some left x then suffix x will give how many

    died

    and if we are at some right then prefix x

    will give how many died..

    once a robot dies i should not count that..

    so i travel some x left distances and some y right distance..

    all the right distances i  can sort and all the left distances i can sort...

    and then for each arr[i] it will have some dist left dist where it dies and right dist where it dies..

    ok so if left survival > left_max_travelled then this cannot die here..

    else mp[left_survival]++

    that's it ..

    and same for right side..

    if mp i cannot find curr right dist then continue

    else mp[right survival] ++

    and while travelling decrease the amount..

*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> arr(n), b(m);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        sort(b.begin(), b.end());

        map<int, set<int>> LEFT, RIGHT;
        string s;
        cin >> s;

        int left_size = 1, right_size = 1;
        for (int i = 0; i < n; i++)
        {
            auto it = lower_bound(b.begin(), b.end(), arr[i]);
            // this will give left closest..
            if (it != b.end())
            {

                int spike = *it;
                if (spike < arr[i])
                {

                    int dist = abs(arr[i] - spike);
                    // i die here..
                    LEFT[dist].insert(i);
                    left_size = max(left_size, spike);
                }
                else if (it != b.begin())
                {
                    it--;
                    spike = *it;
                    int dist = abs(arr[i] - spike);
                    LEFT[dist].insert(i);
                    left_size = max(left_size, spike);
                }
            }
            else
            {
                it--;
                int spike = *it;
                int dist = abs(arr[i] - spike);
                LEFT[dist].insert(i);
                left_size = max(left_size, spike);
            }
            auto it1 = upper_bound(b.begin(), b.end(), arr[i]);
            if (it1 != b.end())
            {
                int spike = *it1;
                int dist = abs(arr[i] - spike);
                RIGHT[dist].insert(i);
                right_size = max(right_size, dist);
            }
        }

        set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(i);
        }
        int curr_pos = 0;
        for (auto a : s)
        {
            if (a == 'L')
                curr_pos--;
            else
                curr_pos++;
            if (curr_pos <= 0)
            {
                for (auto a : LEFT[abs(curr_pos)])
                {
                    if (st.count(a))
                        st.erase(a);
                }
            }
            else
            {
                for (auto a : RIGHT[curr_pos])
                {
                    if (st.count(a))
                        st.erase(a);
                }
            }
            cout << st.size() << " ";
        }

        cout << endl;
    }
    return 0;
}
