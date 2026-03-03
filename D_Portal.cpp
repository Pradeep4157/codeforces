#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    if the ele on the right of 2nd portal is smaller than the

    first ele of 2nd portal then we can send it there..

    also if the ele on the left of first portal is bigger than

*/
int x, y;
bool middle_empty(vector<int> &arr, int n)
{
    vector<int> first;
    vector<int> middle;
    vector<int> last;
    for (int i = 0; i < n; i++)
    {
        if (i < x)
            first.push_back(i);
        else if (i >= y)
            last.push_back(i);
        else
            middle.push_back(i);
    }
    // now keep pushing right ele till you are satisfied..
    int right_start = 0;
    if (middle.empty())
    {
        return 1;
    }
    else
        return 0;
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
        cin >> n >> x >> y;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        map<int, int> same_same;
        int left = 0, right = 0;
        while (right < n)
        {
            while (right < n && arr[left] == arr[right])
                right++;
            right--;
            same_same[left] = right;
            right++;
            if (right == n)
                break;
            left = right;
        }
        bool is_empty = middle_empty(arr, n);
        if (is_empty)
        {
            for (auto a : arr)
            {
                cout << a << " ";
            }
            cout << endl;
            continue;
        }
        // for (auto a : same_same)
        // {
        //     cout << a.first << ":" << a.second << endl;

        // }
        vector<int> res1, res2;
        {
            // pushing right ele to the left..
            vector<int> first;
            vector<int> middle;
            vector<int> last;
            for (int i = 0; i < n; i++)
            {
                if (i < x)
                    first.push_back(i);
                else if (i >= y)
                    last.push_back(i);
                else
                    middle.push_back(i);
            }
            int right_start = 0;
            int right_size = last.size();
            while (true)
            {
                if (right_start == right_size)
                    break;
                int curr = arr[right_start];
                int comp = arr[middle[0]];
                if (comp == curr)
                {
                    int mid_end = same_same[middle[0]];
                    int next_start = mid_end + 1;
                    // if next start is in right array then push it doesnt matter..
                    if (next_start >= last[0])
                    {
                        // then it is same thing we can do it..
                        first.push_back(last[right_start]);
                    }
                    else
                    {
                        // it is in middle subarray ..
                        comp = arr[next_start];
                        if (comp > curr)
                            first.push_back(last[right_start]);
                        else
                            break; // they cant be same..
                    }
                }
                else if (comp > curr)
                {
                    // then push it ahead..
                    first.push_back(last[right_start]);
                }
                else
                    break; // because its worse..
                right_start++;
            }
            // now we have all split..

            for (auto a : first)
                res1.push_back(arr[a]);
            for (auto a : middle)
                res1.push_back(arr[a]);
            for (int i = right_start; i < right_size; i++)
            {
                res1.push_back(arr[last[i]]);
            }
        }
        {
            // now we try to move left..
            vector<int> left;
            vector<int> middle;
            vector<int> right;
            for (int i = 0; i < n; i++)
            {
                if (i < x)
                    left.push_back(i);
                else if (i >= y)
                    right.push_back(i);
                else
                    middle.push_back(i);
            }
            int left_size = left.size();
            int left_end = left_size - 1;
            // now we keep moving left till valid..
            while (true)
            {
                if (left_end < 0)
                    break;
                // now we see if we should move this left to right..
                int curr = arr[left_end];
                if (arr[left[left_end]] > middle[0])
                {
                    // we will send it ..
                    left_end--;
                }
                else if (arr[left[left_end]] < middle[0])
                {
                    // we will def not send..
                    break;
                }
                else
                {
                    // it is same..
                    // now if next will be after same same..
                    int start = middle[0];
                    int end = same_same[start];
                    int next_start = end + 1;
                    if (next_start > middle[middle.size() - 1])
                    {
                        // the whole array is same only..
                        // so now we need to comp it with start of next but it doesnt matter because its like same thing..
                        left_end--;
                    }
                    else
                    {
                        int comp = arr[next_start];
                        if (comp > curr)
                        {
                            // no we wont send..
                            break;
                        }
                        else
                        {
                            left_end--;
                        }
                    }
                }
            }
            for (int i = 0; i <= left_end; i++)
            {
                res2.push_back(arr[left[i]]);
            }
            for (auto a : middle)
                res2.push_back(arr[a]);
            for (int i = left_end + 1; i < left_size; i++)
            {
                res2.push_back(arr[left[i]]);
            }
            for (auto a : right)
                res2.push_back(arr[a]);
        }
        bool first_better = 1;
        for (int i = 0; i < n; i++)
        {
            if (res1[i] > res2[i])
            {
                first_better = false;
                break;
            }
            else if (res1[i] < res2[i])
            {
                break;
            }
        }
        
        vector<int> res;
        if (first_better)
            res = res1;
        else
            res = res2;
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
