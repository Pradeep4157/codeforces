#include <bits/stdc++.h>
#define int long long
using namespace std;
double dist(double a, double b, double x, double y)
{
    double first = pow(abs(x - a), 2);
    double second = pow(abs(y - b), 2);
    return sqrt(first + second);
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
        double x, y, a, b;
        cin >> x >> y >> a >> b;
        vector<double> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (n == 1)
        {
            double first = pow(abs(x - a), 2);
            double second = pow(abs(y - b), 2);
            double curr = first + second;
            double have = pow(arr[0], 2);
            cout << ((have == curr) ? "Yes" : "No") << endl;
            continue;
        }
        double maxi = accumulate(arr.begin(), arr.end(), 0);
        double req = dist(a, b, x, y);
        sort(arr.begin(), arr.end());
        double rem = maxi - arr[n - 1];
        double mini = max((double)0, arr[n - 1] - rem);
        if (req >= mini && req <= maxi)
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
    return 0;
}
