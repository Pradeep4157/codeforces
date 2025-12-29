#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n, -1));
        int c = (n - 1) / 2;
        arr[c][c] = 0;
        int count = 1;
        int amount = 2;
        char prev = 'r';
        int i = c;
        int j = c + 1;
        int number = 1;
        while (true)
        {
            // condition on count and amount
            if (count > 2)
            {
                if (amount == 2)
                {
                    if (count > 3)
                    {
                        count = 1;
                        amount++;
                    }
                }
                else
                {
                    count = 1;
                    amount++;
                }
            }
            if (prev == 'r')
            {
                // down traversal
                prev = 'd';
                int endi = i + amount;
                bool end = false;
                if (endi > n)
                {
                    end = 1;
                    endi = 1;
                }
                while (i < endi)
                {
                    arr[i][j] = number;
                    number++;
                    i++;
                }
                if (end)
                    break;
                i--;
                j--;
            }
            else if (prev == 'd')
            {
                // left traversal
                prev = 'l';
                // here the matrix can finish
                int endj = j - amount;
                bool end = false;
                if (endj < -1)
                {
                    endj = -1;
                    end = 1;
                }
                while (j > endj)
                {
                    arr[i][j] = number;
                    number++;
                    j--;
                }
                if (end)
                    break;
                j++;
                i--;
            }
            else if (prev == 'l')
            {
                // up traversal
                prev = 'u';
                int endi = i - amount;
                bool end = false;
                if (endi < -1)
                {
                    endi = -1;
                    end = 1;
                }
                while (i > endi)
                {
                    arr[i][j] = number;
                    number++;
                    i--;
                }
                if (end)
                    break;
                i++;
                j++;
            }
            else
            {
                // right traversal
                prev = 'r';
                int endj = j + amount;
                bool end = false;
                if (endj > n)
                {
                    endj = n;
                    end = true;
                }
                while (j < endj)
                {
                    arr[i][j] = number;
                    number++;
                    j++;
                }
                if (end)
                {
                    break;
                }
                j--;
                i++;
            }
            count++;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}
