#include <bits/stdc++.h>
#define int long long
using namespace std;
int res;
int half;
int limit;
int n;
unordered_set<int> st;
unordered_map<int, unordered_map<string, int>> dp;
bool ispalindrome(int res)
{
    string ans = to_string(res);
    int i = 0;
    int size = ans.size();
    int j = size - 1;
    while (i < j)
    {
        if (ans[i] != ans[j])
            return false;
        i++;
        j--;
    }
    // cout << ans << endl;
    return true;
}
int baseAToDecimal(const std::string &str, int base)
{

    int result = 0;
    for (char ch : str)
    {
        int digit = (isdigit(ch)) ? ch - '0' : toupper(ch) - 'A' + 10;

        if (result > (limit - digit) / base)
        {
            return 0;
        }

        result = result * base + digit;
    }
    if (result == base)
        return 0;
    if (ispalindrome(result))

    {

        return result;
    }
    return 0;
}

string decimalToBaseA(int num, int base)
{
    if (num == 0)
        return "0";
    string result;
    while (num > 0)
    {
        int digit = num % base;
        result += (digit < 10) ? '0' + digit : 'A' + digit - 10;
        num /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}
void dfs(int index, int maxi, string temp)
{
    if (index > half)
    {

        return;
    }

    // all the smaller ones
    auto it = dp.find(index);
    if (it != dp.end() && it->second.count(temp))
    {
        return;
    }
    dp[index][temp] = 1;
    string newtemp = temp;
    string rev = newtemp;
    reverse(rev.begin(), rev.end());
    string evenfull = newtemp + rev;
    int curr = baseAToDecimal(evenfull, n);
    res += curr;
    for (int i = 0; i < n; i++)
    {
        string oddfull = newtemp + to_string(i) + rev;
        string neww = temp + to_string(i);
        dfs(index + 1, maxi, neww);
        int curr = baseAToDecimal(oddfull, n);

        res += curr;
    }

    for (int i = 0; i < n; i++)
    {
    }
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> limit;
    res = 0;
    string strlimit = decimalToBaseA(limit, n);
    // cout << strlimit << endl;
    int size = strlimit.size();
    half = size / 2;
    st.clear();
    dp.clear();
    string temp;

    dfs(0, n, temp);
    //   still one lengths are left
    //   dfs string of length at max half
    cout << res << endl;
    return 0;
}
