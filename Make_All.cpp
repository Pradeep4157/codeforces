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
    vector<int> arr(20);
    int sum = 3;
    arr[0] = 1;
    arr[1] = 2;
    for (int i = 2; i < 20; i++)
    {
        int newele = sum;
        arr[i] = newele;
        sum += newele;
    }
    for (auto a : arr)
        cout << a << " ";
    cout << endl;

    return 0;
}
