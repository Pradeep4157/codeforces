#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k;
bool firstcheck(vector<int> &arr, string &s, int k)
{
    int i = 0;
    while (i < n)
    {
        while (i < n && s[i] == '0')
            i++;
        if (i == n)
            break;
        int j = i;
        int currsum = 0;
        while (j < n && s[j] == '1')
        {
            currsum += arr[j];
            j++;
        }
        if (currsum > k)
            return true;
        i = j;
    }
    return false;
}
bool secondcheck(vector<int> &arr, string &s, int k)
{
    int i = 0;
    while (i < n)
    {
        while (i < n && s[i] == '0')
            i++;
        if (i == n)
            break;
        int j = i;
        int currsum = 0;
        while (j < n && s[j] == '1')
        {
            currsum += arr[j];
            j++;
        }
        if (currsum == k)
            return true;
        i = j;
    }
    return false;
}
int kadane(vector<int> &arr)
{
    int sum = 0;
    int maxsum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = max(arr[i], arr[i] + sum);
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}
int_fast32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                count++;
        }
        int index = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                index = i;
                arr[i] = -1e13;
            }
        }
        if (count == 0)
        {
            int maxsum = kadane(arr);
            if (maxsum == k)
            {
                cout << "Yes" << endl;
                for (auto a : arr)
                    cout << a << " ";
                cout << endl;
            }
            else
                cout << "No" << endl;
            continue;
        }
        int newsum = kadane(arr);
        if (newsum > k)
        {
            cout << "No" << endl;
            continue;
        }

        int leftsum = 0;
        int currsum = 0;
        for (int j = index - 1; j >= 0; j--)
        {
            currsum += arr[j];
            leftsum = max(leftsum, currsum);
        }
        int rightsum = 0;
        currsum = 0;
        for (int j = index + 1; j < n; j++)
        {
            if (s[j] == '0')
                arr[j] = INT_MIN;
        }
        for (int j = index + 1; j < n; j++)
        {
            currsum += arr[j];
            rightsum = max(rightsum, currsum);
        }
        int sum = leftsum + rightsum;
        int rem = k - sum;
        arr[index] = rem;

        cout << "Yes" << endl;
        for (auto a : arr)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
