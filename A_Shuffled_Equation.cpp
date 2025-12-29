#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> arr(3);
    for (int i = 0; i < 3; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    if (arr[0] * arr[1] == arr[2])
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
    return 0;
}
