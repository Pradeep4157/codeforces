#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so for every monster i will kill it with a sword,,

    get a new sword of max(x,ci)

    so sort swords..

    i will try to  kill lowest monster with lowest sword..

    if lowest is not powerful..

    throw it away..

    then kill it insert new sword of max(x,ci)

    remove that monster from pq

    now monster with same power will i defeat the smaller

    reward one or larger one first ?

    my goal is to defeat as many monsters as possible ..

    so if i take the smaller ones it doesnt matter because

    it is adding only

    if i take larger ones it might get used up first..


*/
struct CustomCompare
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second > b.second;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        priority_queue<int, vector<int>, greater<int>> swords;
        priority_queue<pair<int, int>, vector<pair<int, int>>, CustomCompare> monsters;
        int best = 0;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            swords.push(ele);
            best = max(best, ele);
        }
        vector<pair<int, int>> temp(m);

        for (int i = 0; i < m; i++)
        {
            cin >> temp[i].first;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> temp[i].second;
        }
        sort(temp.begin(), temp.end());

        for (int i = 0; i < m; i++)
        {
            if (temp[i].second == 0)
                continue;
            // theres no point fighting monster out of our league..
            if (temp[i].first <= best)
                best = max(best, temp[i].second);
            if (temp[i].second > best)
            {

                break;
            }
            best = max(best, temp[i].second);
            monsters.push({temp[i].first, temp[i].second});
        }
        // first we will defeat all > 0 monsters..
        int res = 0;
        vector<int> remaining;
        while (true)
        {

            if (monsters.empty())
                break;
            int currmonsterpower = monsters.top().first;
            int reward = monsters.top().second;

            while (true)
            {
                if (swords.empty())
                    break;
                int currsword = swords.top();
                if (currsword >= currmonsterpower)
                    break;
                swords.pop();
                remaining.push_back(currsword);
            }
            if (swords.empty())
                break;
            int currsword = swords.top();
            swords.pop();
            monsters.pop();
            currsword = max(currsword, reward);
            swords.push(currsword);
            res++;
        }
        // now we will defeat remaining 0 monsters with best swords..
        // now we have best swords and garbage swords..
        // its 100% that all monsters are empty..
        for (auto a : remaining)
        {
            swords.push(a);
        }
        // push all 0 monsters..
        for (auto a : temp)
        {
            if (a.second == 0)
                monsters.push({a.first, a.second});
        }
        while (true)
        {

            if (monsters.empty())
                break;
            int currmonsterpower = monsters.top().first;
            int reward = monsters.top().second;

            while (true)
            {
                if (swords.empty())
                    break;
                int currsword = swords.top();
                if (currsword >= currmonsterpower)
                    break;
                swords.pop();
            }
            if (swords.empty())
                break;
            int currsword = swords.top();
            swords.pop();
            monsters.pop();

            res++;
        }
        cout << res << endl;
    }
    return 0;
}
