#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<unordered_map<int, double>> dice(n);

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        unordered_map<int, int> freq;
        for (int j = 0; j < k; j++)
        {
            int face;
            cin >> face;
            freq[face]++;
        }
        for (auto &p : freq)
        {
            dice[i][p.first] = (double)p.second / k;
        }
    }
    for (auto a : dice)
    {
        for (auto b : a)
        {
            cout << b.first << ":" << b.second << " ";
        }
        cout << endl;
    }
    double maxProb = 0.0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double prob = 0.0;
            for (auto &p : dice[i])
            {
                if (dice[j].count(p.first))
                {
                    prob += p.second * dice[j][p.first];
                }
            }
            maxProb = max(maxProb, prob);
        }
    }

    cout << fixed << setprecision(15) << maxProb << endl;

    return 0;
}
