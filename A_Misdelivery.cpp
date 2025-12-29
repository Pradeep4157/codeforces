#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int index;
    string curr;
    cin >> index;
    cin >> curr;
    if (arr[index - 1] == curr)
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
    return 0;
}
