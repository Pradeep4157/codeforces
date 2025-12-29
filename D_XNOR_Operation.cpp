#include <bits/stdc++.h>
#define int long long
using namespace std;
int count(int l)
{
    int total = 0;
    for (int k = 2; k <= l; k += 2)
    {
        total += (l - k + 1);
    }
    return total;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0;
    int res = 0;
    while (i < n)
    {
        while (i < n && s[i] == '0')
            i++;
        if (i == n)
            break;
        int j = i;
        while (j < n && s[j] == '1')
            j++;
        j--;
        int l = j - i + 1;
        res += (l * (l + 1)) / 2;
        i = j + 1;
    }
    i = 0;
    vector<pair<int, int>> zeroes;
    while (i < n)
    {
        while (i < n && s[i] == '1')
            i++;
        if (i == n)
            break;
        int j = i;
        while (j < n && s[j] == '0')
            j++;
        j--;
        zeroes.push_back({i, j});
        int l = j - i + 1;
        int curr = count(l);
        res += curr;
        i = j + 1;
    }
    for (auto a : zeroes)
    {

        int left = a.first;

        int right = a.second;
        int len = right - left + 1;
        if (left == right)
            continue;
        left--;
        right++;
        while (left >= 0 && s[left] == '1')
            left--;
        left++;
        while (right < n && s[right] == '1')
            right++;
        right--;
        int leftcount = a.first - left;
        int rightcount = right - a.second;
        // combining with left ones
        int leftposs = (leftcount * (leftcount + 1)) / 2;
        int rightposs = (rightcount * (rightcount + 1)) / 2;
        res += leftposs * (len / 2);
        res += rightposs * (len / 2);
        cout << left << ":" << right << "->" << leftcount << ":" << rightcount << endl;
        if ((right - left + 1) % 2 == 0)
            res += (leftcount * rightcount);
    }
    cout << res << endl;
    return 0;
}
