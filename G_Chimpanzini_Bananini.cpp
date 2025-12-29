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
        int q;
        cin >> q;
        int score = 0;
        int sum = 0;
        int sum2 = 0;
        deque<int> arr1, arr2;
        int curr = 1;
        while (q--)
        {
            int s;
            cin >> s;
            if (s == 1)
            {
                int firstlast = arr1.back();
                int secondlast = arr2.back();
                arr1.pop_back();
                arr2.pop_back();
                arr1.push_front(firstlast);
                arr2.push_front(secondlast);
                if (curr == 1)
                {
                    int currfirst = arr1.front();
                    score += ((sum - currfirst) - ((arr1.size() - 1) * currfirst));
                    cout << score << endl;
                }
                else
                {
                    int currfirst = arr2.front();
                    score += ((sum - currfirst) - ((arr1.size() - 1) * currfirst));
                    cout << score << endl;
                }
            }
            else if (s == 2)
            {
            }
            else
            {
            }
        }
    }
    return 0;
}
