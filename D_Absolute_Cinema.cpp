#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    f(1) = 0 + a2 + 2a3 + 3a4 + ...(n - 1)an

    f(1) - f(2) = a2 - a1 -> T

    f(3) - f(2) = a1 - a2 -> V

    T - V  = 2*a2


    A,B and C,B

    you get 2B

    now after all this 1,n will be left..

    which can be found from each other's eqn..

    that is 1 is (n - 1)a1 + (n - 2)a2... 1an - 1 = f(n)

    and same for n is 1a2 + ....(n - 1) = f(1)

*/
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> res(n);
        for (int i = 1; i < n - 1; i++)
        {
            int a = i - 1;
            int b = i;
            int c = i + 1;
            int curr = arr[a] - arr[b];
            curr += arr[c] - arr[b];
            curr /= 2;
            res[i] = curr;
        }
        // for 1..
        int first = 0;
        int last = 0;
        int multiple = 1;
        for (int i = n - 2; i > 0; i--)
        {
            first += (multiple++) * (res[i]);
        }
        first = arr[n - 1] - first;
        first /= (n - 1);
        res[0] = first;
        multiple = 1;
        for (int i = 1; i < n - 1; i++)
        {
            last += (multiple++) * res[i];
        }
        last = arr[0] - last;
        last /= (n - 1);
        res[n - 1] = last;
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
