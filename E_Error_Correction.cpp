#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    if len is not equal..

    so in a set i will keep all the string indexes..

    and keep removing the ones that do not match..

    with a counter if it exceeds 2 then remove ..

    i think there are cases for deletion..

    among the valids at this index..

    if the index matches then move to the next string ...

    else :

        either this index is changed so we need to do index + 1..

        else it might be del

    it has the same complexity ...

    so why this complex method..

    W.K.T only one operation has been done..

    either del / inserted / changed / same :

    if len is same then either changed /  same so only one change allowed..

    else if len is not same then :

        len2 should be len + 1 / len - 1 and also only 1 diff..


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> res;
    int size = s.size();
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        int size2 = t.size();
        int diff = abs(size - size2);

        if (diff > 1)
        {
            continue;
        }
        // else it might be valid..
        if (diff == 0)
        {
            // only 1 change allowed..
            int counter = 0;
            for (int j = 0; j < size; j++)
            {
                if (s[j] != t[j])
                    counter++;
                if (counter > 1)
                    break;
            }
            if (counter <= 1)
            {
                // valid..
                res.push_back(i + 1);
            }
        }
        else
        {
            diff = size - size2;
            // diff is 1 then one is del
            if (diff == 1)
            {
                int count = 0;
                int index = 0;
                for (int j = 0; j < size; j++)
                {
                    if (index >= size2)
                    {
                        count++;
                        continue;
                    }
                    if (s[j] != t[index])
                    {
                        count++;
                    }
                    else
                    {
                        index++;
                    }
                    if (count > 1)
                        break;
                }
                if (count == 1)
                {
                    res.push_back(i + 1);
                }
            }
            else
            {
                int count = 0;
                int index = 0;
                for (int j = 0; j < size2; j++)
                {
                    if (index >= size)
                    {
                        count++;
                        continue;
                    }
                    if (s[index] != t[j])
                    {
                        count++;
                    }
                    else
                    {
                        index++;
                    }
                    if (count > 1)
                        break;
                }
                if (count == 1)
                {
                    res.push_back(i + 1);
                }
            }
        }
    }
    cout << res.size() << endl;
    for (auto a : res)
        cout << a << " ";
    cout << endl;
    return 0;
}
