#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    only thing that matters in this prob is

    max of bi and max of ai..

    and if m was small we could

    do 1...m

    res+=max(b+i,a)

    so till some i index a will be dominent..

    after that b + i will  be dominent..

    so we need to find that index

    bs..

    low = 0, high = m;

    for a mid.
        if ( b + mid <= a){
            res = mid

            low inc..


        }
        else high dec..

    so after this res times a and rem = m - res

    rem*b + sum(res+1..m)


    so y or i gets updated at every index..

    so we cant

    now i have found the point after which

    i am def going to use b + i..

    so i need to calculate what is res

    for res + 1..

    from there onwards it will be +1,+1... m

    what's happening after res..

    i am taking first till some index..


    after that i am taking b,b,b,b...

    so the ans is still going to be

    const for all  <= the last first



*/
int sum(int a, int b)
{
    long long sum = 1LL * (b - a + 1) * (a + b) / 2;
    return sum;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n), B(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> B[i];
        }
        int a = *max_element(arr.begin(), arr.end());
        int b = *max_element(B.begin(), B.end());
        int low = 0, high = m;
        int res = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int first = 0;
            int second = 0;
            for (int i = 0; i < n; i++)
            {
                first = max(arr[i], B[i] + first);
                second = max(second, arr[i]);
            }
            if (first <= second)
            {
                res = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        cout << res << endl;
        // now res times a .. and rem times b
        int ans = res * a;

        if (res < m)
        {
            // then i am going to use b + i..
            res++;
            for (int i = 0; i < n; i++)
            {
                res = max(res + B[i], arr[i]);
            }
            // now i have what it is for the first one..
        }
        // ans += (rem * b);
        // ans += sum(res + 1, m);
        // cout << ans << endl;
    }
    return 0;
}
