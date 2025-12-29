#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        vector<int> bitCount(32, 0);
        for (int i = 0; i < n; ++i)
        {
            for (int b = 0; b < 32; ++b)
            {
                if ((a[i] >> b) & 1)
                {
                    bitCount[b]++;
                }
            }
        }

        long long maxSum = 0;
        for (int i = 0; i < n; ++i)
        {
            long long sum = 0;
            for (int b = 0; b < 32; ++b)
            {
                if ((a[i] >> b) & 1)
                {
                    sum += (1LL << b) * (n - bitCount[b]);
                }
                else
                {
                    sum += (1LL << b) * bitCount[b];
                }
            }
            maxSum = max(maxSum, sum);
        }

        cout << maxSum << endl;
    }

    return 0;
}
