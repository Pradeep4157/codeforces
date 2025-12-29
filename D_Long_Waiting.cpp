#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
struct CustomComp
{
    bool operator()(const vector<int> &a, const vector<int> &b) const
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int currtime = 0;
    int customers = 0;

    priority_queue<vector<int>, vector<vector<int>>, CustomComp> pq;

    for (int i = 0; i < n; i++)
    {
        int entertime, duration, people;
        cin >> entertime >> duration >> people;
        currtime = max(currtime, entertime);
        if (customers + people <= k)
        {
            cout << currtime << endl;

            pq.push({duration + currtime, people});
            customers += people;
        }
        else
        {
            // cout << customers << ":" << i << endl;
            while (!pq.empty())
            {
                vector<int> curr = pq.top();
                pq.pop();
                int leavetime = curr[0], peopleleft = curr[1];
                // cout << i << ":" << currtime << ":" << leavetime << "->" << people << endl;
                customers -= peopleleft;
                currtime = max(currtime, leavetime);
                if (customers + people <= k)
                    break;
            }
            customers += people;
            pq.push({duration + currtime, people});
            cout << currtime << endl;
        }
    }
    return 0;
}
