#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> Remainder;
    
    for (int i = 0; i < nums.size(); i++)
    {
        int remainder = target - nums[i];

        if (Remainder.find(remainder) != Remainder.end())
        {
            return {Remainder[remainder], i}; // Immediately return the result
        }
        Remainder[nums[i]] = i;
    }
    return {}; // Return an empty vector if no solution is found
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cin >> target;

    vector<int> res = twoSum(arr, target);

    if (res.empty())
        cout << "No solution found\n";
    else
        cout << res[0] << " " << res[1] << endl;

    return 0;
}
