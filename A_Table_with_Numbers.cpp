#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we take k pairs of numbers

    from the array ..

    all of these pairs should be vlaid..

    the no of pairs that i select should be <=n..

    so n pairs i can select..




*/
int n, h, l;
bool is_valid(int a, int b)
{

    return ((a <= h) && (b <= l));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> h >> l;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int res = 0;
        vector<bool> vis(n, false);
        sort(arr.begin(), arr.end());

        int left = 0, right = n - 1;
        while (left < right)
        {
            if (is_valid(arr[left], arr[right]) || is_valid(arr[right], arr[left]))
            {
                res++;
                left++;
                right--;
            }
            else
                right--;
        }
        cout << res << endl;
    }

    return 0;
}
